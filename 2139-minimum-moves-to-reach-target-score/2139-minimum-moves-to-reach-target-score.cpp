class Solution {
public:
    int minMovesH(int target, int maxDoubles,int steps){
      if(target == 1){
        return steps;
      }
      if(maxDoubles ==0){
        return (target-1 + steps);
      }

      if(target%2 == 0){
        return minMovesH(target/2,maxDoubles-1,steps+1);
      }
      else{
        return minMovesH(target-1,maxDoubles,steps+1);
      }
}

    int minMoves(int target, int maxDoubles) {
       //return minMovesH(target,maxDoubles,0);
       int steps = 0; 
       while(target > 1){
           if(maxDoubles > 0){
               if(target%2 == 0){
                   target /= 2;
                   maxDoubles -= 1;
               }
               else{
                   target -= 1;
               }
                 steps++;   
           }
           else{
               
               steps = steps + target -1; 
               target = 1;
           }
       }    
      return steps;  
    }
};