// simple recursion
class Solution {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        // if the tree is empty, create a new node
        if(root == null) {
            root = new TreeNode(val);
            root.left = null;
            root.right = null;
        }
        // if the value to insert is less than the current node's value, go left
        else if (val < root.val) {
            root.left = insertIntoBST(root.left, val); // recurse on the left subtree
        }
        // otherwise, go right
        else {
            root.right = insertIntoBST(root.right, val); // recurse on the right subtree
        }
        return root;
    }
}
