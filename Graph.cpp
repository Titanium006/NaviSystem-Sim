#include "Graph.h"

Graph::Graph(int n, int m)
{
	vertexNum = n;
	edgeNum = m;
	this->mark = new int[this->vertexNum];;
	for (int i = 0; i < this->vertexNum; i++)
	{
		this->mark[i] = UNVISITED;
	}
	this->DjArray = new double[this->vertexNum];
	for (int i = 0; i < this->vertexNum; i++)
	{
		this->DjArray[i] = INFINITY;
	}
	int num = MapNum;
	map = new int* [num];
	for (int i = 0; i < num; i++)
	{
		map[i] = new int[num];
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			map[i][j] = 0;
		}
	}
	int adder = 0, x = 0, y = 0;
	for (int i = 0; i < num; i++)
	{
		if (adder == n)
		{
			break;
		}
		for (int j = 0; j < num; j++)
		{
			if (adder == n)
			{
				break;
			}
			else
			{
				x = rand() % num;
				y = rand() % num;
				if (map[x][y] == 1)
				{
					continue;
				}
				else
				{
					map[x][y] = 1;
					vertexArray.push_back(Node(x, y, 0));
					adder++;
				}
			}
		}
	}
	matrix = new Weight* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new Weight[n];
	}
	//为图矩阵赋予初值INFINITY，INFINITY表示两点间距离大，即两点不可达
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				matrix[i][j].setLength(0);
			}
			else
			{
				matrix[i][j].setLength(INFINITY);
			}
		}
	}
}

int Graph::getVertexNum()
{
	return vertexNum;
}

int Graph::getEdgeNum()
{
	return edgeNum;
}

Weight** Graph::getMartix()
{
	return matrix;
}

void Graph::addEdge(Node s, Node e, Weight w)//起点 终点 长度
{

	matrix[s.getId()][e.getId()] = w;

}

bool Graph::isExistEdge(Node s, Node e)//起点 终点
{
	bool IF = false;
	if (matrix[s.getId()][e.getId()].getLength() != INFINITY)//如果不是最大值，即两节点之间已经存在边
	{
		IF = true;
	}
	return IF;
}

void Graph::print()
{
	cout << "本图的矩阵形式如下：" << endl;
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			if (matrix[i][j].getLength() >= INFINITY)
			{
				cout << setw(10) << setfill(' ') << left << "0.00";
			}
			else
			{
				cout << setw(10) << setfill(' ') << left << setiosflags(ios::fixed) << setprecision(2) << matrix[i][j].getLength();
			}
		}
		cout << endl;
	}

}

int Graph::getFirstNeighbor(const int id)
{
	int i;
	for (i = 0; i < this->vertexNum; i++)
	{
		if (this->matrix[id][i].getLength() != INFINITY && this->mark[i] == UNVISITED && id != i)
		{
			return i;
		}
	}
	return -1;
}

int Graph::getNextNeighbor(const int id1, const int id2)
{
	int i;
	for (i = id2 + 1; i < this->vertexNum; i++)
	{
		if (this->matrix[id1][i].getLength() != INFINITY && this->mark[i] == UNVISITED && id1 != i)
		{
			return i;
		}
	}
	return -1;
}

bool Graph::isExistNode(Node n)
{
	if (this->map[n.getX()][n.getY()] == 1)
	{
		return true;
	}
	return false;
}

Node Graph::findVertex(int id)
{
	Node node;
	for (int i = 0; i < this->vertexArray.size(); i++)
	{
		if (id == this->vertexArray[i].getId()) {
			node = this->vertexArray[i];
			break;
		}
	}
	return node;
}

Node Graph::findVertex(int x, int y)
{
	Node node;
	for (int i = 0; i < this->vertexArray.size(); i++)
	{
		if (x == this->vertexArray[i].getX() && y == this->vertexArray[i].getY()) {
			node = this->vertexArray[i];
			break;
		}
	}
	return node;
}

Edge Graph::findEdge(Node s, Node e)
{
	Edge edge;
	for (int i = 0; i < this->edgeArray.size(); i++)
	{
		if (this->edgeArray[i].getStart() == s && this->edgeArray[i].getEnd() == e)
		{
			edge = this->edgeArray[i];
		}
	}
	return edge;
}

void Graph::setMark(int id, int label)
{
	this->mark[id] = label;
}

int Graph::minVertex()
{
	int i = 0, v = -1, add = 0;
	for (i = 0; i < this->vertexNum; i++)
	{
		if (add == 0 && this->mark[i] == UNVISITED)
		{
			v = i;
			add++;
			continue;
		}
		else if (add == 1 && this->mark[i] == UNVISITED && (this->DjArray[i] < this->DjArray[v]))
		{
			v = i;
		}
	}
	return v;
}

void Graph::Dijkstra(Stack<Node>& s, int start, int end)
{
	for (int i = 0; i < this->vertexNum; i++)
	{
		if (this->matrix[start][i].getLength() != INFINITY)
		{
			this->DjArray[i] = this->matrix[start][i].getLength();
		}
		else
		{
			this->DjArray[i] = INFINITY;
		}
	}
	for (int i = 0; i < this->vertexNum; i++)
	{
		this->mark[i] = UNVISITED;
	}
	int* pre = new int[this->vertexNum];
	for (int i = 0; i < this->vertexNum; i++)
	{
		pre[i] = INT_MAX;
	}
	pre[start] = 0;
	int i, v, w;
	for (i = 0; i < this->vertexNum; i++)
	{
		v = minVertex();
		if (this->DjArray[v] == INFINITY || v == -1)
		{
			return;
		}
		this->setMark(v, VISITED);
		for (w = this->getFirstNeighbor(v); w < this->vertexNum; w = this->getNextNeighbor(v, w))
		{
			if (w == -1)
			{
				break;
			}
			double length = (this->DjArray[v] + this->findEdge(this->findVertex(v), this->findVertex(w)).getWeight().getLength());
			if (this->DjArray[w] > length)
			{
				this->DjArray[w] = length;
				pre[w] = v;
			}
		}
	}
	int p = end;
	while (1)
	{

		if (p != INT_MAX)
		{
			s.push(findVertex(p));
			p = pre[p];
		}
		else
		{
			s.push(findVertex(start));
			break;
		}
	}
}

void Graph::quickSort(double* arr, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int i = start;
	int pivot = arr[i];
	int j = end;
	while (i < j)
	{
		while (i < j && pivot <= arr[j])
		{
			j--;
		}
		if (i < j)
		{
			arr[i++] = arr[j];
		}
		while (i < j && pivot >= arr[i])
		{
			i++;
		}
		if (i < j)
		{
			arr[j--] = arr[i];
		}
	}
	arr[i] = pivot;
	quickSort(arr, start, i - 1);
	quickSort(arr, i + 1, end);
}

void Graph::Dijkstra(queue<Node>&q, int start)
{
	for (int i = 0; i < this->vertexNum; i++)
	{
		if (this->matrix[start][i].getLength() != INFINITY)
		{
			this->DjArray[i] = this->matrix[start][i].getLength();
		}
		else
		{
			this->DjArray[i] = INFINITY;
		}
	}
	for (int i = 0; i < this->vertexNum; i++)
	{
		this->mark[i] = UNVISITED;
	}
	int* pre = new int[this->vertexNum];
	for (int i = 0; i < this->vertexNum; i++)
	{
		pre[i] = INT_MAX;
	}
	int i, v, w;
	for (i = 0; i < this->vertexNum; i++)
	{
		v = minVertex();
		if (this->DjArray[v] == INFINITY || v == -1)
		{
			return;
		}
		this->setMark(v, VISITED);
		for (w = this->getFirstNeighbor(v); w < this->vertexNum; w = this->getNextNeighbor(v, w))
		{
			if (w == -1)
			{
				break;
			}
			double length = (this->DjArray[v] + this->findEdge(this->findVertex(v), this->findVertex(w)).getWeight().getLength());
			if (this->DjArray[w] > length)
			{
				this->DjArray[w] = length;
			}
		}
	}
	this->quickSort(this->DjArray, 0, this->vertexNum - 1);
	for (int i = 1; i <= 100; i++)
	{
		q.push(this->findVertex(this->DjArray[i]));
	}
}

void Graph::getShortestPath(int start, int end)
{
	Stack<Node>s;
	Node n;
	this->Dijkstra(s, start, end);
	while (!s.isEmpty())
	{
		n = s.getTop();
		cout << "点" << n.getId() << "(" << n.getX() << "," << n.getY() << ")";
		s.pop();
		if (s.size() != 0)
		{
			cout << "->";
		}
	}
	cout << endl;
	cout << "最短路径长度从点" << this->findVertex(start).getId()
		<< "到点" << this->findVertex(end).getId() << "为"
		<< this->DjArray[end] << endl;
}

Graph::~Graph()
{

}

void Graph::refreshCarFlow()
{
	Node n;
	Edge e;
	int x = 0, y = 0;
	cout << "请输入要查找的点的横纵坐标：";
	while (1)
	{
		cin >> x >> y;
		n.setX(x);
		n.setY(y);
		if (isExistNode(n))
		{
			n = findVertex(x, y);
			break;
		}
		else
		{
			cout << "点不存在，请重新输入坐标！" << endl;
		}
	}
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < vertexNum; k++)
		{
			for (int j = 0; j < vertexNum; j++)
			{
				if (matrix[k][j].getLength() != INFINITY && matrix[k][j].getLength() != 0)
				{
					double t = rand() % (MaxCapacity + 10);
					matrix[k][j].setCarNum(t);
				}
			}
		}
		//for (int a = 0; a < vertexNum; a++)
		//{
		//	for (int b = 0; b < vertexNum; b++)
		//	{
		//		cout << matrix[a][b].getCarNum() << '\t';
		//	}
		//	cout << endl;
		//}
		queue<Edge> q;
		for (int i = getFirstNeighbor(n.getId()); i < getVertexNum(); i = getNextNeighbor(n.getId(), i))
		{
			if (i == -1)
			{
				break;
			}
			else
			{
				q.push(findEdge_refresh(n, findVertex(i)));
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
			if (cs <= 0.6)
			{
				cout << "--拥堵" << endl;
			}
			else if (cs > 0.6 && cs <= 1)
			{
				cout << "--正常" << endl;
			}
			else
			{
				cout << "--畅通" << endl;	
			}
		}
		Sleep(3000);	// 3秒刷新一次
	}
}

Edge Graph::findEdge_refresh(Node s, Node e)
{
	//怎么找到点和邻接矩阵之间的对应行列关系呢？
	Edge edge;
	edge.setStart(s);
	edge.setEnd(e);
	edge.setWeight(matrix[s.getId()][e.getId()]);
	return edge;
}

void Graph::refresh()
{
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < vertexNum; k++)
		{
			for (int j = 0; j < vertexNum; j++)
			{
				if (matrix[k][j].getLength() != INFINITY && matrix[k][j].getLength() != 0)
				{
					double t = rand() % (MaxCapacity + 10);
					matrix[k][j].setCarNum(t);
				}
			}
		}
		Sleep(3000);	// 3秒刷新一次
	}

}
