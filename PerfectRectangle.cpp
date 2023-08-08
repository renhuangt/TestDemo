#include <iostream>
#include <vector>
#include <limits>
#include <unordered_set>

using namespace std;

/*
 * 一个矩阵可以由左上角点的坐标和右下角点的坐标代表。
 * 给定一些矩阵， 请返回这些矩阵全拼在一起， 能否拼出完美的矩形？
 * 完美的矩形指， 内部没有重叠、 没有突出和凹陷、 所有矩形正好拼成一块。
 */

//两个标准
//1.除了整个拼成的大矩形的最左下、最左上、最右上、最右下的点出现一次，其余点都出现了2次
//2.拼成的整个大矩形的面积是所有小矩形的面积的和

class PerfectRectangle{

public:
    bool isRectangleCover(vector< vector<int> >& rectangles){

        if(rectangles.size() == 0 || rectangles[0].size() == 0)
            return false;

        int xL = std::numeric_limits<int>::max();
        int yD = std::numeric_limits<int>::max();
        int xR = std::numeric_limits<int>::min();
        int yU = std::numeric_limits<int>::min();
        unordered_set<string> mySet;
        int area = 0;   //每一个小矩形，累加的面积和

        for(vector<int> rect : rectangles){

            //rect[0]: 左下角点x坐标
            //rect[1]: 左下角点y坐标
            //rect[2]: 右上角点x坐标
            //rect[3]: 右上角点y坐标
            xL = min(xL, rect[0]);
            yD = min(yD, rect[1]);
            xR = max(xR, rect[2]);
            yU = max(yU, rect[3]);
            area += (rect[2] - rect[0]) * (rect[3] - rect[1]);  //所有小矩形的面积累加和

            string s1 = to_string(rect[0]) + "_" + to_string(rect[1]);    //左下角的点下标
            string s2 = to_string(rect[0]) + "_" + to_string(rect[3]);    //左上角的点下标
            string s3 = to_string(rect[2]) + "_" + to_string(rect[3]);    //右上角的点下标
            string s4 = to_string(rect[2]) + "_" + to_string(rect[1]);    //右下角的点下标

            //之前加过，返回false
            //之前没加过，返回true
            //加入过偶数次就删除，加入过奇数次就保留
            if(!mySet.insert(s1).second) mySet.erase(s1);
            if(!mySet.insert(s2).second) mySet.erase(s2);
            if(!mySet.insert(s3).second) mySet.erase(s3);
            if(!mySet.insert(s4).second) mySet.erase(s4);
        }

        if((mySet.find(to_string(xL) + "_" + to_string(yD)) == mySet.end())
                || (mySet.find(to_string(xL) + "_" + to_string(yU)) == mySet.end())
                || (mySet.find(to_string(xR) + "_" + to_string(yU)) == mySet.end())
                || (mySet.find(to_string(xR) + "_" + to_string(yD)) == mySet.end())
                || (mySet.size() != 4))
            return false;

        return area == (xR - xL) * (yU - yD);
    }
};

int main()
{
    vector< vector<int> > matrix = { {2, 2, 4, 4}, {4, 2, 6, 4}, {2, 4, 6, 6} };
    PerfectRectangle ans;

    cout << ans.isRectangleCover(matrix) << endl;

    return 0;
}
