class Solution {
public:
    std::string minRemoveToMakeValid(string s) {
        
        std::stack<pair<char,int>>stk;
        std::string ans ;
        int n = s.length();
        for(int i = 0 ; i < n;i++){
            if(s[i] == '('){
                stk.push(make_pair('(',i));
            }
            else if(s[i] == ')'){
                if( stk.empty() == false && stk.top().first == '(' ){
                    stk.pop();
                }
                else if(stk.empty()){
                   s[i] = 'N';                    
                }
            }
        }
        
        while(stk.empty() == false){
            s[stk.top().second] = 'N';
            stk.pop();
        }
            
        for(int i = 0 ; i  <n ; i++){
            if(s[i] != 'N')
                ans += s[i];
        }
        return ans;
    }
};
