#include<bits/stdc++.h>
class segmentTree
{
public:
 vector<int>seg;
    segmentTree(int n=0){ 
        seg.resize(n*4);
    }
    void build(int i,int low,int high,int arr[]){
        if(low==high){
            seg[i]=arr[low];
            return;
        }
        int mid=(low+high)/2;
    build(2*i+1,low,mid,arr);
    build(2*i+2,mid+1,high,arr);
    seg[i]=(seg[2*i+1]+seg[2*i+2]);
    // seg[i]=min(seg[2*i+1],seg[2*i+2]);
    // seg[i]=max(seg[2*i+1],seg[2*i+2]);
    // it can be changed according to the 
    // operation needed in the question
    }
    int query(int i,int low,int high,int l,int r){
        if(high<l or r<low)return 0;
        if(l<=low and r>=high)return seg[i];
        // else call left and right and return the ans;
        int mid=(low+high)/2;
    int left=query(2*i+1,low,mid,l,r);
    int right=query(2*i+2,mid+1,high,l,r);
    return (left+right);
    // return min(left,right);
    // return max(left,right);
    }
       void update(int i,int low,int high,int val,int idx){
        if(low==high and low==idx){
            seg[i]=val;
            return;
        }
    //     if(idx>=low and idx<=high){
    //     int mid=(low+high)/2;
    // update(2*i+1,low,mid, val, idx);
    // update(2*i+2,mid+1,high, val, idx);
    // seg[i]=(seg[2*i+1]+seg[2*i+2]);
    //     }
    int mid=(low+high)/2;
    if(idx<=mid){
        update(i*2+1,low,mid-1,val,idx);
    }
    else 
        update(i*2+2,mid+1,high,val,idx);
    seg[i]=(seg[i*2+1]+seg[i*2+2]);
       }
};

class frequencyTree
{
public:
 vector<unordered_map<int,int>>seg;
    frequencyTree(int n=0){ 
        seg.resize(n*4);
    }
    void build(int i,int low,int high,int arr[]){
        if(low==high){
            seg[i][arr[low]]++;;
            return;
        }
        int mid=(low+high)/2;
    build(2*i+1,low,mid,arr);
    build(2*i+2,mid+1,high,arr);
    for(auto k:seg[2*i+1]){
        seg[i][k.first]+=k.second;
    }
    for(auto k:seg[2*i+2]){
        seg[i][k.first]+=k.second;
    }
    }
    int query(int i,int low,int high,int l,int r,int val){
        if(high<l or r<low)return 0;
        if(l<=low and r>=high)return seg[i][val];
        // else call left and right and return the ans;
        int mid=(low+high)/2;
    int left=query(2*i+1,low,mid,l,r);
    int right=query(2*i+2,mid+1,high,l,r);
    return (left+right);
    // return min(left,right);
    // return max(left,right);
    }
       void update(int i,int low,int high,int val,int idx){
        if(low==high and low==idx){
            seg[i]=val;
            return;
        }
    //     if(idx>=low and idx<=high){
    //     int mid=(low+high)/2;
    // update(2*i+1,low,mid, val, idx);
    // update(2*i+2,mid+1,high, val, idx);
    // seg[i]=(seg[2*i+1]+seg[2*i+2]);
    //     }
    int mid=(low+high)/2;
    if(idx<=mid){
        update(i*2+1,low,mid-1,val,idx);
    }
    else 
        update(i*2+2,mid+1,high,val,idx);
    seg[i]=(seg[i*2+1]+seg[i*2+2]);
       }
};

// range frequency queries
// store hashmap on each node




// open bracket and closed brackets in a range

class Node{
    int open,close,full;
    Node(int o=0,int c=0,int f=0){
        open=o;
        close=c;
        full=f;
    }
}

class bracket
{
public:
    vector<Node>seg;
    bracket(int n){
        seg.resize(4*n);
    }
    void build(int i,int low,int high,string &s){
        if(low==high){
            seg[i].open=(s[low]=='(');
            seg[i].close=(s[low]==')');
        }
        // call left ,right
        int mid=(low+high)/2;
        build(i*2+1,low,mid,s);
        build(i*2+1,mid+1,high,s);
        seg[i].full=(seg[i*2+1].full+seg[i*2+2].full+min(seg[i*2+1].open,seg[i*2+2].close));
        seg[i].open=(seg[i*2+1].open+seg[i*2+2].open-min(seg[i*2+1].open,seg[i*2+2].close));
        seg[i].close=(seg[i*2+1].close+seg[i*2+2].close-min(seg[i*2+1].open,seg[i*2+2].close));
    }

    int query(int i,int low,int high,int l,int r){
       if(r<low or l>high)return 0;
       if(low>=l and high<=r)return seg[i];
    int mid=(low+high)/2;
    int left=query(i*2+1,low,mid,l,r);
    int right=query(i*2+1,mid+1,right,l,r);
    return left+right;
    }

};
 int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    segmentTree st(s.size());
    while(n--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        cout<<st.query(0,0,s.size()-1,l,r)<<'\n';
    }
 }
