class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n = prices.size();
        int buy=0,sell=0;
        
        while(buy<n && sell<n){
            if(sell+1<n && prices[sell]<=prices[sell+1])
                sell++;
            else{
                profit+=(prices[sell]-prices[buy]);
                buy=sell+1;
                sell++;
            }
            
        }
        return profit;
    }
};