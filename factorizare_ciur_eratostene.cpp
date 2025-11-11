///pb prim003 pbinfo, https://www.pbinfo.ro/probleme/2325/prim003
#include <iostream>
#include <bitset>
using namespace std;

#define SIZE 1000000
bitset <SIZE + 1> E;

int P[100001], np;

int F[1000001];

int main()
{
    E[0]=E[1]=1;
    for(int i=2;i*i<=SIZE;i++)
        if(E[i]==0) 
            for(int j=i*i;j<=SIZE;j+=i)
                E[j]=1;
    for(int i=2;i<=SIZE;++i)
        if(E[i]==0) P[++np]=i;

    ///descompunere
    
    for(int i=1;i<=SIZE;i++) 
        if(E[i]==1) {
            int x=i,d=1,s=0; //d e indice
            while(x>1) {
                if(x%P[d]==0) {
                    while(x%P[d]==0) { ///P[d] in loc de d
                        s++;
                        x=x/P[d];
                    }
                }
                d++;
                if(P[d]*P[d]>x && x>1) {
                    s++;
                    x = 1;
                }
            }
            if(s == 2) F[i]=1;
        }
    //sp
    for(int i=1;i<=SIZE;++i) F[i]+=F[i-1];
    
    int t;
    cin>>t;
    while(t--) {
        int a,b;
        cin>>a>>b;
        cout<<F[b]-F[a-1]<<' ';
    }
    
    return 0;
}
