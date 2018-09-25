
#include <bits/stdc++.h>
#include <vector>
//nhap vao theo hing xoan oc

using namespace std;

int main()
{

    int n;
    vector <int> a[1000];
    cin>>n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            a[i].push_back(1);
        }
    }
    int dem=1,vtri1=0;
    while ((dem<n*n)&&(dem!=n*n)){
    for (int i=vtri1; i<a[vtri1].size()-vtri1-1; i++){
        a[vtri1][i]=dem;
        dem++;
    }
    for (int i=vtri1;i<a[vtri1].size()-vtri1-1; i++){
        a[i][a[i].size()-vtri1-1]=dem;
        dem++;
    }
    for (int i=a[vtri1].size()-vtri1-1; i>vtri1; i--){
        a[a[vtri1].size()-vtri1-1][i]=dem;
        dem++;
    }
    for (int i=a[vtri1].size()-vtri1-1; i>vtri1; i--){
        a[i][vtri1]=dem;
        dem++;
    }

        vtri1++;
    }
    if (dem==n*n){
        a[(n-1)/2][(n-1)/2]=n*n;
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<a[i].size(); j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
