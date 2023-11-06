#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1000000
#define f first
#define s second
typedef pair<ll,ll>PII;
 
pair<ll,bool> prim(vector<vector<PII>>graph,int N)
{
    ll minCost=0;
    vector<bool>marked(N,false);
    priority_queue<PII>que;
    que.push({0,0});
   // marked[0]=true;
    while(!que.empty())
    {
        PII myPair=que.top();
        que.pop();
        ll u=myPair.s;
        if(marked[u])
        continue;
        minCost+=abs(myPair.f);
        marked[u]=true;
        for(int i=0;i<graph[u].size();i++)
        {
            ll v=graph[u][i].f;
            ll w=graph[u][i].s;
            if(marked[v]==false)
            {
                que.push({-w,v});
            }
        }
    }
    bool flag = true;
    for(int i=0;i<N;i++) {
        if(marked[i] == false) {
            flag = false;
            break;
        }
    }
    pair<ll,bool>myPair;
    myPair.first = minCost;
    myPair.second = flag;
    return myPair;
}
 
int main()
{
    int T;
    cin>>T;
    while(T--) {
    //code starts here
    int N,M;
    cin>>N>>M;
    ll X,Y,W;
    vector<vector<PII>>adj(N);
    for(int i=0;i<M;i++)
    {
        cin>>X>>Y>>W;
        adj[X-1].push_back({Y-1,W});
        adj[Y-1].push_back({X-1,W});
    }
    pair<ll,bool> rslt=prim(adj,N);
    if(rslt.second) {
        cout<<rslt.first<<endl;
    }
    else {
        cout<<"Need More Dealers"<<endl;
    }
    //code ends here
    }
    return 0;
}
