#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<iostream>
#include<string>
#include<ctype.h>
#include<cstring>
#include<iomanip>
#include<map>
#include<vector>
#include <algorithm>
using namespace std;
//Cau 2.a)
bool is_possible(int board[9][9], int row, int col, int val) {
	for (int i = 0; i < 9; i++) {
		if (board[i][col] == val) {
			return false;
		}
	}
	for (int i = 0; i < 9; i++) {
		if (board[row][i] == val) {
			return false;
		}
	}
	int starRow = 3 * (row / 3);
	int starCol = 3 * (col / 3);
	for (int i = starRow; i < starCol + 3; i++) {
		for (int j = starCol; j < starCol + 3; j++) {
			if (board[i][j] == val) {
				return false;
			}
		}
	}
	return true;
}
//Cau 2.b)
bool solve(int board[9][9], int row, int col) {
	if (col == 9) {
		if (row == 9 - 1) {
			return true;
		}
		else {
			col = 0;
			row++;
		}
	}
	if (board[row][col] != 0) {
		return solve(board, row, col + 1);
	}
	for (int x = 1; x <= 9; x++) {
		if (is_possible(board, row, col, x) == true) {
			x = board[row][col];
			if (solve(board, row, col + 1) == true) {
				return true;
			}
		}
		board[row][col] = 0;
	}
	return false;
}
