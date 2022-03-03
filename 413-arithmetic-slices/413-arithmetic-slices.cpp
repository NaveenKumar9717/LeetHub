class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums){
       if(nums.size() < 3)
           return 0;
        int count = 0;
        int last_diff = nums[1]-nums[0];
        int curr_count = 0;
        
        for(int i = 1 ; i <nums.size()-1;i++){
          int curr_diff = nums[i+1] - nums[i];
          if(curr_diff == last_diff){
              curr_count += 1;
          }
          else{
              last_diff = curr_diff ;
              curr_count = 0;
          } 
          count += curr_count ;  
        }
        return count;
    }
}; 