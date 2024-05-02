import whisper
import RPi.GPIO as GPIO # Import Raspberry Pi GPIO library
import time 
import warnings
import pyaudio
import wave
import sounddevice
import os
import serial


warnings.filterwarnings("ignore", category=UserWarning)
#warnings.filterwarnings("ignore", category=RuntimeWarning, message="ALSA lib*")



# GLOBALLY SET-UP VALUES
p = pyaudio.PyAudio()
ser=serial.Serial('/dev/ttyACM0',9600) # '/dev/ttyAMA0 is Arduino COM Port
model = whisper.load_model("base")

GPIO.setwarnings(False) # Ignore warning for now
GPIO.setmode(GPIO.BOARD) # Use physical pin numbering
button_pin = 10
GPIO.setup(button_pin, GPIO.IN, pull_up_down=GPIO.PUD_DOWN) # Set pin 10 to be an input pin and set initial value to be pulled low (off)
debounce_delay = 0.05
last_button_state = GPIO.input(button_pin)

FRAMES_PER_BUFFER = 2048
FORMAT = pyaudio.paInt16
CHANNELS = 1
RATE = 44100
RECORD_DURATION = 1  # Duration of each recording in seconds

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

frames = []
# is_recording = False


def record_mic():
	global frames, is_recording
	frames = []  # Reset frames list
	print("Start recording...")

	input_device_index = p.get_default_input_device_info()["index"]
	is_recording = True

	stream = p.open(
		format=FORMAT,
		channels=CHANNELS,
		rate=RATE,
		input=True,
		frames_per_buffer=FRAMES_PER_BUFFER,
		input_device_index=input_device_index
	)

	start_time = time.time()
	while is_recording:
		data = stream.read(FRAMES_PER_BUFFER)
		frames.append(data)

		# Check if recording duration exceeds RECORD_DURATION
		if time.time() - start_time >= RECORD_DURATION:
			break

	# Stop and close the stream
	stream.stop_stream()
	stream.close()

	# Save the recorded audio
	save_audio()


def save_audio():
	global frames
	if frames:
		print("Saving recording...")
		file_path = "output.wav"

		# Delete the existing file if it exists
		if os.path.exists(file_path):
			os.remove(file_path)

		with wave.open(file_path, "wb") as wf:
			wf.setnchannels(CHANNELS)
			wf.setsampwidth(p.get_sample_size(FORMAT))
			wf.setframerate(RATE)
			wf.writeframes(b"".join(frames))
		print("Recording saved as output.wav")
	else:
		print("No recording to save.")



def convert_audio_to_text(audio_path):
	result = model.transcribe(audio_path)
	result = validate_result(result["text"])
	print("Transcription Result:", result)
	return result
	
def send_command(command):
    ser.write(command.encode())
    print(f"Sent command: {command}")



def button_press():
	global last_button_state
	current_button_state= GPIO.input(button_pin)
	#print("Current button state:", current_button_state)
	#print("Last button state:", last_button_state)
	if current_button_state != last_button_state:
		last_button_state = current_button_state
		if current_button_state == GPIO.HIGH:
			time.sleep(0.2)
			last_button_state=0
			return True


def validate_result(string):
	global EXCEPTIONS_DICTIONARY
	sample_text = string.upper().replace('.','').strip(  )
	if sample_text in EXCEPTIONS_DICTIONARY.keys():
		sample_text = EXCEPTIONS_DICTIONARY[sample_text]
	return sample_text

def main():
	print("Please Wait While Audio Database is configured")
	target_model = whisper.load_model("base")

	print("Press Button to Begin")

	try:
		while True: # Run forever
			
			
			if GPIO.input(10) == GPIO.HIGH:
				button_pressed=button_press()
				if	button_pressed:
					ser.write(b'#')
					print("Say Letter")
					record_mic()
					start_time = time.time()
					print("Please Wait While Transcribing")
					text_result = convert_audio_to_text('output.wav')
					end_time = time.time()
					send_command(text_result)
					print(f"Transcription took {end_time - start_time} seconds")
					print("Press Button to Begin")


	except KeyboardInterrupt:
		GPIO.cleanup()
		ser.close()

if __name__ == "__main__":
    main()
