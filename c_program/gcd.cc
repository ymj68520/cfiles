#include <cstdio>

using namespace std;

int gcd(int x, int y){
    if(x<=0 || y<=0)
        return -1;
    
    while(x!=y){
        if(x > y)
            x -= y;
        else
            y -= x;
    }
    return y;
}

int main(){
    int x = 4,y = 8;
    
    printf("%d\n",gcd(x,y));

    return 0;
}