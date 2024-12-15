class Solution {
public:
    double gain(int p,int t){
        return (double)(p+1)/(t+1)-(double)p/t;
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>>pq;

        for(auto& cls :classes){
            pq.push({gain(cls[0],cls[1]),{cls[0],cls[1]}});
        }

        while (extraStudents--){
            auto [g,pt]=pq.top();
            pq.pop();
            int p=pt.first;
            int t=pt.second;
            pq.push({gain(p+1,t+1),{p+1,t+1}});
        }

        double sum=0;
        while(!pq.empty()){
            auto [g,pt]=pq.top();
            pq.pop();
            sum+=(double)pt.first/pt.second;
        }

        return sum/classes.size();
    }
};