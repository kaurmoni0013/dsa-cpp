/*
Problem: Rat in a Maze
Platform: GFG
Difficulty: Medium
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:

    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};
    string dir = "UDLR";
        
    bool valid(int i ,int j ,int n){
        return i>=0 && j>=0 && i<n && j<n;
    }

    void Total(vector<vector<int>>& matrix ,int i,int j, int n,string& path, vector<vector<int>>& visited,vector<string>& ans){

        if(i == n-1 && j == n-1){
            ans.push_back(path);
            return;
        }

        visited[i][j] = 1;
        for(int k=0 ; k<4; k++){
             if(valid(i+row[k],j+col[k],n) && matrix[i+row[k]][j+col[k]] && !visited[i+row[k]][j+col[k]]){
                path.push_back(dir[k]);
                Total(matrix,i+row[k],j+col[k],n,path,visited,ans);
                path.pop_back();
             }
        }
        visited[i][j] = 0;

    }
};

int main() {

    Solution obj;

    vector<vector<int>> maze = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };

    int n = maze.size();

    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<string> ans;
    string path =""; 
    if(maze[0][0] == 0 || maze[n-1][n-1] == 0){
    cout<<"There is no Path"<<endl;
    return 0;
    }
    obj.Total(maze, 0, 0, n,path, visited, ans);

    if(ans.empty())
    cout << "No Path Found";
    else
    {
        for(string s : ans)
            cout << s << endl;
    }

    return 0;
}