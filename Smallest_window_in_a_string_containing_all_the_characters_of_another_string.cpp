class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int m[256]={0};
        int ans=INT_MAX;
        int start=0;
        int count=0;
        for(int i=0;i<p.size();i++){
            if(m[p[i]]==0){
                count++;
            }
            m[p[i]]++;
        }
        int j=0;
        int i=0;
        
        while(j<s.size()){
            m[s[j]]--;
            if(m[s[j]]==0){
                count--;
            }
            
            if(count==0){
                while(count==0){
                    if(ans> j-i+1){
                        ans=min(ans,j-i+1);
                        start=i;
                    }
                    m[s[i]]++;
                    if(m[s[i]]>0){
                        count++;
                    }
                    i++;
                }
            }
            j++;
        }
        if(ans!=INT_MAX){
            return s.substr(start,ans);
        }
        else {
            return "-1";
        }
        
    }
};
