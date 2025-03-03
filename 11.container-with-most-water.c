// @leet start
int maxArea(int* height, int heightSize) {
	int left = 0;
	int right = heightSize - 1;
	int result = 0;

	while (left < right) {
		int val;
		int v_left = height[left];
		int v_right = height[right];

		if (v_left > v_right) {
			val = v_right;
		} else {
			val = v_left;
		}

		val *= right - left;

		if (val > result) {
			result = val;
		}

		if (v_left > v_right) {
			right--;
		} else {
			left++;
		}
	}

	return result;
}
