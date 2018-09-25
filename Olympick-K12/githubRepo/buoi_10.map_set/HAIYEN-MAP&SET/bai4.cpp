#include <bits/stdc++.h>

using namespace std;

void XoaMax(map <int,int> &a)
{
    map <int,int> ::iterator i=a.begin();
    int Max=-1e9;
    for (; i!=a.end(); i++){
        if ((*i).first>Max){
            Max=(*i).first;
        }
    }
    a[Max]=0;
}
void XoaMin(map <int,int> &a)
{
    map <int,int> ::iterator i=a.begin();
    int Min=1e9;
    for (; i!=a.end(); i++){
        if ((*i).first<Min){
            Min=(*i).first;
        }
    }
    a[Min]=0;
}

int main()
{
    int n;
    cin>>n;
    map <int,int> a;
    for (int i=1; i<=n; i++){
        int x,y;
        cin>>x;
        if (x==1){
            cin>>y;
            a[y]=1;
        }
        if (x==2){
            XoaMax(a);
        }
        if (x==3){
            XoaMin(a);
        }
    }
    for (map <int,int> :: iterator i=a.begin(); i!=a.end(); i++){
        if((*i).second==1){
            cout<<(*i).first<<" ";
        }
    }
    return 0;
}
