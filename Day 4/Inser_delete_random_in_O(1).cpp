class RandomizedSet {
    unordered_map<int,int> m;
    vector<int> arr;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(m.find(val)!=m.end()) return false;
        m[val]=arr.size();
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val)==m.end()) return false;
        int last = arr.back();
        m[last] = m[val];
        arr[m[val]] = last;
        arr.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        int i = rand()%arr.size();
        return arr[i];
    }
};