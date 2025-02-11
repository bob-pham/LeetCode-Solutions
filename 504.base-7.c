// @leet start
char* convertToBase7(int num) {
	char * result;
	bool neg = num < 0;
	int size = 0;
	int idx;

	if (neg) {
		num *= -1;
	}
	int temp = num;

	do {
		temp /= 7;
		size++;
	} while (temp > 0);

	if (neg) {
		result = malloc((sizeof(char) * (size)) + 2);
		result[0] = '-';
		result[size+1] = '\0';
		idx = size;
	} else {
		result = malloc((sizeof(char) * (size)) + 1);
		result[size] = '\0';
		idx = size - 1;
	}

	temp = num;
	do {
		result[idx--] = '0' + (temp % 7);
		temp /= 7;
	} while (temp > 0);

	return result;
}
// @leet end
