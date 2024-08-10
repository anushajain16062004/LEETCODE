class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        if(n==0){return 0;}
        int m=heights[0].size();
        if(m==0){return 0;}

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        vector<vector<int>>distance(n,vector<int>(m,INT_MAX));
        distance[0][0]=0;

        pq.push({0,{0,0}}); // diff,{row,col}

        vector<vector<int>>directions={{-1,0},{0,-1},{1,0},{0,1}};

        while(!pq.empty()){
            int diff=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();

            if(x==n-1 and y==m-1){
                return diff;
            }

            for(const auto&dir:directions){
                int newX=x+dir[0];
                int newY=y+dir[1];

                if(newX>=0 and newY>=0 and newX<n and newY<m){
                    int newEffort=max(abs(heights[x][y]-heights[newX][newY]),diff);
                    if(newEffort<distance[newX][newY]){
                        distance[newX][newY]=newEffort;
                        pq.push({newEffort,{newX,newY}});
                    }
                }
            }
        }

        return -1;
    }
};