#include "PageRank.h"

int main() {
	
	std::ifstream input_file("test.txt");
	std::vector<int> input;
	int temp = 0, size = 0;
	while (input_file >> temp) {
		input.push_back(temp);
		++size;
	}
	int dimension = size / 4;
	

	//int input[16] = { 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0 };
	//int input[4][4] = { {0, 1, 1, 0}, {1, 0, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0} };

	std::vector<std::vector<double>> matrix;
	for (int y = 0; y < dimension; ++y) {
		matrix.push_back(std::vector<double>());
		for (int x = 0; x < dimension; ++x) {
			matrix.at(y).push_back(input.at(y * dimension + x));
			std::cout << matrix.at(y).at(x) << " ";
		}
		std::cout << std::endl;
	}

	system("pause");

	return 0;
	
}