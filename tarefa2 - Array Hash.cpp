#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    while(true){
        int matriz[4][4];
        cin >> n;
        if(!n) break;

        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                cin >> matriz[i][j];

        for(int i = 0; i < 4; i++)
            matriz[i][i] *= n;

        for(int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << matriz[j][i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}