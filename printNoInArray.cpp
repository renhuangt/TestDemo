#include <iostream>
#include <vector>

using namespace std;

/*
 * 给定一个整数数组A，长度为n，有1<= A[i] <= n，且对于[1,n]的整数，其中部分整数会重复出现而部分不会出现。
 *实现算法找到[1,n]中所有未出现在A中的整数。
 *提示：尝试实现O(n)的时间复杂度和O(1)的空间复杂度（返回值不计入空间复杂度）
 *
 */

class PrintNoInArray{

public:
    void printNoInArray(vector<int> arr){

        if(arr.empty() || arr.size() < 1)
            return;

        for(unsigned int i = 0; i < arr.size(); ++i)
            modify(arr, arr[i]);

        for(unsigned int i = 0; i < arr.size(); ++i)
            if(arr[i] != i + 1)
                cout << i + 1 << " ";
    }

private:
    void modify(vector<int>& arr, int value){

        while(arr[value - 1] != value){

            int tmp = arr[value - 1];
            arr[value - 1] = value;
            value = tmp;
        }
    }
};

int main()
{
    vector<int> arr = {3, 2, 3, 1, 4};
    PrintNoInArray ans;

    ans.printNoInArray(arr);

    return 0;
}
