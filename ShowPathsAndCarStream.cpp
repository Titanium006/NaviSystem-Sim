#include <iostream>
#include "Graph.h"
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "Weight.h"
using namespace std;

void showPathsAndCarStream(Graph& g)
{
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
	Edge e;
	queue<Edge>q;
	for (int i = g.getFirstNeighbor(n.getId()); i < g.getVertexNum(); i = g.getNextNeighbor(n.getId(), i))
	{
		if (i == -1)
		{
			break;
		}
		else
		{
			q.push(g.findEdge(n, g.findVertex(i)));
		}
	}
	int count = 0;
	double cs = 0;
	cout << "点" << n.getId() << "附近边如下：" << endl;
	while (!q.empty())
	{
		e = q.front();
		q.pop();
		cs = e.getCarStream();
		cout << "边" << count++ << "\t点" << e.getStart().getId() << "(" << e.getStart().getX() << "," << e.getStart().getY() << ")--"
			<< "点" << e.getEnd().getId() << "(" << e.getEnd().getX() << "," << e.getEnd().getY() << ")--"
			<< "车流量为" << cs << "辆/s";
		if (cs <= 2)
		{
			cout << "--拥堵" << endl;
		}
		else if (cs > 2 && cs <= 5)
		{
			cout << "--正常" << endl;
		}
		else
		{
			cout << "--畅通" << endl;
		}
	}
}