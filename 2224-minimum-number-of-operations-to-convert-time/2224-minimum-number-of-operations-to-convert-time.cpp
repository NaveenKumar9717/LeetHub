class Solution {
public:
    int convertTime(string current, string correct) {
        int current_minutes = 0;
        int correct_minutes = 0;
        
        current_minutes = stoi(current.substr(0,2))*60 + stoi(current.substr(3,2));
        correct_minutes = stoi(correct.substr(0,2))*60 + stoi(correct.substr(3,2));
        int diff = correct_minutes - current_minutes;
        
        int ans  = (diff/60);
        diff -= (60*ans);
        
        ans += (diff/15);
        diff -= (15*(diff/15));
        
        ans += (diff/5);
        diff -= (5*(diff/5));
        
        ans += (diff);
        //diff -= (15*(diff/15));
        
        return ans;
    }
};