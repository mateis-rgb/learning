from random import randint;

def create_random_array () -> list:
	array: list = list();

	for k in range(10000):
		array.append(randint(-99999, 99999));
	
	return array;


def quick_sort (array: list) -> list:
	if (len(array) < 2):
		return array;
	
	pivot_index: int = len(array) - 1;
	pivot: int = array[pivot_index];

	lesser: list = [item for item in array[:pivot_index] if (item <= pivot)];
	greater: list = [item for item in array[:pivot_index] if (item > pivot)];

	return quick_sort(lesser) + [pivot] + quick_sort(greater);

def main ():
	print("[program]: Creating Array...");
	array: list = create_random_array();

	print("[program]: Sorting Array...");
	quick_sort(array);

	print("[program]: All OK!");

if (__name__ == "__main__"):
	main();