#include <iostream>
#include <vector>

class Solution {
	public:
		bool isValidSudoku(std::vector<std::vector<char>>& board) {
			int row[9][9] = {0}; // row[i][j] = 1 means row i has number j
			int col[9][9] = {0}; // col[i][j] = 1 means col i has number j
			int box[9][9] = {0}; // box[i][j] = 1 means box i has number j
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (board[i][j] == '.') continue;
					int num = board[i][j] - '1'; // 0-8
					int k = i / 3 * 3 + j / 3; // box index
					if (row[i][num] || col[j][num] || box[k][num]) return false;
					row[i][num] =col[j][num] = box[k][num] = 1; // mark
				}
			}
			return true;
		}
};

int main()
{
	std::vector<std::vector<char>> board1 = {
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};

	std::vector<std::vector<char>> board2 = {
		{'8','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};

	Solution s;
	std::cout << s.isValidSudoku(board1) << std::endl;
	std::cout << s.isValidSudoku(board2) << std::endl;
	return 0;
}

