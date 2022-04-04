class RandomizedCollection {
private:
    unordered_map<int,set<int>> m;
    vector<int> arr;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool flag = m.find(val)==m.end();
        
        m[val].insert(arr.size());
        arr.push_back(val);
        return flag;
    }
    
    bool remove(int val) {
        if(m.find(val)==m.end()) return false;
        
        int index = *(m[val].begin());
        int lastInd = arr.size()-1;
        m[arr[index]].erase(index);
        
        if(index!=lastInd){
            m[arr[lastInd]].erase(lastInd);
            m[arr[lastInd]].insert(index);
            swap(arr[lastInd],arr[index]);
        }
        
        arr.pop_back();
        
        if(m[val].size()==0)
            m.erase(val);
        
        return true;
    }
    
    int getRandom() {
        int ind = rand()%arr.size();
        return arr[ind];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */