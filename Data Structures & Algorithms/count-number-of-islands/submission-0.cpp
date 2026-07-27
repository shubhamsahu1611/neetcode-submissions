class Solution {
public:
    vector<vector<bool>> vis;
    vector<int> dir={1, 0, -1, 0, 1};
    void dfs(int i, int j, vector<vector<char>> &grid){
        if(vis[i][j]) return ;
        vis[i][j]=true;
        if(grid[i][j]=='0') return;
        for(int k=0;k<4;k++){
            int ni=i+dir[k];
            int nj=j+dir[k+1];
            if(ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size() && grid[ni][nj]=='1' && !vis[ni][nj]){
                dfs(ni, nj, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vis.assign(grid.size(), vector<bool>(grid[0].size(), false));
        int comp=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i, j, grid);
                    comp++;
                }
            }
        }
        return comp;
    }
};
