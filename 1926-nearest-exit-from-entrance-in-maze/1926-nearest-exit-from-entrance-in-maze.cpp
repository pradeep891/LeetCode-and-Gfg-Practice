class Solution {
public:
    
    bool valid(int x , int y ,vector<vector<char>>& maze ){        
        int n  = maze.size() , m = maze[0].size();
        if(x == n || y == m || y < 0 || x < 0) return false;
        if(maze[x][y] == '+') return false;
        maze[x][y] = '+';
        return true;        
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int x = entrance[0] , y = entrance[1];
        queue< pair<int , int> >q;
        
        int n  = maze.size() , m = maze[0].size();
        
        if(valid(x+1 , y , maze)) q.push({x+1 , y});
        if(valid(x-1 , y , maze)) q.push({x-1 , y});
        if(valid(x , y+1 , maze)) q.push({x , y+1});
        if(valid(x , y-1 , maze)) q.push({x , y-1});
        
        maze[x][y] = '+';
        int ans = INT_MAX;
        int level = 0;
        
        while(q.size()){
            int sz = q.size();
            level++;
            for(int i=0 ;i<sz; i++){
                x = q.front().first;
                y = q.front().second;
                q.pop();
                
                if(x==0 || y == 0 || x == n-1 || y == m-1) return level;

                if(valid(x+1 , y , maze)) q.push({x+1 , y});
                if(valid(x-1 , y , maze)) q.push({x-1 , y});
                if(valid(x , y+1 , maze)) q.push({x , y+1});
                if(valid(x , y-1 , maze)) q.push({x , y-1});

            }
        }
        return -1;
    }
};