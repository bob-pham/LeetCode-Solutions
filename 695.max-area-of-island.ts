// @leet start
function maxAreaOfIsland(grid: number[][]): number {
	let result = 0;
	let m = grid.length;
	let n = grid[0].length;

	const dfs = (x: number, y: number, size: number): number => {
		if (grid[y][x] == 0) {
			return size;
		}

		grid[y][x] = 0;
		size++;

		if (y + 1 < m) {
			size = dfs(x, y + 1, size);
		}

		if (y - 1 >= 0) {
			size = dfs(x, y - 1, size);
		}

		if (x + 1 < n) {
			size = dfs(x + 1, y, size);
		}

		if (x - 1 >= 0) {
			size = dfs(x - 1, y, size);
		}

		return size;
	}

	for (let y = 0; y < m; y++) {
		for (let x = 0; x < n; x++) {
			if (grid[y][x] == 1) {
				result = Math.max(result, dfs(x, y, 0));
			}
		}
	}

	return result;
    
};
// @leet end
