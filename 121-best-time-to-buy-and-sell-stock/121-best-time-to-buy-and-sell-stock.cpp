class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int profit = 0 ;
	int max_stock = 0 ;
	int n = prices.size() ;
	for (int i = n - 1; i >= 0; i--) {
		if (prices[i] >= max_stock) {
			max_stock = prices[i] ;
		}
		if ((max_stock - prices[i]) > profit) {
			profit = max_stock - prices[i] ;

		}
	}
	return profit ;  
    }
};