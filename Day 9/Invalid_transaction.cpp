class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<string> name(n),city(n);
        vector<int> time(n),amount(n);
        
        for(int i=0;i<n;i++){
            vector<string>temp;
            string t;
            istringstream f(transactions[i]);
            while(getline(f,t,',')){
                temp.push_back(t);
            }
            name[i]=temp[0];
            time[i]=stoi(temp[1]);
            amount[i]=stoi(temp[2]);
            city[i]=temp[3];
        }
        
        set<int> result;
        unordered_map<string,vector<int>> m;
        for(int i=0;i<n;i++){
            if(amount[i]>1000){
                result.insert(i);
            }
            if(m.find(name[i])!=m.end()){
                for(auto index:m[name[i]]){
                    if(city[i]!=city[index] && abs(time[i]-time[index])<=60){
                        result.insert(i);
                        result.insert(index);
                    }
                }
            }
            m[name[i]].push_back(i);
        }
        vector<string> res;
        for(auto x:result){
            res.push_back(transactions[x]);
        }
        return res;
    }
};