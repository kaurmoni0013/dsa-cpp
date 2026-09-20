#include<bits/stdc++.h>
using namespace std;

void BFS(int start, vector<vector<int>> graph, int V){
    vector<bool> visited(V, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        int current = q.front();
        q.pop();
        cout<<current<<" ";
        for(int neighbor: graph[current]){ 
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

}

int main(){

    int V, E;
    cout<<"Enter number of Vertices: ";
    cin>>V;

    vector<vector<int>> graph(V);

    cout<<"Enter number of Edges: ";
    cin>>E;

    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout<<endl;

    int start;
    cout<<"Enter starting node: ";
    cin>>start;

    BFS(start, graph, V);

    return 0;
}