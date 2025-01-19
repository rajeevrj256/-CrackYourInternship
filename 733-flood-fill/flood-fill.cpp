class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        if (image[sr][sc] == color) return image;
    
        queue<pair<int,int>>q;
        q.push({sr,sc});
    
        int dx[4]={0,0,1,-1};
        int dy[4]={-1,1,0,0};
        int originalColor = image[sr][sc];
        image[sr][sc] = color;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m &&  image[nx][ny]==originalColor){
                    
                image[nx][ny]=color;
                q.push({nx,ny});
                }


            }
        }

        return image;

    }
};