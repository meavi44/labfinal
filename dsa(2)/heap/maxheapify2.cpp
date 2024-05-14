//maxheapify via array
//this logic is only applicable when the index is given 
#include<bits/stdc++.h>
using namespace std;
void maxheapify(vector<int>&v,int idx){
int l=2*idx+1;
int r=2*idx+2;
int largest=0;
if(l<=v.size()&&v[l]>v[idx]){
    largest=l;
}
else{
    largest=idx;
}
if(r<=v.size()&&v[r]>v[largest]){
    largest=r;
}
if(largest!=idx){
    swap(v[largest],v[idx]);
    maxheapify(v,largest);
}

}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    maxheapify(v,0);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}