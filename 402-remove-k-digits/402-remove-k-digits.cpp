class Solution {
public:
    string removeKdigits(string num, int k) {
       if(num.length() < k)
           return "0";
        if(k == 0)
            return num;
        
        string ans = "";
        stack<char>stk;
        stk.push(num[0]);
        for(int i = 1;i < num.length();i++){
          while(k > 0 && stk.empty() == false && stk.top() > num[i]){
              stk.pop();
              k--;
          }    
        stk.push(num[i]);
            
         if(stk.size() == 1 && num[i] == '0')
                stk.pop();
            
        }
        
    while(k && stk.empty() == false){
        stk.pop();
        k--;
    }
   while(stk.empty() == false)
        {
            ans += (stk.top());
            stk.pop(); 
        }
        
        reverse(ans.begin(),ans.end());  
        
        if(ans.length() == 0)
            return "0";
        
        return ans;
         
    }
};