class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

        /*
        num will read the numbers from 1 to n
        compare it one by one with the target
        if match, perform push operation, otherwise increment num and perform push and pop operations
        */
        int num = 1;
        vector<string> ans;

        int i = 0;

        while(i < target.size()){

            if(target[i] == num){
                ans.push_back("Push");
                i++;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            num++;
        }

        return ans;
    }
};
