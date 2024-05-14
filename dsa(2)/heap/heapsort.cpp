#include<bits/stdc++.h>
using namespace std;
void maxheap(vector<int>&v,int idx){
    int l=2*idx+1;
    int r=2*idx+2;
    int largest=idx;
    if(l<v.size()&&v[l]>v[idx]){
        largest=l;
    }
    else{
        largest=idx;
    }
    if(r<v.size()&&v[r]>v[largest]){
        largest=r;
    }
    if(largest!=idx){
        swap(v[largest],v[idx]);
        maxheap(v,largest);
    }
}
void heapify(vector<int>&v){
    for(int i=v.size()-1;i>=0;i--){
        maxheap(v,i);
    }
}
void heapsort(vector<int>&v){
    for(int i=v.size()-1;i>0;i--){
        swap(v[0],v[i]);
        v.pop_back();
        maxheap(v,0);
    }   
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    heapify(v);
    heapsort(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

}