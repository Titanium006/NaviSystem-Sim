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
using namespace std;

#define MaxCapacity 100
#define MinCapacity 10

class Weight
{
private:
	double length;
	int carNum;
	int carCapacity;
public:
	Weight();
	Weight(double l, int cn);
	/// <summary>
	/// 获取长度权重
	/// </summary>
	double getLength()const;
	/// <summary>
	/// 设置长度权重
	/// </summary>
	void setLength(double l);
	/// <summary>
	/// 获取当前车辆数目
	/// </summary>
	double getCarNum()const;
	/// <summary>
	/// 设置当前车辆数目
	/// </summary>
	void setCarNum(double cn);
	/// <summary>
	/// 获取车容量
	/// </summary>
	double getCarCapacity()const;
	/// <summary>
	/// 设置车容量
	/// </summary>
	void setCarCapacity(double cc);
};

