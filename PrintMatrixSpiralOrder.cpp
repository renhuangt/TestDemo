#include <iostream>
#include <vector>

using namespace std;

/*
 * 用螺旋的方式打印矩阵， 比如如下的矩阵
 * 0 1 2 3
 * 4 5 6 7
 * 8 9 10 11
 * 打印顺序为： 0 1 2 3 7 11 10 9 8 4 5 6
 */

class PrintMatrixSpiralOrder{

public:
    void spiralOrderPrint(vector< vector<int> >& matrix){

        int tR = 0;
        int tC = 0;
        int dR = matrix.size() - 1;
        int dC = matrix[0].size() - 1;
        while(tR <= dR && tC <= dC)
            printEdge(matrix, tR++, tC++, dR--, dC--);
    }

private:
    void printEdge(vector< vector<int> >& matrix, int tR, int tC, int dR, int dC){

        if(tR == dR){//左上角的行 和 右下角的行 在同一行, 即只有一行

            for(int i = tC; i <= dC; ++i)
                cout << matrix[tR][i];
        }else if(tC == dC){//左上角的列 和 右下角的列 在同一列，即只有一列

            for(int i = tR; i <= dR; ++i)
                cout << matrix[i][tC];
        }else{

            int curCol = tC;
            int curRow = tR;
            while(curCol != dC){

                cout << matrix[tR][curCol++] << " ";
            }
            while(curRow != dR){

                cout << matrix[curRow++][dC] << " ";
            }
            while(curCol != tC){

                cout << matrix[dR][curCol--] << " ";
            }
            while(curRow != tR){

                cout << matrix[curRow--][tC] << " ";
            }
        }
    }
};

int main()
{
    vector< vector<int> > arr = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
    PrintMatrixSpiralOrder matrix;

    matrix.spiralOrderPrint(arr);

    return 0;
}
