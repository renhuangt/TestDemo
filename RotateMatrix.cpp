#include <iostream>
#include <vector>

using namespace std;

/*
 * 给定一个正方形矩阵， 只用有限几个变量， 实现矩阵中每个位置的数顺时针转动90度， 比如如下的矩阵
 * 0 1 2 3
 * 4 5 6 7
 * 8 9 10 11
 * 12 13 14 15
 * 矩阵应该被调整为：
 * 12 8 4 0
 * 13 9 5 1
 * 14 10 6 2
 * 15 11 7 3
 */

class RotateMatrix{

public:
    void rotate(vector< vector<int> >& matrix){

        int tR = 0;
        int tC = 0;
        int dR = matrix.size() - 1;
        int dC = matrix[0].size() - 1;
        while(tR < dR)
            rotateEdge(matrix, tR++, tC++, dR--, dC--);
    }

    void printEdge(vector< vector<int> >& matrix){

        for(int i = 0; i < matrix.size(); ++i){

            for(int j = 0; j < matrix[0].size(); ++j)
                cout << matrix[i][j] << " ";

            cout << endl;
        }
    }

private:
    void rotateEdge(vector< vector<int> >& matrix, int tR, int tC, int dR, int dC){

        int times = dC - tC;
        int tmp = 0;
        for(int i = 0; i != times; ++i){

            tmp = matrix[tR][tC + i];
            matrix[tR][tC + i] = matrix[dR - i][tC];
            matrix[dR - i][tC] = matrix[dR][dC - i];
            matrix[dR][dC - i] = matrix[tR + i][dC];
            matrix[tR + i][dC] = tmp;
        }
    }
};

int main()
{
    vector< vector<int> > arr = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
    RotateMatrix matrix;

    matrix.rotate(arr);

    matrix.printEdge(arr);

    return 0;
}
