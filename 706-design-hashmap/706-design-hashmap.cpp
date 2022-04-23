#define MAXN 1000006
class MyHashMap {
public:
    
    int Hash[MAXN];
    
    MyHashMap() {
      for(int i = 0 ; i <MAXN;i++)
          Hash[i] = -1;
        
    }
    
    void put(int key, int value) {
        Hash[key] = value;   
    }
    
    int get(int key) {
        return Hash[key];
    }
    
    void remove(int key) {
        Hash[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */