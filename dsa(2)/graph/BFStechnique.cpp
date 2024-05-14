//bfs

#include<bits/stdc++.h>
using namespace std;
vector<int>BFS(vector<int>v[],int n,int start){
    int visited[n+1]={0};
    queue<int>q;
    visited[start]=1;
    q.push(start);
    vector<int>bfs;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(int val:v[node]){
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
vector<int>vec[n+1];
for(int i=0;i<m;i++){
    cin>>u>>v;
    vec[u].push_back(v);
    vec[v].push_back(u);

}
int start =5;
vector<int>res=BFS(vec,n,start);
for(int i=0;i<res.size();i++){
    cout<<res[i]<<" ";
}
}