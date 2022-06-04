int N;
class Solution {
public:
    bool isSafe(int row, int col,vector<string>&combinations){
        for(int i = 0; i < N; i++) {
		    if(combinations[i][col] == 'Q') return false; 
		    if(row - i >= 0 && col - i >= 0 && combinations[row - i][col - i] == 'Q')                  return false;
		    if(row - i >= 0 && col + i <  N && combinations[row - i][col + i] == 'Q')                  return false;
	    }
	        return true;
    }
    void Solutions(int row,vector<string>&combinations,vector<vector<string>>&ans){
        if(row == N){
            ans.push_back(combinations);
            return;
        }
        
        for(int col = 0 ; col  < N;col++){
            if(isSafe(row,col,combinations)){
                combinations[row][col] = 'Q';
                Solutions(row+1,combinations,ans);
                combinations[row][col] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        //vector<vector<string>>combinations;
        N = n;
        vector<string> combinations(n, string(n, '.')); 
        vector<vector<string>>ans;
        Solutions(0,combinations,ans);
        return ans;
    }
};