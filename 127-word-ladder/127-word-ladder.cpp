class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       
        int depth = 1 ; 
        set<string> mp ;
        set<string>visited ; 
        for(int i = 0 ; i<wordList.size();i++)
            mp.insert(wordList[i])  ;
        
        
        queue<string>qu  ;
        qu.push(beginWord) ;
     visited.insert(beginWord) ;
        while(! qu.empty()){
            int size = qu.size() ;
            while(size--){
            string current = qu.front() ;
           
            qu.pop() ;
            for(int i =0 ; i <current.length();i++){
               for(int j = 0 ;j<26;j++){
                   string temp  = current ; 
                   if(current[i] != ('a' + j)){
                       temp[i] = ('a' + j ) ;
                        // cout<<temp<<endl;
                       if(temp == endWord && mp.find(temp) != mp.end() )
                           return depth +1 ;
                       
                       if(mp.find(temp) != mp.end() && visited.find(temp) == visited.end()){
                           //cout<<temp<<endl;
                               visited.insert(temp) ;
                           qu.push(temp) ;
                           
                       }
                       
                   }
               }  
            }
           //depth++ ;      
        }
          depth++ ;
            
            }   
            
        
        return 0;  
    }
};