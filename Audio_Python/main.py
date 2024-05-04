# Project Title: ISL Alphabet Translator Audio
# Description: Record audio inputted by user to be transcribed and sent serially to an Arduino Mega
# By Deirdre Deeney
# Date: 04/05/2024

import whisper  # Importing whisper library for some functionality
import RPi.GPIO as GPIO  # Import Raspberry Pi GPIO library for interacting with GPIO pins o
import time  # Importing time module for time-related functions
import warnings  # Importing warnings module to handle warnings
import pyaudio  # Importing pyaudio library for audio I/O operations
import wave  # Importing wave module for reading and writing WAV files
import sounddevice  # Importing sounddevice to prevent multiple ALAS warnings
import os  # Importing os module for interacting with the operating system
import serial  # Importing serial module for serial communication

warnings.filterwarnings("ignore", category=UserWarning)  # Ignore UserWarnings

# GLOBALLY SET-UP VALUES
print("Welcome to ISL Alphabet translator ")
# Initialize PyAudio
p = pyaudio.PyAudio()

# Establish serial connection with Arduino
ser = serial.Serial('/dev/ttyACM0', 9600)

print("Please Wait While Audio Database is configured")
config_time = time.time()
# Load a model from the whisper library
model = whisper.load_model("base")
print(f"Time taken to load model {time.time() - config_time} seconds")  # testing time to load models

# Configure GPIO
GPIO.setwarnings(False)  # Ignore GPIO warnings for now
GPIO.setmode(GPIO.BOARD)  # Use physical pin numbering
button_pin = 10  # GPIO pin for the button
GPIO.setup(button_pin, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)  # Set up button pin as input with pull-down resistor
debounce_delay = 0.05  # Debounce delay for button press
last_button_state = GPIO.input(button_pin)  # Track the last state of the button

# Audio recording parameters
FRAMES_PER_BUFFER = 3200  # Number of audio frames saved to buffer per second
FORMAT = pyaudio.paInt16  # Audio format for recording feedback
CHANNELS = 1  # Number of channels for recording
RATE = 16000  # Sampling rate
RECORD_DURATION = 1  # Duration of each recording in seconds

# Dictionary mapping letters that could be mistaken for words
EXCEPTIONS_DICTIONARY = {
    "HEY": "A",
    "SEE": "C",
    "SEA": "C",
    "YOU": "U",
    "WHY": "Y",
    "WHY?": "Y",
    "EYE": "I",
    "AYE": "I",
    "BEE": "B",
    "BE": "B",
    "DEE": "D",
    "OKAY": "K",
    "OK": "K",
    "ASS": "S",
    "AS": "S",
    "OH": "O",
    "OH!": "O",
    "OR": "R",
    "PEA": "P",
    "PEE": "P"
}

frames = []  # List to store audio frames
is_recording = False  # Initialise recording as False to begin with


# Variable to record audio from microphone
def record_mic():
    global frames, is_recording
    frames = []  # Reset frames list
    print("Start recording...")

    # Get the default input device index
    input_device_index = p.get_default_input_device_info()["index"]
    is_recording = True

    # Open audio stream for recording
    stream = p.open(
        format=FORMAT,
        channels=CHANNELS,
        rate=RATE,
        input=True,
        frames_per_buffer=FRAMES_PER_BUFFER,
        input_device_index=input_device_index
    )

    start_time = time.time()  # Record start time
    while is_recording:
        data = stream.read(FRAMES_PER_BUFFER)  # Read audio data
        frames.append(data)  # Append audio data to frames list

        # Check if recording duration exceeds RECORD_DURATION
        if time.time() - start_time >= RECORD_DURATION:
            break

    # Stop and close the audio stream
    stream.stop_stream()
    stream.close()

    # Save the recorded audio
    save_audio()


# Function to save recorded audio to a WAV file
def save_audio():
    global frames
    if frames:
        print("Saving recording...")
        file_path = "output.wav"

        # Delete the existing file if it exists
        if os.path.exists(file_path):
            os.remove(file_path)

        # Open a WAV file and write audio frames to it
        with wave.open(file_path, "wb") as wf:
            wf.setnchannels(CHANNELS)
            wf.setsampwidth(p.get_sample_size(FORMAT))
            wf.setframerate(RATE)
            wf.writeframes(b"".join(frames))  # Concatenate audio frames and write to file
        print("Recording saved as output.wav")
    else:
        print("No recording to save.")


# Function to convert audio file to text using a pre-trained model
def convert_audio_to_text(audio_path):
    result = model.transcribe(audio_path)  # Transcribe audio to text
    result = validate_result(result["text"])  # Validate and process the transcribed text
    print("Transcription Result:", result)  # Print transcription result
    return result  # Return the processed text


# Function to send a command via serial communication
def send_command(command):
    ser.write(command.encode())  # Send the command over the serial connection
    print(f"Sent command: {command}")  # Print the command


# Function to handle button press event
def button_press():
    global last_button_state
    current_button_state = GPIO.input(button_pin)  # Get the current state of the button
    if current_button_state != last_button_state:  # Check if button state has changed
        last_button_state = current_button_state  # Update last button state
        if current_button_state == GPIO.HIGH:  # Check if button is pressed
            time.sleep(debounce_delay)  # Wait for debounce
            last_button_state = 0  # Reset last button state
            return True  # Return True indicating button press


# Function to validate letter using exception dictionary and process the transcribed text
def validate_result(string):
    global EXCEPTIONS_DICTIONARY
    sample_text = string.upper().replace('.', '').strip()  # Ensure capital format and remove full stop and blank space
    if sample_text in EXCEPTIONS_DICTIONARY.keys():  # Replace text if in Exceptions Dictionary
        sample_text = EXCEPTIONS_DICTIONARY[sample_text]
    return sample_text  # Return the processed text


# Main function to run the program
def main():
    print("Press Button to Begin")

    try:
        while True:  # Run forever
            if GPIO.input(button_pin) == GPIO.HIGH:  # Check if button is pressed
                button_pressed = button_press()  # Check if button is pressed
                if button_pressed:
                    ser.write(b'#')
                    ser.write(b'#')  # Send a '#' signal to indicate the start of audio recording
                    print("Say Letter")
                    record_mic()  # Record audio
                    start_time = time.time()  # Record start time for transcription
                    print("Please Wait While Transcribing")
                    text_result = convert_audio_to_text('output.wav')  # Convert recorded audio to text
                    end_time = time.time()  # Record end time for transcription
                    send_command(text_result)  # Send the transcribed text as a command
                    print(f"Transcription took {end_time - start_time} seconds")  # Print transcription duration
                    print("Press Button to Begin")  # Prompt to press the button again

    except KeyboardInterrupt:
        GPIO.cleanup()  # Clean up GPIO settings
        ser.close()  # Close the serial connection


if __name__ == "__main__":
    main()  # Run the main function if the script is executed directly
