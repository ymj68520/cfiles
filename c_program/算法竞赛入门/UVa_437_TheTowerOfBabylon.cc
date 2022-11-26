#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

struct block{
    int x,y,z;
};

int main(){
    vector<block> blocks;
    int n,x1,y1,z1;
    cin >> n;
    if(n==0)    return 0;
    for(int i=0;i<n;i++){
        cin >> x1 >> y1 >> z1;
        blocks.push_back({x1,y1,z1});
        blocks.push_back({x1,z1,y1});
        blocks.push_back({y1,x1,z1});
        blocks.push_back({y1,z1,x1});
        blocks.push_back({z1,x1,y1});
        blocks.push_back({z1,y1,x1});
    }
    sort(blocks.begin(),blocks.end(),[](block a,block b){
            if(a.x != b.x)  return a.x < b.x;
            else if(a.y != b.y) return a.y < b.y;
            else    return a.z < b.z;
    });
    int size = blocks.size();
    int maxHigh = 0;
    int dp[255];memset(dp,0,sizeof(dp));
    for(int i=0;i<size;i++){
        dp[i] = blocks[i].z;
        for(int j=0;j<i;j++){
            if(blocks[i].x > blocks[j].x && blocks[i].y > blocks[j].y)
                dp[i] = max(dp[i],dp[j]+blocks[i].z);
        }
        maxHigh = max(maxHigh, dp[i]);
    }

    cout << maxHigh << endl;

    return 0;

}