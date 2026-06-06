﻿#include <iostream>
using namespace std;

int main()
{
    int a;
    char b;
    cout << "请给定一个字符:" << endl;
    cin >> b;
    cout << "请给定一个数字:" << endl;
    cin >> a;
    if (a % 2 == 0) { cout << "请输入奇数"; }
    else {
        for (int j = 1; j <= (a + 1) / 2; j++) {
            for (int i = 1; i <= j; i++) {
                for (int z = 1; z <= a; z++) {
                    if (z <= (a + 1) / 2 + j - 1 && z >= (a + 1) / 2 - j + 1) { cout << b; }
                    else { cout << ' '; }
                }cout << endl;
            }
        }
        for (int x = 1; x <= (a + 1) / 2; x++) {
            for (int y = 1; y <= (a + 1) / 2; y++) {
                if (y == (a + 1) / 2) { cout << b << endl; }
                else {
                    cout << ' ';
                }
            }
        }
        return 0;
    }
}