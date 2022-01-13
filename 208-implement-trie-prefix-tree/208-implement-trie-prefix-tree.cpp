class Trie {
private :
    class TrieNode {
        public :
        TrieNode* children[26];
        bool isend;
        TrieNode(){
            for(int i = 0 ; i <26;i++)
                children[i] =  NULL;
             	isend = false;
        }
    };

TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    void insertH(string word, TrieNode*head){
    	//cout<<word<<"<---word in insert "<<word.length()<<endl;
      if(word.length() == 0){
      	   head->isend = true;
    		return;
      }

        int idx = word[0] - 'a';
        char x = 'a' + idx ;
        //cout<<"insert :- "<<(x)<<endl;
        if(head->children[idx] == NULL){
            head->children[idx] = new TrieNode();	
        }
        
       insertH(word.substr(1),head->children[idx]);
     return;
    }

   bool searchH(string word, TrieNode*head){
          if(word.length() ==0){
          	return head->isend;
          }    	
        int idx = word[0] - 'a';
        char x = 'a' + idx ;
       // cout<<"its search"<<(x)<<endl;
         if(head->children[idx] == NULL)
         	return false;
         return searchH(word.substr(1),head->children[idx]);
    }

    bool startsWithH(string prefix,TrieNode*head){
        if(prefix.length() == 0)
            return true;
    int idx = prefix[0] - 'a';

    if (head->children[idx] == NULL)
        {
          return false;
        }
        else{
            return startsWithH(prefix.substr(1),head->children[idx]);
        }    

    }

    void insert(string word){
    	cout<<word<<endl;
    	insertH(word,root);
    }

    

    bool search(string word) {
    	 return searchH(word,root);
    }
    
    bool startsWith(string prefix) {
        return startsWithH(prefix,root);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */