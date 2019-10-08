#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    int tc;cin>>tc;
    while(tc--){
        string s;cin>>s;
        random_shuffle(s.begin(),s.end());
        cout<<s<<endl;
    }
}
