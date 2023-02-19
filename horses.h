#pragma once

#include <vector>

void solve(std::vector<std::vector<int>> b, int hX, int hY ,int row, int col, int moveNum,bool& solved);

void printBoard(std::vector<std::vector<int>> b);

bool isSolved(std::vector<std::vector<int>> b);