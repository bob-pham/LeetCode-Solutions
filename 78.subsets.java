// @leet start
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        result.add(new ArrayList<>());

        for (int i = 0; i < nums.length; i++) {
            List<List<Integer>> temp = new ArrayList<>();
            temp.add(new ArrayList<>());
            result.addAll(this.subsetHelper(nums, i, temp));
        }

        return result;
    }

    private List<List<Integer>> subsetHelper(int[] nums, int idx, List<List<Integer>> argList) {
        List<List<Integer>> local = new ArrayList<>();
        List<List<Integer>> result;
        for (List<Integer> list : argList) {
            List<Integer> temp = new ArrayList<>(list);
            temp.add(nums[idx]);
            local.add(temp);
        }

        result = new ArrayList<>(local);

        for (int i = idx + 1; i < nums.length; i++) {
            List<List<Integer>> child = this.subsetHelper(nums, i, local);
            result.addAll(child);
        }
        return result;
    }
}
// @leet end
