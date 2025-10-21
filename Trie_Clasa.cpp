//INFOARENA TRIE https://www.infoarena.ro/problema/trie

//#include <iostream>

#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

void format_word(char* s)
{
    char* p = strchr(s, '\n');
    if (p) *p = 0;
}

class Trie {

public:
    int val;
    int nrFii;
    Trie* Fiu[26];

    Trie() {
        val = nrFii = 0;
        memset(Fiu, 0, sizeof(Fiu));
    }

    void pushRec(char* s) { ///RECURSIV
        if (*s == '\0') {
            val++;
            return;
        }

        int x = *s - 'a';
        if (Fiu[x] == NULL)
        {
            Fiu[x] = new Trie();
            nrFii++;
        }

        Fiu[x]->pushRec(s + 1);
    }

    void push(char* s) {  ///iterativ
        Trie* T = this;

        while (*s) {
            int x = *s - 'a';
            if (T->Fiu[x] == 0) {
                T->Fiu[x] = new Trie();
                T->nrFii++;
            }
            T = T->Fiu[x];
            s++;
        }

        T->val++;

    }

    void rmv(char* s) {

        if (*s == '\0') { if (val > 0) val--; return; }

        int x = *s - 'a';
        if (Fiu[x] == 0) return;

        Fiu[x]->rmv(s + 1);

        if (Fiu[x]->nrFii == 0 && Fiu[x]->val == 0) {
            delete Fiu[x];
            Fiu[x] = 0;
            nrFii--;
        }

    }

    int countREC(char* s) { ///REC

        if (*s == '\0') return val;

        int x = *s - 'a';
        if (*s != '\0' && Fiu[x] == 0) return 0;

        return Fiu[x]->countREC(s + 1);

    }

    int count(char* s) {
        Trie* T = this;
        while (*s) {
            int x = *s - 'a';
            if (T->Fiu[x] == 0) return 0;
            s++;
            T = T->Fiu[x];
        }
        return T->val;
    }

    int longest_prefix(char* s) {
        Trie* T = this;
        int i = 0;
        while (s[i]) {
            int x = s[i] - 'a';
            if (T->Fiu[x] == 0) break;
            i++;
            T = T->Fiu[x];
        }

        return i;
    }

};

int main()
{
    freopen("trie.in", "r", stdin);
    freopen("trie.out", "w", stdout);

    char line[32];
    Trie T = Trie();
    while (fgets(line, 32, stdin)) {

        format_word(line + 2);
        switch (line[0])
        {
        case '0': T.push(line + 2); break;
        case '1': T.rmv(line + 2); break;
        case '2': printf("%d\n", T.count(line + 2)); break;
        case '3': printf("%d\n", T.longest_prefix(line + 2)); break;
        }

    }

    return 0;
}
