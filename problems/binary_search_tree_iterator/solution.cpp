class BSTIterator {
public:
    list<int> a;
    
    void traversal(TreeNode *root) {
        if(!root) return;
        traversal(root->left);
        a.push_front(root->val);
        traversal(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        traversal(root);
    }
    
    int next() {
        int val = a.back(); a.pop_back();
        return val;
    }
    
    bool hasNext() {
        return !a.empty();
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
// class BSTIterator {
//     stack<TreeNode*> st;
//     void pushall(TreeNode* root){
//         for(;root!=NULL;st.push(root) , root=root->left);
//     }
    
// public:
//     BSTIterator(TreeNode* root) {
//        pushall(root);
//     }
    
//     int next() {
//         TreeNode* tp=st.top(); st.pop();
//         pushall(tp->right);
//         return tp->val;
        
        
// //         TreeNode *prev = path.top(); path.pop();
// //         // cout <<"Prev "<< (prev ? (prev->val) : 0) << endl;
// //         TreeNode *cur = path.top(); path.pop();
// //         // if(cur) cout <<"Next "<< (cur->val) << endl;
        
// //         if(prev and cur == prev->right) { // cur is right of prev
// //             path.push(prev);   
// //         }
// //         else{ // prev is left child of cur or have jumped up tree
// //             // cout << "Moving to parent" << endl;
// //             if(cur->right) { // has right node
// //                 // cout << "Has right, adding:" << endl;
// //                 prev = cur->right;
// //                 while(prev) {
// //                     // cout << prev->val << endl;
// //                     path.push(prev);
// //                     prev = prev->left;
// //                 } // next will be leftmost child of this right node
// //                 path.push(nullptr);
// //             }
// //             else path.push(cur); // no right node
// //         }
        
// //         return cur->val;
//     }
    
//     bool hasNext() {
//         return !st.empty();
//     }
// };

// /**
//  * Your BSTIterator object will be instantiated and called as such:
//  * BSTIterator* obj = new BSTIterator(root);
//  * int param_1 = obj->next();
//  * bool param_2 = obj->hasNext();
//  */