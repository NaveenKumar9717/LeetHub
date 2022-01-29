class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>stk;
        int left_small[heights.size()];
        int right_small[heights.size()];
        int max_area = 0 ;
        for(int i = 0 ;i <heights.size();i++){
            if(stk.empty()){
                left_small[i] = 0;
                stk.push(i);
            }
            else{
               while(stk.empty() == false && heights[stk.top()] >= heights[i]){
                   stk.pop();
               }
               if(stk.empty()){
                   left_small[i] = 0;
                   stk.push(i);
                 }
                else{
                    left_small[i] = stk.top()+1;
                     stk.push(i);
                }
            }
        }
        
      while (!stk.empty())
       stk.pop();
    
      int n = heights.size() ;  
     for(int  i = n-1;i>=0;i--){
        if(stk.empty()){
                right_small[i] = n-1 ;
                stk.push(i);
                }
            else{
               while(stk.empty() == false && heights[stk.top()] >= heights[i]){
                   stk.pop();
               }
               if(stk.empty()){
                   right_small[i] = n-1;
                   stk.push(i);
                 }
                else{
                    right_small[i] = stk.top()-1;
                    stk.push(i);
                }
            }        
        }
       for(int i  = 0;i <n; i++){
           max_area = max(max_area,(right_small[i]-left_small[i] + 1)*heights[i]);
       }    
    return max_area;
    }
};