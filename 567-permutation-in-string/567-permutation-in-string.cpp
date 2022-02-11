class Solution {
public:
    int hashfunction(string p,int*freq){   
      for(int i = 0 ;i <26;i++)
            freq[i] = 0;
         
      for(int i = 0 ;i <p.length();i++){
          int idx = p[i] - 'a';
          freq[idx] += 1;
      }
         
      int Res = 0;   
      for(int i = 0 ;i <26;i++){
          Res  += (freq[i]*(97+i));
      }   
      return Res;
    }
    bool isEqual(int*freq1, int*freq2){
        cout<<"At Equal"<<endl;
        for(int i = 0 ; i<26;i++){
            if(freq1[i] != freq2[i])
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        int freq1[26];
        int freq2[26];
        int curr_hash = 0;
        int Patthash = hashfunction(s1,freq1);
        string s = s2;
        for(int i = 0; i <=(s2.length() - s1.length());i++){
            if(i == 0){
                curr_hash = hashfunction(s.substr(0,s1.length()),freq2);
          //      cout<<"curr_has-->"<<curr_hash<<endl;
                if(curr_hash == Patthash && isEqual(freq1,freq2)){
                    return true;
                }                         
            }
            else{
          int idx = s[i-1] - 'a';
          curr_hash -= (97 + idx);
          freq2[idx]--;      
          idx =  s[i + s1.length()-1]-'a';
          //cout<<"New char -->"<<s[i + p.length()-1]<<endl;      
          curr_hash += (97+idx);      
          freq2[idx] += 1;
           //cout<<"cuur hash else  -->"<<curr_hash<<endl;     
          if(curr_hash == Patthash && isEqual(freq1,freq2))      
          {
              return true;
          }   
            }
        } 
        return false;
    }
};