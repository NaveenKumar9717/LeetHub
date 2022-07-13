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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*>qu;
        vector<vector<int>>ans;  
        if(!root)
        return ans;
        qu.push(root);
        while(qu.empty() == false){
            vector<int>level;
            int size = qu.size();
            while(size--){
                TreeNode* curr = qu.front();
                qu.pop();
                level.push_back(curr->val);
                if(curr->left)
                qu.push(curr->left);
                
                if(curr->right)
                qu.push(curr->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};