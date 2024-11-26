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

// Erm, Classic (insert those twitch emotes)
class Solution {
    public TreeNode invertTree(TreeNode root) {
        if (root != null) {
            TreeNode inverted_left = invertTree(root.left);
            TreeNode inverted_right = invertTree(root.right);
            root.left = inverted_right;
            root.right = inverted_left;
        }

        return root;
    }
}