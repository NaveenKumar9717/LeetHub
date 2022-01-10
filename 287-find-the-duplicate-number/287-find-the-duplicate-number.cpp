class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int x = 0  ;
    int duplicate  = -1 ;
    while (nums[abs(nums[x])] > 0) {
        nums[x] = -1 * nums[x]  ;
        x = abs(nums[x]) ;
    }
    return abs(nums[x]) ;  
    }
};