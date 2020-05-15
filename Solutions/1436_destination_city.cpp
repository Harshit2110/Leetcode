class Solution {
public:
    string destCity(vector<vector<string>>& paths) {

        /*
            Since there is no loop and destination is going to be exactly one city,
            we can say that if graph is formed, it can be viewed as singly linked list with last node as the destination city.

            Therefore, using hashing, keeping track of cities from which we can leave. The one with the count = 0 will be the answer.
        */
        unordered_map<string, int> fromCity;

        for(int i = 0; i < paths.size(); i++){
            fromCity[paths[i][0]]++;
        }

        string ans;

        for(int i = 0; i < paths.size(); i++){
            if(fromCity[paths[i][1]] == 0){
                ans = paths[i][1];
                break;
            }
        }

        return ans;
    }
};
