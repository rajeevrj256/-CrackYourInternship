class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);

        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;

        }

        queue<int>q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int course=0;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            course++;
            for(auto it:adj[top]){
                indegree[it]--;

                if(indegree[it]==0) q.push(it);
            }
        }

        return course==numCourses;
    }
};