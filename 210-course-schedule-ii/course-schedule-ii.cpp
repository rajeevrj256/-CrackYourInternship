class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses);
        for(auto prereq:prerequisites){
            adj[prereq[1]].push_back(prereq[0]);
            indegree[prereq[0]]++;

        }

        queue<int>node;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){

            node.push(i);
            }
        }
        vector<int>ans;
        while(!node.empty()){
            int temp=node.front();
            node.pop();

            for(auto & i:adj[temp]){
                indegree[i]--;
                if(indegree[i]==0) node.push(i);
            }

            ans.push_back(temp);
        }

        return (ans.size()==numCourses?ans:vector<int>{});
    }
};