#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int>v,v1;
    for(int i=0; i< n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int dem=1,i=0;
    while(v.size()!=0 || v1.size()!=0)
    {
        for(int i=0; i<v.size(); i++)
        {

            if(dem==m)
            {
                cout << v[i] << " ";
                v.erase(v.begin()+i, v.begin()+i+1);
                dem=0;
                i--;
            }
            else
            {
                v1.push_back(v[i]);
                v.erase(v.begin()+i,v.begin()+i+1);
                i--;
            }
            dem++;
        }
        if(v.empty())
        {
            v=v1;
            v1.clear();
        }
//        cout <<"dem ne: "<< dem << endl;
//        cout << "i ne: "<< i << endl;
//        if(dem==m)
//        {
//            cout << v[i]<< " ";
//            v.erase(v.begin()+i,v.begin()+i+1);
//            dem=1;
//            i--;
//        }
//        else
//        {
//            v1.push_back(v[i]);
//        }
//        dem++;
//        i++;
//        cout << "so phan tu con lai: "<< v.size()<< endl;
//        if(v.size()==0)
//        {
//            v=v1;
//            i=0;
//            v1.clear();
//
//        }
    }
    return 0;
}
