#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <cstring>
#include <random>
#include <iomanip>
#include <queue>
#include "Node.h"
#include "Weight.h"
using namespace std;

#define CFront 0.1
#define CFunc 1

/// <summary>
/// 图的边类
/// start为图的第一个结点
/// end为图的第二个结点
/// length为图的权重值，后续完善，暂时用double定义
/// </summary>
class Edge
{
	friend class Weight;
private:
	Node start;
	Node end;
	Weight weight;
	static int count;//打印边时记录当前数目位置
public:
	Edge();
	~Edge();
	Edge(Node s, Node e, Weight len);
	/// <summary>
	/// 获取结点1
	/// </summary>
	/// <returns>结点1 start</returns>
	Node getStart()const;
	/// <summary>
	/// 获取结点2
	/// </summary>
	/// <returns>结点2 end</returns>
	Node getEnd()const;
	/// <summary>
	/// 打印边
	/// </summary>
	void print();
	/// <summary>
	/// 获取边的权重值
	/// </summary>
	/// <returns>权重值weight</returns>
	Weight getWeight()const;
	Edge& operator=(const Edge& edge)
	{
		if (this != &edge)
		{
			this->start = edge.start;
			this->end = edge.end;
			this->weight = edge.weight;
		}
		return *this;
	}
	/// <summary>
	/// 获取通行时间分段函数值
	/// </summary>
	double getCarFuncValue();
	/// <summary>
	/// 获取车流量
	/// </summary>
	double getCarStream();
	/// <summary>
	/// 设置边的起点
	/// </summary>
	/// <param name="s"></param>
	void setStart(Node s);
	/// <summary>
	/// 设置边的终点
	/// </summary>
	/// <param name="e"></param>
	void setEnd(Node e);
	/// <summary>
	/// 设置边的权重
	/// </summary>
	/// <param name="w"></param>
	void setWeight(Weight w);
};

