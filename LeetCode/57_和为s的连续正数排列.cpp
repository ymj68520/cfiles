#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > findContinuousSequence(int target) {
    int i = 1; // 滑动窗口的左边界
    int j = 1; // 滑动窗口的右边界
    int sum = 0; // 滑动窗口中数字的和
    vector<vector<int>> res;

    while (i <= target / 2) {   // 大于一半必不可能等于
        if (sum < target) {
            // 右边界向右移动
            sum += j;
            j++;
        } else if (sum > target) {
            // 左边界向右移动
            sum -= i;
            i++;
        } else {
            // 记录结果
            vector<int> arr;
            for (int k = i; k < j; k++) {
                arr.push_back(k);
            }
            res.push_back(arr);
            // 左边界向右移动
            sum -= i;
            i++;
        }
    }

    return res;
}

int main(){
    int t = 15;
    vector<vector<int> > r = findContinuousSequence(t);
    for(vector<vector<int> >::iterator i=r.begin();i!=r.end();i++){
        for(vector<int>::iterator j = (*i).begin();j!=(*i).end();j++)
            cout << *j << " ";
        cout << endl;
    }

    return 0;
}