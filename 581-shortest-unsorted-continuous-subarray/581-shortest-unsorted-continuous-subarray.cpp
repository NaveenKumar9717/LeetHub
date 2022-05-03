class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
     // thanks @midnightsimon, although I was close to this using min and max but was not able to thin from let and thna right
        int n = nums.size();
        int Left_Uns = 0;
        int Right_Uns = 0;
        int ans = n;
        
        int i = 0 ;
        while(i < n-1 && nums[i] <= nums[i+1])
            i++;
        if(i < n-1)
        Left_Uns = i;
        
        i = n-1;
        while(i-1 >= 0 && nums[i] >= nums[i-1])
            i--;
        if(i>=1)    
        Right_Uns = i;
        
        ans = Right_Uns - Left_Uns + 1 ;
        if(ans == 1)
            return 0;
        
        int min_ele = INT_MAX;
        int max_ele = INT_MIN;
        for( i = Left_Uns; i<= Right_Uns;i++){
            min_ele = min(nums[i],min_ele);
            max_ele = max(nums[i],max_ele);
        }
        
        
        i  = Left_Uns-1;
        while(i >= 0 && nums[i] > min_ele){
            ans++;
            i--;
        }
        
        i = Right_Uns + 1;
         while(i < n && nums[i] < max_ele){
            ans++;
            i++;
        }
        
        
        return ans;
        
   
    }
};