class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_map<int, bool> visited;

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        /*
            This is a graph based question. You will account the time for subtree if any child in that
            subtree has an apple.
            For example,
            n = 7
            edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]
            hasApple = [false,true,true,false,true,true,false]

            We traverse from 0->1, then 1->4. Now 4 is the leaf node, does not contain an apple. So we will not account
            this in time calculation.
            Now, we move to another child of 1. 1->5. 5 is leaf node, and contain an apple. So we will add the time of 2s and return to 1.

            Now we are at 1, and time is 2 as 1's subtree has an apple. 1 also has an apple, but it does not matter. WHY?
            As 1's subtree involve atleast an apple. therefore to collect that apple we will traverse from 1. Hence, the
            time to traverse 0->1 will be added, irrespective of fact whether 1 has apple or not as collecting an apple does not
            involve any time.

            This problem can be solved using bottom-up approach. DFS will be the best technique.
        */

        //create the graph from given edges list.
        initGraph(edges);
        //Call dfs <start node, time, hasApple>
        return dfs(0, 0, hasApple);
    }

    void initGraph(vector<vector<int>>& edges){

        //adj. List
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
    }

    int dfs(int node, int time, vector<bool>& hasApple){

        //boundary check.
        if(visited[node])
            return 0;

        //mark node as visited
        visited[node] = true;

        int totaltime = 0; //this will updated only when a child has an apple.

        for(int i = 0; i < graph[node].size(); i++){
            totaltime += dfs(graph[node][i], 2, hasApple);
        }

        //if no child has apple
        if(totaltime == 0 && hasApple[node] == false)
            return 0;

        return totaltime + time;
    }
};
