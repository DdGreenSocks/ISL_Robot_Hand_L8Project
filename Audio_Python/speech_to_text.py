import whisper
import time
import warnings

warnings.filterwarnings("ignore", category=UserWarning)

def convert_audio_to_text(audio_path, model):
    result = model.transcribe(audio_path)
    print(result["text"])


if __name__ == "__main__":
    target_model = whisper.load_model("base")
    

while True:
	start_time=time.time()
	convert_audio_to_text('output.wav', target_model)
	print(f"Time Taken {time.time()-start_time} seconds")
	time.sleep(2)


