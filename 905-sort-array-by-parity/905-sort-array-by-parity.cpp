class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
         int n = nums.size();
       
        
         int even_index = 0;
         for(int i = 1;i<n;i++){
             if(nums[i]%2 == 0  && nums[even_index]%2 != 0){
                 swap(nums[i],nums[even_index]);
                
             }
             if(nums[even_index]%2 == 0)
                 even_index++;
         }
       return nums;    
    }
};