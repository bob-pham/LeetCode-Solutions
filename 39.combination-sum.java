// @leet start
class Pair {
    public int sum;
    public List<Integer> arr;
    Pair(int start) {
        this.sum = start;
        this.arr = new ArrayList<>();
        this.arr.add(start);
    }

    Pair(Pair p) {
        this.sum = p.sum;
        this.arr = new ArrayList<>(p.arr);
    }
}


class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();

        for (int i = 0; i < candidates.length; i++) {
            for (int j = i; j < candidates.length; j++) {
                List<Pair> vals = new ArrayList<>();
                vals.add(new Pair(candidates[i]));
                result.addAll(this.combinationSumHelper(candidates, j, target, vals));
            }
        }

        return result;
    }

    private List<List<Integer>> combinationSumHelper(int[] candidates, int idx, int target, List<Pair> vals) {
        List<Pair> local = new ArrayList<>();
        List<List<Integer>> localResult = new ArrayList<>();
        int val = candidates[idx];

        for (Pair p : vals) {
            if (p.sum + val == target) {
                p.arr.add(val);
                localResult.add(p.arr);
                continue;
            }
            if (p.sum + val > target) {
                continue;
            }
            Pair temp = new Pair(p);
            p.sum += val;
            p.arr.add(val);
            local.add(temp);
        }

        for (int i = idx; i < candidates.length; i++) {
            localResult.addAll(this.combinationSumHelper(candidates, i, target, local));
        }

        return localResult;
    }
}
// @leet end
