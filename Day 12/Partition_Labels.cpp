class Solution {
public:
    vector<int> partitionLabels(string s) {
        int maxInd=0, prevBreak=0;
        vector<int> ans;
        
        // get the last index of each character
        map<char,int> last;
        for(int i=0;i<s.length();i++){
            last[s[i]]=i;
        }
        
        // we keep a track of the maximum of the last index for each character we iterate through
        // if the current index reach the maximum, so we can break the string here.
        for(int i=0;i<s.length();i++){
            maxInd = max(maxInd,last[s[i]]);
            if(i==maxInd){
                ans.push_back(maxInd-prevBreak+1);
                prevBreak=i+1;
            }
        }
        return ans;
    }
};