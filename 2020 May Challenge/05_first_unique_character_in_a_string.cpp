class Solution {
public:
    int firstUniqChar(string s) {

        //hash array initialized with zero.
        int hash[26] = {0};

        for(int i = 0; i < s.length(); i++){
            hash[s[i] - 'a'] += 1;
        }

        int index = -1;

        for(int i = 0; i < s.length(); i++){
            if(hash[s[i] - 'a'] == 1){
                index = i;
                break;
            }
        }

        return index;
    }
};
