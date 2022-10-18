class Solution {
public:
    int ans=0;
    
    public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root){
            dfs(root,targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }
        return ans;
    }
    
    void dfs(TreeNode* root, long int sum){
        if(!root)return;
        if(root->val==sum)ans++;
        dfs(root->left,sum-root->val);
        dfs(root->right,sum-root->val);
    }
};

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
//     unordered_map<long,int> paths;
//     int count = 0;

//     void countPathSum(TreeNode* root, int targetSum, long sum) {
//         if(!root) return;
        
//         sum += root->val;
        
//         if(sum == targetSum) count++;
//         if(paths.find(sum - targetSum) != paths.end())
//             count += paths[sum - targetSum]; // number of possible paths that lead to this sum
//         paths[sum]++; // we are on this path which gives this sum
        
//         countPathSum(root->left, targetSum, sum);
//         countPathSum(root->right, targetSum, sum);
        
//         paths[sum]--; // Leaving this path
    
//     }
    
// public:
//     int pathSum(TreeNode* root, int targetSum) {
//         countPathSum(root, targetSum, 0);
//         return count;
//     }
// };