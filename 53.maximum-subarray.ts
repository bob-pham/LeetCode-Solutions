// @leet start
function maxSubArray(nums: number[]): number {
	let global_max: number = nums[0];
	let current_sum: number = global_max;

	for (let i: number = 1; i < nums.length; i++) {
		let curr_val = nums[i];
		if (current_sum < 0 && curr_val > current_sum) {
			current_sum = curr_val;
		} else {
			current_sum += curr_val; 
		}

		global_max = Math.max(global_max, current_sum);

	}

	return global_max;

};
// @leet end
