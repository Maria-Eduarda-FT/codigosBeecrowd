#include <bits/stdc++.h>
using namespace std;
//maior valor possivel de um int
const int INF = numeric_limits<int>::max();
unordered_map<string, int> tamanho_index = {
    {"XXL", 0}, {"XL", 1}, {"L", 2}, {"M", 3}, {"S", 4}, {"XS", 5}
};

class HungarianAlgorithm {
private:
    int n, m;
    vector<vector<int>> cost;

public:
    HungarianAlgorithm(vector<vector<int>> &matrix) {
        cost = matrix;
        n = matrix.size(); //linhas
        m = matrix[0].size(); //colunas
    }

    bool solve() {
        vector<int> match_right(m, -1);
        //percorre o numero de linhas
        for (int i = 0; i < n; i++) { 
            vector<bool> visited(m, false);//verifica as colunas
            if (!aumenta(i, visited, match_right))
                return false;
        }
        return true;
    }

    bool aumenta(int i, vector<bool> &visited, vector<int> &match_right) {
        //percorre o numero de colunas
        for (int j = 0; j < m; j++) {
            if (cost[i][j] == 0 && !visited[j]) {
                visited[j] = true;
                if (match_right[j] == -1 || aumenta(match_right[j], visited, match_right)) {
                    match_right[j] = i;
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int N, M;
        cin >> N >> M;
        //matriz M x N
        vector<vector<int>> custos(M, vector<int>(N, INF));
        int disponiveis = N / 6;
        //preenchendo matriz com tamanhos disponiveis
        for (int i = 0; i < M; i++) {
            string tam1, tam2;
            cin >> tam1 >> tam2;
            int idx1 = tamanho_index[tam1];
            int idx2 = tamanho_index[tam2];
            //colunas
            for (int j = 0; j < disponiveis; j++) {
                custos[i][idx1 + 6*j] = 0;
                custos[i][idx2 + 6*j] = 0;
            }
        }

        HungarianAlgorithm hungarian(custos);
        cout << (hungarian.solve() ? "YES" : "NO") << endl;
    }

    return 0;
}