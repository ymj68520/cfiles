/*
    思路:输入T组数据,首先猜测T数值并不大,
    输入n元组3 ≤ n ≤ 15,看出最大也就15,而每次走一步也就为n,
    最多也就1000步,数值很小所以直接穷举便可,循环节也就可以直接忽略
*/
/*
#include <iostream>
#include <cmath>
#include <set>
#include <vector>
using namespace std;

int main(){
    set<vector<int> > setofntuple;
    vector<int> ntuple,temp,zero;
    int T,n;
    scanf("%d%*c",&T);
    while(T--){
        setofntuple.clear();
        ntuple.clear();
        scanf("%d%*c",&n);
        for(int i=0;i<n;i++)
            zero.push_back(0);
        
        for(int i=0,t;i<n;i++){
            cin >> t;
            ntuple.push_back(t);
        }
        while(1){
            if(ntuple == zero){
                printf("ZERO");
                break;
            }
            setofntuple.insert(ntuple);
            for(int i=0;i<n;i++)
                temp[i] = abs(ntuple[i]-ntuple[(i+1)%(n-1)]);
            if(setofntuple.count(temp)){
                printf("LOOP\n");
                break;
            }
            ntuple = temp;
        }
    }
    return 0;
}*/
#include <iostream>
#include <vector>
#include <cmath>//绝对值函数abs()
using namespace std;

int main()
{
    int group;//表示一共几组数据
    int n;//表示接下来输入的数据是几元
    int num;//组数据里面的数字
    cin >> group;
    for (int i = 1; i <= group; i++)
    {
        vector<int> nums;//表示一组数据
        vector <int> tempnums;
        cin >> n;
        for (int j = 1; j <=n ; j++)
        {
            cin >> num;
            nums.push_back(num);
            tempnums.push_back(num);
        }
        for (int k = 0; k < 1000; k++)
        {
            int total = 0;
            for (int j = 0; j< n; j++)
                total += nums[j];
            if (total == 0)
            {
                cout << "ZERO\n";
                break;
            }
            for (int j = 0; j < n; j++)
            {
                if (j==n-1)
                    tempnums[j] = abs(nums[j] - nums[0]);
                else
                    tempnums[j] = abs(nums[j] - nums[j+1]);
            }
            for (int j = 0; j < n; j++)
            {
                nums[j] = tempnums[j];
            }
        }
        int total = 0;
        for (int j = 0; j < n; j++)
            total += nums[j];
        if (total != 0)
        {
            cout << "Loop\n";
        }
    }
    return 0;
}