class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0 ; 
        int i = 0 ; 
        int j = height.size() -1 ; 
        while(i < j ){
            if(height[i] <= height[j]){
               max_water = max(max_water,height[i]*(j-i)) ; 
               i++;
            }
            else{
                //cout<<height[i]<<" - --"<<height[j]<<endl;
                 int x = (j-i)*height[j] ; 
                 max_water = max(max_water,x) ; 
                 j--;
                }
        }
        return max_water ; 
    }
};