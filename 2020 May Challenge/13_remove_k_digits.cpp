class Solution {
public:
    string removeKdigits(string num, int k) {

        /*
        we plot a height graph of the digits while traverse from left to rigth,
        then we have to flatten the curve as much as possible.

        => therefore, we have to remove the digits at which local maxima occurs.

        => if digits are already in ascending order, then remove the digits from the last
        */

        int n = num.length();

        stack<char> height;

        for(int i = 0; i < n; i++){
            while(!height.empty() && k > 0 && height.top() > num[i]){
                height.pop();
                k--;
            }

            if(!height.empty() || num[i]!='0')
                height.push(num[i]);
        }

        //if digits are in ascending order
        while(!height.empty() && k--)
            height.pop();

        //if stack is empty
        if(height.empty())
            return "0";

        string ans = "";
        while(!height.empty()){
            ans = height.top() + ans;
            height.pop();
        }

        return ans;
    }
};
