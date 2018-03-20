#pragma once
#include <vector>
#include <array>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

// Random Walk
const static double P = 0.85;
// Minimum difference
const static double D = 0.00001;
void printMatrix(const std::vector<std::vector<double>> &arr);
void matrixMultiplication(const std::vector<std::vector<double>> &arr1, std::vector<std::vector<double>> &arr2);