#include<bits/stdc++.h>
inline double degrees(double x){return x*180.0/M_PI;}
inline double rad    (double x){return x*M_PI/180.0;}
using namespace std;
int main(){
    freopen("robot.in","r",stdin);
    int tc;cin>>tc;
    while(tc--){
        double l0,l1,l2,l3;
        cin>>l0>>l1>>l2>>l3;
        double X,Y,Z;
        cin>>X>>Y>>Z;
        Z = rad(Z);
        double t1,t2,a,b,c;
        a = Y -l3*cos(Z) -l0;
        b = X -l3*sin(Z);
        c = (a*a+b*b+l1*l1-l2*l2)*0.5/l1;
        assert(c*c <= b*b + a*a);
        double T1[]={atan2(b*c+a*sqrt(a*a+b*b-c*c),a*c-b*sqrt(a*a+b*b-c*c)),atan2(b*c-a*sqrt(a*a+b*b-c*c),a*c+b*sqrt(a*a+b*b-c*c))};
        double T2[]={atan2(b-l1 * sin(T1[0]) ,a-l1*cos(T1[0]))-T1[0],atan2(b-l1 * sin(T1[1]) , a-l1*cos(T1[1]))-T1[1]};
        cout.precision(10);
        for(int i=0;i<2;i++)
        if(fabs(l0+l1*cos(T1[i])+l2*cos(T1[i]+T2[i])+l3*cos(Z)-Y) <=1e-8 && fabs(l1*sin(T1[i])+l2*sin(T1[i]+T2[i])+l3*sin(Z)-X) <=1e-8 ){
            cout<<fixed<<degrees(T1[i])<<" "<<degrees(T2[i])<<" "<<(degrees(Z-T1[i]-T2[i]))<<"\n";
            break;
            
        }
    }
}
