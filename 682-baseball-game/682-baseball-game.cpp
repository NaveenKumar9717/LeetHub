class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>sumtable;
        int n = ops.size();
        int curr_sum = 0;
        for(int i =0 ;i < n;i++){
            if(ops[i] == "C"){
                sumtable.pop_back();
            }
            else if(ops[i] ==  "D"){
                sumtable.push_back(sumtable[sumtable.size()-1]*2);
            }
            else if(ops[i] ==  "+"){
                sumtable.push_back(sumtable[sumtable.size()-1] + sumtable[sumtable.size()-2]);
            }
            else{
                int val =  stoi(ops[i])  ;
                sumtable.push_back(val);
            }
        }
        curr_sum = 0;
        for(int i = 0;i<sumtable.size();i++){
            curr_sum += sumtable[i];
        }
        
        return curr_sum;
    }
};