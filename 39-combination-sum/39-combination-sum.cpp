class Solution {
public:
void combinationSumH(vector<int>& candidates, int target, int index,vector<vector<int>>&ans,vector<int>& v){
      if(index == candidates.size()){
          return ;
      }
      if(target == 0){
          ans.push_back(v);
          return ;
      }  
      if(target - candidates[index] >= 0) {
          v.push_back(candidates[index]);
      combinationSumH(candidates,target -candidates[index],index,ans,v);
          v.pop_back();
combinationSumH(candidates,target,index+1,ans,v);
          }
       else{
           combinationSumH(candidates,target,index+1,ans,v);
       } 
    }
    void combination(vector<int>& candidates, int target, vector<int> currComb, int currSum, int currIndex, vector<vector<int>>& ans){
        if(currSum>target) return; //backtrack
        if(currSum==target){
            ans.push_back(currComb); //store the solution and backtrack
            return;
        }
        
        for(int i=currIndex; i<candidates.size(); i++){ //try all possible options for the next level
            currComb.push_back(candidates[i]); //put 1 option into the combination
            currSum+=candidates[i];
            combination(candidates, target, currComb, currSum, i, ans); //try with this combination, whether it gives a solution or not.
            currComb.pop_back(); //when this option backtrack to here, remove this and go on to the next option.
            currSum-=candidates[i];
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//      vector<vector<int>>ans;
//         // vector<int>v;
//         //  combinationSumH(candidates,target,0,ans,v);
//          // return ans;
//          vector<int> dp[candidates.size()+1][target+1];
//          for(int i = 0 ;i <=target;i++){
//              vector<int>v;
//              dp[0][i] = v;
//              dp[i][0]  = v;
//          }
//         int  n = candidates.size();
//          for(int i = 1; i <=n;i++){
//           for(int j = 1;j<=target;j++){
//              if(j - candidates[i-1] >= 0){
                 
//              }
//              else{
//                  dp[i][j] = dp[i-1][j];
//              } 
//           }   
//          }
          
           
          
        
//          //memset(dp,-1,sizeof(dp));
//          return ans;
         vector<vector<int>> ans;
        vector<int> currComb;
        combination(candidates, target, currComb, 0, 0, ans);
        return ans;
    }
};