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
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0 ;
        queue<TreeNode*>qu;
        qu.push(root);
        while(qu.empty() == false){
            int size = qu.size();
            int curr_sum = 0;
            while(size){
              TreeNode* curr = qu.front();
              qu.pop();
              curr_sum += curr->val;
              if(curr->left)  
              qu.push(curr->left);  
              
              if(curr->right)
              qu.push(curr->right);    
              size--;    
            }
          ans = curr_sum;  
        }
        return ans; 
    }
};