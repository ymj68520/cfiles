/*
    静态树表是把有序的静态查找表根据数据被查找的概率生成一颗二叉树，
    使得从二叉树的根节点起，查找左右子树的概率大致相等，使平均查找长度较短。
    若每个数据的被查找概率相等，直接使用折半查找即可，不必生成二叉树。
    每个元素被查找的概率是不一定相同，折半查找不是最佳方法！
    如果仅仅考虑查找成功的情况，构造一颗静态 最优查找树 的性能是最好的。
    用数学公式来表示就是：使得PH值最小的树为该数组的静态最优查找树。
        它等于结点i的查找路径长度c，乘以该结点被查找的概率p；h表示节点i在搜索树中的高度。
    通俗点来说，就是权值越大的结点，越放到靠近根结点的位置！
    这个很好理解，这种结点要么查找概率大，要么需要的比较次数（折半查找中的次数）多，
    要么以上两者都占了，当然应该越早查越好啊，但是这种树的构造时间复杂度为O(n^3);
    因此需要次优查找树!~~ 这种树的查找效率很少低于最优查找树的3%。
    
    补述最优二叉树（赫夫曼树）：
        贪心算法。每次找权值最小的两个节点合起来组成新的结点，新节点权值为子节点权值之和，
        重复执行，直到剩下一棵树。
*/
/*
    最优查找树： 详情看https://blog.csdn.net/PeacefulBY/article/details/4634196?spm=1001.2014.3001.5501
        最优二叉查找树是使查找各9节点平均代价最低的二叉查找树。
        具体来说就是：给定键值序列 K = <k1 , k2 , . . . , kn >，k1 < k2 <· · · < kn ，
            其中键值ki ,被查找的概率为pi ，要求以这些键值构建一颗二叉查找树T，
            使得查找的期望代价最低（查找代价为检查的节点数）。
        对于查找期望代价的解释：
            对于键值ki , 如果其在构造的二叉查找树里的深度为depthT(ki )，
            则搜索该键值的代价= depthT(ki ) +1（需要加上深度为0的树根节点）。
            由于每个键值被查找的概率分别为pi ，i=1,2,3…,n。所以查找期望代价为： 
                E[T的查找代价] = ∑[(i=1)~n] (depthT(ki ) +1) · pi
        时间复杂度：
            穷举构造最优二叉查找树，其实就是这样的一个问题：
                给一个拥有n个数的已排序的节点，可以将其构造成多少种不同的BST（用来找到一个最优的二叉查找树）？
                设可以构造成T(n)个，那么枚举每一个元素作为根节点的情况，
                当第一个元素作为根节点时，其余n-1个构成右子树，无左子树，是n-1情况时的子问题， 共T(n-1)种；
                当第二个元素作为根节点时，左子树有1个元素，右子树有n-2个元素，
                    根据乘法原理共有T(1)T(n-2)种情况……
                依此类推得 到：
                    T(n) = T(0)T(n-1) + T(1)T(n-2) + T(2)T(n-3) + ...... + T(n-2)T(1) + T(n-1)T(0)；
                此外，有T(0)=T(1)=1。
                下面来求解T(n)：

                    定义函数 f(x) = T(0) + T(1) · x + T(2) · x2 + ......
                    那么有：
        f(x)^2 = (T(0)^2 ) + (T(0)T(1) + T(1)T(0)) · x + (T(0)T(2) + T(1)T(1) + T(2)T(0)) · x^2 + ......
              = T(1) + T(2) · x + T(3) · x2 + ......
              = (f(x) - T(0)) / x
              = (f(x) - 1) / x
                    这样解方程得到 f(x) = [1 - (1 - 4x)1/2 ] / 2x
                    右边进行泰勒展开，再与定义式比较最终得到： T(n) = (2n)! / (n!(n+1)!)  
                    然后根据Stirling公式：n! ～ (2πn)^1/2 · (n/e)^n
                    于是有(2n)! / n!(n+1)! ～ (4 n^1/2 · 2n^2n ) / (2n^1/2 · n^n · (2(n+1))^1/2 · (n+1)^n )
                                            ～ 4^n · (n+1)^-3/2 · (n/(n+1))^n
                                            ～ 4^n · n^-3/2  
                    因此最后得到穷举方法构造最优二叉查找树的时间复杂度： T(n) = O(4^n · n^-3/2 )
            递归构造最优查找树：
                实际上左右子树是互不影响的，不需要穷举所有左右子树的组合，所以不需要用乘法原理，加法原理就可以了，
                这样式子变为：
            T(n) = T(0) + T(n-1) + T(1) + T(n-2) + T(2) + T(n-3) + ...... + T(n-2) + T(1) + T(n-1) + T(0) 
                 = 2(T(0) + T(1) + T(2) + ...... + T(n-1))
                 = 3T(n-1)
            所以得到T(n) = O(3^n) ，还是指数级的一个算法
            动态规划构造最优查找树：
                O(n^3);


    次优查找树：
        次优查找树是折半查找的一种一般形式，其理论基础是“被查找的各元素是不等概的”，
        而折半查找就是被找等概的，我们在使用中默认了这一性质。
        比如对有序数组：
            1,2,3,4,5
        用折半查找时，应该现比较最中间的3，如果如果待查整数等于3，查找结束。
        如果小于3，就继续在左边的部分数组里查找；反之，在右边的数组里查找。

        问题在于，我们为什么不从4开始找呢？为什么不从1开始呢？
            因为在等概率的情况下，这样能让整体的平均搜索的长度（也就是次数）最小，
                实际也是二分查找树的深度最小。
                因为相同结点数的二叉树，越是丰满的二叉树高度越小。
                也就是说，每个节点的左右子树的高度差越小，二叉树的高度就越小，
                查找越底层的元素所需要的路径长度就越短，比较次数也越少
                （相同结点数完全二叉树的深度小于等于其他形态的二叉树的深度）。
        核心：选出一个结点，使得它左右两侧的子数组的权值累加和之差的绝对值最小。
            把这个结点当做根节点，递归地用刚才的左右子数组构造它的左右子树。
        之前的折半查找树是为了让左右子树的高度差尽量小，
        现在你就把高度的概念替换为权值之和来理解，就好了。
        为什么要让左右子树的权值累加和之差最小？为了使树的深度最小。
        
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define Status bool
#define OK true
#define ERROR false
#define Nil NULL
typedef char KeyType;   // 定义关键字类型为字符型
typedef struct ElemType{
    // 数据元素类型
    KeyType key;    // 关键字
    int weight;     // 权值
}ElemType;

// Traverse()调用的与之配套的访问数据元素的函数
void Visit_t(ElemType c){
    printf("%c, %d",c.key,c.weight);
}
// 与之配套的从文件输入数据元素的函数
void InputFromFile(FILE *f,ElemType *c){
    fscanf(f,"%*c%c%d",&c->key,&c->weight); // %*c用来读取回车
}
// 与之配套的从键盘读入关键字的函数
void InputKey(KeyType *k){
    if(sizeof(KeyType)==sizeof(int))
        scanf("%d",k);
    else
        scanf("%c",k);
}
#define ET eeeeeeeetttttt       // 重定义冲突
#include "顺序表的查找.h"   // 相对路径
#include "数值比较的宏.h"

typedef ElemType TElemType;
#include "../../../Tree/BinaryTree/BinaryTree.h"

#define N 100 // 静态查找表的最大表长 设置sw[]数组用到

// 由有序表R[low~high]及其累计权值表sw（其中sw[0]=0)递归构造次优查找树T
Status SecondOptimal(BiTree *T,ElemType R[],int sw[],int low,int high){
    int j,i=low;    // 有最小Δpi值的序号，初值设为当low==high（有序表仅一个元素）时的值
    double dw = sw[high]+sw[low-1]; // 固定项                                                             
    double min = fabs(sw[high]-sw[low]);    // ΔPi的最小值，初值设置为当low==high的值
    for(j=low+1;j<=high;j++)   // 当low != high时,选择最小的ΔPi值
        if(fabs(dw-sw[j]-sw[j-1])<min)  // 找到小于min的值
        {
            i=j;    // 更新有最小ΔPi的序号
            min = fabs(dw-sw[j]-sw[j-1]);  // 更新ΔPi的最小值
        }
    if(!(*T = (BiTree)malloc(sizeof(BiTNode))))
        return ERROR;
    (*T)->data = R[i];  // 将最小ΔPi值的数据元素赋值给树节点的数据域
    if(i==low)  // 有最小ΔPi值的序号是最小序号
        (*T)->lchile = NULL;
    else // 有最小ΔPi值的序号不是最小序号
        SecondOptimal(&(*T)->lchile,R,sw,i+1,high); // 递归构造次优查找左子树
    if(i==high) // 有最小ΔPi值的序号是最大序号
        (*T)->rchild = NULL;    // 设右子树为空
    else    // 有最小ΔPi值的序号不是最大序号
        SecondOptimal(&(*T)->rchild,R,sw,i+1,high); // 递归构造次优查找右子树

    return OK;    
}

// 按照有序表ST中各数据weight域求累计权值数组sw，CreaeSOSTree()调用
void FindSW(int sw[],SSTable ST){
    int i;
    sw[0] = 0;  // 置边界值
    printf("\nsw = 0");
    for(i=0;i<=ST.Length;i++)   // 由小到大计算累计权值sw[i]并输出
    {   sw[i] = sw[i-1]+ST.elem[i].weight;  // 累计权值[i-1]+[i]项权值
        printf("%5d",sw[i]);
    }
}
typedef BiTree SOSTree;     // 次优查找二叉链表的存储结构
// 由有序表ST构造一颗次优查找树T。ST的数据元素含有权域weight。
void CreateSOSTree(SOSTree *T,SSTable ST){
    int sw[N+1];    // 累计权值数组
    if(ST.Length == 0)  // 空表
        (*T) = NULL;
    else    // fei非空
    {
        FindSW(sw,ST);  // 按照有序表ST中各数据元素的weight域求累计权值表sw
        SecondOptimal(T,ST.elem,sw,1,ST.Length);
        // 由有序表ST[1~ST.Length]及其累计权值表sw(其中sw[0]==0)递归构造次优查找树T
    }
}
// 在次优查找树T中查找主关键字等于key的元素。找到则返回OK，T指向该元素，否则返回ERROR
Status Search_SOSTree(SOSTree *T,KeyType key){
    while(*T)   // 树非空
        if((*T)->data.key == key) // 树根节点关键字的值等于key
            return OK;
        // 大左(更大）小右(更小)
        else if((*T)->data.key > key)   // 树T的根节点关键字域大于key
            (*T) = (*T)->lchile;    // T指向T的左子树，继续查找
        else // 树T根节点的关键字域小于Key
        
            (*T) = (*T)->rchild;    // T指向T的右子树，继续查找
    return ERROR;   // 次优查找树中不存在待查元素
}
