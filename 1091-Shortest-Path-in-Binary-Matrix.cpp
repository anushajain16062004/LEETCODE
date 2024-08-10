class Solution {
public:

    bool isValid(int i,int j,vector<vector<int>>& grid){
        int n=grid.size();
        n=grid[0].size();
        return i>=0 and j>=0 and i<n and j<n and grid[i][j]==0;
    }


    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        n=grid[0].size();

        if(grid[0][0]==1 or grid[n-1][n-1]==1){return -1;}

        vector<pair<int,int>>directions={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        int ans=1;

        while(!q.empty()){
            int t=q.size();

            for(int i=0;i<t;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();

                if(x==n-1 and y==n-1){
                    return ans;
                }

                for(auto&it:directions){
                    int newX=x+it.first;
                    int newY=y+it.second;

                    if(isValid(newX,newY,grid)){
                        q.push({newX,newY});
                        grid[newX][newY]=1;
                    }
                }
            }
            ans++;
        }
        
        return -1;
    }
};