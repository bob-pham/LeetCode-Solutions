// @leet start
int minimizeXor(int num1, int num2) {
	int bit_count = 0;
	int result = 0;

	for (int i = 0; i < sizeof(int) * 8; i++) {
		if ((num2 & 1) == 1) {
			bit_count++;
		}
		num2 >>= 1;
	}


	for (int i = (sizeof(int) * 8) - 1; i > 0; i--) {
		if (((num1 >> i) & 1 )== 1 && bit_count > 0) {
			result++;
			bit_count--;
		}
		result <<= 1;
	}

	for (int i = 0; i < sizeof(int) * 8 && bit_count > 0; i++) {
		if (((result >> i) & 1) == 0) {
			result += 1 << i;
			bit_count--;
		}
	}
    
	return result;
}
// @leet end
