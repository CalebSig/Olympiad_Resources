///pb prim003 pbinfo, https://www.pbinfo.ro/probleme/2325/prim003
#include <iostream>
#include <bitset>
using namespace std;

#define SIZE 1000000
int F[SIZE + 1];

int main()
{
    for(int i=2;i<=SIZE;i++)
        {
            if(F[i]==0)
            {
                for(int j=2*i;j<=SIZE;j=j+i) {
                    int x = j;
                    while(x%i==0) {x=x/i; F[j]++;}  ///suma tuturor exponentilor
                }
            } 
            else
            {
                if(F[i]==2) {F[i]=1; /*cout<<i<<" ";*/}
                else F[i]=0;
            }
            F[i]+=F[i-1]; ///suma partaila
        }
    
    int t;
    cin>>t;
    while(t--) {
        int a,b;
        cin>>a>>b;
        cout<<F[b]-F[a-1]<<" ";
    }
    return 0;
}
