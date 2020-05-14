class Solution {
public:
    bool isPerfectSquare(int num) {

        if(num == 1)
            return true;

        int start = 2;
        int end = num / 2;

        while(start <= end){
            int mid = (start + end) / 2;

            if((long int)mid * mid == (long int)num)
                return true;
            else if((long int)mid * mid > (long int)num)
                end = mid - 1;
            else
                start = mid + 1;
        }

        return false;
    }
};
