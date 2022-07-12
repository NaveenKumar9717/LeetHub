int target = 0;
class Solution {
public:
    bool makesquareH(vector<int>& matchsticks, int idx, int side1, int side2, int side3, int side4){
        if(idx == matchsticks.size()){
            int count = 0;
           if(side1 == side2 && (side1 == side3) && (side3 == side4))
               return true;
            
            return false;
        }
        
    if(side1 + matchsticks[idx] <= target   &&                                       makesquareH(matchsticks,idx+1,side1+matchsticks[idx],side2,side3,side4))
            return true;

    if(side2+matchsticks[idx] <= target    &&             makesquareH(matchsticks,idx+1,side1,side2+matchsticks[idx],side3,side4))
            return true;
        
    if(side3+matchsticks[idx]<= target && makesquareH(matchsticks,idx+1,side1,side2,side3+matchsticks[idx],side4))
            return true;
            
    if(side4+matchsticks[idx] <= target && makesquareH(matchsticks,idx+1,side1,side2,side3,side4+matchsticks[idx]))
        return true;
        
        return false;    
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(int i = 0 ; i < matchsticks.size();i++)
            sum += matchsticks[i];
        
        sort(matchsticks.begin(),matchsticks.end(),greater<int> ());
        target = sum/4;
        if(sum%4 != 0)
          return false;
        
        return makesquareH(matchsticks,0,0,0,0,0);
    }
};