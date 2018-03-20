#include "PageRank.h"

int main() {
	std::string filename = "test.txt";
	std::ifstream input_file(filename);
	std::vector<int> input;
	int temp = 0, size = 0;
	while (input_file >> temp) {
		input.push_back(temp);
		++size;
	}
	int dimension = size / 4;

	// Add the values read from filename to 2D vector array matrix
	std::vector<std::vector<double>> matrix;
	std::cout << "Reading file " << filename << std::endl;
	for (int y = 0; y < dimension; ++y) {
		matrix.push_back(std::vector<double>());
		for (int x = 0; x < dimension; ++x) {
			matrix.at(y).push_back(input.at(y * dimension + x));
		}
	}
	printMatrix(matrix);

	// Divide the values in the column by the sum of the column. 
	// Generate "importance"
	for (int x = 0; x < dimension; ++x) {
		int sum = 0;
		for (int y = 0; y < dimension; ++y) {
			sum += (int) matrix.at(y).at(x);
		}
		for (int y = 0; y < dimension; ++y) {
			if (matrix.at(y).at(x) != 0) {
				matrix.at(y).at(x) = (double)matrix.at(y).at(x) / sum;
			}
		}
	}
	printMatrix(matrix);

	system("pause");

	return 0;
	
}

void printMatrix(const std::vector<std::vector<double>> &arr) {
	for (size_t y = 0; y < arr.size(); ++y) {
		for (size_t x = 0; x < arr.size(); ++x) {
			if (arr.at(y).at(x) != 0) {
				std::cout << arr.at(y).at(x) << " ";
			} else {
				std::cout << arr.at(y).at(x) << " ";
			}
		}
		std::cout << std::endl;
	}
}