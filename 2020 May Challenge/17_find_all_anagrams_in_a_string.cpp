class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        /*
            Sliding window technique can be used along with hashing.
            window will be size of string p. Two pointers will be used to traverse the window.
        */

        //initialize variables
        vector<int> hashS(26,0);
        vector<int> hashP(26,0);
        vector<int> ans;

        int n = s.size();
        int window = p.size();

        int left = 0;
        int right = 0;

        if(n < window)
            return ans;

        while(right < window){
            hashP[p[right]-'a']++;
            hashS[s[right]-'a']++;
            right++;
        }
        right--;
        //Now, left and right are start and end point of window with hashP already commuted.

        while(right < n){
            if(hashP == hashS) // if both has are same, anagram is found.
                ans.push_back(left);

            //move the window and commute hash again
            right++;

            if(right != n) //boundary check
                hashS[s[right]-'a']++;

            hashS[s[left]-'a']--;
            left++;
        }

        return ans;

    }
};
