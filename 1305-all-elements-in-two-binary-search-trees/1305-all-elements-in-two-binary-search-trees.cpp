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
    void getAllElementsH(TreeNode* root,vector<int>&ans){
        if(!root)
         return ;
        getAllElementsH(root->left,ans);
        ans.push_back(root->val);
        getAllElementsH(root->right,ans); 
        
    }
//     void getAllElementsH(TreeNode* root1, TreeNode* root2,vector<int>&ans){
//         if(root1 == NULL && root2 == NULL){
//             return ;
//         }
//         if(root1 == NULL || root2 == NLL){
            
//         }
//         if(root1->val <= root2->val){
            
//         }
//         else{
            
//         }
        
        
//     }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>arr1;
        vector<int>arr2;
         getAllElementsH(root1,arr1);
         getAllElementsH(root2,arr2);
         // sort(ans.begin(),ans.end());    
          // getAllElementsH(root1,root2,ans);
        vector<int>ans;
        int i = 0;
        int j = 0;
        while(i < arr1.size() && j< arr2.size()){
            if(arr1[i] == arr2[j]){
                ans.push_back(arr1[i]);
                ans.push_back(arr2[j]);
                i++;
                j++;   
            }
            else if(arr1[i] < arr2[j]){
                ans.push_back(arr1[i]) ;
                i++;
            }
            else{
                ans.push_back(arr2[j]) ;
                j++;  
            }
        }
        
      while(i < arr1.size()){
          ans.push_back(arr1[i]);
           i++;
      }
       while(j < arr2.size()){
          ans.push_back(arr2[j]);
          j++;
          }  
     return ans;
    }
    
};