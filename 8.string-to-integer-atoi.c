// @leet start
#include <stdint.h>
int myAtoi(char* s) {
	uint64_t result = 0;
	size_t len = strlen(s);
	bool negative = s[0] == '-';

	for (size_t i = negative ? 1 : 0; i < len; i++) {
		if (s[i] == ' ') {
			continue;
		}
		result *= 10;
		result += s[i] - '0';
	}

	return (int) result;
    
}
// @leet end
