class Solution {
public:

    int dfs(int i,int j,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        int count=0;

        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]==0){return 0;}

        if(grid[i][j]==-1){return 0;}

        grid[i][j]=-1;
        count++;

        count+=dfs(i+1,j,grid);
        count+=dfs(i-1,j,grid);
        count+=dfs(i,j+1,grid);
        count+=dfs(i,j-1,grid);
        
        return count;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans=max(ans,dfs(i,j,grid));
                }
            }
        }

        return ans;
    }
};