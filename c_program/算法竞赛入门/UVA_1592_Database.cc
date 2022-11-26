/*
    输入一个n行m列的数据库（n【1-10000】，m【1,10】）寻找满足如下关系的行列：
        存在两个不同行r1，r2，两个不同列c1，c2，
        使得(r1,c1)=(r2,c1),(r1,c2)=(r2,c2),即为行相等
    解法：
        一、四重循环暴力枚举。
        二、只枚举c1，c2，然后从上到下扫描各行。每次碰到一个新的行r，把c1，c2内容作为一个
            二元组存到一个map中，如果map中的键值中已经存在这个二元组，
            该映射到的就是所要求的的r1，当前行为r2.
            在主循环之前做一个预处理，给所有字符串分配一个编号，即二元组变为整数。
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;

const int maxn = 10000+10;
const int maxm = 10+1;
map<string,int> IDcache;    // 将字符串映射为ID
typedef pair<int,int> PL;   // 映射为ID后的二元组
int id=0;   // 字符串id从0开始递增
int m=1,n=1;    // n行，m列
int database[maxn][maxm];// 转换为ID的字符串数据库
int DistributeID(const string &s){
    // 为一个字符串s分配ID，若已存在返回原有ID，若不存在则分配一个
    if(!IDcache.count(s))
        IDcache[s] = id++;
    return IDcache[s];  // 返回ID        
}
void Findthat(){
    int c1,c2;
    for(c1=0;c1<m-1;c1++){
        for(c2=c1+1;c2<m;c2++){
            map<PL,int> findcache;  // 将二元组映射为整数，该整数为二元组的行
            for(int i=0;i<n;i++){
                PL temp = make_pair(database[i][c1],database[i][c2]);
                if(findcache.count(temp)){  // 找到
                    puts("NO");
                    printf("%d %d\n",findcache[temp],i);
                    printf("%d %d\n",c1,c2);
                    return; // 结束寻找
                }
                findcache[temp] = i;
            }

        }
    }
    printf("YES\n");
}
int main(){
    while(cin >> n >> m &&m&&n){  // n行m列
        getchar();  // 换行符！
        IDcache.clear();    // 清空map
        string temp;
        for(int i=0;i<n;i++){
            getline(cin,temp);  // 读取一行
            int pos = -1;    // 分割字符串时的起始位置
            for(int j=0;j<m;j++){
                int p = temp.find(',',pos+1);
                if(p == string::npos)   // 没找到分割位
                    p = temp.length();  // 分割位为结束
                database[i][j] = DistributeID(temp.substr(pos+1,p-pos-1));
                pos = p;
            }
        }
        Findthat();
    }
}