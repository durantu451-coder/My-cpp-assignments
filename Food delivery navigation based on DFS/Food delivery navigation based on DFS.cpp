#include <iostream>
#include<vector>
#include<utility>
using namespace std;

const int N = 5;
int a[N][N] = { 0 };
bool visited[N][N];
int t = 0;
vector<pair<int, int>>path;

bool findpath(int x, int y) {

	if (x >= 5 || x < 0 || y >= 5 || y < 0) {
		return false;
	}
	if (a[x][y] == 0 || visited[x][y]) {
		return false;
	}
	if (a[x][y] == 9) {
		cout << "找到了" << t << endl;
		return true;
	}

	if (!(x == 0 && y == 0)) {
		path.push_back({ x,y });
		t += a[x][y];
		cout << "进入(" << x << "," << y << "), 时间+" << a[x][y] << ", 总时间=" << t << endl;
	}
	visited[x][y] = true;
	if (findpath(x, y + 1)) { return true; }
	if (findpath(x + 1, y)) { return true; }
	if (findpath(x + 1, y)) { return true; }
	if (findpath(x, y - 1)) { return true; }
	if (!(x == 0 && y == 0)) { cout << "回溯(" << x << "," << y << "), 时间-" << a[x][y] << ", 总时间=" << t << endl; t -= a[x][y]; path.pop_back(); }
	visited[x][y] = false;
	return false;
}
int main()
{
	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= 4; j++) {
			cin >> a[i][j];
		}
	}
	if (findpath(0, 0)) {
		cout << t << endl; 
		for (auto p : path){
			cout << "(" << p.first <<","<< p.second << ")";
		}
				}
	else { cout << "找不到" << endl; }
}