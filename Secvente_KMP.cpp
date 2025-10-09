#include <iostream>
#include <iomanip>
using namespace std;

void construire(string w, int T[]) ///precalcularea tabelei T, T[i]=j => de la pozitia curenta i trebuie sa mergem inapoi j caractere pentru a verifica in continuare
{
    int m = w.size();
    T[0] = -1;
    int k = -1;
    int i = 1;

    while (i < m) 
    {
        while (k >= 0 && w[k + 1] != w[i])
            k = T[k];
        if (w[k + 1] == w[i])
            ++k;
        T[i] = k;
        ++i;
    }

    /*for (int i = 0; i < m; ++i) cout << setw(2) << w[i] << " ";
    cout << endl;
    for (int i = 0; i < m; ++i) cout << setw(2) << T[i] << " ";
    cout << endl;*/
}


void KMP(string s, string w)
{
    int T[1001];
    construire(w, T);

    int n = s.size(), m = w.size();
    int i = 0, k = -1; ///indicele lui s, indicele lui w

    while (i < n) 
    {
        while (k >= 0 && w[k + 1] != s[i])
            k = T[k];
        if (w[k + 1] == s[i])
            ++k;
        if (k == m - 1) ///match
        {
            cout << "Sir gasit la: " << i - m + 1 << endl;
            k = T[k]; 
        }
        ++i;
    }
}


int main()
{
    KMP("ABC ABCDABD ABCDABDFSABCABDAABCDAABD", "ABCDABD");
    return 0;
}
