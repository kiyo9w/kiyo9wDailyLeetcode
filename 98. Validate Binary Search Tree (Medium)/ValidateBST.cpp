class Solution {
public:
    // using in-order traversal to ensure the BST properties by checking the order of node values
    // SIDE NOTE: iterative approaches can sometimes help preventing stack overflow issues
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true; // empty tree is valid

        stack<TreeNode*> s; // stack to manage the traversal
        TreeNode *pre = NULL; // pointer to keep track of the previous node

        // iterate until there are nodes to process
        while(root != NULL || !s.empty()){
            // reach the leftmost node of the current subtree
            while(root != NULL){
                s.push(root); // push current node to stack
                root = root->left; // move to left child
            }

            root = s.top(); // node to process
            s.pop(); // remove it from the stack

            // if the current node's value is not greater than the previous, it's not a BST
            if(pre != NULL && root->val <= pre->val){
                return false;
            }
            pre = root; // update the previous node

            root = root->right; // move to the right subtree
        }
        return true; // all nodes satisfy the BST properties
    }
};
