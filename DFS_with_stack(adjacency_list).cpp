#include<bits/stdc++.h>
using namespace std;

void dfs(int source,int destination,vector<int> v[],bool vis[])
{
    stack<int> s;
    s.push(source);
    vis[source] = true;

    while(!s.empty())
    {
        if(vis[destination])
            break;


        int temp = s.top();
        s.pop();
        for(int i=0;i<v[temp].size();i++)
        {
            if(!vis[v[temp][i]])
                s.push(v[temp][i]);
            vis[v[temp][i]] = true;
        }
    }
}

int main()
{
    string node;
    cin>>node;

    map<char,int> mp;

    int siz = node.size();
    for(int i=0;i<siz;i++)
        mp[node[i]] = i;

    vector<int> v[siz];

    while(1)
    {
        cin>>node;
        if(node[0] == '*')
            break;
        v[mp[node[0]]].push_back(mp[node[1]]);
        v[mp[node[1]]].push_back(mp[node[0]]);
    }
    while(1)
{
    bool vis[siz];
    for(int i=0;i<siz;i++)
        vis[i] = false;

    char source,destination;
    cin>>source;
    cin>>destination;
    


    dfs(mp[source],mp[destination],v,vis);

    

    if(vis[mp[destination]])
        cout<<"Yes line clear"<<endl;
    else cout<<"Fuck off"<<endl;
}



    return 0;
}
