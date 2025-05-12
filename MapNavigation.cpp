#include <iostream>
#include "Graph.h"
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "Weight.h"
#include "K-means.h"
using namespace std;

Graph createUDWG();
void findPaths(Graph& g);
void findHundredPoints(Graph& g);
void showPathsAndCarStream(Graph& g);

// 程序的主函数
int main()
{
	Graph g = createUDWG();
	system("pause");
	// 暂时默认有三个缩放比例，分别对应sub=0，1，2
	while (!K_means(g.vertexArray, 100, 0))
	{
		continue;
	}
	cout << "..................." << endl;
	while (!K_means(g.vertexArray, 20, 1))	// 聚类点数与输入点数越接近，迭代时间就越长
	{
		continue;
	}
	cout << "..................." << endl;
	while (!K_means(g.vertexArray, 50, 2))
	{
		continue;
	}
	cout << "..................." << endl;
	//int tap = 0, label = 0;
	//while (1)
	//{
	//	cout << "1----寻找最短路径-----" << endl;
	//	cout << "2---寻找附近100个点---" << endl;
	//	cout << "3--寻找附近 路和车流--" << endl;
	//	cout << "4----打印邻 接矩阵----" << endl;
	//	cout << "5--------退 出--------" << endl;
	//	while (1)
	//	{
	//		cin >> tap;
	//		if (tap < 1 && tap > 5)
	//		{
	//			cout << "输入有误，请重新输入！" << endl;
	//		}
	//		else
	//		{
	//			break;
	//		}
	//	}
	//	switch (tap)
	//	{
	//	case 1:
	//		findPaths(g);
	//		break;
	//	case 2:
	//		findHundredPoints(g);
	//		break;
	//	case 3:
	//		g.refreshCarFlow();
	//		break;
	//	case 4:
	//		g.print();
	//		break;
	//	case 5:
	//		label = 1;
	//		break;
	//	default:
	//		break;
	//	}
	//	system("pause");
	//	//system("cls");
	//	if (label == 1)
	//	{
	//		break;
	//	}
	//}
	return 0;
}