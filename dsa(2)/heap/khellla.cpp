#include<bits/stdc++.h>
using namespace std;
vector<int>BFS(vector<int>v[],int node,int n){
    //vector<int>visited(n,0);
    //visited[n]={0};
    int visited[n+1]={0};
    visited[node]=1;
    queue<int>q;
    q.push(node);
    vector<int>bfs;
    while(!q.empty()){
        int khela=q.front();
        q.pop();
        bfs.push_back(khela);
        for(int val:v[khela]){
            if(visited[val]!=1){
                visited[val]=1;
                q.push(val);
            }
        }
    }
    return bfs;
}
int main(){
    int n,m,u,v;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start=1;
   vector<int>result= BFS(adj,start,n);
//    for(int i=0;i<result.size();i++){
//     cout<<result[i]<<" ";
//    }
  for (int node : result) {
        cout << node << " ";
    }
}