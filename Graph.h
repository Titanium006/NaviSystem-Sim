#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <queue>
#include <random>
#include <ctime>
#include<Windows.h>		//定时器用
#include "Node.h"
#include "Edge.h"
#include "Weight.h"
#include "Stack.h"
using namespace std;

#define UNVISITED 0//未被访问
#define VISITED 1//被访问
#define random(a,b) rand()%(b-a+1)+a
#define MapNum 400

class Graph
{
	friend class Weight;
private:
	Weight** matrix;
	int vertexNum;
	int edgeNum;
	int* mark;
	double* DjArray;
	
public:
	vector<Node> vertexArray;
	int** map;
	vector<Edge> edgeArray;
	Graph(int n, int m);
	/// <summary>
	/// 获取结点数
	/// </summary>
	/// <returns>结点数</returns>
	int getVertexNum();
	/// <summary>
	/// 获取边数
	/// </summary>
	/// <returns>边数</returns>
	int getEdgeNum();
	/// <summary>
	/// 获取两点之间的最短路径
	/// </summary>
	void getShortestPath(int start, int end);
	/// <summary>
	/// 获取最小的顶点值
	/// </summary>
	int minVertex();
	/// <summary>
	/// 获取第一个邻结点
	/// </summary>
	/// <param name="id">结点编号</param>
	int getFirstNeighbor(const int id);
	/// <summary>
	/// 获取下一个邻结点
	/// </summary>
	/// <param name="id1">结点编号1</param>
	/// <param name="id2">结点编号2</param>
	int getNextNeighbor(const int id1, const int id2);
	/// <summary>
	/// 获取矩阵
	/// </summary>
	Weight** getMartix();
	/// <summary>
	/// 增加新边
	/// </summary>
	/// <param name="s">边的初始结点</param>
	/// <param name="e">边的末节点</param>
	/// <param name="len">边的权重值</param>
	void addEdge(Node s, Node e, Weight w);
	/// <summary>
	/// 展示邻接矩阵
	/// </summary>
	void print();
	/// <summary>
	/// 判断边是否存在
	/// </summary>
	/// <param name="s">边的初始结点</param>
	/// <param name="e">边的末结点</param>
	bool isExistEdge(Node s, Node e);
	/// <summary>
	/// 判断结点是否存在
	/// </summary>
	bool isExistNode(Node n);
	/// <summary>
	///寻找结点
	/// </summary>
	Node findVertex(int id);
	/// <summary>
	///寻找结点重载
	/// </summary>
	Node findVertex(int x,int y);
	/// <summary>
	/// 设置标记
	/// </summary>
	void setMark(int id, int label);
	/// <summary>
	///寻找边
	/// </summary>
	Edge findEdge(Node s, Node e);
	/// <summary>
	/// Dijkstra寻路
	/// </summary>
	void Dijkstra(Stack<Node>& s, int start, int end);
	/// <summary>
	/// 快速排序
	/// </summary>
	void quickSort(double* arr, int start, int end);
	/// <summary>
	/// Dijkstra寻路重载
	/// </summary>
	void Dijkstra(queue<Node>&q, int start);
	~Graph();
	/// <summary>
	/// 车流刷新函数
	/// </summary>
	void refreshCarFlow();
	/// <summary>
	/// 车流刷新用寻边函数
	/// </summary>
	/// <returns></returns>
	Edge findEdge_refresh(Node s, Node e);
	/// <summary>
	/// 通用更新车流函数
	/// </summary>
	void refresh();
};
