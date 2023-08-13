#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/*
 * 给定一个正数数组arr， 返回该数组能不能分成4个部分， 并且每个部分的累加和相等， 切分位置的数不要。
 * 例如：
 * arr=[3, 2, 4, 1, 4, 9, 5, 10, 1, 2, 2]
 * 返回true
 * 三个切割点下标为2, 5, 7.
 * 四个子数组为[3,2], [1,4], [5], [1,2,2]
 */

class Split4Parts{

public:
    bool canSplit1(vector<int> arr){

        if(arr.empty() || arr.size() < 7)//分成4部分, 切3刀, 至少要去掉3个数，那么还剩3个数是无法构成4部分的
            return false;

        unordered_set<string> mySet;
        int sum = 0;
        for(unsigned int i = 0; i < arr.size(); ++i)
            sum += arr[i];

        int leftSum = arr[0];
        for(unsigned int i = 1; i < arr.size() - 1; ++i){ //从[1]位置开始切，但是不能且在最后一个位置

            mySet.insert(to_string(leftSum) + "_" + to_string(sum - arr[i] - leftSum));
            leftSum += arr[i];
        }

        int L = 1;
        int LSum = arr[0];
        int R = arr.size() - 2;
        int RSum = arr[arr.size() - 1];
        while(L < R - 3){//为了保证能切出4部分出来

            if(LSum == RSum){

                string lKey = to_string(LSum * 2 + arr[L]);
                string rKey = to_string(RSum * 2 + arr[R]);
                if(mySet.find(lKey + "_" + rKey) != mySet.end()){

                    return true;
                }
                LSum += arr[L++];

            }else if(LSum < RSum){

                LSum += arr[L++];

            }else{

                RSum += arr[R--];
            }
        }

        return false;
    }

    bool canSplit2(vector<int> arr){

        if(arr.empty() || arr.size() < 7)
            return false;

        unordered_map<int, int> myMap;
        int sum = arr[0];
        for(unsigned int i = 1; i < arr.size(); ++i){

            myMap.insert(make_pair(sum, i));
            sum += arr[i];
        }

        int LSum = arr[0];
        for(int cut1 = 1; cut1 < arr.size() - 5; ++cut1){

            int checkSum = 2 * LSum + arr[cut1];
            if(myMap.find(checkSum) != myMap.end()){

                int cut2 = myMap[checkSum];
                checkSum += LSum + arr[cut2];

                if(myMap.find(checkSum) != myMap.end()){

                    int cut3 = myMap[checkSum];
                    if(checkSum + arr[cut3] + LSum == sum)
                        return true;
                }
            }

            LSum += arr[cut1];
        }

        return false;
    }
};

int main()
{
    vector<int> arr = {3, 2, 4, 1, 4, 9, 5, 10, 1, 2, 2};
    Split4Parts ans;

    cout << ans.canSplit1(arr) << endl;
    cout << ans.canSplit2(arr) << endl;

    return 0;
}
