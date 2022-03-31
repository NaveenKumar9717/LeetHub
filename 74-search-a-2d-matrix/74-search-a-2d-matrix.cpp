class Solution {
public:
    int searchRow(vector<vector<int>>& matrix, int target){
        int si = 0 ;
        int ei = matrix.size()-1;
        int m = matrix[0].size();
        int ans = -1;
        while(si <= ei){
            int mid = (si + ei)/2;
            if(matrix[mid][m-1] >= target){
                ans = mid;
                ei = mid-1;
            }
            else{
                si = mid + 1;
            }
        }
        return ans;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int idx = searchRow(matrix,target);
       if(idx == -1)
        return false;
       // cout<<idx<<endl;
        int m = matrix[0].size();
        int n = matrix.size();
        
        int si = 0;
        int ei = m - 1;
        //cout<<"ei-->"<<ei<<endl;
        int ans = -1;
        while(si <= ei){
            int mid = (si + ei)/2;
            if(matrix[idx][mid] == target)
                return true;
            else if(matrix[idx][mid] < target)
                si = mid + 1;
            else
                ei = mid - 1;
            
        }
        return false;   
        
//       cout<<idx<<endl;  
        
//       int n  = matrix.size() ;
//       int left  = 0 ; 
//       int right  = matrix[0].size() - 1 ;
        
//       while(left < n && right >=0 ){
         
//          if(matrix[left][right] == target)
//              return true ;
//          else if(matrix[left][right] > target)
//              right-- ;
//          else
//              left++;
         
//      }   
//      return false ;  
    }
};