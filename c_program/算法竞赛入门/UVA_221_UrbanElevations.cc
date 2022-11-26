/*
    有n个建筑物，输入每个建筑物的左下角（俯视图）坐标（即x、y坐标的最小值）、
    宽度（即x方向的长度）、深度（即y方向的长度）和高度（以上均为实数），
    输出正视图中能看到的所有建筑物，按照左下角x坐标从小到大进行排序，
    左下角x坐标相同时按照y坐标从小到大排序。这道题的输入不会引起精度问题。

 离散化！

    由于x坐标上在实数范围内有无限个点，不可能枚举所有的坐标，所以我们的办法就是离散化。
    将所有的建筑物的左右点坐标存储与数组x中，然后对x进行排序去重，
    则数组中任意两个相邻x坐标形成的区间要么完全可见，要么完全不可见。
    这样，只需要在该区间任意选取一点（我们选取中点），
    就能判断某一个建筑物在该区间内是否可见。
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100 + 5;
struct Building {
    int id;     // 编号
    double x,y,w,d,h;   // 左下角坐标，x方向宽，y方向深度，z方向高度
    bool operator < (const Building &rhs) const {   // sort使用
        return x<rhs.x || (x==rhs.x && y<rhs.y);    // 要么偏左，要么偏后
    }
}b[maxn];

int n;  // 总建筑数
double x[maxn*2];
// 判断建筑物i是否覆盖x=mx点
bool cover(int i,double mx){
    return b[i].x<=mx && b[i].x+b[i].w >= mx;   // x<mx且x+w>mx
}
// 判断建筑物i在x=mx处是否可见
bool visible(int i,double mx){
    if(!cover(i,mx))    return false;
    for(int k=0;k<n;k++)    // 建筑物i覆盖mx点 遍历所有建筑
        if(b[k].y<b[i].y && b[k].h>=b[i].h && cover(k,mx)) return false;
        // 如果有一个建筑在建筑物i前面且比i高并且也覆盖mx点则建筑物i不可见
    return true;
}

int main(){
    int kase=0;
    while(scanf("%d",&n)==1 && n){  // 成功读入且不为0
        for(int i=0;i<n;i++){   // 一次读入n个建筑的信息
            scanf("%lf%lf%lf%lf%lf",&b[i].x,&b[i].y,&b[i].w,
                &b[i].d,&b[i].h);
            x[i*2] = b[i].x;        // 堆！i*2为i建筑的左x值 i*2+1为建筑的右x值
            x[i*2+1] = b[i].x + b[i].w;
            b[i].id = i+1;  // id从1开始
        }
        sort(b,b+n);    // 对建筑物进行排序
        sort(x,x+n*2);  // 对x坐标进行排序
        int m = unique(x,x+n*2) - x;    // x坐标排序去重 得到m个坐标
        if(kase++)  printf("\n");
        printf("For map #%d, the visible buildings are numbered as follows:\n%d",
            kase,b[0].id);  // 第一个一定可见
        for(int i=1;i<n;i++){   // 遍历所有建筑
            bool vis = false;   // 可见标志
            for(int j=0;j<m-1;j++)  // 对每一个建筑遍历所有不重复的坐标中点
                if(visible(i,(x[j]+x[j+1])/2)){
                    vis = true;
                    break;
                }
            if(vis)
                printf(" %d",b[i].id);
        }
        printf("\n");
    }
    return 0;
}