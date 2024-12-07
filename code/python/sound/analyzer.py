import argparse
from pydub import AudioSegment
from colorama import Fore
from pyfiglet import figlet_format

def traitement (audio_file_path: str) -> dict[str, any]:
	# Load the uploaded audio file to analyze it further
	audio = AudioSegment.from_file(audio_file_path)

	# Check the duration and properties of the audio file to understand it better
	audio_info = {
		"duration_seconds": len(audio) / 1000,
		"channels": audio.channels,
		"frame_rate": audio.frame_rate,
		"sample_width": audio.sample_width
	}

	return audio_info


def main():
	screen = figlet_format("AudioAnalyzer.py")
	print(f"{Fore.GREEN} {screen} {Fore.WHITE}")

	parser = argparse.ArgumentParser(description="Analyseur de son.")

	arguments = Arguments()

	parser.add_argument("-i", "--input", nargs=1, help="Chemin du fichier audio en entrée.")

	parser.parse_args(namespace=arguments)

	in_path: str = arguments.input[0]

	audio_info: dict[str, any] = traitement(in_path)

	print(audio_info)

	return

if __name__ == "__main__":
	main()