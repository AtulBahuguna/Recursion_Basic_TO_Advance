#include<bits/stdc++.h>

/*
User: Atul Bahuguna
problem link: https://leetcode.com/problems/sudoku-solver/description/

*/
using namespace std;
bool safe(int row, int col, vector<vector<char>>&board, char ch) {

	for (int i = 0; i < 9; i++) {
		//check row
		if (board[i][col] == ch) {
			return false;
		}
		//check col
		if (board[row][i] == ch) {
			return false;
		}
		//check inside cell
		if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch) {
			return false;
		}
	}
	return true;
}
bool solve(vector<vector<char>>&board) {

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {

			if (board[i][j] == '.') {
				for (char c = '1'; c <= '9'; c++) {
					if (safe(i, j, board, c)) {
						board[i][j] = c;
						if (solve(board)) {
							return true;
						} else {
							board[i][j] = '.';
						}
					}
				}
				return false;
			}
		}
	}
	return true;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

	vector<vector<char>>board(9, vector<char>(9));
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
		}
	}
	//Backtracking function
	solve(board);


	//printing the board
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

//for input use this test case 
/*

53..7....
6..195...
.98....6.
8...6...3
4..8.3..1
7...2...6
.6....28.
...419..5
....8..79


*/
