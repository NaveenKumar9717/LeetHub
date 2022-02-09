class Bitset {
    private : 
    int set_count;
    string bitstr;
    int flip_chk;
    int length ;
    public:
    
    Bitset(int size) {
        bitstr ="";
        set_count = 0;
        flip_chk = 0;
        length = size;
        for(int i = 0;i<size;i++)
            bitstr += '0'; 
    }
    
    void fix(int idx) {
        if(flip_chk){
          if(bitstr[idx] =='1'){
             set_count++;
             bitstr[idx] = '0'; 
          }
           
        }
        else{
           if(bitstr[idx] =='0'){
               bitstr[idx] = '1';
               set_count++;
           } 
            
        }
    }
    
    void unfix(int idx) {
       if(flip_chk){
         if(bitstr[idx] =='0'){
             set_count--;
             bitstr[idx] = '1';
         }   
           
       }
       else{
        if(bitstr[idx] == '1'){
            set_count--;
            bitstr[idx] = '0';
        }  
       } 
    }
    
    void flip() {
       flip_chk = (1-flip_chk); 
       set_count = (max(length,set_count)-min(length,set_count)); 
    }
    
    bool all() {
        return set_count == length;
    }
    
    bool one() {
        return set_count >=1;
    }
    
    int count() {
        return set_count;
    }
    
    string toString() {
        string ans = bitstr;
        if(flip_chk){
          for(int i = 0;i <bitstr.length();i++){
              if(bitstr[i] == '1')
                  ans[i] = '0';
              else
                  ans[i] = '1';
          } 
        }
     
        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */