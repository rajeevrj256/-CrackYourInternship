class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>hash(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});

        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;

            if(word==endWord) return step;
            q.pop();

            for(int i=0;i<word.size();i++){
            char letter=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(hash.find(word)!=hash.end()){
                        q.push({word,step+1});
                        hash.erase(word);

                    }
                }
                word[i]=letter;
            }
        }
        return 0;

    }
};