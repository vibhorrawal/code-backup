#include<bits/stdc++.h>
using namespace std;

vector<int>g[600], g2[600];
int val[600], v, e;
bool sign[600];

int BFS1(int u){

    int tot = 0;
    bool sign1[600];
    memset(sign1, true, sizeof sign1);
    queue<int>q;
    q.push(u);
    sign1[u] = false;

    while( !q.empty() ){

        int u1 = q.front();
        q.pop();
        for(auto v : g[u1]){
            if(!sign1[v]) continue;
            tot += val[v];
            q.push(v);
            sign1[v] = false;
        }
    }
    return tot;
}

int BFS2(int u){

    int tot = 0;
    bool sign1[600];
    memset(sign1, true, sizeof sign1);
    queue<int>q;
    q.push(u);
    sign1[u] = false;
    sign[u] = false;
    while( !q.empty() ){
        int u1 = q.front();
        q.pop();
        for(auto v : g2[u1]){
            if(!sign1[v]) continue;
            sign[v] = sign1[v] = false;
            q.push(v);
        }
    }

    for(int i = 1; i <= v; i++){
        if(sign[i]) tot += val[i];
    }
    return tot;
}

int main(){
    int cas = 1;
    while( scanf("%d%d",&v,&e) == 2 ){
        if(e == 0 && v == 0) break;
        for(int i = 1; i <= v; i++) scanf("%d",&val[i]);

        while( e-- ){
            int u1, v1;
            scanf("%d%d",&u1,&v1);
            g[u1].push_back(v1);
            g2[v1].push_back(u1);
        }

        int q;
        scanf("%d",&q);
        printf("Case #%d:\n",cas++);
        while(q--){
            int x;
            memset(sign, true, sizeof sign);
            scanf("%d",&x);
            int mini = BFS1(x);
            int maxi = BFS2(x);
            printf("%d\n",abs(maxi-mini));
        }
        printf("\n");

        for(int i = 0; i <= v; i++){
            g[i].clear();
            g2[i].clear();
        }
    }
return 0;
}
