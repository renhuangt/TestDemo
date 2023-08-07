#include <iostream>
#include <vector>

using namespace std;

/*
 * 有n个打包机器从左到右一字排开， 上方有一个自动装置会抓取一批放物品到每个打包机上，
 * 放到每个机器上的这些物品数量有多有少， 由于物品数量不相同，
 * 需要工人将每个机器上的物品进行移动从而到达物品数量相等才能打包。
 * 每个物品重量太大、每次只能搬一个物品进行移动， 为了省力， 只在相邻的机器上移动。
 * 请计算在搬动最小轮数的前提下， 使每个机器上的物品数量相等。 如果不能使每个机器上的物品相同，返回-1。
 * 例如[1,0,5]表示有3个机器， 每个机器上分别有1、 0、 5个物品， 经过这些轮后：
 * 第一轮： 1 0 <- 5 => 1 1 4
 * 第二轮： 1 <- 1 <- 4 => 2 1 3
 * 第三轮： 2 1 <- 3 => 2 2 2
 * 移动了3轮， 每个机器上的物品相等， 所以返回3
 * 例如[2,2,3]表示有3个机器， 每个机器上分别有2、 2、 3个物品，
 * 这些物品不管怎么移动， 都不能使三个机器上物品数量相等， 返回-1
 */

class PackingMachine{

public:
    int minOps(vector<int> arr){

        if(arr.empty() || arr.size() < 0)
            return 0;

        int size = static_cast<int>(arr.size());
        int sum = 0;
        for(unsigned int i = 0; i < arr.size(); ++i)
            sum += arr[i];

        if(sum % size != 0)
            return -1;

        int avg = sum / size;//平均每台机器上应该有的包裹数量
        int leftSum = 0;//假设当前处于i为止，我i左侧一共的包裹数量
        int res = 0;
        for(unsigned int i = 0; i < arr.size(); ++i){

            int L = i * avg - leftSum;//(i * avg): i左侧机器一共需要的包裹数量; leftSum: i左侧机器实际的包裹数量
            //(size - i - 1) * avg: i右侧机器一共需要的包裹数量; (sum - leftSum - arr[i]): i右侧机器实际的包裹数量
            int R = (size - i - 1) * avg - (sum - leftSum - arr[i]);
            if(L > 0 && R > 0){//左右两边都需要包裹，当前i位置包裹数量最多，因此要往两边给，但是一次只能给一件

                res = max(res, abs(L) + abs(R));

            }else{

                res = max(res, max(abs(L), abs(R)));//给包裹的动作可以和接收包裹的动作同时进行
            }

            leftSum += arr[i];
        }

        return res;
    }
};

int main()
{
    vector<int> arr = {1, 0, 5};
    PackingMachine machine;

    cout << machine.minOps(arr) << endl;

    return 0;
}
