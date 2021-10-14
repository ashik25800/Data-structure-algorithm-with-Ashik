#include<bits/stdc++.h>
using namespace std;

void bfs(int source,int destination,vector<int> v[],bool vis[],int sequence[])
{
    queue<int> q;
    q.push(source);
    vis[source] = true;

    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        for(int i=0;i<v[temp].size();i++)
        {

            if(!vis[v[temp][i]])
            {           vis[v[temp][i]] = true;
                        sequence[v[temp][i]] = temp;
                        q.push(v[temp][i]);
            }
        }
    }

}

void printing_shortest_path(string node,int sequence[],int terget)
{
    int temp = terget;
    if(sequence[terget] == -1)
    {
        
        return;
    }

    temp = terget;
    printing_shortest_path(node,sequence,sequence[terget]);
    cout<<node[temp]<<" ";
}

int main()
{
    string node;
    cin>>node;
    string  xx = node;

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
    int sequence[siz];

    for(int i=0;i<siz;i++)
        sequence[i] = -1;


    for(int i=0;i<siz;i++)
        vis[i] = false;

    char source,destination;
    cin>>source;
    cin>>destination;
    


    bfs(mp[source],mp[destination],v,vis,sequence);

    

    if(vis[mp[destination]])
    {
        cout<<source<<" ";
        printing_shortest_path(xx,sequence,sequence[mp[destination]]);
        cout<<destination<<endl;
    }
    else cout<<"Fuck off"<<endl;
   
}



    return 0;
}
