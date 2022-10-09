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
    public boolean findTarget(TreeNode root, int k) {
        return findTargetHelper(root, k, new HashSet<Integer>());
    }
    
    private boolean findTargetHelper(TreeNode curr, int k, HashSet<Integer> found) {
        if (curr == null) {
            return false;
        }
        
        if (found.contains(k - curr.val)) {
            return true;
        }
        
        found.add(curr.val);
        
        return findTargetHelper(curr.left, k, found) || findTargetHelper(curr.right, k, found);
    }
}