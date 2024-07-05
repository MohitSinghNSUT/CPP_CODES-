#include<bits/stdc++.h>
#define for(i,n) for(int i=0;i<n;i++)
class DisjointSet
{
 vector<int>rank,parent,size;
public:
    DisjointSet(int n){
        rank.clear();
        parent.clear();
        rank.resize(n+1);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            size[i]=1;
            parent[i]=i;
        }
    }
    int findparent(int n){
        if(parent[n]==n)return n;
    return parent[n]=findparent(parent[n]);
    }
    
    void  union_rank(int u,int v){
        int p1=findparent(u);
        int p2=findparent(v);
        if(p1==p2)return;
     if(rank[p1]==rank[p2]){
        parent[p1]=p2;
        rank[p1]++;
    }
    else if(rank[p1]<rank[p2]){
        parent[p1]=p2;
    }
    else{
        parent[p2]=p1;
    }

    }
    void union_size(int u,int v){
    int p1=findparent(u);
    int p2=findparent(v);
    if(p1==p2)return;
    if(size[p1]<size[p2]){
        parent[p1]=p2;
        size[p2]+=size[p1];
    }
    else{
        parent[p2]=p1;
        size[p1]+=size[p2];
    }
    }
};

