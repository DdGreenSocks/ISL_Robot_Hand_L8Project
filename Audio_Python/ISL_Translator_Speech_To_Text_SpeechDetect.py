import pyaudio
import wave
import threading
import time
import RPi.GPIO as GPIO

# GPIO pin configuration
TRIGGER_PIN = 2   # Button connected to GPIO 2
GREEN_LED_PIN = 15  # Green LED connected to GPIO 15
RED_LED_PIN = 14   # Red LED connected to GPIO 14

# Parameters for audio input and recording
FORMAT = pyaudio.paInt16
CHANNELS = 1
RATE = 44100
CHUNK_SIZE = 1024
RECORD_DURATION = 5  # Duration of each recording in seconds
OUTPUT_FILE = "output.wav"

# PyAudio initialization
p = pyaudio.PyAudio()

# Setup GPIO pins
GPIO.setmode(GPIO.BCM)
GPIO.setup(TRIGGER_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(GREEN_LED_PIN, GPIO.OUT)
GPIO.setup(RED_LED_PIN, GPIO.OUT)

# Function to control LED status
def set_led(pin, state):
    GPIO.output(pin, state)

# Function to start recording audio
def start_recording():
    frames = []
    stream = p.open(format=FORMAT,
                    channels=CHANNELS,
                    rate=RATE,
                    input=True,
                    frames_per_buffer=CHUNK_SIZE)

    print("Recording... Press the button again to stop.")

    set_led(GREEN_LED_PIN, GPIO.HIGH)  # Turn on green LED (recording)
    set_led(RED_LED_PIN, GPIO.LOW)     # Turn off red LED (not recording)

    while GPIO.input(TRIGGER_PIN) == GPIO.LOW:
        data = stream.read(CHUNK_SIZE)
        frames.append(data)

    print("Recording stopped.")

    # Stop and close the audio stream
    stream.stop_stream()
    stream.close()

    # Save the recorded audio to a WAV file
    if frames:
        with wave.open(OUTPUT_FILE, 'wb') as wf:
            wf.setnchannels(CHANNELS)
            wf.setsampwidth(p.get_sample_size(FORMAT))
            wf.setframerate(RATE)
            wf.writeframes(b''.join(frames))
            print(f"Recording saved as {OUTPUT_FILE}")

    set_led(GREEN_LED_PIN, GPIO.LOW)  # Turn off green LED
    set_led(RED_LED_PIN, GPIO.HIGH)   # Turn on red LED (not recording)

# Main function to wait for trigger
def main():
    set_led(GREEN_LED_PIN, GPIO.LOW)  # Ensure green LED is off
    set_led(RED_LED_PIN, GPIO.HIGH)   # Ensure red LED is on

    print("Waiting for button press to start recording...")

    while True:
        if GPIO.input(TRIGGER_PIN) == GPIO.LOW:
            threading.Thread(target=start_recording).start()  # Start recording in a separate thread
            break
        time.sleep(0.1)

    # Cleanup GPIO
    GPIO.cleanup()

if __name__ == "__main__":
    main()
