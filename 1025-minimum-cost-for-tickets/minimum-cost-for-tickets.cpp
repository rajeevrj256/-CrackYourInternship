class Solution {
public:
    int t[365][1000];
    int solve(vector<int>&days,vector<int>&costs,int valid,int index){
        if(index>=days.size())return 0;
        //three differnt ways;

        if (days[index] <= valid) 
            return t[index][valid] = solve(days, costs, valid, index + 1);
        if(t[index][valid]!=-1)return t[index][valid];
        int ticket_1_day_pass=costs[0]+solve(days,costs,days[index],index+1);
        
       
        int ticket_7_day_pass=costs[1]+solve(days,costs,days[index]+6,index+1);
    
       
       
        int ticket_30_day_pass=costs[2]+solve(days,costs,days[index]+29,index+1);

        return t[index][valid]=min({ticket_1_day_pass,ticket_7_day_pass,ticket_30_day_pass});
    



    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(t,-1,sizeof(t));
        return solve(days,costs,0,0);
    }
};