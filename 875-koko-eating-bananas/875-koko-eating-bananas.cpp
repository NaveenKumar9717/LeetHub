class Solution {
public:
    bool isPossible(vector<int>& piles, int k,int h){
        if(k <= 0)
            return false;
        bool ans = true;
        int hours_taken = 0 ;
    
        for(int i = 0 ;i < piles.size();i++){
            double x = (double)(piles[i])/(double)(k);
           //cout<<"d"<<x<<endl;
            //cout<<piles[i]<<":-->"<<(ceil(x))<<endl;
            hours_taken += (ceil(x)) ;
            
            if(hours_taken > h)
                return false;
        }
        //cout<<"hours taken "<<hours_taken<<endl;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        //sort(piles.begin(),piles.end());
        int high  = 0 ;
        for(int i = 0 ;i <piles.size();i++)
            high = max(high,piles[i]);
        
        int mink = 0;
        int maxk = high;
        
        //cout<<"maxk"<<maxk<<endl;
        int ans = maxk;
      //  cout<<isPossible(piles,3,8);
        while(mink <= maxk){
            int mid = (mink+maxk)/2;
            if(isPossible(piles,mid,h)){
                cout<<"mid :"<<mid<<endl;
                ans = min(ans,mid);
             maxk = mid- 1; 
            }
            else{
                cout<<"mink-->"<<mid+1<<endl;
                mink = mid + 1;
            }
            
        }
        return ans;
    }
};