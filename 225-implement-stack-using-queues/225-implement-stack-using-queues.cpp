queue<int>qu1;
queue<int>qu2;
int tp = -1;  
class MyStack {
public:
     
    MyStack() {
      // qu1.clear();
       while(qu1.empty() == false)
           qu1.pop();
        
        while(qu2.empty() == false)
           qu2.pop();
        
      // qu2.clear();
      tp = -1; 
    }
    
    void push(int x) {
        qu1.push(x);
        tp++;
    }
    
    int pop() {
        int top_ele = -1;
        int top = -1;
        while(qu1.empty() == false){  
          top = qu1.front();
          qu2.push(top);  
          qu1.pop();  
        }
        
        while(qu2.empty() == false){
          if(qu2.size() == 1){
          top_ele = qu2.front();
           qu2.pop();   
           continue ; 
          }   
          top = qu2.front();
          qu1.push(top);  
          qu2.pop();  
        }
        tp--;
        return top_ele;
        
    }
    
    int top() {
        int top = -1;
        while(qu1.empty() == false){
          top = qu1.front();
          qu2.push(top);  
          qu1.pop();  
        }
        
        while(qu2.empty() == false){
          top = qu2.front();
          qu1.push(top);  
          qu2.pop();  
        }
        return top;
    }
    
    bool empty() {
        return (tp+1) == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */