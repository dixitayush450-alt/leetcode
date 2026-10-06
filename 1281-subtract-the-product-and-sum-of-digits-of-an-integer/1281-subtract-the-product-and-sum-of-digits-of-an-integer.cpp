class Solution {
public:
    int subtractProductAndSum(int n) {
        return [&](){int p=1,s=0,x=n;while(x){p*=x%10;s+=x%10;x/=10;}return p-s;}();
        
    }
};