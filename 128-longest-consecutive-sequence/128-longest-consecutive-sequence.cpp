class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool>mp;
        int n  = nums.size();
        for(int i = 0 ; i <n;i++){
            mp[nums[i]] = false;
        }
        int max_len = 0;
        for(int i = 0 ; i < n; i++){
           int element = nums[i];
            if(mp[element])
              continue;
        
            int len = 0;
            //move forward 
            for(int start = element; mp.find(start) != mp.end(); start++ ){
                len++;
                mp[start] = true;
            }
            
             //move backward 
            for(int start = element-1; mp.find(start) != mp.end(); start-- ){
                len++;
                mp[start] = true;
            }

             max_len = max(max_len,len);
            
        }
        
        return max_len;
        
    }
};