class Solution {
public:
    
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> lsum(k+1,0),rsum(k+1,0);
        int ans=0;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
            lsum[i+1]=sum;
        }
        sum=0;
        int j=n-1;
        for(int i=k;i>=0;i--){
            sum+=cardPoints[j--];
            rsum[i]=sum;
        }
        
        for(int i=0;i<=k;i++){
            ans = max(ans,lsum[i]+rsum[k-i]);
        }
        return ans;
    }
};