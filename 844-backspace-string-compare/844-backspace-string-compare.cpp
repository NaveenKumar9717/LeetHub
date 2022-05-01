class Solution {
public:
    bool backspaceCompare(string s, string t) {
        //string new_s = "";
        vector<char>vec_s;
        vector<char>vec_t;
       // bool flag = true;
        for(int i = 0;i < s.length();i++){
           if(s[i] == '#' && vec_s.size() > 0)
             vec_s.pop_back();
           else if(s[i] != '#')
             vec_s.push_back(s[i]);   
        } 
    
         for(int i = 0;i < t.length();i++){
           if(t[i] == '#' && vec_t.size() > 0)
             vec_t.pop_back();
           else if(t[i] != '#')
             vec_t.push_back(t[i]);   
        } 
        
        return vec_s == vec_t;
    }
};