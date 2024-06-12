#include<bits/stdc++.h>
using namespace std;
int main(){
    int f[20]={1,1};
    for(int n=2;n<20;n++){
        f[n]=f[n-1]+f[n-2];
    }
    for(int i=0;i<20;i++){
        cout<<f[i]<<endl;
    }
    return 0;
}
