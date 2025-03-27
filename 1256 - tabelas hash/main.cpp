#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> hashDuda(int M, vector<int> keys){
    vector<vector<int>> table(M);
    
    for (int key : keys) {
        int index = key % M ;
        table[index].push_back(key);
    }
    return table;
}

int main() {
    int N;
    
    cin >> N;    
    for (int j = 0; j < N; j++) {
        if (j > 0) 
            cout << endl;  
        
        int M, qntChaves;
        cin >> M >> qntChaves;   
        vector<int> keys(qntChaves);
        
        for (int i = 0; i < qntChaves; ++i){
            cin >> keys[i];
        }
        vector<vector<int>> table = hashDuda(M, keys);
        for (int i = 0; i < M; ++i) {
            cout << i;
            for (int key : table[i]) {
                cout << " -> " << key;
            }
            cout << " -> \\\n";
        }
    }
    return 0;
}