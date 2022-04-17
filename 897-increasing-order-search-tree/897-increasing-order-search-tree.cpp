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
    void inorder(TreeNode* root,vector<TreeNode*>& vec){
        if(!root)
            return;
        
        inorder(root->left,vec);
        vec.push_back(root);
        inorder(root->right,vec);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*>vec;
        inorder(root,vec);
        root = vec[0];
        TreeNode* last = root;
        root->left = NULL;
        for(int i = 1;i<vec.size();i++){
            last->right = vec[i];
            vec[i]->left = NULL;
            last = vec[i];
        }
        return root;
    }
};