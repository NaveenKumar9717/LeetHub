int m,n;
int dp[101][101];
class Solution {
public:
    bool valid(int x, int y){
       return  x >= 0 &&  x < m && y >= 0 && y  < n ;
    }
    int DFS(vector<vector<int>>& obstacleGrid, int x, int y){
        if(x == (m-1) && y == (n-1))
            return 1;
        if(dp[x][y] != -1)
          return dp[x][y];
        int ans = 0;
        if( valid(x+1,y) && obstacleGrid[x+1][y] == 0)
            ans += DFS(obstacleGrid,x+1,y);
        
        if( valid(x,y+1) && obstacleGrid[x][y+1] == 0)
            ans += DFS(obstacleGrid,x,y+1);
        dp[x][y]  = ans;
        return ans;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1)
            return 0;
         m = obstacleGrid.size();
         n = obstacleGrid[0].size();
         
         memset(dp,-1,sizeof(dp));
        return DFS(obstacleGrid,0,0);
    }
};