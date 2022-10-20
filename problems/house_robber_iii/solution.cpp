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
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        
        // It's houserobber1 for each path, combined (either they all use root or none do)
        int l, r;
        return dfs(root, l, r);
    }
    
    int dfs(TreeNode* root, int &l, int &r) { // Find max including this node
        if(!root) return 0;

        int ll = 0, lr = 0, rl = 0, rr = 0; // create a tree of values in call stack
        l = dfs(root->left, ll, lr);
        r = dfs(root->right, rl, rr);
        
        return max(root->val + ll + lr + rl + rr, l + r); // either include or skip root node
    }
};