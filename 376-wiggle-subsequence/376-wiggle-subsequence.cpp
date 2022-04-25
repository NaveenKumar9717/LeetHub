class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        //return 1;
        int len = nums.size();
      if(len <= 1)
       return len;
      int up[len];
      int down[len];
      for(int  i = 0; i < len;i++)
      {
          up[i] = 0;
          down[i] = 0;
      }
      for(int i = 1; i < len;i++){
          for(int j = 0;j < i;j++){
              if(nums[j] < nums[i]){
                  up[i] = max(up[i],down[j] + 1);
              }
              else if(nums[j] > nums[i]){
                  down[i] = max(down[i],up[j]+1);
              }
          } 
      }  
        
      return 1 + max(up[len-1],down[len-1]);  
        
    }
};