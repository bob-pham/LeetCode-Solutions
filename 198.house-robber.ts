// @leet start
function rob(nums: number[]): number {
	let l = nums.length;
	if (nums.length < 2) {
		return nums[0];
	}

	let mem = [nums[0], nums[1]];

	if (2 < l) {
		mem.push(nums[0] + nums[2]);
	}

	for (let i = 3; i < l; i++) {
		mem.push(Math.max(mem[i - 2], mem[i - 3]) + nums[i]);
	}

	return Math.max(mem[l-1], mem[l-2]);
    
};
// @leet end
