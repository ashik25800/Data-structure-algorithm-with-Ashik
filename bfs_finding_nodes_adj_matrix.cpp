#include<bits/stdc++.h>
using namespace std;



bool finding_element(char source,char terget,bool *a,int nodes_siz,map<char,int> mp,string nodes)
{
    bool vis[nodes_siz];
    for(int i = 0;i<nodes_siz;i++)
        vis[i] = false;

    queue<char> que;
    que.push(source);
    vis[mp[source]] = true;
    cout<<"Here's the list :";
    while(!que.empty())
    {
        if(que.front() == terget)
            return true;
        char ch = que.front();
        for(int i=0;i<nodes.length();i++)
        {
            if((*((a+mp[ch]*nodes_siz)+i)) == true && !vis[i])
            {
                que.push(nodes[i]);
                vis[i] = true;
            }
        }
        
        cout<<" "<<que.front();

        que.pop();
    }


    return false;

}



void maker(int siz,bool *a)
{
    for(int i=0;i<siz;i++)
        for(int j=0;j<siz;j++)
            *((a+i*siz)+j) = false;
}

 int main()
 {
    string nodes;
    cin>>nodes;

    map<char,int> mp;
    for(int i=0;i<nodes.length();i++)
        mp[nodes[i]] = i;
    int siz = nodes.length();


    bool arr[siz][siz]; //adj matrix
    maker(siz,(bool *)arr);

    string edges;
    cout<<"Format : (x,y)"<<endl;
    while(1)
    {
        cin>>edges;
        if(edges == "end")
            break;
        arr[mp[edges[0]]][mp[edges[2]]] = true;
        arr[mp[edges[2]]][mp[edges[0]]] = true;
    }

    



  


    //local ----------------------------
    cout<<"   ";
    for(int i=0;i<nodes.length();i++)
        cout<<nodes[i]<<" ";cout<<endl;
    for(int i=0;i<=nodes.length()*2+1;i++)
        cout<<"_";cout<<endl;

    for(int i=0;i<nodes.length();i++)
    {
        cout<<nodes[i]<<"| ";
        for(int j=0;j<nodes.length();j++)
        {
            cout<<arr[mp[nodes[i]]][mp[nodes[j]]]<<" ";
        }cout<<endl;
    }




    cout<<endl;

    while(1)
    {
            char ch,ch1;
        cin>>ch>>ch1;

        cout<<endl;
        cout<<finding_element(ch,ch1,(bool *) arr,nodes.length(),mp,nodes)<<endl;
    }


    

    return 0;
 }
