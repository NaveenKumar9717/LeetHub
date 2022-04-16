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
    void inorder(TreeNode* root){
        if(!root)
            return;
        
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
    int convertBSTH(TreeNode* root,int rtree_sum){
     if(!root)
      return 0;
    
    int right_sum  = convertBSTH(root->right,rtree_sum);
    int left_sum   = convertBSTH(root->left,rtree_sum+right_sum+root->val);
    
    int tot_sum = root->val + left_sum + right_sum;
    root->val = root->val + right_sum + rtree_sum;    
    return tot_sum;    
    }
    TreeNode* convertBST(TreeNode* root) {
        convertBSTH(root,0);
        //inorder(root);
        //cout<<endl;
        return root;
    }
};