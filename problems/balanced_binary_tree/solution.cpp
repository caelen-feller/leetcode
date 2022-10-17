/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int height(TreeNode* root) { 
        if(!root) return 0;
       
        // Height of left subtree...
		int leftHeight = height(root->left);
        // Height of height subtree...
		int rightHight = height(root->right);
        
        // In case of left subtree or right subtree unbalanced, return -1...
		if (leftHeight == -1 || rightHight == -1)  return -1;
        // If their heights differ by more than ‘1’, return -1...
        if (abs(leftHeight - rightHight) > 1)  return -1;
        
        // Otherwise, return the height of this subtree as max(leftHeight, rightHight) + 1...
		return max(leftHeight, rightHight) + 1;
    }
    
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(height(root) == -1) return false;
        return true;
    }
};