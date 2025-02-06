// @leet start
int hammingWeight(int n) {
	int result = 0;
	for (int i = 0; i < (sizeof(int) * 8); i++) {
		if (n & 1 == 1) {
			result++;
		}
		n >>= 1;
	}
	return result;
    
}
// @leet end
