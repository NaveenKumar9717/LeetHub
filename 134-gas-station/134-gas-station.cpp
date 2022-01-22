class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      
        int size = gas.size();
        int start = -1 ;
        for(int i = 0 ; i < gas.size();i++){
          //  bool flag = false;
         
           if(gas[i] >= cost[i]){
                
                start = i;
                i = (i +1)%size;
                int temp_curr =  gas[start] - cost[start];
               while(i != start && temp_curr + gas[i] >= cost[i]){
                   temp_curr += (gas[i] - cost[i]); 
                   i = (i +1)%size;
                   cout<<"i:->"<<i<<endl;
                }
               if(i == (start)){
                   return i;
               }
               else if(i < start){
                   return -1;
               }
               
              i--;
           }
            
        }
        
        return -1;
    }
};