#define MAXN 1000006
class MyHashSet {
public:
    int Hash[MAXN];
    MyHashSet() {
      for(int i = 0 ; i <MAXN;i++)
          Hash[i] = -1;
    }
    
    void add(int key) {
         Hash[key] = 1;   
    }
    
    void remove(int key) {
        Hash[key] = -1;
    }
    
    bool contains(int key) {
        return Hash[key] != -1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */