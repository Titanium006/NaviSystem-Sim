#include "K-means.h"
float SquareDistance(Node& A, Node& B) {
    return (A.getX() - B.getX()) * (A.getX() - B.getX()) + (A.getY() - B.getY()) * (A.getY() - B.getY());
}
bool K_means(vector<Node>& dataset, int k, int sub) 
{
    vector<Node> centroid;//����set

    //srand()����Ϊ��������������ú���
    //time(0)Ϊʱ����㺯����1970.1.1�����ڵ�ʱ��
    //һ�´��뼴��ʾ�����������
    //srand((int)time(0));

    int n = 1;
    int length = dataset.size();
    while (n <= k) {
        int cen = (float)rand() / (RAND_MAX + 1) * length;
        Node p(dataset[cen].getX(), dataset[cen].getY(),dataset[cen].getId(), sub, n);
        centroid.push_back(p);
        n++;
    }

    //��ʾ������ɵ�����
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
            int shortest = INT_MAX;//������̾���
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
        //��ĸ���ó�ֵ0
        for (int i = 0; i < k; i++) {
            FenMu[i] = 0;
        }
        //��������ֵΪ0
        for (int i = 0; i < k; i++) {
            centroid[i] = Node(0, 0, i, sub, i + 1);
        }
        //ͳ��ÿ������x��y�ܺͣ�����
        for (int i = 0; i < length; i++) {
            //centroid[dataset[i].getCluster() - 1].x += dataset[i].x;
            centroid[dataset[i].getCluster(sub) - 1].setX(centroid[dataset[i].getCluster(sub) - 1].getX() + dataset[i].getX());
            //centroid[dataset[i].getCluster() - 1].y += dataset[i].y;
            centroid[dataset[i].getCluster(sub) - 1].setY(centroid[dataset[i].getCluster(sub) - 1].getY() + dataset[i].getY());
            FenMu[dataset[i].getCluster(sub) - 1]++;
        }
        //���ļ������
        for (int i = 0; i < k; i++) {
            if (FenMu[i] == 0)
            {
                return false;   // ����0����������������಻�ɹ�������falseֵ
            }
            centroid[i].setX(centroid[i].getX() / FenMu[i]);
            centroid[i].setY(centroid[i].getY() / FenMu[i]);
        }

        //���²��Ե�ǰʱ��ı仯�������ÿ�ε����Ľ��ֱ����������
        //cout << "time:" << time << endl;
        //for (int i = 0; i < k; i++) {
        //    cout << "x:" << centroid[i].getX() << "\ty:" << centroid[i].getY() << "\tc:" << centroid[i].getCluster(sub) << endl;
        //}

        //SSE
        //�˷���ͨ��abs��oSSE>nSSE)���жϲ�������
        for (int i = 0; i < length; i++) {
            nSSE += SquareDistance(centroid[dataset[i].getCluster(sub) - 1], dataset[i]);
        }
    }
    return true;
}