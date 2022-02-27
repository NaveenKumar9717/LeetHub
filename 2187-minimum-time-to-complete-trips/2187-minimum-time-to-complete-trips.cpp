class Solution {
public:
    bool iscomplete(vector<int>& time, long long max_time,int totalTrips){
        long long count = 0;
        for(int i = 0;i<time.size();i++){
            count += (long long)((long long)(max_time)/time[i]);
        }
        return count >= (long long)(totalTrips);
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long ans = 0;
        long long maxtime = 1;
        for(int i = 0;i <time.size();i++){
            maxtime = (long long)(max((long long)(time[i]),maxtime));
        }
        
        maxtime = (long long)(maxtime*(long long)(totalTrips));
        long long mintime = 1;
        while(mintime <= maxtime){
            long long mid  = (long long)( (long long)(mintime)+maxtime)/2;
            if(iscomplete(time,mid,totalTrips)){
                ans = mid;
                maxtime = mid-1;
            }
            else{
                mintime = mid+1;
            }
        }
        return ans;
    }
};