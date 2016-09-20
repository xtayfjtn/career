// frog.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include <iostream>
//#include <vector>
//#include <cstdio>
//#include <cstdlib>
//using namespace std;
//
//#define MAX_CUL 10
//
//int map[MAX_CUL][MAX_CUL];
//int step[MAX_CUL][MAX_CUL];
//
//int n, m, P;
//
//int getX(int l){
//	return l%n;
//}
//
//int getY(int l){
//	return l / n;
//}
//
//int getC(int x, int y){
//	return x * n + y;
//}
//
//bool DFS(vector<int>& list, int x, int y, int p){
//	if (x < 0 || y < 0 || x >= n || y >= m || p < 0 || map[x][y] == 0) {
//
//		return false;
//	}
//	else {
//		if (step[x][y] != -1 && step[x][y] > p) {
//			return false;
//		}
//		else {
//			step[x][y] = p;
//		}
//	}
//
//
//	list.push_back(getC(x, y));
//	cout << "IN:" << x << " " << y << endl;
//	if (x == 0 && y == m - 1) {
//		return true;
//	}
//	else if (false == (
//		//向下
//		DFS(list, x, y + 1, p) ||
//		//向右
//		DFS(list, x + 1, y, p - 1) ||
//		//向讈E		DFS(list, x - 1, y, p - 1) ||
//		//向上
//		DFS(list, x, y - 1, p - 3))) {
//		cout << "OUT:" << x << " " << y << endl;
//		list.pop_back();
//		return false;
//	}
//	else {
//		return true;
//	}
//
//}
//
//
//void print(vector<int>& list){
//	for (int i = 0; i < list.size(); i++){
//		cout << "[" << getX(list[i]) << "," << getY(list[i]) << "]";
//		if (i != list.size() - 1) cout << ",";
//	}
//}
//
//int main()
//{
//	//freopen("in.txt", "r", stdin);
//
//
//	cin >> n >> m >> P;
//	for (int i = 0; i<n; i++)
//	for (int j = 0; j<m; j++)
//		cin >> map[i][j];
//
//
//
//	//INIT
//	for (int i = 0; i<n*m; i++)
//		step[getX(i)][getY(i)] = -1;
//
//
//
//	vector<int> list;
//	// step[0][0] = P;
//	// list.push_back(0);
//	if (DFS(list, 0, 0, P)){
//		print(list);
//	}
//	else {
//		cout << "Can not escape!";
//	}
//
//	cout << endl;
//	for (int i = 0; i<n; i++) {
//		for (int j = 0; j<m; j++){
//			cout << step[i][j];
//			cout << " ";
//		}
//		cout << endl;
//	}
//
//}
#include <iostream>
#include <vector>

using namespace std;

int n, m, p;
#define MAX_CUL 10

int map[MAX_CUL][MAX_CUL];
int step[MAX_CUL][MAX_CUL];

int getX(int l){
	return l%n;
}

int getY(int l){
	return l / n;
}

//int getC(int x, int y){
//	return x * n + y;
//}

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
			map[i][j] = -1;
		}
	}

	vector<int> list;//save the road.
	return 0;
}

