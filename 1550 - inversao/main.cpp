#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int inverte(int n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return stoi(s);// string to integer
}
int buscaLargura(int A, int B) {
    vector<bool> visitado(B + 1, false);
    queue<pair<int, int>> F;  // número atual, passos

    visitado[A] = true;
    F.push({A, 0});

    while (!F.empty()) {
        auto [u, passos] = F.front();
        F.pop();
        if (u == B) return passos;//encontrou
        
        int prox2 = inverte(u);
        if (prox2 <= 10000 && !visitado[prox2]) { //inv
            visitado[prox2] = true;
            F.push({prox2, passos + 1});
        }

        int prox1 = u + 1;
        if (prox1 <= 10000 && !visitado[prox1]) {//add
            visitado[prox1] = true;
            F.push({prox1, passos + 1});
        }
    }
}

int main() {
    int T;

    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;
        cout << buscaLargura(A, B) << endl;
    }
    return  0;
}