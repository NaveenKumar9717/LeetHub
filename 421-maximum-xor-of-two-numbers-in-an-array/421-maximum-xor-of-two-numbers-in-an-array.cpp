
class Node{
    Node* links[2];
    public :
    Node(){
        links[0] = NULL;
        links[1] = NULL;
    }
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
           if(!node->containKey(bit)){
              node->put(bit,new Node());
           }
           node = node->get(bit);
       }    
   } 
   
   int getMax(int num){
       Node* node = root;
       int maxVal = 0;
       for(int i = 31;i>=0;i--){
           int bit = ((num>>i) & 1);
           if(node->containKey(1-bit)){
               maxVal = ( maxVal | (1 << i));
               node = node->get(1-bit);
           }
           else{
               node = node->get(bit);
           }
       }
       return maxVal;
   } 
    
};

class Solution {
public:
       
    int findMaximumXOR(vector<int>& nums){
       // return 28;
        Trie* T = new Trie();
        for(int i = 0; i < nums.size();i++){
           T->insert(nums[i]);    
        }
        int MaxXor = 0;
        for(int i = 0; i < nums.size();i++){
           MaxXor = max( MaxXor,T->getMax(nums[i]));    
        }
        return MaxXor;
    }
};