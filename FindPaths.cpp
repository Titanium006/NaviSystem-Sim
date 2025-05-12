#include <iostream>
#include "Graph.h"
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "Weight.h"
using namespace std;

void findPaths(Graph& g)
{
	int start, end;
	cout << "请输入想要进行Dijkstra的始末结点编号：" << endl;
	cout << "请输入起点：";
	while (1)
	{
		cin >> start;
		if (start < g.getVertexNum() && start >= 0)
		{
			break;
		}
		else
		{
			cout << "编号范围应在0~" << g.getVertexNum() << "之间！请重新输入！" << endl;
		}
	}
	cout << "请输入终点：";
	while (1)
	{
		cin >> end;
		if (end < g.getVertexNum() && end >= 0)
		{
			break;
		}
		else
		{
			cout << "编号范围应在0~" << g.getVertexNum() << "之间！请重新输入！" << endl;
		}
	}
	g.getShortestPath(start, end);
}