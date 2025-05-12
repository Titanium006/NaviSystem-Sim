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
using namespace std;

/// <summary>
/// 图的结点类
/// x为结点横坐标
/// y为结点纵坐标
/// id为结点编号
/// </summary>
class Node
{
private:
	int x;
	int y;
	int id;
	int cluster[3];		// 预设有3个聚类缩放比例
public:
	/// <summary>
	/// 结点Node的有参构造函数
	/// </summary>
	/// <param name="x">横坐标</param>
	/// <param name="y">纵坐标</param>
	/// <param name="id">结点编号</param>
	/// <param name="sub">聚类缩放比例编号，从0开始</param>
	/// <param name="c">聚类组号</param>
	Node(const int x, const int y, const int id, const int sub = 0, const int c = 0);
	/// <summary>
	/// 结点Node的无参构造函数
	/// </summary>
	Node();
	/// <summary>
	/// 结点Node的析构函数
	/// </summary>
	~Node();
	/// <summary>
	/// 获取结点横坐标
	/// </summary>
	/// <returns>横坐标x</returns>
	int getX()const;
	/// <summary>
	/// 获取结点纵坐标
	/// </summary>
	/// <returns>纵坐标y</returns>
	int getY()const;
	/// <summary>
	/// 获取结点编号
	/// </summary>
	/// <returns>结点编号id</returns>
	int getId()const;
	/// <summary>
	/// 获取聚类编号
	/// </summary>
	/// <param name="sub">输入所需聚类编号，从0开始</param>
	/// <returns></returns>
	int getCluster(int sub)const;
	/// <summary>
	/// 设置结点横坐标
	/// </summary>
	/// <param name="x">横坐标</param>
	void setX(int x);
	/// <summary>
	/// 设置结点纵坐标
	/// </summary>
	/// <param name="y">纵坐标</param>
	void setY(int y);
	/// <summary>
	/// 设置结点编号
	/// </summary>
	/// <param name="id">编号</param>
	void setId(int id);
	/// <summary>
	/// 设置聚类组号
	/// </summary>
	/// <param name="c"></param>
	void setCluster(int sub, int c);
	Node& operator= (const Node& node)
	{
		if (this != &node)
		{
			this->x = node.x;
			this->y = node.y;
			this->id = node.id;
		}
		return *this;
	}
	bool operator== (Node& node)
	{
		if (this == &node)
		{
			return true;
		}
		else if (this->x == node.x && this->y == node.y && this->id == node.id)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};