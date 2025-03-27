#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string dieta, cafe, almoco;
        int qtd[256] = {0};
        bool cheater = false;
        
        cin >> dieta >> cafe >> almoco;
        for (char c : dieta) qtd[c]++;
        for (char c : cafe + almoco) {
            if (qtd[c]) qtd[c]--;
            else cheater = true;
        }

        if (cheater) cout << "CHEATER\n";
        else {
            for (char c = 'A'; c <= 'Z'; c++) {
                while (qtd[c]--) cout << c;
            }
            cout << endl;
        }
    }
    return 0;
}