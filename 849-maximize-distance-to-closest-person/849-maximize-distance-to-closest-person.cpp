class Solution {
public:
    bool isPossible(vector<int>& seats, int dis){
        int tot_seats = seats.size();
        int empty = 0;
        int max_empty = 0;
        int start_index  =-1 ;
        for(int i = 0; i<seats.size();i++){
            if(seats[i] == 0){
                empty++;
                max_empty = max(empty,max_empty);
            }
            else{
                empty = 0;
            }
        }
        
        int ans = 0;
        int k = 0 ;
        while(seats[k] == 0){
                k++;
            }
            ans = k; 
            
          k  = (tot_seats - 1);
            while(seats[k] == 0 && k>=0){
                k--;
            }
            k++;
            int suffix_empty = (tot_seats-k);
            cout<<"Suffix_empty :->"<<suffix_empty<<endl;
            ans = max(suffix_empty,ans);
        
        if(max_empty%2 != 0){
            ans = max(ans,(max_empty/2) + 1);
        }
        else
        {
        ans = max(ans,max_empty/2);
        }
        
        return ans >= dis;    
    }
    
    int maxDistToClosest(vector<int>& seats) {
        int minDis = 1;
        int maxDis = seats.size();
        int ans = 1;
      // cout<<isPossible(seats,6)<<endl;
        while(minDis <= maxDis){
            int mid = (minDis + maxDis)/2;
            if(isPossible(seats,mid)){
                ans = mid;
                minDis = mid+1;
            }
            else{
                maxDis = mid-1;
            }
        }
        
        return  ans;
    }
};