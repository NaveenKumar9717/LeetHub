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
class BSTIterator {
public:
    unordered_map<int,TreeNode*>mp;
    int curr_pos = 0;
    int ptr_idx =  1;
    void inorder(TreeNode* root){
        if(!root)
          return;
        
       inorder(root->left);
       curr_pos++;
       mp[curr_pos] = root;
       inorder(root->right); 
    }
    
    BSTIterator(TreeNode* root) {
    inorder(root);   
    }
    
    int next() {
        if(!mp[ptr_idx]){
            cout<<"NULL FOUND AT->"<<ptr_idx<<endl;
            return -1;
        }
        ptr_idx++;
        return mp[ptr_idx-1]->val;
      
    }
    
    bool hasNext() {
        if(ptr_idx  <= mp.size())
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */