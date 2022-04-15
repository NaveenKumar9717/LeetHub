class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
      //thanks @ Pragya_Anand great ..
        int days = prices.size();
        if(days <= 1)
            return 0;
        
        vector<int> buy(days,0);
        vector<int> sell(days,0);    
        buy[0] -= prices[0];
        sell[0] = 0;
        
        //picking the minimum prices to buy so to get max profit
        buy[1] = max(-prices[0],-prices[1]);
        
        sell[1] = max(0,prices[1] - prices[0]);
        
        for(int day = 2; day < days; day++){
          buy[day] = max(buy[day-1],sell[day-2] - prices[day]);
          
          sell[day] = max(sell[day-1],buy[day-1]+prices[day]); 
            
        }
        return sell[days-1];
    }
};