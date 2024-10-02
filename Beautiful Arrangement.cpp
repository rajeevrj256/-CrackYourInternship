class Solution {
public:
    void backtracking(int n,int pos,vector<bool>used,int& cnt){
        if(pos>n){
            cnt++;
            return;
        }
        for(int i=1;i<=n;i++){
            if(!used[i] && (i%pos==0 || pos %i==0)){
            used[i]=true;
            backtracking(n,pos+1,used,cnt);
            used[i]=false;
            }
        }
    }
    int countArrangement(int n) {
        vector<bool>used(n+1,false);
        int cnt=0;
        backtracking(n,1,used,cnt);
        return cnt;
    }
};