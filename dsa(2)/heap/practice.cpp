//build max heap from given array


#include<bits/stdc++.h>
using namespace std;
void maxheapify(vector<int>&v,int idx){
int l=2*idx+1;
int r=2*idx+2;
int largest=idx;
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
void build_heap(vector<int>&v){
for(int i=floor(v.size()/2)-1;i>=0;i--){
    maxheapify(v,i);
}
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    build_heap(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}
