// @leet start
int binaryGap(int n) {
	int back = 0;
	int result = 0;

	while ((n & 1) == 0) {
		back++;
		n >>= 1;
	}

	for (int i = back; i < 30; i++) {
		if ((n & 1) == 1) {
			if (i - back > result) {
				result = i - back;
			}
			back = i;
		}
		n >>= 1;
	}
    
	return result;
}
// @leet end
