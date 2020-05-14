class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> hash;

        for(int i = 0; i < S.length(); i++){
            hash[S[i]] += 1;
        }

        int ans = 0;

        for(int i = 0; i < J.length(); i++){
            ans += hash[J[i]];
        }

        return ans;
    }
};
