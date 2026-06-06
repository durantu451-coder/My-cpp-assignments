// 导航外卖pro.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

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
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
