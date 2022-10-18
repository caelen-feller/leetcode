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
    int ans;
public:
    int kthSmallest(TreeNode* root, int k) {
        findk(root, k);
        return ans;
    }
    
    void findk(TreeNode* root, int &k) {
        if(!root) return;
        
        findk(root->left, k);
        
        if (--k == 0) {
            ans = root->val;
            return;
        } 
        
        findk(root->right, k);
    }
};