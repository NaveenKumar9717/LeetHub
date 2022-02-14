class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long sum = 0;
        long long ans = 1e18;
        sort(beans.begin(),beans.end());
        for(int i = 0 ;i <beans.size();i++)
            sum += beans[i];
        
        for(int i = 0 ; i <beans.size();i++){
            long long temp =  sum - (long long)(beans[i]*(beans.size()-i));
            ans = min(ans,temp);
        }
        return ans;
    }
};