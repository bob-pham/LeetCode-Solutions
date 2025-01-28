// @leet start
function productExceptSelf(nums: number[]): number[] {
	let forward: number[] = [];
	let backward: number[] = [];
	let result: number[] = [];
	let l: number = nums.length;

	for (let i = 0; i < l; i++) {
		forward.push(0);
		backward.push(0);
	}

	let curr_product = 1;
	for (let i = 0; i < l; i++) {
		forward[i] = curr_product;
		curr_product *= nums[i];
	}

	curr_product = 1;
	for (let i = l - 1; i >= 0; i--) {
		backward[i] = curr_product;
		curr_product *= nums[i];
	}

	for (let i = 0; i < l; i++) {
		result.push(forward[i] * backward[i]);
	}


	return result;
    
};
// @leet end
