

#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<vector<int>>ker = { {1,-1,1},{1,-1,-1},{1,-1,-1} };
    int x, y;
    while (cin >> x >> y) {
        vector<vector<int>> vec(x+2, vector<int>(y+2, 0));
        for (int i = 1; i < x+1; i++) {
            for (int j = 1; j < y+1; j++) {
                int a; cin >> a;
                vec[i][j] = a;
            }
        }
        vector<vector<int>>redo(x, vector<int>(y, 0));
        for (int i = 1; i < x+1; i++) {
            for (int j = 1; j < y+1; j++) {
                int sum = 0;
                int m = 0;
                int n = 0;
                for (int k = i - 1; k < i + 2; k++) {
                    for (int h = j - 1; h < j + 2; h++) {
                        sum += vec[k][h] * ker[m][n];
                            n++;
                    }m++; n = 0;
                }
                redo[i - 1][j - 1] = sum;
            }
        }
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (j != y - 1) {
                    cout << redo[i][j] << " ";
                }
                else cout << redo[i][j] << endl;
            }
        }
    }
}

