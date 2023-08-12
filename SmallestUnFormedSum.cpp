#include <iostream>
#include <vector>
#include <unordered_set>
#include <limits>
#include <algorithm>

using namespace std;

/*
 * 给定一个正数数组arr，其中所有的值都为整数，以下是最小不可组成和的概念:
 * 把 arr 每个子集内的所有元素加起来会出现很多值， 其中最小的记为 min，最大的记为max,
 * 在区间[min,max]上，如果有数不可以被arr某一个子集相加得到，那么其中最小的那个数是arr的最小不可组成和,
 * 在区间[min,max]上，如果所有的数都可以被arr的某一个子集相加得到，那么max+1是arr的最小不可组成和,
 * 请写函数返回正数数组 arr 的最小不可组成和。
 * 【举例】
 * arr=[3,2,5]。子集{2}相加产生2为 min，子集{3,2,5}相加产生 10 为 max。
 * 在区间[2,10]上，4、6和9不能被任何子集相加得到，其中 4 是 arr 的最小不可组成和。
 * arr=[1,2,4]。子集{1}相加产生 1 为 min，子集{1,2,4}相加产生 7 为 max。
 * 在区间[1,7]上，任何 数都可以被子集相加得到，所以 8 是 arr 的最小不可组成和。
 */

// [进阶]
// 如果已知正数数组 arr 中肯定有 1 这个数， 是否能更快地得到最小不可组成和?

class SmallestUnFormedSum{

public:
    int unFormedSum1(vector<int>& arr){

        if(arr.empty() || arr.size() == 0)
            return 0;

        unordered_set<int> mySet;
        process(arr, 0, 0, mySet);//从[0]位置出发，之前形成的累加和为0
        int mins = std::numeric_limits<int>::max();

        for(int i = 0; i < arr.size(); ++i)
            mins = min(mins, arr[i]);

        for(int i = mins + 1; i != std::numeric_limits<int>::min(); ++i){

            if(mySet.find(i) == mySet.end())
                return i;
        }

        return 0;
    }

    int unFormedSum2(vector<int>& arr){

        if(arr.empty() || arr.size() == 0)
            return 0;

        int sum = 0;
        int mins = std::numeric_limits<int>::max();
        for(unsigned int i = 0; i < arr.size(); ++i){

            sum += arr[i];
            mins = min(mins, arr[i]);
        }

        vector<bool> dp(sum + 1, 0);
        dp[0] = true;
        for(unsigned int i = 0; i < arr.size(); ++i){

            for(int j = sum; j >= arr[i]; --j)
                dp[j] = dp[j - arr[i]] ? true : dp[j];
        }

        for(int i = mins; i != dp.size(); ++i)
            if(!dp[i])
                return i;

        return sum + 1;
    }

    //进阶问题
    int unFormedSum3(vector<int>& arr){

        if(arr.empty() || arr.size() == 0)
            return 0;

        sort(arr.begin(), arr.end());
        int range = 0;//我能搞定的数的范围
        for(unsigned int i = 0; i < arr.size(); ++i){

            if(arr[i] > range + 1){

                return range + 1;

            }else{

                range += arr[i];
            }
        }

        return range + 1;
    }

private:
    //来到当前位置i, 之前形成的累加和preSum
    void process(vector<int>& arr, int i, int preSum, unordered_set<int>& mySet){

        if(i == arr.size()){

            mySet.insert(preSum);
            return;
        }

        process(arr, i + 1, preSum, mySet);//不要当前数
        process(arr, i + 1, preSum + arr[i], mySet);//要当前数
    }
};

int main()
{
    vector<int> arr = {3, 2, 5};
    SmallestUnFormedSum ans;

    cout << ans.unFormedSum1(arr) << endl;
    cout << ans.unFormedSum2(arr) << endl;

    vector<int> arr2 = {1, 2, 4};
    cout << ans.unFormedSum1(arr2) << endl;
    cout << ans.unFormedSum2(arr2) << endl;

    cout << "=====================" << endl;

    vector<int> arr3 = {4, 1, 2, 9};
    cout << ans.unFormedSum3(arr3) << endl;

    return 0;
}
