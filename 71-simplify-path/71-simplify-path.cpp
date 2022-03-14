class Solution {
public:
    string simplifyPath(string path) {
        string ans ;
        stack<string>stk;
        int n = path.length();
        for(int i  = 0; i < n;++i){
            if(path[i] == '/')
                continue;
            
            string temp ;
            while(i < n && path[i] != '/'){
                temp += path[i];
                i++;
            }
            
            if(temp == "."){
              continue;
            }
            else if(temp == ".."){
                if(!stk.empty())
                    stk.pop();
            }
            else{
              stk.push(temp);     
            }
        }
        
        while(stk.empty() == false){
            ans = "/" + stk.top() + ans;
            stk.pop();
        }
        
        if(ans.length() == 0)
            return "/";
        
        return ans;
    }
};