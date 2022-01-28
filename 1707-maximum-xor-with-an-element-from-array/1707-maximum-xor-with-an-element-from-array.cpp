class Node{
    Node* links[2];
    public :
    bool containKey(int bit){
        return (links[bit]  != NULL);
    }
    
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit,Node* node){
        links[bit] = node;
    }
};

class Trie{
Node* root;     

 public:
   Trie(){
       root = new Node();
   } 
    
   void insert(int num){
       Node* node = root;
       for(int i = 31; i>= 0;i--){
           int bit = ((num >> i) & 1 );
           if(node->containKey(bit) == false){
              node->put(bit,new Node());
           }
           node = node->get(bit);
       }    
   } 
   
   int getMax(int num){
       Node* node = root;
       int maxVal = 0;
       if(node == NULL){
           cout<<"Checkkkkkk"<<endl;
       }
       for(int i = 31;i>=0;i--){
           int bit = ((num>>i) & 1);
           if(node == NULL)
        cout<<"Here is null"<<endl;
           
           if(node->containKey(1-bit)){
               maxVal = ( maxVal | (1 << i));
               node = node->get(1-bit);
           }
           else{
               node = node->get(bit);
               if(node == NULL){
                   cout<<"It cam from--> at "<<i<< " "<<num<< " with bit "<<bit<<endl;
               }
           }

       }
       return maxVal;
   } 
    
};

class store{
    public:
    vector<int> q;
    int idx;
};

bool comparator(store a, store b){
    return a.q[1] <= b.q[1] ;
}

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans(queries.size());
       
        sort(nums.begin(),nums.end());
        Trie* T = new Trie();
        vector<pair<int,pair<int,int>>>arr;
        for(int i = 0 ; i <queries.size();i++){
            pair<int,pair<int,int>> temp;
            temp.first = queries[i][1] ;
            temp.second.second = i;
            temp.second.first = queries[i][0];
            arr.push_back(temp);
            ans[i]  = -1;
        }
        
        sort(arr.begin(),arr.end());
        int pos = 0 ; 
       bool isTrieExist = false;
         for(int i = 0 ; i <arr.size();i++){
              
           while(pos < nums.size() && nums[pos] <= arr[i].first){
               T->insert(nums[pos]);
              //cout<<"les than -->"<<nums[pos]<<endl;
               pos++;
               isTrieExist = true;
           }
           if(isTrieExist)  
           ans[arr[i].second.second] = T->getMax(arr[i].second.first);  
         }
        
        return ans;
    }
};