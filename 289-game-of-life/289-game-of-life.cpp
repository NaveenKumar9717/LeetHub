class Solution {
public:
    int a[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
    
    int countLiveNei(vector<vector<int>>& board, int x, int y){
        int count = 0;
       for(int i = 0 ; i < 8;i++){
           int new_x = x + a[i][0];
           int new_y = y + a[i][1];
           if(new_x >=0 && new_x < board.size() && new_y >=0 && new_y < board[0].size()){
              // cout<<"new_x, new_y ---> "<<new_x<<" "<<new_y<<" : "<<board[new_x][new_y]<<endl;
               if(board[new_x][new_y] == -1 || board[new_x][new_y] == 1)
                   count++;
           }
       } 
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i =0; i<n;i++){
          for(int j = 0 ; j < m ;j++){
              int livecount = countLiveNei(board,i,j);
               //cout<<i<<" : "<<j<<"->"<<livecount<<" ";
              if(board[i][j] == 1){
                 
                 if(livecount < 2 || livecount > 3){
                     board[i][j] = -1;
                 }
                  
              }
              else{
                  if(livecount == 3){
                      board[i][j] = 2;
                  }
              }
              
          }  
           // cout<<endl;
        }
        
         for(int i =0; i<n;i++){
          for(int j = 0 ; j < m ;j++){
             if(board[i][j] == -1)
                 board[i][j] = 0;
             else if(board[i][j] == 2)
                 board[i][j] = 1;
          }  
        }
        
        
    }
};