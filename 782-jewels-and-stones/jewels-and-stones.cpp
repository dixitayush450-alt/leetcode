class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        return count_if(stones.begin(),stones.end(),[&](char c){return jewels.find(c)!=string::npos;});
        
    }
};