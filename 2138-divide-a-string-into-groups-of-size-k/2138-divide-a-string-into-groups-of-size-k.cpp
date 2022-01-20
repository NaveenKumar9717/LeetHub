class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int i = 0 ;
        while((i+k) <= s.length()){
            ans.push_back(s.substr(i,k));
            //cout<<"this is inserting->"<<s.substr(i,k)<<endl;
            i += k;
        }
        if(i<s.length()){
            string temp = s.substr(i);
            string new_fill ="";
            for(int j = 0; j<k-temp.length();j++){
                new_fill += fill;
                
            }
            temp += new_fill;
            ans.push_back(temp);
        }
        return ans;
    }
};