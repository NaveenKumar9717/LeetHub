class Solution {
public:
    void print(int x){
        cout<<"value : --> "<<x<<endl;
    }
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int target = sum - x;
        //print(target);
        int start = 0;
        int ans = -1;
        int subarray_size =  -1;
        int curr_sum = 0;
        for(int j = 0 ; j < nums.size();j++){
            curr_sum += nums[j];
            //decreasing the sum  by moving the start to move forward;
            while(curr_sum > target && start  <= j){
                curr_sum -= nums[start];
                start++;
            }
           //print(curr_sum);
            if(curr_sum == target)
              subarray_size = max(subarray_size,j - start + 1);
            
        }
        
        return subarray_size != -1 ? (nums.size() - subarray_size) : subarray_size;
    }
};