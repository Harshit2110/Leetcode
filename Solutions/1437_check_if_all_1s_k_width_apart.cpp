class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {

        /*
            Two-pointer technique will be used.
            j will stay at 1 while i will traverse until next 1 is found.
            index distance is calulated i - j - 1 and compared with k.
            j will be updated to new 1;
        */

        int n = nums.size();

        int i = 0;
        while(i < n && nums[i]==0) // i will be at first index where num is 1.
            i++;

        int j = i;
        while(i < n){
            if(nums[i] == 1 && i!=j){
                if( (i-j-1) < k )
                    return false;
                j = i;
            }
            i++;
        }

        return true;
    }
};
