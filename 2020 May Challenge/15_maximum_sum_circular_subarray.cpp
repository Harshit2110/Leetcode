class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        /*
            A good observation is that, maximum sum subarray can be calculated with
            (totalSum - minimum sum subarray).
            But there are boundary cases:

            => if Total_sum = minimum sum subarray, it will imply
            that all elements are negative or either there is one positive element.
            => totalSum - minimum sum subarray could be less then maximum element in the array.
            therefore, maximum sum will be given by max(maximumElement, totalSum - minimumSumSubarray)
            => if all are positive, invert will make all elements negative, and it will give
            totalSum - minimum element as ans where as answer should be totalSum;
            with invert method, two pass have to be used, calculating redundant variables.
        */

        int curMin = 0;
        int minSum = INT_MAX;
        int totalSum = 0;
        int curMax = 0;
        int maxSum = INT_MIN;

        for(int i = 0; i < A.size(); i++){
            totalSum += A[i];

            curMin = min(A[i], A[i]+curMin);
            minSum = min(minSum, curMin);

            curMax = max(A[i], A[i]+curMax);
            maxSum = max(maxSum,curMax);
        }

        if(totalSum == minSum) //all elements are negative
            return maxSum;

        return max(maxSum, totalSum - minSum); // handle all other cases
    }
};
