class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        // /-------Did not able to get his solution by myslef----
        
        int count = 0;
        unordered_map<int,int>mp;
        
        for(int i = 0 ; i < arr.size();i++){
           count =  (count + mp[target -  arr[i]])%(1000000007);
           for(int j = 0; j < i;j++){
               mp[(arr[i] + arr[j])]++;
           } 
        }
        
        return count;
    }
};