class Solution {
public:
    int brokenCalc(int startValue, int target) {
        //Although it not very much intuitive but thats right way to solve 
        int count = 0 ;
        while(startValue < target){
            count += 1;
            if(target%2 == 0)
               target /= 2;
            else
                target += 1;
        }
        
        count += (startValue - target);
        return count;
    }
};