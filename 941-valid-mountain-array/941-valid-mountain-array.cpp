class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3){
            return false;
        }
        int max_element = 0;
        int index = -1;
        for(int i = 0 ; i < arr.size();i++){
            if(max_element < arr[i]){
                max_element= max(arr[i],max_element);
                index = i;
            }
        }
        if(index == 0 || index == (arr.size()-1))
            return false;
        
        //left should be positive
        for(int i = 0; i< index;i++){
            if(arr[i+1]-arr[i] <= 0)
                return false;
        }
        
        //for right side 
          for(int i = index; i< arr.size()-1;i++){
            if(arr[i+1]-arr[i] >= 0)
                return false;
          }
        
        return true;
    }
};