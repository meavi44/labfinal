//dfs

#include<bits/stdc++.h>
using namespace std;
void DFS(vector<int>v[],int node,vector<int>&dfs,vector<int>&visit){
    visit[node]=1;
    dfs.push_back(node);
    
    for(int val : v[node]){
        if(visit[val]!=1){
            DFS(v,val,dfs,visit);
        }           
    }
    
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>arr[n+1];
    vector<int>visit(n+1,0);
    vector<int>dfs;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
    arr[u].push_back(v);
    arr[v].push_back(u);
    }
   DFS(arr,1,dfs,visit);
    for(int i=0;i<dfs.size();i++){
        cout<<dfs[i]<<" ";
    }

}