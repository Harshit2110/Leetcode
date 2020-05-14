// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int start = 1;
        long int end = n;
        long int ans = n;

        long int mid;

        while(start <= end){

            mid = (start + end)/2;
            if(isBadVersion(mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        return ans;
    }
};
