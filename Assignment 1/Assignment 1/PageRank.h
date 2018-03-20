#pragma once
#include <vector>
#include <array>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

const static double P = 0.85;
void printMatrix(const std::vector<std::vector<double>> &arr);
void matrixMultiplication(const std::vector<std::vector<double>> &arr1, std::vector<std::vector<double>> &arr2);