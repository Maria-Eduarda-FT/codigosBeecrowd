#include <bits/stdc++.h>

using namespace std;

int main() {
    while (true) {
        int N, M;
        cin >> N >> M;
        
        if (N == 0 && M == 0)
            break;
        
        map<string, vector<int>> aplicacoesServidor;
        for (int i = 0; i < N; ++i) {
            int Q;
            cin >> Q;
            for (int j = 0; j < Q; ++j) {
                string app;
                cin >> app;
                aplicacoesServidor[app].push_back(i);
                // Armazena o servidor i como aquele que oferece app
            }
        }

        set<int> clientes;
        for (int i = 0; i < M; ++i) {
            int P;
            cin >> P;
            
            for (int j = 0; j < P; ++j) {
                string app;
                cin >> app;
                if (aplicacoesServidor.find(app)) {
                    for (int servidor : aplicacoesServidor[app]) {
                        clientes[i].insert(servidor);
                    }
                }
            }
        }
        
        int conexoes = 0;
        for (int i = 0; i < M; ++i) {
            conexoes += clientes[i].size();
        }
        cout << conexoes << endl;
    }

    return 0;
}
