class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
    
        int m = grid.size() ; 
        
        if (m==0)
            return  0 ;
        
        int n = grid[0].size() ; 
        
         
        
        bool vis[m][n] ;
        int pt = 0 ;
        
        queue<pair<int,int>> d ; 
        queue<pair<int,int>> q  ;
        
        for (int i = 0 ; i<m ; i++)
            for(int j =0 ; j<n ; j++)
            {
                vis[i][j] = false ; 
                if (grid[i][j]== '1' )
                {   
                    d.push(make_pair(i,j)) ;
                    pt ++ ; 
                }
            }
        
        
        int ctt = 0 ; 
        
        while(!d.empty())
        {
        
            int sr = d.front().first ;
            int sc = d.front().second ; 
            d.pop() ;
            
           if (!vis[sr][sc])
           {
                vis[sr][sc] = true ;
                q.push(make_pair(sr,sc)) ;
                int e[4][2] = {{1,0},{-1,0},{0,1},{0,-1}} ; 
        
                while(!q.empty())
                {
                    
                    int r = q.front().first ; 
                    int c = q.front().second ; 
                    q.pop() ; 
                
                    for (int k = 0 ; k<4 ; k++) 
                    {
                        int x = r + e[k][0] ; 
                        int y = c + e[k][1] ; 
                
                        if (x>=0 && y>=0 && x<m && y<n && grid[x][y] == '1' && !vis[x][y])
                        {
                            vis[x][y] = true ;   
                            q.push(make_pair(x,y)) ;  
                        } 
                
                    }   
                }
               ctt++ ; 
            }
            
            
        }
        
     return ctt ; 
    }
};
