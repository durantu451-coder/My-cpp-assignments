// 3.17student.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

class Student {
private:
	double score;
	static int count;
	static double total;

public:
	void scoreTotalCount(double s) {
		total += s;
		count++;
		score = s;
	}
	static double sum() {
		return total;
	}
	static double average() {
		return total / count;
	}
};
double Student::total = 0;
int Student::count = 0;

int main() {
	vector<Student> students; // 存储学生对象的向量
	double score;
	int numStudents;
	// 输入学生人数
	cout << "请输入学生人数：";
	cin >> numStudents;
	// 输入每个学生的成绩
	for (int i = 0; i < numStudents; ++i) {
		cout << "请输入第 " << (i + 1) << " 个学生的成绩：";
		cin >> score;
		students.push_back(Student());
		students[i].scoreTotalCount(score);
	}
	// 输出总分和平均分
	cout << "全班学生的总分是：" << Student::sum() << endl; cout << "全班学生的平均分是：" << fixed << setprecision(2) << Student::average() << endl;
	return 0;
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
