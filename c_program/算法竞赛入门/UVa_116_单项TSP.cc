#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;
/*
5 6
3 4 1 2 8 6
6 1 8 2 7 4
5 9 3 9 9 5
8 4 1 3 2 6
3 7 2 8 6 4
*/
int main(){
    int m,n;
    cin >> m >> n;
    int a[m][n];
    for(int i=0;i<m;i++) for(int j=0;j<n;j++)
        scanf("%d",a[i]+j);
    int d[m][n];memset(d,0,sizeof(d));
    int next[m][n];memset(next,0,sizeof(next));
    int ans = INT32_MAX;
    int first = 0;
    for(int j=n-1;j>=0;j--){
        for(int i=0;i<m;i++){
            if(j==n-1)  d[i][j] = a[i][j];
            else{
                int rows[3] = {i,i-1,i+1};
                if(i==0)    rows[1] = m-1;
                if(i==m-1)  rows[2] = 0;
                sort(rows,rows+3);
                d[i][j] = INT32_MAX;
                for(int k=0;k<3;k++){
                    int v = d[rows[k]][j+1] + a[i][j];
                    if(v < d[i][j]){
                        d[i][j] = v;
                        next[i][j] = rows[k];
                    }
                }
                if(j==0 && d[i][j]<ans){
                    ans = d[i][j];
                    first = i;
                }
            }
        }
        cout << first + 1;
        for(int i=next[first][0],j=1;j<n;i=next[i][j],j++)
            cout << " " << i+1;
        cout << endl << ans << endl;
    }
    return 0;
}