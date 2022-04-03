class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        vector<int> minLeft(n,0);
        int minPrice=prices[0];
        for(int i=0;i<n;i++){
            minPrice=min(minPrice,prices[i]);
            minLeft[i]=minPrice;
        }
        
        vector<int> maxTransactionLeft(n,0);
        int maxTransaction=0;
        for(int i=0;i<n;i++){
            maxTransaction = max(maxTransaction,prices[i]-minLeft[i]);
            maxTransactionLeft[i] = maxTransaction;
        }
        
        vector<int> maxRight(n,0);
        int maxPrice=prices[n-1];
        for(int i=n-1;i>=0;i--){
            maxPrice=max(maxPrice,prices[i]);
            maxRight[i]=maxPrice;
        }
        vector<int> maxTransactionRight(n,0);
        maxTransaction=0;
        for(int i=n-1;i>=0;i--){
            maxTransaction = max(maxTransaction,maxRight[i]-prices[i]);
            maxTransactionRight[i] = maxTransaction;
        }
        
        int result=0;
        for(int i=0;i<n;i++){
            result = max(result,maxTransactionLeft[i]+maxTransactionRight[i]);
        }
        return result;
    }
};