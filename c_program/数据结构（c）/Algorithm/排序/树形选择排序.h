/*
    树形选择排序：（竞标赛排序）
        选择排序的主要操作是进行关键词间的比较，因此改进简单选择排序应该从如何减少比较出发考虑。
        显然，在n个关键字中选择出最小值，至少进行n-1次比较，然而下一次则需要进行n-2次比较。
        若能利用前n-1次比较信息，则可以减少以后各趟选择排序中所用的比较次序。

        树形选择排序是首先对n个记录的关键字进行两两比较，然后再⌈n/2⌉ 个较小者中再进行两两比较，
        如此重复，直至选出最小的关键字为止。
            ⌈ ⌉
        这个过程可以用一颗n个叶子节点的完全二叉树表示。
        从叶子节点开始，和其兄弟节点比较，修改叶子节点到根节点的路径上的各节点的关键字，则根为最小值。
        每次选出一个最小值后，将这个最小值修改为最大值。
        含有n个叶子节点的的完全二叉树的深度为⌈ log_2 n ⌉+1，则在树形选择排序中，除了最小关键字之外，
        每选择一个次小关键字仅需要⌈ log_2 n ⌉次比较，因此它的时间复杂度为 O(n*logn);
        
        但是，辅助存储空间较多，和“最大值”进行多余的比较等缺点显著。

        因此，威洛姆斯提出了堆排序。

    堆排序：（Heap Sort）
        只需要一个记录大小的辅助空间，每个待排序的记录仅占用一个存储空间
        堆的定义如下：（2i为其左孩子，2i+1为右孩子）
            {
                k_i <= K_2i;    k_i <= k_2i+1;
            }   // 小顶堆
            或
            {
                k_i >= K_2i;    k_i >= k_2i+1;
            }   // 大顶堆
        若将和此序列对应的一位数组（即以一位数组作此序列的存储结构）看成是一个完全二叉树。
        则堆的含义表明，完全二叉树中所有非终端节点的值均不大于（不小于）其左右孩子节点的值。
        由此，则一个堆序列的堆顶元素必为最小值（最大值）

        若在输出堆顶的最小值之后，使剩余的n-1个元素的序列重新构成一个堆，则得到次小值。
        如此反复执行，便得到一个有序序列，此过程为堆排序。

        （1）由一个无序序列建成一个堆：

        （2）输出堆顶元素后，调整剩余元素为新堆：
*/
#include "../查找/静态查找表/数值比较的宏.h"
#include "Data_Struct.h"
typedef SqList HeapType;
// 已知H.r[s~m]中记录的关键字除H.r[s].key之外均满足堆的定义，
// 本函数调整H.r[s]的关键字，使得H.r[s~m]中记录的关键字均满足堆的定义。
void HeapAdjust(HeapType *H,int s,int m,bool flag){// s调整位置 m调整数
    int j;
    H->r[0] = H->r[s];  // 利用H的闲置空间结点存储待调整记录
    for(j=2*s;j<m;j*=2) // j指向待调整记录[s]的左孩子，沿key较大的孩子节点向下筛选
    {
        if(flag)    // 大堆顶
        {
            if(j<m && LT(H->r[j].key,H->r[j+1].key))    // 左孩子的关键字 < 右孩子的关键字
                j++;    // j指向右孩子
            if(!GT(H->r[0].key,H->r[j].key))  // [s]的关键字不小于[j]的关键字
                break;  // 不必再调整，退出循环
        }
        else // 小堆顶
        {
            if(j<m && GT(H->r[j].key,H->r[j+1].key))    // 左孩子的关键字 > 右孩子的关键字
                j++;    // j指向[s]的右孩子
            if(!GT(H->r[0].key,H->r[j].key))  // [s]的关键字不小于[j]的关键字
                break;  // 不必再调整，退出循环
        }
        H->r[s] = H->r[j];  // 否则，[j]为顶，插入[s]
        s = j;  // [s]的位置向下移动到[j]（原左孩子或者右孩子处）
    }
    H->r[s] = H->r[0];  // 将待调整的记录插入[s]
}
void HeapAdjust_array(int array[],int n,int s,bool flag){
    int j,temp=array[s];
    for(j=2*s+1;j<n;j=j*2+1){
        if(flag){
            if(j<n && LT(array[j],array[j+1]))
                j++;
            if(!GT(temp,array[j]))
                break;
        }
        else{
            if(j<n && GT(array[j],array[j+1]))
                j++;
            if(!GT(temp,array[j]))
                break;
        }
        array[s] = array[j];
        s = j;
    }
    array[s] = temp;
}
// 对顺序表H进行堆排序
// 当flag为true时，按升序排序（大顶堆） 当flag为false时，按降序排序（小顶堆）
void HeapSort(HeapType *H,bool flag){
    int i;
    for(i=H->length/2;i>0;i--)  // 从最后一个非叶子节点到第一个节点
        HeapAdjust(H,i,H->length,flag); // 调整H.r[i],使得H.r[i~length]成为大（小）顶堆
    for(i=H->length;i>1;i--){
        H->r[0] = H->r[1];  // 将堆顶记录[1]和未完全排序的H.r[1~i]中的最后一个记录[i]交换
        H->r[1] = H->r[i];
        H->r[i] = H->r[0];  
        HeapAdjust(H,1,i-1,flag);   // 调整H.r[1],使得H.r[1 ~ i-1]重新成为da（小）堆顶
    }
}
void HeapSort_array(int array[],int n,bool flag){
    int i;
    int temp;
    for(i=n;i>=0;i--)
        HeapAdjust_array(array,n,i,flag);
    for(i=n;i>0;i--){
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        HeapAdjust_array(array,i-1,1,flag);
    }
}
