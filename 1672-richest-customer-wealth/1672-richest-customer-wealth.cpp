class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int r=0; for(auto&a:accounts)r=max(r,accumulate(a.begin(),a.end(),0)); return r;
        
    }
};