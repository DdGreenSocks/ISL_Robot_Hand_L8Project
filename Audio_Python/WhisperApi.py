import whisper
import time


def convert_audio_to_text(audio_path, model):
    result = model.transcribe(audio_path)
    print(result["text"])


if __name__ == "__main__":
    target_model = whisper.load_model("base")
    while True:
        convert_audio_to_text('output.wav', target_model)
        time.sleep(2)

