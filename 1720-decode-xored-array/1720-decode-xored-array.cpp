class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
      vector<int> ans;
        ans.push_back(first);
        int last = first;
        for(int i = 0 ; i < encoded.size();i++){
            ans.push_back(encoded[i] ^ last );
            last = encoded[i] ^ last;
        }
        return ans;
    }
};