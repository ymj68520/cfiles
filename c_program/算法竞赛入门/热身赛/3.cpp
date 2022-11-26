// Celeste
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    int n,i,sum=0;
    scanf("%d",&n);
    int A[n],B[n],cost[n];
    set<int> pa,pb;
    for(i=0;i<n;i++)
        scanf("%d",A+i);
    for(i=0;i<n;i++)
        scanf("%d",B+i);
    for(i=0;i<n;i++)
        if(A[i]>B[i]){
            cost[i] = B[i];
            pb.insert(i);
        }
        else{
            cost[i] = A[i];
            pa.insert(i);
        }
    int diff=pa.size()>pb.size()?pa.size()-pb.size():pb.size()-pa.size();
    if(pa.size()>pb.size()){
        int more[pa.size()];
        i=0;
        for(set<int>::iterator it = pa.begin();it!=pa.end();it++)
            more[i++] = B[*it];
        sort(more,more+pa.size());
        for(i=0;i<diff;i++)
            cost[more[i]] = B[more[i]];   
    }
    else if(pa.size()<pb.size()){
        int more[pb.size()];
        i=0;
        for(set<int>::iterator it = pb.begin();it!=pb.end();it++)
            more[i++] = A[*it];
        sort(more,more+pb.size());
        for(i=0;i<diff;i++)
            cost[more[i]] = A[more[i]];  
    }
    for(i=0;i<n;i++)
        printf("%d,",cost[i]);
        //sum+=cost[i];
    //printf("%d",sum);
}