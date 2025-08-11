#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e5;
vector<int> Tree[MAX];
int up[MAX][20];

void binary_lifting(int v, int p){
    up[v][0] = p;
    for(int i = 1; i<20; i++){
        if(up[v][i-1]!=-1){
            up[v][i] = up[up[v][i-1]][i-1];
        }
        else up[v][i] =  -1;
    }
    for(int u:Tree[v]){
        if(u!=p){
            binary_lifting(u, v);
        }
    }
}

int ans_query(int node, int k){
    if(node==-1 || k==0) return node;

    for(int i = 19; i>=0; i--){
        if(k>=(1<<i)){
            return ans_query(up[node][i], k-(1<<i));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long t, n, m, x, i, j, k, q;
    t = 1;
    while(t--){
        cin>>n>>q;
        for(int i = 2; i<n+1; i++){
            cin>>x;
            Tree[x].push_back(i);
            Tree[i].push_back(x);
        }
        binary_lifting(1, -1);
        while(q--){
            int node, k;
            cin>>node>>k;
            cout<<ans_query(node, k)<<'\n';
        }
    }
    return 0;
}