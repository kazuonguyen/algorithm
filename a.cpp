#include <bits/stdc++.h>
using namespace std;
queue <int> q;
int fre[10000],par[1000],s,m,n,f;
vector <int> a[10000];

void docf(){
    cin>>m>>n>>s>>f;
    int u,v;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
     }
}
void BFS(int s){
    q.push(s);
    while(!q.empty()){
        int u =  q.front();
        q.pop();
        fre[u]=0;
        for(int j=0;j<a[u].size();j++){
            int v = a[u][j];
            if(fre[v]){
                q.push(v);
                par[v]=u;
            }
        }
    }
    
}
void truyvet(int f){
    if(f==s){
        cout<<f<<" ";
    }
    else{
        if(par[f]==-1)  cout<<"No hope :<";
        else{
            truyvet(par[f]);
            cout<<f<<" ";
        }
    }
}
int lienthong(){
    int slt=0;
    for(int i=1;i<=n;i++){
    if(fre[i]){
        slt++;
        BFS(i);
    }
}
    return slt;
}
int main(){
    docf();
    memset(par,-1,sizeof(par));
        memset(fre,1,sizeof(fre));
    cout<<"\n"<<lienthong();
    return 0;
}