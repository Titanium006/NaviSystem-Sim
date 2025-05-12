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
#include "Node.h"
#include "Edge.h"
#include "Graph.h"
#include "Weight.h"
using namespace std;

template<class T>
class Stack 
{
private:
	T* pBuff;
	size_t len;
public:
	Stack()
	{
		pBuff = NULL;
		len = 0;
	}
	~Stack()
	{
		if (pBuff)
		{
			delete[]pBuff;
		}
		pBuff = NULL;
		len = 0;
	}
	/// <summary>
	/// 存入数据
	/// </summary>
	void push(const T& data)
	{
		T* pTemp = new T[len + 10000];//开内存
		if (pBuff)
		{
			memcpy(pTemp, pBuff, sizeof(T) * len);//拷贝数据
			delete[]pBuff;//释放
		}
		pBuff = pTemp;
		pBuff[len++] = data;
	}
	/// <summary>
	/// 获取最上面的数据
	/// </summary>
	T getTop()
	{
		return pBuff[len - 1];
	}
	/// <summary>
	/// 弹出最上面的数据
	/// </summary>
	void pop()
	{
		len--;
	}
	/// <summary>
	/// 判断栈是否为空
	/// </summary>
	bool isEmpty()
	{
		return(len == 0);
	}
	size_t size()
	{
		return this->len;
	}
};//栈结构创建