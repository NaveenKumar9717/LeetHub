
   
  
  bool sortByVal(const pair<int, int> &a,const pair<int, int> &b) 
        { 
            return (a.second > b.second); 
        } 
class Solution {
public:
   
    int minimumOperations(vector<int>& nums) {
               unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        int n = nums.size();
        int even_count  = n/2 + (n%2 != 0);
        int odd_count  = n/2;
       // cout<<"Ecene_count :->"<<even_count<<"--  Odd count-->"<<odd_count<<endl;
        for(int i = 0 ;i < nums.size();i++){
            if(i%2 == 0){
                mp1[nums[i]]++;
            }
            else{ //cout<<"odd ->"<<nums[i]<<" ";
                 mp2[nums[i]]++;
            }
        }
        
       vector<pair<int, int>> vec1;
       //cout<<endl; 
	// copy key-value pairs from the map to the vector
      unordered_map<int, int> :: iterator it1 = mp1.begin();
      for (; it1!=mp1.end(); it1++) 
      { //cout<<it1->first<<" fist map-> "<<it1->second<<endl;
        vec1.push_back(make_pair(it1->first, it1->second));
      }
        
      unordered_map<int, int> :: iterator it2;
      vector<pair<int, int>> vec2;  
      for (it2=mp2.begin(); it2!=mp2.end(); it2++) 
      {
        vec2.push_back(make_pair(it2->first, it2->second));
      }  
        
      sort(vec1.begin(), vec1.end(), sortByVal);  
      sort(vec2.begin(), vec2.end(), sortByVal); 
      int i = 0;
      int j = 0;
        //cout<<"vec1 ->: ";
      //for(int k = 0 ; k < vec1.size();k++)
          //cout<<"("<<vec1[k].first<<","<<vec1[k].second<<")";
      //cout<<endl<<"for vec2 --> :";
      // for(int k = 0 ; k < vec2.size();k++)
        //  cout<<"("<<vec2[k].first<<","<<vec2[k].second<<")"; 
       //cout<<endl; 
      while(i  < vec1.size() && j < vec2.size()){
          cout<<vec1[i].first<< " "<<vec2[j].first<<endl;
          if(vec1[i].first != vec2[j].first){
              //cout<<"From here"<<endl;
              //cout<<vec1[i].first<<" "<<vec1[i].second<< " for odd "<<vec2[j].first<<" "<<vec1[j].second<<endl; 
              return (even_count - vec1[i].second + odd_count - vec2[j].second);
          }
      else if((vec1[i].first == vec2[j].first) && (vec1[i].second != vec2[j].second))
      {       
            if(vec1[i].second < vec2[j].second)
                i++;
          else
              j++;
      }
      else{
          i++;
      }    
      }  

      return (even_count - vec1[0].second + odd_count) ;

    }
};