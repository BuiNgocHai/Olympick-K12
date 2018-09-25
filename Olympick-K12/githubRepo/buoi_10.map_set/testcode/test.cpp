#include <bits\stdc++.h>

using namespace std;
map <int,int> CNTT;
map <int,int> DT;
int main()
{
    int n; cin>>n;
    int m; cin>>m;
     for(int i=0;i<n;i++){
        int temp; cin>> temp;
        CNTT[temp]++;
      }
      for( int i=0;i<m;i++){
        int temp; cin>>temp;
        DT[temp]++;
      }
    map <int,int>:: iterator it=CNTT.begin();
    map <int,int>:: iterator tt=DT.begin();
    int x=0,y=0;
    for( ;it!=CNTT.end();it++)
    {
        for( ;tt!=DT.end();tt++)
        {
            if((*it).first == (*tt).first){
                x=(*it).second * (*tt).second;

            }
        }

          cout<<x<<" ";
    }


    return 0;
}

