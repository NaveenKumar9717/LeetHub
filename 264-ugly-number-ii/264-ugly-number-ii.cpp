class Solution {
public:
    int nthUglyNumber(int n) {
      if(n<=1)
       return n;
        
     vector<int>ugly(n);
     int two_count = 0;
     int three_count = 0;
     int five_count = 0;
     ugly[0] = 1;
     for(int i = 1;i <n;i++){
         ugly[i] = min(ugly[two_count]*2,min(ugly[three_count]*3,ugly[five_count]*5));
         if(ugly[i] == 2*ugly[two_count])
             two_count++;
         if(ugly[i] == 3*ugly[three_count])
             three_count++;
         if(ugly[i] == 5*ugly[five_count])
             five_count++;
         
     }   
      return ugly[n-1];
    }
};