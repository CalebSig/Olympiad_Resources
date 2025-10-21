///pbinfo Intervale6 #3939 https://www.pbinfo.ro/probleme/3939/intervale6
#include <fstream>
using namespace std;
ifstream fin("intervale6.in");
ofstream fout("intervale6.out");

int F[10001];
int main() {

    int n, st, dr, x, cnt = 0;
    fin >> n;

    for (int i = 1; i <= n; i++) {
        fin >> x;

        F[x]++;
    }

    for (int i = 1; i <= 10000; i++)     // sume partiale
        F[i] += F[i - 1];

    while (fin >> st >> dr) {
        int nr = F[dr] - F[st - 1];
        if (nr == 0)
            cnt++;
    }

    fout << cnt;
    return 0;
}
