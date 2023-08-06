#include <iostream>
#include <vector>

using namespace std;

/*
 * 给定一个有序的正数数组arr和一个正数range， 如果可以自由选择arr中的数字，
 * 想累加得到 1~range 范围上所有的数， 返回arr最少还缺几个数。
 * 【 举例】
 * arr = {1,2,3,7}， range = 15,
 * 想累加得到 1~15 范围上所有的数， arr 还缺 14 这个数， 所以返回1
 * arr = {1,5,7}， range = 15
 * 想累加得到 1~15 范围上所有的数， arr 还缺 2 和 4， 所以返回2
 */

class MinPatches{

public:
    int minPatches(vector<int>& arr, int range){

        int patches = 0;//缺多少个数字
        int touch = 0; //已经完成了1~touch的目标
        for(unsigned int i = 0; i < arr.size(); ++i){

            while(arr[i] > touch + 1){//先搞定1 ~ arr[i] - 1范围

                touch += touch + 1;//touch + 1是缺的数字
                patches++;
                if(touch >= range)
                    return patches;
            }

            touch += arr[i];
            if(touch >= range)
                return patches;
        }

        while(range >= touch + 1){

            touch += touch + 1;
            patches++;
        }

        return patches;
    }
};

int main()
{
    vector<int> arr = {3, 17, 21, 78};
    MinPatches ans;

    cout << ans.minPatches(arr, 67) << endl;
    return 0;
}
