#include <iostream>
#include "Graph.h"
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "Weight.h"
using namespace std;

void findHundredPoints(Graph& g)
{
	if (g.getVertexNum() < 100)
	{
		return;
	}
	Node n;
	int x = 0, y = 0;
	cout << "请输入要查找的点的横纵坐标：";
	while (1)
	{
		cin >> x >> y;
		n.setX(x);
		n.setY(y);
		if (g.isExistNode(n))
		{
			n = g.findVertex(x, y);
			break;
		}
		else
		{
			cout << "点不存在，请重新输入坐标！" << endl;
		}
	}
	queue<Node>q;
	g.Dijkstra(q, n.getId());
	int add = 0;
	cout << "点" << n.getId() << "附近的100个点坐标如下：" << endl;
	while (!q.empty())
	{
		n = q.front();
		q.pop();
		add++;
		cout << "点" << n.getId() << "(" << n.getX() << "," << n.getY() << ") ";
		if (add == 5)
		{
			cout << endl;
			add = 0;
		}
	}
}