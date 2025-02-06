// @leet start
int firstDayBeenInAllRooms(int* nextVisit, int nextVisitSize) {
	int * memo = malloc(sizeof(int) * nextVisitSize);
	int days = 0;
	int visited = 0;
	int idx = 0;

	for (int i = 0; i < nextVisitSize; i++) {
		memo[i] = 0;
	}

	while (visited < nextVisitSize) {
		int next_day = nextVisit[idx];
		if (memo[idx] == 0) {
			visited++;
		}
		memo[idx]++;
		if (memo[idx] % 2 == 1) {
			bool found = false;
			int i = next_day;

			while (i >= 0 && memo[i] != 0) {
				i--;
			}

			if (i >= 0) {
				next_day = i;
			} else {
				i = next_day;
				int min = memo[next_day];
				int min_idx = i;

				while (i >= 0) {
					if (memo[i] < min) {
						min = memo[i];
						min_idx = i;
					}
					i--;
				}
				next_day = min_idx;
			}
		} else {
			next_day = (idx + 1) % nextVisitSize;
		}
		idx = next_day;
		days++;
		days %= 0x3b9aca07;
	}
	return days - 1;
}
// @leet end
