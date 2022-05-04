class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        //return 5;
       unordered_map<int,int>mp;
       int n = nums.size();
       
       for(int i = 0; i< n; i++)
           mp[nums[i]]++;
        
       int count = 0;
       for(int  i = 0; i < n ;i++){
           if(mp.find(k-nums[i]) != mp.end()){
               if(nums[i]*2 == k){
                   count += mp[nums[i]]/2;
               }
               else{
                   count +=  min(mp[nums[i]],mp[k-nums[i]]);    
               }
              mp[nums[i]] = 0; 
           }
       } 
        
     return count;
    }
};