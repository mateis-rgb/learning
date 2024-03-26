#include <iostream>
#include <array>

using array = std::array<int, 99>;

int max_indice (array arr)
{
	int i_max = arr[0];

	for (int k = 1; k < arr.size(); k++)
	{
		if (i_max < arr[k])
		{
			i_max = arr[k];
		}
	}

	return i_max;
}

int main (void)
{
	array arr = {1, 2, 3, 4, 5, 6};
	int maximum = max_indice(arr);

	std::cout << "indice max: " << maximum << "\n";
	std::cout << "maximum: " << arr[maximum] << "\n";

	return 0;
}