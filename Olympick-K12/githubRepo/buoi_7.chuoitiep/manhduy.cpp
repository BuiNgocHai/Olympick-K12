#include<bits\stdc++.h>
 using namespace std; 
  int main () 
     {  string a="hackerrank"; 
       int n,i; 
        cin>>n; 
         for(i=0;i<n;i++) { 
            string s; int j=0,vt=0,vt1,dem=0;
            cin>>s;
             for(j=0;j<a.length();j++){
				 if(s.find(a[j],vt)==-1){
			    dem=0;
				 break;
				 }else{
				 	dem++;
				 	vt1=s.find(a[j],vt);
				 	vt=vt1+1;
				 	
				 }
             	
			 }
			 if(dem==10)
			 cout<<"YES"<<endl;
			 else
			 cout<<"NO"<<endl;  
             
		 }
       return 0;
	 }
    
