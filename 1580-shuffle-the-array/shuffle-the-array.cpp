class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> r; for(int i=0;i<n;i++) r.insert(r.end(),{nums[i],nums[i+n]}); return r;
        
    }
};