// @leet start

bool is_valid(char** board, int boardSize, int col, int row) {
	bool map[9] = {false};

	for (int x = 0; x < boardSize; x++) {
		char val = board[row][x];
		if (val == '.') {
			continue;
		}

		if (map[val - '1']) {
			return false;
		}

		map[val - '1'] = true;
	}

	for (int i = 0; i < 9; i++) {
		map[i] = false;
	}

	for (int y = 0; y < boardSize; y++) {
		char val = board[y][col];
		if (val == '.') {
			continue;
		}

		if (map[val - '1']) {
			return false;
		}

		map[val - '1'] = true;
	}
		
	for (int i = 0; i < 9; i++) {
		map[i] = false;
	}

	int tlx = col - (col % 3);
	int tly = row - (row % 3);

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			char val = board[y + tly][x + tlx];
			if (val == '.') {
				continue;
			}
			if (map[val - '1']) {
				return false;
			}

			map[val - '1'] = true;
		}
	}

	return true;
}

bool solve(char ** board, int boardSize, int y_start) {
	for (int y = y_start; y < boardSize; y++) {
		for (int x = 0; x < boardSize; x++) {
			if (board[y][x] != '.') {
				continue;
			}

			for (char c = '1'; c <= '9'; c++) {
				board[y][x] = c;
				if (is_valid(board, boardSize, x, y) && solve(board, boardSize, y)) {
					return true;
				}
				board[y][x] = '.';
			}
			return false;
		}
	}
	return true;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
	solve(board, boardSize, 0);
}
// @leet end
