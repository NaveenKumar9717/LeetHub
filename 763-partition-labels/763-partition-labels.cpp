class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        unordered_map<char,pair<int,int>>mp;
       for(int i = 0 ; i < s.length();i++){
           if(mp.find(s[i]) == mp.end())   
               mp[s[i]].first = i;
           mp[s[i]].second = i; 
       }
        
       int i  = 0 ;
       int len = s.length();
       while(i < len){
           int curr_len = mp[s[i]].second - mp[s[i]].first + 1;
           for(int  j = i + 1; j < i+curr_len;j++){
               curr_len = max(curr_len, mp[s[j]].second - i + 1);
           }
          i += (curr_len);
          ans.push_back(curr_len); 
       }
        return ans;
    }
};