class KthLargest {
public:
     priority_queue<int,vector<int>,greater<int>>qu;
    int maxK=0;
    KthLargest(int k, vector<int>& nums) {
        maxK =k;
      
        for(int i =0 ;i <nums.size();i++){
            qu.push(nums[i]);
            while(qu.size()>k){
                qu.pop();
            }
        }   
    }
    
    int add(int val) {
      qu.push(val);
        if(qu.size()>maxK)
            qu.pop();
        
        return qu.top(); 
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */