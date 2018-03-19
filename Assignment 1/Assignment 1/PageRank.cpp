#include "PageRank.h"

int main() {
	/*
	std::ifstream input_file("test.txt");
	std::vector<int> list;
	int temp = 0, size = 0;
	while (input_file >> temp) {
		list.push_back(temp);
		++size;
	}
	int dimension = size / 4;
	*/

	int input[16] = { 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0 };
	//int input[4][4] = { {0, 1, 1, 0}, {1, 0, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0} };
	int dimension = 4;

	std::vector<std::vector<double>> matrix;
	for (int y = 0; y < dimension; ++y) {
		matrix.push_back(std::vector<double>());
		for (int x = 0; x < dimension; ++x) {
			if (input[y * dimension + x] == 1) {
				matrix.at(y).push_back(input[y * dimension + x]);
			} else {
				matrix.at(y).push_back(input[y * dimension + x]);
			}
		}
	}

	

	system("pause");

	return 0;
	
}