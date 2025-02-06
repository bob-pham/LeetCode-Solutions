// @leet start

const char GREEN = 1;
const char RED = 2;
const char YELLOW = 3;

void dfs(char ** grid, int * result, int n, int start_y, int start_x) {
	for (int y = start_y; y < n; y++) {
		for (int x = start_x; x < 3; x++) {
			if (grid[y][x] != 0) {
				continue;
			}
			int can_green = 1;
			int can_red = 1;
			int can_yellow = 1;

			if (x - 1 >= 0) {
				can_green &= grid[y][x-1] != GREEN;
				can_red &= grid[y][x-1] != RED;
				can_yellow &= grid[y][x-1] != YELLOW;
			}

			if (x + 1 < 3) {
				can_green &= grid[y][x+1] != GREEN;
				can_red &= grid[y][x+1] != RED;
				can_yellow &= grid[y][x+1] != YELLOW;
			}

			if (y - 1 >= 0) {
				can_green &= grid[y-1][x] != GREEN;
				can_red &= grid[y-1][x] != RED;
				can_yellow &= grid[y-1][x] != YELLOW;
			}

			if (y + 1 < n) {
				can_green &= grid[y+1][x] != GREEN;
				can_red &= grid[y+1][x] != RED;
				can_yellow &= grid[y+1][x] != YELLOW;
			}

			if (can_red) {
				grid[y][x] = RED;
				dfs(grid, result, n, y, x);
				grid[y][x] = 0;
				if ((y == n - 1) && (x == 2)) {
					*result = (*result + 1) % 0x3b9aca07;
				}
			}

			if (can_yellow) {
				grid[y][x] = YELLOW;
				dfs(grid, result, n, y, x);
				grid[y][x] = 0;
				if ((y == n - 1) && (x == 2)) {
					*result = (*result + 1) % 0x3b9aca07;
				}
			}

			if (can_green) {
				grid[y][x] = GREEN;
				dfs(grid, result, n, y, x);
				grid[y][x] = 0;
				if ((y == n - 1) && (x == 2)) {
					*result = (*result + 1) % 0x3b9aca07;
				}
			}


			return;
		}
	}
}

int numOfWays(int n) {
	int result = 0;
	char ** grid = malloc(sizeof(char * ) * n);

	for (int i = 0; i < n; i++) {
		grid[i] = malloc(sizeof(char) * 3);
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < 3; x++) {
			grid[y][x] = 0;
		}
	}

	dfs(grid, &result, n, 0, 0);

	for (int i = 0; i < n; i++) {
		free(grid[i]);
	}
	free(grid);

	return result;
    
}
// @leet end
