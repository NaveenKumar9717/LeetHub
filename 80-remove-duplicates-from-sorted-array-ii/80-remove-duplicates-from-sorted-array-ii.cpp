class Solution {
public:
    int removeDuplicates(vector<int>& nums){
        int last_index = 0;
        for(int i = 0;i <nums.size();i++){
            int j = i+1;
            int count = 1;
            while(j<nums.size() && nums[i] == nums[j]){
                j++;
                count++;    
            }
            if(count>=2 && (last_index+1) < nums.size()){  
              nums[last_index] = nums[i];
              nums[last_index+1] = nums[i];  
              last_index += 2;  
            }
            else{
              nums[last_index] = nums[i]; 
              last_index += 1;
            }
            i = j-1;
        }
     return last_index ;
    }
   
};