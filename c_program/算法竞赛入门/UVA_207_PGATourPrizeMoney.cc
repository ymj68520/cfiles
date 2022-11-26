/*
    按照高尔夫球赛的规则处理给出的数据。
    规则是一共有四轮比赛，成绩就是杆数，越少越好。
    一开始所有的人都可以打前两轮，打完之后从里面选出成绩最好的前70名来。
    然后这前70名再打后面两轮，把四轮的成绩加起来得到总排名，然后根据排名发奖金。
    
    比赛当中有业余选手，他们在比赛时和职业选手没有区别，
    同样在比赛结束后参与总排名，但是不参与领奖金，
    比如一个业余选手得了第3名，第4名是职业选手，那么第4名拿第3名的奖金。
    所以发奖金依据的是前70名中职业选手的排名发的。
    也因为业余选手的存在，前70名有可能不全是职业选手导致奖金发不完，如果发不完那么就不发了。

    比赛可能会出现并列的情况。前面选人时，如果选到第70个有并列的情况，
    那么并列的也一同参与到后面两轮的比赛当中，发奖金发前70名。
    最后发奖金时，如果第k名有n人并列，则第k~n+k-1名对应的奖金相加后平均分给这些人，
    名次取第k名，后面加个T，表示并列，平分奖金。
    业余选手不参与领奖金，因此平分不算业余选手在内，业余选手的排名后面也不加T。
    保证冠军不并列。

    比赛中可能会出现犯规的情况，一旦犯规，成绩全部作废。保证第一轮选人至少选70个人。
*/
// #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cctype>
#include<utility>
#include<cassert>
#include<cmath>
using namespace std;

#define FOR(i,n) for(int i=0;i<(n);i++)

const int maxn = 144;   // 选手数
const int n_cut = 70;   // 最大晋级数
double eps = 1e-6;      // 误差（存在平分现象
double money[n_cut], totle; // 奖金比例数组 总和
int n;  // 选手数

struct Player {
    char name[25];  
    int rd[4], sc36, sc72, dq; // 四轮成绩 晋级赛成绩 总成绩 犯规标志
    int rnds;   // 轮数，输出使用
    bool star;  // 业余标志

    Player operator =(string &s) {         // 输入赋值
        FOR(i, 20) name[i] = s[i];      // 名字最长不超过20 且其后有多个空格填充
        name[20] = 0;   // 结束标识
        star = false;   // 非业余标志
        if (strchr(name,'*'))   // 判断是否是业余选手
            star = true;    
        sc36 = sc72 = dq = rnds = 0;
        memset(rd, 0, sizeof(rd));  
        FOR(i, 4) {
            char t[5];
            FOR(j, 3) t[j] = s[20 + i * 3 + j]; // 第20位起统一为成绩
            t[3] = '\0';
            if (!(sscanf(t, "%d", &rd[i]))) {   // 读取错误 即为犯规选手
                dq = -1;    // 标记为犯规
                rnds = i;   // 参加过的轮数
                if (i < 2)  // 轮数小于2即为不可能晋级
                    sc36 = -1;  // 未晋级标志
                break;  // 退出循环，其后没有成绩
            }
            else {  // 成功读取
                sc72 += rd[i];  // 计算总成绩
                if (i < 2)
                    sc36 += rd[i];  // 晋级赛成绩
            }
        }
        return *this;
    }
    Player() {     // 构造函数 初始化所有变量为初始值0
        memset(name, 0, sizeof(name));
        FOR(i, 4) rd[i] = 0;
        sc36 = sc72 = dq =rnds= 0;
        star = false;
    }
}player[maxn]; // 所有选手信息表

void print_result() {
    printf("Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won\n-----------------------------------------------------------------------\n");
    int i = 0, cnt = 0;
    while (i < n) {
        if (player[i].dq) {    // 犯规选手
            printf("%s           ", player[i].name);
            FOR(k, player[i].rnds)                     // 输出未犯规前所有成绩
                printf("%-5d", player[i].rd[k]);
            FOR(j, 4 - player[i].rnds)     // 犯规后成绩用空格填充
                printf("     ");
            printf("DQ\n");             // 总成绩为DQ
            i++;
            continue;
        }
        int j = i, m = 0, top = i + 1;
        double tot = 0.0;
        bool have_money = false;    
        while (j<n && player[i].sc72 == player[j].sc72) { // 并列处理
            if (!player[j].star) {  // 此人不是业余的
                m++;    // 并列人数递增
                if (cnt < n_cut) {
                    tot += money[cnt++];    // 并列的所有的比例和
                    have_money = true;      // 并列有奖金的标志
                }
            }
            j++;    // 并列的位置递增
        }
        double totmoney = totle*tot / m;    // 计算人均奖金
        while (i < j) {     // 输出并列的所有选手
            printf("%s ", player[i].name);
            char t[5];
            // 输出排名 附加并列排序 并列数大于1并且有奖金且非业余选手才并列
            sprintf(t, "%d%c", top, (m>1 && have_money && !player[i].star) ? 'T' : ' ');
            printf("%-10s", t);
            FOR(k, 4)   // 没有犯规的人都有四轮成绩
                printf("%-5d", player[i].rd[k]);
            if (!player[i].star && have_money) {   // 非业余且有奖金
                printf("%-10d", player[i].sc72);   // 输出总成绩
                printf("$%9.2f\n", totmoney / 100.0);   // 输出奖金
            }
            else
                printf("%d\n", player[i].sc72);    // 业余没奖金只输出成绩没有奖金
            i++;
        }
    }
}

int main() {
    int T;  // 数据组数
    cin >> T;
    while (T--) {
        cin >> totle;   // 总奖金
        FOR(i, 70) {    // 读入奖金比例
            cin >> money[i];
        } 
        assert(cin >> n && n <= 144);   // 读取选手数
        string s;
        getline(cin, s);    // 读取数据前空行
        FOR(i, n) {
            getline(cin, s);    // 读取数据空行
            player[i] = s;     // 赋值
        }
        sort(player, player + n, [](const Player& t1, const Player& t2) {
            if (t1.sc36 < 0 && t2.sc36 < 0) return false;   // 两人同时犯规不小于
            if (t1.sc36 < 0) return false;  // t1犯规 不小于
            if (t2.sc36 < 0) return true;   // t2犯规 小于
            return t1.sc36 < t2.sc36; });   // 返回晋级赛成绩比较结果
        //assert(player[n_cut-1].sc36 >= 0);
        int len = 0;    // 排序后 前两轮未犯规的长度
        for (; len < n;len++)
            if (player[len].sc36<0)
                break;
        if (len <= n_cut)   // 未犯规人数小于70（最大晋级数）
            n = len;
        else    // 未犯规人数大于70
            for (int i = n_cut-1; i < n; i++)   // 处理70名及其之后
                if (i == n - 1 || player[i].sc36 != player[i + 1].sc36||player[i].sc36<0) {
                    n = i + 1;  // 使总人数变为晋级后人数
                    break;
                }
        sort(player, player + n, [](const Player& t1, const Player& t2) {
            if (t1.dq&&t2.dq) { // 两人同时犯规
                if (t1.rnds != t2.rnds)return t1.rnds>t2.rnds;  // 轮数多的小
                if(t1.sc72!=t2.sc72) return t1.sc72 < t2.sc72;  // 总成绩小的小
                return strcmp(t1.name,t2.name) < 0; // 犯规后均相同按名字字典序排列
            }
            if (t1.dq) return false;    // t1 犯规 则t1大
            if (t2.dq) return true;     // t2 犯规 t2大
            if (t1.sc72 != t2.sc72) return t1.sc72 < t2.sc72;   // 都没犯规比总成绩
            return strcmp(t1.name,t2.name)< 0; });  // 总成绩相同按字典序排列
        print_result(); // 输出结果
        if(T) putchar('\n');
    }
    return 0;
}