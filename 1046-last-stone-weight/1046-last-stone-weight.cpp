class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      priority_queue<int>qu;
        
      for(int i = 0 ; i  < stones.size();i++)
          qu.push(stones[i]);
      
      while(qu.size()>=2){
          int x = qu.top();
          qu.pop();
          int y = qu.top();
          qu.pop();
          if(x != y){
              qu.push(x-y);
          }
      }
        
      int ans = qu.size() == 1 ? qu.top() : 0;
      return ans;  
    }
};