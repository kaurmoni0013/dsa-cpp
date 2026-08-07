#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void directed_un_weighted_Graph(){
    int u,v;
vector<vector<int>>adMat(v,vector<int>(v,0));
cout<<"Enter (u,v):\n";
cin>>u>>v;
adMat[u][v] = 1;
}

void un_weighted_Graph(){
    int u,v;
vector<vector<int>>adMat(v,vector<int>(v,0));
cout<<"Enter (u,v):\n";
cin>>u>>v;
adMat[u][v] = 1;
adMat[v][u] = 1;
}

void undirected_weighted_Graph(){
    int u,v,w;
vector<vector<int>>adMat(v,vector<int>(v,0));
cout<<"Enter (u,v,w):\n";
cin>>u>>v>>w;
adMat[u][v] = w;
adMat[v][u] = w;
}



