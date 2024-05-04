import pyaudio  # Import the PyAudio module for audio input/output
import wave  # Import the wave module for working with audio files

# Define constants for audio recording
FRAMES_PER_BUFFER = 3200  # Number of frames per buffer
FORMAT = pyaudio.paInt16  # Audio format
CHANNELS = 1  # Number of audio channels
RATE = 16000  # Sample rate

def record_mic():
    """
    Function to record audio from the microphone and save it to a WAV file.
    """
    p = pyaudio.PyAudio()  # Create a PyAudio object

    # Open a stream for audio input
    stream = p.open(
        format=FORMAT,
        channels=CHANNELS,
        rate=RATE,
        input=True,
        frames_per_buffer=FRAMES_PER_BUFFER
    )

    print("Start recording...")

    seconds = 1  # Duration of recording (in seconds)
    frames = []  # List to store audio frames

    # Record audio for the specified duration
    for i in range(0, int(RATE / FRAMES_PER_BUFFER) * seconds):
        data = stream.read(FRAMES_PER_BUFFER)  # Read audio data from the stream
        frames.append(data)  # Append the data to the frames list

    # Stop and close the audio stream
    stream.stop_stream()
    stream.close()
    p.terminate()  # Terminate the PyAudio object

    # Save the recorded audio to a WAV file
    obj = wave.open("output.wav", "wb")
    obj.setnchannels(CHANNELS)
    obj.setsampwidth(p.get_sample_size(FORMAT))
    obj.setframerate(RATE)
    obj.writeframes(b"".join(frames))
    obj.close()

if __name__ == "__main__":
    record_mic()  # Call the record_mic function to record audio
