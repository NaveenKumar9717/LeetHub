class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int count = 1;
       
        sort(intervals.begin(),intervals.end());
         int l = intervals[0][0] ;
        int r = intervals[0][1] ;
        for(int i= 1; i<intervals.size(); ++i)
        {   // We can count all intervals those not overlap 
            if(intervals[i][0] > l && intervals[i][1] > r)
                ++count;
            // since array sorted so we can if intervals[i][1] > r than update and get larger range 
            if(intervals[i][1] > r)
            {
                l = intervals[i][0];
                r = intervals [i][1];
            }
        }
        
        return count;
    }
};