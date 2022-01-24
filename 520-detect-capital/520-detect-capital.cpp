class Solution {
public:
    bool detectCapitalUse(string word) {
       int capital_count = 0;
       int first_pos = -1;
       for(int i = 0 ; i < word.length();i++){
           int x = word[i];
           if(x >= 65 && x <= 90 ){
               if(first_pos == -1){
                   first_pos = i;
               }
               capital_count++;
           }
       }
        if(capital_count == word.length() || (capital_count == 1 && first_pos == 0) || (capital_count ==0)){
            return true;
        }
        return false;
    }
};