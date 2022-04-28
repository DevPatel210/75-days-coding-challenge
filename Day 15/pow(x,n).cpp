class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        int n1 = abs(n);
        while(n1>0){
            if(n1&1 == 1) ans = ans*x;
            n1>>=1;
            x*=x;
        }
        
        return (n>0) ?ans : 1/ans;
    }
};