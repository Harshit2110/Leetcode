class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        //Similar to leetcode problem, Find all anagrams in a String
        //init variables
        int n1 = s1.size();
        int n2 = s2.size();

        vector<int> hash_s1(26,0);
        vector<int> hash_s2(26,0);

        int left = 0;
        int right = 0;

        if(n2 < n1)
            return false;

        while(right < n1){
            hash_s1[s1[right]-'a']++;
            hash_s2[s2[right]-'a']++;
            right++;
        }
        right--;

         while(right < n2){
            if(hash_s1 == hash_s2) // if both has are same, permutation is found.
                return true;

            //move the window and commute hash again
            right++;

            if(right != n2) //boundary check
                hash_s2[s2[right]-'a']++;

            hash_s2[s2[left]-'a']--;
            left++;
        }

        return false;
    }
};
