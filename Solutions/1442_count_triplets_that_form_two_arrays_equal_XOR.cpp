class Solution {
public:
    int countTriplets(vector<int>& arr) {

        /*
        compute the prefix XOR of the array.
        prefix[i] = A[0] ^ A[1] ^ ........A[i-1]

        It refers that XOR of range (i ,j) , i < j should be given by prefix[j+1] ^ prefix[i]. WHY?
        prefix[j+1] = A[0] ^ A[1] ....... A[i-1] ^ A[i] ^ A[i+1]....... A[j];

        a == b?
        => a ^ b = 0
        => A[i] ^ A[i+1]......A[j-1] ^ A[j] ^ A[j+1]......A[k] = 0
        => prefix[k+1] ^ prefix[i] = 0
        => prefix[k+1] = prefix[i]

        we have to found pair (i,k) with equal prefix value and j can take any value from i+1 to k.
        Hence the ans will be sun of index difference, ans += k - i - 1;
        */

        //solving the problem in one pass
        int ans = 0;
        int prefixXOR = 0;

        unordered_map<int , int> count = {{0,1}};
        unordered_map<int , int> total;

        for(int i = 0; i < arr.size(); i++){
            prefixXOR = prefixXOR ^ arr[i];

            ans += count[prefixXOR] * i - total[prefixXOR];

            count[prefixXOR]++;
            total[prefixXOR] += i + 1;
        }

        return ans;
    }
};
