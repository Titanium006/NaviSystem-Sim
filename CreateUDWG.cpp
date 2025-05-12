#include <iostream>
#include "Graph.h"
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "Weight.h"
using namespace std;

#define MapNum 400

Graph createUDWG()
{
	//nodeCounts节点个数 edgeCounts边的个数
	//无向连通图中 edgeCounts在[nodeCounts -1, (nodeCounts - 1)*nodeCounts / 2]
	int nodeCounts, edgeCounts;
	/*int edgeWeightMax, edgeWeightMin;*/
	int edgeMax, edgeMin;
	while (true)
	{
		cout << "请输入节点数：";
		cin >> nodeCounts;
		if (nodeCounts > 1)
		{
			break;
		}
		else
		{
			cout << "无法成至少有一条边的连通图，请重新输入！" << endl;
		}
	}
	edgeMin = nodeCounts - 1;
	edgeMax = (nodeCounts - 1) * nodeCounts / 2;
	while (true)
	{
		cout << "请输入边数：" << "（在" << edgeMin << "到" << edgeMax << "之间）";
		cin >> edgeCounts;
		if (!(edgeCounts >= edgeMin && edgeCounts <= edgeMax))
		{
			cout << "输入边数错误，请重新输入！" << endl;
		}
		else
		{
			break;
		}
	}
	/*cout << "请输入边的长度范围（整数且小于999）" << endl;
	while (true)
	{
		cout << "最大值：";
		cin >> edgeWeightMax;
		cout << "最小值：";
		cin >> edgeWeightMin;
		if (edgeWeightMin < edgeWeightMax)
		{
			if (edgeWeightMin > 0 && edgeWeightMax < 999)
			{
				break;
			}
			else
			{
				cout << "不在范围内，请重新输入！" << endl;
			}
		}
		else
		{
			cout << "最小不比最大小，请重新输入！" << endl;
		}
	}*/
	system("cls");
	cout << "输入结束，您生成的图信息为：无向连通图" << endl;
	cout << "节点为" << nodeCounts << "个  "; cout << "边数为" << edgeCounts << endl;
	/*cout << "  边的权值从" << edgeWeightMin << "到" << edgeWeightMax << "之间" << endl;*/

	//正式计算
	Graph graph(nodeCounts, edgeCounts);
	vector<Node>next;
	next.assign(graph.vertexArray.begin(), graph.vertexArray.end());
	graph.vertexArray.clear();
	int val;
	int edgeNum = 0;
	//step1 
		//生成一个连通子图，N-1条边
		//1.1首先随机分组
		//一个记录节点小组下标的数组
	int* arrId = new int[nodeCounts];
	for (int i = 0; i < nodeCounts; i++)
	{
		arrId[i] = 0;
	}
	//小组id
	int id = 0;
	//产生一个随机节点序列
	int* arr = new int[nodeCounts];
	for (int i = 0; i < nodeCounts; i++)
	{
		arr[i] = 0;
	}
	int count = 0;
	srand((unsigned)time(NULL));
	while (count < nodeCounts)
	{
		int val = rand() % nodeCounts;
		if (!arr[val])
		{
			arr[val] = count + 1;
			++count;
		}
	}
	//1.2根据随机序列arr，两个节点一组进行分组
	Node node1, node2;
	Weight weight;
	int curi = 0, curj = 0;
	for (int i = 0; i <= nodeCounts - 2; i = i + 2)
	{
		//分组，标记分组号
		id++;
		arrId[i] = id;
		arrId[i + 1] = id;
		//添加相应边
		node1.setId(arr[i] - 1);
		node2.setId(arr[i + 1] - 1);
		//weight.setLength(rand() / double(RAND_MAX) + (double)(rand() % (edgeWeightMax - edgeWeightMin) + edgeWeightMin + 1));
		srand((unsigned)time(NULL));
		val = rand() % next.size();
		node1.setX(next.at(val).getX());
		node1.setY(next.at(val).getY());
		graph.vertexArray.push_back(node1);
		swap(next[val], next.at(next.size() - 1));
		next.pop_back();
		srand((unsigned)time(NULL));
		val = rand() % next.size();
		node2.setX(next.at(val).getX());
		node2.setY(next.at(val).getY());
		weight.setLength(sqrt(pow((node1.getX() - node2.getX()), 2) + pow((node1.getY() - node2.getY()), 2)));
		graph.vertexArray.push_back(node2);
		swap(next[val], next.at(next.size() - 1));
		next.pop_back();
		Edge newEdge(node1, node2, weight);
		newEdge.print();
		graph.addEdge(node1, node2, weight);
		graph.addEdge(node2, node1, weight);
		graph.edgeArray.push_back(Edge(node1, node2, weight));
		graph.edgeArray.push_back(Edge(node2, node1, weight));
	}
	//system("pause");
	if (nodeCounts % 2 == 1)//奇数，最后一个小组为三个节点
	{
		arrId[nodeCounts - 2] = id;
		arrId[nodeCounts - 1] = id;
		//添加相应边
		node1.setId(arr[nodeCounts - 2] - 1);
		node1.setX(node2.getX());
		node1.setY(node2.getY());
		node2.setId(arr[nodeCounts - 1] - 1);
		srand((unsigned)time(NULL));
		val = rand() % next.size();
		node2.setX(next.at(val).getX());
		node2.setY(next.at(val).getY());
		graph.vertexArray.push_back(node2);
		swap(next[val], next.at(next.size() - 1));
		next.pop_back();
		//weight.setLength(rand() / double(RAND_MAX) + (double)(rand() % (edgeWeightMax - edgeWeightMin) + edgeWeightMin + 1));
		weight.setLength(sqrt(pow((node1.getX() - node2.getX()), 2) + pow((node1.getY() - node2.getY()), 2)));

		Edge newedge(node1, node2, weight);
		newedge.print();
		graph.addEdge(node1, node2, weight);
		graph.addEdge(node2, node1, weight);
		graph.edgeArray.push_back(Edge(node1, node2, weight));
		graph.edgeArray.push_back(Edge(node2, node1, weight));
	}
	//system("pause");
	//1.3 根据现有的小组随机连接,直到只有一个小组
	while (id != 1)
	{
		//任意选择两个存在的小组
		 //首先任意获得第一个被挑选出来的小组group1的编号arrId
		int getRandom = rand() % nodeCounts;
		int group1 = 1;
		int group2 = 1;
		group1 = arrId[getRandom];

		//其次获取在arrId数组中与grroup1相邻的第二个小组group2的编号
		for (int i = getRandom; i <= getRandom + nodeCounts - 1; i++)
		{
			if (arrId[(i % nodeCounts)] != group1)
			{
				group2 = arrId[(i % nodeCounts)];
				break;
			}
		}
		//从两个小组中任意挑出一个节点作为连接节点
		int group1Counts = 0;
		int group2Counts = 0;
		//先获得两个小组的数量
		for (int i = 0; i <= nodeCounts - 1; i++)
		{
			if (arrId[i] == group1)
			{
				group1Counts++;
			}
			if (arrId[i] == group2)
			{
				group2Counts++;
			}
		}
		//随机获取在两个小组中被挑选出的节点的序号
		int nodeChoose1 = rand() % group1Counts + 1;
		int nodeChoose2 = rand() % group2Counts + 1;
		//获取被挑选出来的节点的node_id	，更新arrId			
		group1Counts = 0;
		group2Counts = 0;
		node1.setId(-1);//重新复位
		node2.setId(-1);//重新复位
		for (int i = 0; i <= nodeCounts - 1; i++)
		{
			if (arrId[i] == group1)
			{
				group1Counts++;
			}
			if (arrId[i] == group2)
			{
				group2Counts++;
			}
			if (group1Counts == nodeChoose1 && node1.getId() == -1)//第一次相等的时候
			{
				node1.setId(arr[i] - 1);
				node1.setX(graph.vertexArray[i].getX());
				node1.setY(graph.vertexArray[i].getY());
			}
			if (group2Counts == nodeChoose2 && node2.getId() == -1)//第一次相等的时候
			{
				node2.setId(arr[i] - 1);
				node2.setX(graph.vertexArray[i].getX());
				node2.setY(graph.vertexArray[i].getY());
			}
		}
		//将两个小组合成一个小组,按照“谁小谁做主”的原则，可以预料到最后小组编号全是1
		int connectId = group1 < group2 ? group1 : group2;
		for (int i = 0; i <= nodeCounts - 1; i++)
		{
			if (arrId[i] == group1 || arrId[i] == group2)
			{
				arrId[i] = connectId;
			}
		}
		//随机生成边长
		//weight.setLength(rand() / double(RAND_MAX) + (double)(rand() % (edgeWeightMax - edgeWeightMin) + edgeWeightMin + 1));
		weight.setLength(sqrt(pow((node1.getX() - node2.getX()), 2) + pow((node1.getY() - node2.getY()), 2)));
		//获取边，并添加
		Edge newEdge(node1, node2, weight);
		newEdge.print();
		graph.addEdge(node1, node2, weight);
		graph.addEdge(node2, node1, weight);
		graph.edgeArray.push_back(Edge(node1, node2, weight));
		graph.edgeArray.push_back(Edge(node2, node1, weight));
		//小组数减一
		id--;
	}
	//step2 
	//cout << "继续添加！" << endl;
	int OthertEdgeCount = edgeCounts - nodeCounts + 1;
	while (OthertEdgeCount != 0)
	{
		node1.setId(1);
		node2.setId(1);
		while (node1.getId() == node2.getId())
		{
			node1.setId(rand() % nodeCounts);
			node2.setId(rand() % nodeCounts);
		}
		int get = 0;
		if (!graph.isExistEdge(node1, node2))
		{
			for (int i = 0; i < nodeCounts; i++)
			{
				if (node1.getId() == graph.vertexArray[i].getId())
				{
					node1.setX(graph.vertexArray[i].getX());
					node1.setY(graph.vertexArray[i].getY());
					get++;
					continue;
				}
				if (node2.getId() == graph.vertexArray[i].getId())
				{
					node2.setX(graph.vertexArray[i].getX());
					node2.setY(graph.vertexArray[i].getY());
					get++;
					continue;
				}
				if (get == 2)
				{
					break;
				}
			}
			//weight.setLength(rand() / double(RAND_MAX) + (double)(rand() % (edgeWeightMax - edgeWeightMin) + edgeWeightMin + 1));
			weight.setLength(sqrt(pow((node1.getX() - node2.getX()), 2) + pow((node1.getY() - node2.getY()), 2)));
			Edge newEdge(node1, node2, weight);
			newEdge.print();
			graph.addEdge(node1, node2, weight);
			graph.addEdge(node2, node1, weight);
			graph.edgeArray.push_back(Edge(node1, node2, weight));
			graph.edgeArray.push_back(Edge(node2, node1, weight));
			OthertEdgeCount--;
		}
	}
	return graph;
}