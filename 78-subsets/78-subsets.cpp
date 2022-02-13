class Solution {
public:
    void subsetsH(vector<int>& nums,int idx,vector<int>output,vector<vector<int>>&ans){
        if(idx == nums.size())
        { ans.push_back(output);
         return;
        }
        output.push_back(nums[idx]);
        subsetsH(nums,idx+1,output,ans);
        output.pop_back();
        subsetsH(nums,idx+1,output,ans);
        return ;
           
    }
    vector<vector<int>> subsets(vector<int>& nums) {
     vector<vector<int>>ans;
      vector<int>output;  
     subsetsH(nums,0,output,ans);
     return ans;
    }
};