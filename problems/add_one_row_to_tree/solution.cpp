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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode * out = new TreeNode(val, root, nullptr);
            return out;
        }
        
        queue<TreeNode*> nodes;
        TreeNode * tmp;
        nodes.push(root);
        nodes.push(nullptr);
        
        for(int i = 1; i < depth-1; i++) {
            while(nodes.front() != nullptr)
            {
                tmp = nodes.front();
                if(tmp->left != nullptr) nodes.push(tmp->left);
                if(tmp->right != nullptr) nodes.push(tmp->right);
                nodes.pop();
            }
            nodes.pop(); nodes.push(nullptr);
        }
        
        while(nodes.front() != nullptr) {
            tmp = nodes.front();
            nodes.pop();
            tmp->left = new TreeNode(val, tmp->left, nullptr);
            tmp->right = new TreeNode(val, nullptr, tmp->right);
        } 
        
        return root;
    }
};