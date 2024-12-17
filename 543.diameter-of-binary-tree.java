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
    public int diameterOfBinaryTree(TreeNode root) {
        int result[] = this.treeLength(root);
        return Math.max(result[0] - 1, result[1]);
    }

    private int[] treeLength(TreeNode node) {
        if (node == null) {
            int result[] = {0, 0};
            return result;
        }

        int left[] = this.treeLength(node.left);
        int right[] = this.treeLength(node.right);
        int lval = 1 + Math.max(left[0], right[0]);
        int rval = Math.max(left[0] + right[0], Math.max(left[1], right[1]));

        int result[] = {lval, rval};
        return result;
    }
}
// @leet end
