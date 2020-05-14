class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {

        vector<pair<int, int>> A(N+1, {0,0});
        //1st pair value will tell how many he trusts
        //2nd pair value will tell how many trusted him
        //to be a town judge, first value should be zero, and second value should be n-1

        for(int i = 0; i < trust.size(); i++){
            A[trust[i][0]].first += 1;
            A[trust[i][1]].second += 1;
        }

        for(int i = 1; i <= N; i++){
            if(A[i].first == 0 && A[i].second == N-1)
                return i;
        }

        return -1;
    }
};
