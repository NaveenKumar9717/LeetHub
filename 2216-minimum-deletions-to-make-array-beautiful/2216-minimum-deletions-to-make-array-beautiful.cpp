class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int del_count = 0;
        
        for(int i = 0; i < nums.size()-1;i++){
          if((i+del_count)%2 == 0){
              if(nums[i] == nums[i+1])
                  del_count++;
          }  
            
        }
        
        del_count += (nums.size()-del_count)%2 == 1 ? 1 : 0;
        return del_count;
        
    }
};