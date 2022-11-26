// 求得adr[1~L.length],adr[i]为静态链表的第i个元素
void Sort(SqList L,int adr[]){
    int i=1,p=L.r[0].next;
    while(p)
    {   adr[i++] = p;
        p = L.r[p].next;    
    }
}
// adr给出静态链表L的有序次序，即L.r[adr[i]]是第i小的记录
// 按adr重拍L.r使其有序
void Rearrange(SqList *L,int adr[]){
    int i,j,k;
    for(i=1;i<L->length;i++)    // 从顺序表的第一个记录到倒数第二个记录
        if(adr[i]!=i)   // 记录不在正确位置
        {
            j=i;
            L->r[0] = L->r[i];  // 暂存记录
            while(adr[j]!=i)    // 记录不在正确位置
            {// 调整L.r[adr[j]]的记录到位，知道adr[j] = i为止
                k = adr[j];
                L->r[j] = L->r[k];  // 将[j]中应存的记录移来
                adr[j] = j; // 记录处于正确位置的标记
                j = k;  // 新空出的位置赋值给j，以便继续调整
            }
            L->r[j] = L->r[0];  // 循环调整完毕，将暂存的记录赋值给[j]
            adr[j] = j;
        }
}