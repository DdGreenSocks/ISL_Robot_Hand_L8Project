import pyaudio
import wave
import keyboard
import time
import whisper
import os


FRAMES_PER_BUFFER = 1024
FORMAT = pyaudio.paInt16
CHANNELS = 1
RATE = 44100
RECORD_DURATION = 2  # Duration of each recording in seconds

p = pyaudio.PyAudio()
frames = []
is_recording = False


def start_recording():
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


def convert_audio_to_text(audio_path, model):
    result = model.transcribe(audio_path)
    return result["text"]


def main(model):
    global is_recording

    print("Press SPACE to start/stop recording...")
    keyboard.wait('space')  # Wait for space key press

    if not is_recording:
        start_recording()
        text_result = convert_audio_to_text('output.wav', model)
        print("Transcription Result:", text_result)
        is_recording = False


if __name__ == "__main__":
    target_model = whisper.load_model("base")  # Load the Whisper model
    while True:
        main(target_model)
