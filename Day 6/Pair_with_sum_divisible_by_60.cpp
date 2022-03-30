class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int> m;
        int n = time.size();
        for(int i=0;i<n;i++){
            time[i]=time[i]%60;
            m[time[i]]++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(time[i]==30 || time[i]==0){
                if(m[time[i]]>0){
                    count+=m[time[i]]-1;
                    m[time[i]]--;
                }
            }else if(m.find(60-time[i])!=m.end()){
                count+=m[60-time[i]];
                if(m[time[i]]>1)
                    m[time[i]]--;
                else
                    m.erase(time[i]);
            }
        }
        return count;
    }
};