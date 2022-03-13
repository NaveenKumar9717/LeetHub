class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0){
         return  n >= 1 ? nums[0] : -1;    
        }
        else if(k == 1){
         return n == 1 ? -1 : nums[1];   
        }
        else if(n == 1){
         return   k % 2 == 0 ? nums[0] : -1; 
        }
        int ans=  -1;
        for(int i = 0; i < min(n,k-1);i++)
            ans = max(nums[i],ans);
        
        if(k < n)
          ans = max(ans,nums[k]);
        return ans;
    }
};