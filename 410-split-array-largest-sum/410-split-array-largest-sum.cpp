class Solution {
public:
    bool IsPossible(vector<int>& nums, int max_sum,int m){
      int slots = 1;
      int curr_sum  = 0;
      for(int i = 0;i<nums.size();i++){
          if(curr_sum + nums[i] <= max_sum){
              curr_sum += nums[i];
          }
          else{
              curr_sum = nums[i];
              slots++;
          }
      }  
      
      return slots <= m;  
        
    }
    int splitArray(vector<int>& nums, int m) {
       int ans ;
       int low_sum = 0;
       int max_sum = 0;
       for(int i = 0; i< nums.size();i++){
           low_sum = max(nums[i],low_sum);
           max_sum += nums[i];
       }
        
       while(low_sum <= max_sum){
         int curr_sum = (max_sum+low_sum)/2;
           
         if(IsPossible(nums,curr_sum,m))
         {
            ans = curr_sum;
            max_sum = curr_sum - 1; 
         }
         else{
             low_sum = curr_sum + 1;
         }      
       } 
       return ans; 
    }
};