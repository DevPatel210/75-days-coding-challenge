class TimeMap {
public:
    map<string,vector<pair<int,string>>> ds;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ds[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int start=0,end=ds[key].size();
        string ans="";
        while(start<end){
            int mid = start+(end-start)/2;

            if(ds[key][mid].first<=timestamp){
                ans=ds[key][mid].second;
                start=mid+1;
            }else{
                end=mid;
            }
        }
        return ans;
    }
};