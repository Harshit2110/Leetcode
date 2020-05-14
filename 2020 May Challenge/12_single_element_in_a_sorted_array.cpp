class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        /*
        Each element is repeated twice except for one.

        =>  boundary check, if either first or last element is unique

        =>  if boundary check does not give unique element. We know that even numbers
            will occur in pair, and starts from even index of array till unique number. After unique
            number the even pair will start from odd index of array till the end.
        */

        //using modified binary search
        int start = 0;
        int end = nums.size() - 1;

        //boundary checks
        if(end == 0) // length of array is 1
            return nums[0];
        else if(nums[0] != nums[1])
            return nums[0];
        else if(nums[end]!=nums[end-1])
            return nums[end];


        while(start <= end){
            int mid = (start + end) / 2;

            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
                return nums[mid];

            else if( (mid % 2 == 0 && nums[mid] == nums[mid+1]) || (mid % 2 != 0 && nums[mid] == nums[mid-1]) )
                start = mid + 1;

            else
                end = mid - 1;
        }

        return -1;
    }
};
