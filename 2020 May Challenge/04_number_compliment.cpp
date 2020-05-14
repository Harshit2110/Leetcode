class Solution {
public:
    int findComplement(int num) {

        //find number of bits required in binary representation
        int bitCount = (int)log2(num) + 1;
        //find highest number that can be formed using these number of bits
        //e.g, 5 - 101, so highest number can be formed using three bits is 7 - 111.
        // xor 5 ^ 7 = 101 ^ 111 = 010 = 2, which is 5's compliment
        int highestNumber = (int)((long long)(1 << bitCount) - 1);

        return num ^ highestNumber;

    }
};
