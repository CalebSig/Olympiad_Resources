///PBINFO qtsume 3796 https://www.pbinfo.ro/probleme/3796/qtsume
#include <fstream>
using namespace std;
ifstream cin("qtsume.in");
ofstream cout("qtsume.out");
unsigned long long S1[100001];
unsigned long long S2[100001];
int n, x, y, q;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> x;
		S2[i] = 1ull * x * i + S2[i - 1]; 
		S1[i] = S1[i - 1] + x; ///SABLON
	}
	cin >> q;
	for (int j = 1; j <= q; ++j)
	{
		cin >> x >> y;
		cout << S2[y] - S2[x - 1] - 1ull * (x - 1) * (S1[y] - S1[x - 1]) << '\n'; ///Sume[dr] - Sume[st-1];
	}
	return 0;
}
