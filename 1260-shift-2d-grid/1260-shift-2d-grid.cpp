class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();
        if(k%(m*n) == 0)
         return grid;
        
        vector<int>buffer;
        for(int i = 0 ;i <n;i++){
          for(int j = 0; j < m; j++){
              buffer.push_back(grid[i][j]);
          }  
        }
         int curr_idx = m*n - k%(m*n) ;
        for(int i = 0 ;i <n;i++){
          for(int j = 0; j < m; j++){
              grid[i][j] = buffer[curr_idx];
              curr_idx = (curr_idx+1)%(m*n);
          }  
        }
        return grid;
    }
};