#include "PageRank.h"

int main() {
	std::string filename = "connectivity.txt";
	std::ifstream input_file(filename);
	std::vector<int> input;
	int temp = 0, size = 0;
	while (input_file >> temp) {
		input.push_back(temp);
		++size;
	}
	int dimension = sqrt(size);

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

	std::cout << std::endl << "Convert to stochastic matrix" << std::endl;
	// Divide the values in the column by the sum of the column. 
	// Generate "importance" and tranform matrix to "stochastic"
	for (int x = 0; x < dimension; ++x) {
		int sum = 0;
		for (int y = 0; y < dimension; ++y) {
			sum += (int)matrix.at(y).at(x);
		}
		if (sum == 0) { // 0 connectivity column
			for (int y = 0; y < dimension; ++y) {
				matrix.at(y).at(x) = (double) 1 / dimension;
			}
		} else {
			for (int y = 0; y < dimension; ++y) {
				if (matrix.at(y).at(x) != 0) {
					matrix.at(y).at(x) = (double)matrix.at(y).at(x) / sum;
				}
			}
		}
	}
	printMatrix(matrix);

	// Generation of transition matrix
	std::vector<std::vector<double>> transition;
	const double Q = (double) 1 / dimension;
	for (size_t y = 0; y < matrix.size(); ++y) {
		transition.push_back(std::vector<double>());
		for (size_t x = 0; x < matrix.size(); ++x) {
			transition.at(y).push_back((matrix.at(y).at(x) * P) + (1.0 - P) * Q);
		}
	}
	std::cout << std::endl << "transition" << std::endl;
	printMatrix(transition);

	// Setup rank
	std::vector<std::vector<double>> rank;
	for (size_t i = 0; i < matrix.size(); ++i) {
		rank.push_back(std::vector<double>());
		rank.at(i).push_back(1.0);
	}
	
	
	// Matrix multiplication
	double min = 1;
	for (size_t i = 0; min > D; ++i) {
		std::vector<std::vector<double>> prev(rank);
		std::cout << std::endl <<  "Matrix Multiplication " << i << std::endl;
		matrixMultiplication(transition, rank);
		printMatrix(rank);
		for (size_t i = 0; i < rank.size(); ++i) {
			double difference = std::abs(prev.at(i).at(0) - rank.at(i).at(0));
			min = std::min(difference, min);
		}
	}

	// Ranking
	for (size_t i = 0; i < rank.size(); ++i) {
		rank.at(i).at(0) = rank.at(i).at(0) / dimension;
	}
	std::cout << std::endl << "Ranking of each page" << std::endl;
	for (size_t i = 0; i < rank.size(); ++i) {
		std::cout << (char)(65 + i) << " = " << rank.at(i).at(0) << std::endl;
	}

	system("pause");

	return 0;
	
}

void matrixMultiplication(const std::vector<std::vector<double>> &arr1, 
	std::vector<std::vector<double>> &arr2) {
	// Setup temp
	std::vector<std::vector<double>> temp;
	for (size_t i = 0; i < arr1.size(); ++i) {
		temp.push_back(std::vector<double>());
		temp.at(i).push_back(0);
	}

	// Matrix multiplication
	for (size_t y = 0; y < arr2.at(0).size(); ++y) {
		for (size_t x = 0; x < arr1.size(); ++x) {
			for (size_t z = 0; z < arr2.size(); ++z) {
				//std::cout << "temp" << x << y << " arr1" << x << z << " arr2" << z << y << std::endl;
				temp.at(x).at(y) += arr1.at(x).at(z) * arr2.at(z).at(y);
			}
		}
	}
	std::swap(arr2, temp);
}

void printMatrix(const std::vector<std::vector<double>> &arr) {
	for (size_t y = 0; y < arr.size(); ++y) {
		for (size_t x = 0; x < arr.at(0).size(); ++x) {
			std::cout << arr.at(y).at(x) << " ";
		}
		std::cout << std::endl;
	}
}