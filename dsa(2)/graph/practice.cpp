//number of provinces

#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>adj[],int visit[]){
    visit[node]=1;
    for(int val : adj[node]){
        if(!visit[val]){
        dfs(val,adj,visit);
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    vector<int>adj[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1&&i!=j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int visit[n]={0};
    int count=0;
    for(int i=0;i<n;i++){
        if(!visit[i]){
            count++;
            dfs(i,adj,visit);
        }
    }
    cout<<count<<endl;
}
