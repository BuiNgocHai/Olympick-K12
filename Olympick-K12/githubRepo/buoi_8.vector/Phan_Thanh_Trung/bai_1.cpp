#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m, val=1;
    cin >> n;
    int N=pow(n,2);
    if(n%2==0)
    {
        m=n/2;
    }
    else
        m=n/2+1;
    vector<int> v[n];
    //khoi tao ma tran vuong n*n phan tu voi cac phan tu =0;
    for(int i=0;i<n; i++)
    {
        vector<int>vect;
        for(int j=0; j<n; j++)
        {
            vect.push_back(0);
        }
        v[i]=vect;
    }
    int round=0;
    while(true)
    {
        for(int i=round; i<n-round; i++)
        {
            for(int j=round; j<n-round; j++)
            {
                v[i][j]=val;
                val++;
            }
            break;
        }
        for(int j=n-1-round; j>=0+round; j--)
        {
            for(int i=1+round;i<n-round; i++ )
            {
                v[i][j]=val;
                val++;
            }
            break;
        }
        for(int i=n-1-round; i>=0+round; i--)
        {
            for(int j=n-2-round; j>=0+round; j--)
                {v[i][j]=val;
                val++;
                }
            break;
        }
        for(int j=round; j<n-1-round; j++)
        {
            for(int i=n-2-round; i>=1+round; i--)
            {
                v[i][j]=val;
                val++;
            }
            break;
        }
        round++;
        if(round>m)
            break;
    }


    //xuat vector
    for(int i=0; i< n; i++)
    {
        for(int j=0; j< v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
