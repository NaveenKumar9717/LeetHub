class Solution {
public:
    vector<int> sequentialDigits(int low, int high){
     vector<int> ans;  
     int low_len = 0;
     int high_len = 0;
     int temp = low;
     
     while(temp){
         low_len += 1;
         temp /= 10;
     }
        
     temp = high;
     while(temp){
         high_len += 1;
         temp /= 10;
     }
        
        
     for(int len = low_len; len<= high_len;len++){
         
         for(int start =1;start<=9;start++){
             int num = 0;
             int prod = 1;
             int i = 1;
             int f = start;
             while(i<=len && f<= 9){
                 num *= 10;
                 num += f;
                 f++;
                
                 i++;
             }
            // cout<<"num:-->"<<num<<endl;
             if(num >= low && num <= high && (i-1) == len){
                 ans.push_back(num);
             }
             if(num > high)
                 break;
             
         }
        
       
     } 
        
       return ans;   
    }
};