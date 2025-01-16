// @leet start
function lengthOfLongestSubstring(s: string): number {
	if (s.length <= 1) {
		return s.length;
	}
	let result = 0;
	let dict = {};
	let back_ptr = 0;

	dict[s[0]] = 1;

	for (let front_ptr = 1; front_ptr < s.length; front_ptr++) {
		while (dict[s[front_ptr]] == 1) {
			dict[s[back_ptr++]] = 0;
		}

		dict[s[front_ptr]] = 1;

		result = Math.max(result, front_ptr - back_ptr + 1);
	}

	return result;
    
};
// @leet end
