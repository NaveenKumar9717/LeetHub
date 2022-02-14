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
    // int maxDepthH(TreeNode* root, int depth,int& Max){
    //     if(!root->left && !root->right)
    //         return 1;
    // }
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        if(!root->left && !root->right)
            return 1;
                
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right) ;
        return max(left_depth,right_depth)+1;    
    }
};