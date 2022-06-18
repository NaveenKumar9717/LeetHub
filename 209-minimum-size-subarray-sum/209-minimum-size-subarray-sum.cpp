class Solution {
public:
    void print(int x){
        cout<<"value : --> "<<x<<endl;
    }
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum  < target)
            return 0;
        
        //print(target);
        int start = 0;
        int ans = INT_MAX;
        int subarray_size =  -1;
        int curr_sum = 0;
        for(int j = 0 ; j < nums.size();j++){
            curr_sum += nums[j];
            //decreasing the sum  by moving the start to move forward;
            while(curr_sum >= target && start  <= j){
                ans = min(ans,j - start + 1);
                curr_sum -= nums[start];
                start++;
                
            }
            
        }
        
        return ans;
    }
};