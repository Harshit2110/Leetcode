class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hash;

        for(int i = 0; i < magazine.length(); i++){
            hash[magazine[i]] += 1;
        }

        for(int i = 0; i < ransomNote.length(); i++){
            //if letter is present, decrease the counter for that letter.
            //if counter is zero, return false.

            if(hash[ransomNote[i]]){
                hash[ransomNote[i]] -= 1;
            }
            else{
                return false;
            }
        }

        return true;
    }
};
