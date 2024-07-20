class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        
        
        vector<vector<string> >ans;
        unordered_map <string,vector<string>>hash;
        
        for(int i=0;i<string_list.size();i++){
            string s=string_list[i];
            sort(s.begin(),s.end());
            hash[s].push_back(string_list[i]);
        }
        
        for(auto i:hash){
            ans.push_back(i.second);
        }
        return ans;
    }
    
};