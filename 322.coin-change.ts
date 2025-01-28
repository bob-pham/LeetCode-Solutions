// @leet start
function coinChange(coins: number[], amount: number): number {
	let memo: number[] = [0];
	let l: number = coins.length;

	for (let i: number = 1; i <= amount; i++) {
		let curr_val = -1;
		for (let j: number = 0; j < l; j++) {
			let val: number = coins[j];

			if (i - val >= 0 && memo[i-val] != -1) {
				if (curr_val === -1) {
					curr_val = memo[i-val] + 1;
				} else {
					curr_val = Math.min(curr_val, memo[i-val] + 1);
				}
			}
		}
		memo.push(curr_val)
	}

	return memo[amount];
    
};
// @leet end
