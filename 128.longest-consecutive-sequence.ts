// @leet start
function longestConsecutive(nums: number[]): number {
	let max_length: number = 0;
	let memo = {};

	for (let i = 0; i < nums.length; i++) {
		let val = nums[i];
		if (!(val in memo)) {
			memo[val] = 1;
		}
	}

	for (const key in memo) {
		let key_val = Number(key);
		if ((key_val - 1) in memo) {
			memo[key] += memo[key_val];
		}
	}

	for (const key in memo) {
		max_length = Math.max(memo[key], max_length);
	}

	return max_length;
    
};
// @leet end
