#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <limits>
#include "Node.h"
using namespace std;
float SquareDistance(Node& A, Node& B);
bool K_means(vector<Node>& dataset, int k, int sub);