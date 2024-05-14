
//for storing input we use matrix here

#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m,u,v;
cin>>n>>m;
int arr[n+1][m+1];
for(int i=0;i<m;i++){
    cin>>u>>v;
    arr[u][v]=1;
    arr[v][u]=1;

}
}


//for storing input we use vector here

#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m,u,v;
cin>>n>>m;
vector<int>vec[n+1]={0};
for(int i=0;i<m;i++){
    cin>>u>>v;
    vec[u].push_back(v);
    vec[v].push_back(u);

}
}