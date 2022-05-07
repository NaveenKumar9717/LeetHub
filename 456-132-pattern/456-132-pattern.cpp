class Solution {
public:
//     bool merge132pattern(vector<int>& nums,int si,int mid,int ei){
//         int  i = si;
//         int  j = mid;
//         int  k = mid+1;
//         int capacity[ei-si+1];
        
//         while()
        
        
//     }
//     bool find132pattern(vector<int>& nums,int si,int ei){
//         if(si >= (ei))
//          return false;
//        int mid = (si+ei)/2;
       
//        bool left  = find132pattern(nums,si,mid);
//        bool right = find132pattern(nums,mid+1,ei);
        
//        if(left || right)
//            return true;
        
//        return merge132pattern(nums,si,mid,ei); 
//     }
    bool find132pattern(vector<int>& nums) {
       
        stack<int> st;
        int thirdElement = INT_MIN;
        
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] < thirdElement) return true;
            while(!st.empty() && st.top() < nums[i]){ 
                thirdElement = st.top();
                st.pop();                                                                            }                                                                             
            st.push(nums[i]);
        }
        
        return false;
      }
};