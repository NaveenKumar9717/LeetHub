class Solution {
public:
    void print(vector<int>&v){
        for(int i = 0 ; i < v.size();i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }
    int called = 0;
    long long sumnum(int count,int a){
       
        if(count <= 0)
            return 0;
        called += count; 
       //cout<<"in sumnun "<<"count :"<<count<< " a -->"<<a<<endl;
        long long ans =  ((((long long)(count))*(0.5))*(2*((long long)(a)) + (count-1)));
        //cout<<"ans-->"<<ans<<endl;
        return ans;
    }
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        //print(nums);
        long long ans = 0;
       // k -= 1;
        int count1 = (nums[0] - 1);
        count1 = min(k,count1);
        int tot_k = 0;
        k -= count1;
        tot_k += count1;
        ans += sumnum(count1,1);
       //cout<<"first ans"<<ans<<endl;
        
        for(int i = 1 ; i <nums.size() && k;i++){
            if(k <=0){
         //    cout<<"tot_k->"<<tot_k<<" "<<called<<endl;
                return ans;
            } 
            if(nums[i] == nums[i-1])
                continue;
            int count = 0; 
            count = nums[i]- nums[i-1] - 1;
            count = min(count,k);
            k -= count;
            tot_k += count;
            if(k>=0)
            ans += sumnum(count,(nums[i-1]+1));
        }
        ans += sumnum(k,nums[nums.size()-1]+1);
        //cout<<"tot_k->"<<tot_k<<endl;
        return ans;
    }
};