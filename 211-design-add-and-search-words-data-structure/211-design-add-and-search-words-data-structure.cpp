// class Trie{
// private :
//     class TrieNode{
//         public :
//         TrieNode* children[26];
//         bool isend;
//         TrieNode(){
//             for(int i = 0 ; i <26;i++)
//                 children[i] =  NULL;
//              	isend = false;
//         }
//     };

// TrieNode* root;

// public:
//     Trie() {
//         root = new TrieNode();
//     }
//     void insertH(string word, TrieNode*head){
//     	//cout<<word<<"<---word in insert "<<word.length()<<endl;
//       if(word.length() == 0){
//       	   head->isend = true;
//     		return;
//       } 
        
//         int idx = 0;
//         idx = word[0] - 'a';
//         char x = 'a' + idx ;
//         //cout<<"insert :- "<<(x)<<endl;
//         if(head->children[idx] == NULL){
//             head->children[idx] = new TrieNode();	
//         }
        
//        insertH(word.substr(1),head->children[idx]);
//      return;
//     }

//    bool searchH(string word, TrieNode*head){
//         // if(word.length() != 0 && word[0] =='.'){
//         //      return searchH(word.substr(1),head);
//         // } 
//        if(word.length() ==0){
//              //cout<<"Word end"<<endl; 
//           	return head->isend;
//           }    	
//        if(word[0] == '.'){
//       for(int i = 0;i<26;i++){
//       if(head->children[i] && searchH(word.substr(1),head->children[i]))
//                return true;
//            }
//            return false;
//        }
       
//         int idx ;
        
//         idx = word[0] - 'a';
//        // if(idx ==-51)
//         //cout<<idx<< "with word "<<word[0]<<endl;
//        // cout<<"its search"<<(x)<<endl;
//          if(head->children[idx] == NULL)
//          	return false;
//          return searchH(word.substr(1),head->children[idx]);
//     }

//  void insert(string word){
//     	cout<<word<<endl;
//     	insertH(word,root);
//     }
    
//     bool search(string word) {
//     	 return searchH(word,root);
//     }
    
// };

class WordDictionary {
public:
   unordered_map<int,vector<string>>mp;
    
    WordDictionary() {
        
    }
//    WordDictionary::~ WordDictionary() {
        
//     }
    
    void addWord(string word) {
      mp[word.length()].push_back(word);
    }
    
    bool search(string word) {
        if(mp.find(word.length()) != mp.end()){
         for(int i = 0 ; i < mp[word.length()].size();i++){
           if(compare(word,mp[word.length()][i]))
               return true;
         }
          
         }
        return false;
    }
    
    bool compare(string str1, string str2){
      for(int i  = 0;i<str1.length();i++){
          if(str1[i]  == '.')
              continue;
          else if(str1[i] != str2[i])
              return false;
      }  
        return true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */