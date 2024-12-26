class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0;i<asteroids.size();i++){
            bool explode=false;
            while(!st.empty() && asteroids[i]<0 &&  asteroids[st.top()]>0){
                if(abs(asteroids[i])>abs(asteroids[st.top()])){

                st.pop();

                }else if(abs(asteroids[i])==abs(asteroids[st.top()])){

                    st.pop();
                    explode=true;
                    break;

                }else{
                    explode=true;
                    break;
                }
            }
            if(!explode){

            st.push(i);
            }
        }

        vector<int>ans;
        while(!st.empty()){
            ans.push_back(asteroids[st.top()]);
            st.pop();
        }
       reverse(ans.begin(),ans.end());
        return ans;
    }
};