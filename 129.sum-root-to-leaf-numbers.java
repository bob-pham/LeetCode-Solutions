// @leet start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int sumNumbers(TreeNode root) {
        int result = 0;
        List<Integer> rootLeafNums = this.sumNumberHelper(root, 0);

        for (int i : rootLeafNums) {
            System.out.print(i);
            System.out.print(" ");
            result += i;
        }
            System.out.println();

        return result;
    }

    private List<Integer> sumNumberHelper(TreeNode currNode, int currVal) {
        if (currNode == null) {
            List<Integer> result = new ArrayList<>();
            result.add(currVal);
            return result;
        }

        if (currNode.left == null && currNode.right == null) {
            List<Integer> result = new ArrayList<>();
            result.add((10 * currVal) + currNode.val);
            return result;
        }

        if (currNode.left == null) {
            return this.sumNumberHelper(currNode.right, (currVal * 10) + currNode.val);
        }

        if (currNode.right == null) {
            return this.sumNumberHelper(currNode.left, (currVal * 10) + currNode.val);
        }

        List<Integer> left = this.sumNumberHelper(currNode.left, (currVal * 10) + currNode.val);
        List<Integer> right = this.sumNumberHelper(currNode.right, (currVal * 10) + currNode.val);

        left.addAll(right);
        return left;
    }
}
// @leet end
