class Solution {
public:
    int removePalindromeSub(string s) {
     int first=0,end=s.size()-1;
        while(first<end){
            if(s[first]==s[end]){
                first+=1;
                end-=1;
            }
            else
                return 2;
        }
        return 1;   
    }
};