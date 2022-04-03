class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int i = n - 2;
        while(i>= 0 && nums[i] >= nums[i+1])
            i--;
        
        if(i == -1)
        {
            sort(nums.begin(),nums.end());
           return;
        }  
        
        sort(nums.begin() + (i+1), nums.end());
        
        int j = i + 1;
        while( nums[i] >= nums[j])
            j++;
        
        swap(nums[i],nums[j]);
        return;
        
    }
};