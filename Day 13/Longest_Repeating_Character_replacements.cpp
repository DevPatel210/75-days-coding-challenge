class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> frequency;
        int maxFreq=0, start=0,end=0,n = s.length();
        int ans=0;
        
        // increment the window size till the number of characters - number of repeating characters
        // is not > k i.e. we have not exceeded the k replacements. If difference >k increment start till
        // difference <= k. Store the maximum length in the ans.
        while(end<n){
            frequency[s[end]]++;
            maxFreq = max(maxFreq,frequency[s[end]]);
            
            while(end-start+1-maxFreq>k){
                frequency[s[start]]--;
                start++;
            }
            
            ans = max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};