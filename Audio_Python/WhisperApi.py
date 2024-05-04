import time  # Import the time module for time-related functions
import whisper  # Import the whisper module for loading the Whisper model


def convert_audio_to_text(audio_path, model):
    """
    Function to convert audio to text using the provided model.

    Parameters:
        audio_path (str): Path to the audio file.
        model: Loaded Whisper model for transcription.
    """
    result = model.transcribe(audio_path)  # Transcribe audio to text using the model
    print(result["text"])  # Print the transcription


if __name__ == "__main__":
    target_model = whisper.load_model("tiny.en")  # Load the Whisper model
    while True:  # Infinite loop
        start_time = time.time()  # Record the start time
        convert_audio_to_text('output.wav', target_model)  # Convert audio to text
        time.sleep(2)  # Wait for 2 seconds
        print(f"Time Taken {time.time()-start_time}")  # Print the time taken for the conversion
