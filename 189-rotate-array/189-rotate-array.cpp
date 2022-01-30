class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      int n = nums.size();
        vector<int> temp(n);
     
      for(int i  = 0 ; i <nums.size();i++) {
         // cout<<i<<"-->"<<(i+k)%n<<endl;
          temp[(i+k)%n] = nums[i];
      }
      for(int i  = 0 ; i <nums.size();i++) {
          nums[i] = temp[i];
      }  
        return ;
    }
};