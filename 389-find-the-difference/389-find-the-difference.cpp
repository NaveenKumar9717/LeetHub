class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<int,int>mp;
        for(int i = 0;i <s.length();i++){
            mp[s[i]]++;
        }
         unordered_map<int,int>mp1;
         for(int i = 0;i <t.length();i++){
            mp1[t[i]]++;
         }
         
         for(int i = 0;i <t.length();i++){
           if(mp.find(t[i]) != mp.end() && mp[t[i]] == mp1[t[i]]){
              continue;
           }
           else{
               return t[i];
              }  
         }
        return 'a';
    }
};