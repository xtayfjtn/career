// frog.cpp : Defines the entry point for the console application.
//http://www.cnblogs.com/wizardkeven/p/5887020.html

//题目描述
//小青蛙有一天不小心落入了一个地下迷宫，小青蛙希望用自己仅剩的体力值P跳出这个地下迷宫。为了让问题简单，假设这是一个n*m的各自迷宫。迷宫每个位置为0或者1. 0代表这个位置有障碍物，小青蛙到达不了这个位置；1代表小青蛙可以达到的位置。小青蛙出事在(0, 0)位置。地下迷宫的出口在(0, m - 1)(保证这两个位置都是1，并且保证一定有起点到终点可达的路径)。小青蛙在迷宫中水平移动一个单位距离需要消耗1点体力值。向上爬一个单位距离需要消耗3个体力值，向下移动不消耗体力值。当小青蛙的体力值等于0时候还没有到达出口，小青蛙将无法逃离迷宫。现在需要你帮助小青蛙计算出能否用今生的体力值跳出迷宫（即达到(0, m - 1)的位置
//
//输入：
//
//输入 n + 1行：
//第一行为3个整数n, m(3 <= m, n <= 10), P(1 <= P <= 100)
//接下来的n行：
//每行m个0或者1，以空格分隔
//输出：
//如果能逃离迷宫，则输出一行体力消耗最小的路径，输出格式见样例所示；如果不能逃离迷宫，则输出“Can not escape!”。
//测试数据保证答案唯一
//输入例子：
//* 4 4 10
//* 1 0 0 1
//* 1 1 0 1
//* 0 1 1 1
//* 0 0 1 1
//
//输出例子：
//
//[0, 0], [1, 0], [1, 1], [2, 1], [2, 2], [2, 3], [1, 3], [0, 3]

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int n, m, p;
#define MAX_CUL 10

int map[MAX_CUL][MAX_CUL];
int step[MAX_CUL][MAX_CUL];

int getX(int l){
	return l / n;
}

int getY(int l){
	return l % n;
}

int getC(int x, int y){
	return x * n + y;
}

bool getpath(vector<int> &list, int x, int y, int p)
{
	if (x < 0 || y < 0 || x >= n || y >= n || p < 0 || map[x][y] == 0)
	{
		return false;
	}
	 else
	 {
		 if (step[x][y] != -1 && step[x][y] > p)
		 {
			 return false;
		 }
		 else
		 {
			 step[x][y] = p;
		 }
	 }
	list.push_back(getC(x, y));
	if (x == 0, y == m - 1)
	{
		return true;
	}
	else if (false == (getpath(list, x, y + 1, p) || getpath(list, x + 1, y, p - 1) || getpath(list, x - 1, y, p - 1) || getpath(list, x, y + 1, p - 3)))
	{
		list.pop_back();
		return false;
	}
	else
	{
		return true;
	}
}

void printpath(vector<int> &list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << "[" << getX(list[i]) << "," << getY(list[i]) << "]";
		if (i != list.size() - 1)
		{
			cout << ",";
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	cin >> n >> m >> p;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			step[i][j] = -1;
		}
	}

	vector<int> list;//save the path.

	if (getpath(list, 0, 0, p))
	{
		printpath(list);
	}
	 else
	 {
		 cout << "Can not escape!" << endl;
	 }
	return 0;
}
