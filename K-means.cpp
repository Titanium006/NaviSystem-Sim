#include "K-means.h"
float SquareDistance(Node& A, Node& B) {
    return (A.getX() - B.getX()) * (A.getX() - B.getX()) + (A.getY() - B.getY()) * (A.getY() - B.getY());
}
bool K_means(vector<Node>& dataset, int k, int sub) 
{
    vector<Node> centroid;//质心set

    //srand()函数为随机生成种子设置函数
    //time(0)为时间计算函数，1970.1.1到现在的时间
    //一下代码即表示随机重置种子
    //srand((int)time(0));

    int n = 1;
    int length = dataset.size();
    while (n <= k) {
        int cen = (float)rand() / (RAND_MAX + 1) * length;
        Node p(dataset[cen].getX(), dataset[cen].getY(),dataset[cen].getId(), sub, n);
        centroid.push_back(p);
        n++;
    }

    //显示随机生成的质心
    //for (int i = 0; i < k; i++) {
    //    cout << "x:" << centroid[i].getX() << "\ty:" << centroid[i].getY() << "\tc:" << centroid[i].getCluster(sub) << endl;
    //}

    //int time = 100;
    int oSSE = INT_MAX;
    int nSSE = 0;
    while (abs(oSSE - nSSE) >= 1) {
        oSSE = nSSE;
        nSSE = 0;
        //update cluster for all the Nodes
        for (int i = 0; i < length; i++) {
            int shortest = INT_MAX;//定义最短距离
            int n = 1;
            int cur = dataset[i].getCluster(sub);
            while (n <= k)
            {
                float distance = SquareDistance(dataset[i], centroid[n - 1]);
                if (distance < shortest) {
                    cur = n;
                    shortest = distance;
                }
                n++;
            }
            dataset[i].setCluster(sub, cur);
        }
        //update the centroid
        int* FenMu = new int[k];
        //分母设置初值0
        for (int i = 0; i < k; i++) {
            FenMu[i] = 0;
        }
        //质心重置值为0
        for (int i = 0; i < k; i++) {
            centroid[i] = Node(0, 0, i, sub, i + 1);
        }
        //统计每个质心x，y总和，个数
        for (int i = 0; i < length; i++) {
            //centroid[dataset[i].getCluster() - 1].x += dataset[i].x;
            centroid[dataset[i].getCluster(sub) - 1].setX(centroid[dataset[i].getCluster(sub) - 1].getX() + dataset[i].getX());
            //centroid[dataset[i].getCluster() - 1].y += dataset[i].y;
            centroid[dataset[i].getCluster(sub) - 1].setY(centroid[dataset[i].getCluster(sub) - 1].getY() + dataset[i].getY());
            FenMu[dataset[i].getCluster(sub) - 1]++;
        }
        //质心计算完成
        for (int i = 0; i < k; i++) {
            if (FenMu[i] == 0)
            {
                return false;   // 出现0作除数的情况，聚类不成功，返回false值
            }
            centroid[i].setX(centroid[i].getX() / FenMu[i]);
            centroid[i].setY(centroid[i].getY() / FenMu[i]);
        }

        //以下测试当前时间的变化，并输出每次迭代的结果直到最终收敛
        //cout << "time:" << time << endl;
        //for (int i = 0; i < k; i++) {
        //    cout << "x:" << centroid[i].getX() << "\ty:" << centroid[i].getY() << "\tc:" << centroid[i].getCluster(sub) << endl;
        //}

        //SSE
        //此方法通过abs（oSSE>nSSE)的判断不断收敛
        for (int i = 0; i < length; i++) {
            nSSE += SquareDistance(centroid[dataset[i].getCluster(sub) - 1], dataset[i]);
        }
    }
    return true;
}