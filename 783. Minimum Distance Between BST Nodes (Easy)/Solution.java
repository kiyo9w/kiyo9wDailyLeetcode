class Solution {
    // track values
    Integer prev = null; // previous node
    int minVal = Integer.MAX_VALUE; // min difference

    // recursion, in-order traversal
    public int minDiffInBST(TreeNode root) {
        if(root == null) {
            return 0; // base case: empty tree, return 0
        }

        minDiffInBST(root.left); // traverse left subtree

        if(prev != null) {
            minVal = Math.min(minVal, root.val - prev); // update min diff if current diff smaller
        }
        prev = root.val; // update previous node

        minDiffInBST(root.right); // traverse right subtree

        return minVal;
    }
}
