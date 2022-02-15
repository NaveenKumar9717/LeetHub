class Solution {
public:
    int lengthOfLongestSubstring(string s) {
//         if(s.length() ==0)
//             return  0;
//         unordered_map<char,int>mp;
//         int i = 0;
//         int max_len = 1;
//         int j =  0; 
//    while(j < s.length()){
       
//       while(j < s.length() &&  mp.find(s[j]) == mp.end()){ 
//           max_len = max(max_len,j-i+1);  
//           mp[s[j]] = j;
//           j++;
//           }
//           if(j < s.length()){ 
//             i = mp[s[j]]+1; 
//             mp[s[j]] = j;
//             j++;
            
//           }
//           else{
//            return max_len;}  
//         }
//         return max_len;
         vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};