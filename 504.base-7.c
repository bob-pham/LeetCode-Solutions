// @leet start
char* convertToBase7(int num) {
	bool negative = num < 0;
	char * return_str;
	int temp;
	int idx = 0;


	if (negative) {
		temp = num * -1;
		while (temp > 0) {
			temp /= 7;
			idx++;
		}
		return_str = malloc(sizeof(char) * (idx + 2));
		temp = num * -1;
		return_str[0] = '-';
		idx = 1;
	} else {
		temp = num;
		while (temp > 0) {
			temp /= 7;
			idx++;
		}
		return_str = malloc(sizeof(char) * (idx + 1));
		temp = num;
		idx = 0;
	}

	while (temp > 0) {
		return_str[idx++] = (temp % 7) + '0';
		temp /= 7;
	}

	return_str[idx] = '\0';
	return return_str;
}
// @leet end
