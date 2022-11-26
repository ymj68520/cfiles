#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_R(char **b,int x1,int y1,int x2,int y2){
    if(x1!=x2){     
        if(y1!=y2){
            return false;  
        }
        else   
        {
            if(x1<x2){   
                for(int i=x1+1;i<x2;i++)
                    if(b[i][y1]  !='\0'){
                        return false; 
                    }
            }
            else{    
                for(int i=x2+1;i<x1;i++)
                    if(b[i][y1] !='\0')
                        return false;
            }
        }
    }else{
        if(y1<y2) 
        {   for(int i=y1+1;i<y2;i++)
                if(b[x1][i] !='\0')
                    return false;
        }
        else   
            for(int i=y2+1;i<y1;i++)
                if(b[x1][i] !='\0')
                    return false;
    }
    return true;
}
bool is_H(char **b,int x1,int y1,int x2,int y2){
    if(x1<x2)  
    {
        if(y1<y2)  
        { 
            if(y2>0)
            if((b[x2][y2-1] =='\0') && (x2-1==x1 && y2-2 == y1))   
                return true; 
            if(x2>0)
            if(b[x2-1][y2]  == '\0' && (x2-2 == x1 && y2-1 == y1))
                return true;
        }
        else   
        {
            if(x2>0)
            if(b[x2-1][y2] =='\0' && (x2-2==x1 && y2+1==y1)) 
                    return true;
            if(y2<8)
            if(b[x2][y2+1] =='\0' && y2+2 == y1 && x2-1==x1) 
                    return true;
        }
    }
    else  
    {
        if(y1<y2)   
        {  
            if(x2<9)
            if(b[x2+1][y2] =='\0' && x2+2==x1 && y2-1==y1)   
                    return true;
            if(y2>0)
            if(b[x2][y2-1] =='\0' && x2+1 == x1 && y2-2 == y1)  
                    return true;
        }
        else    
        {
            if(y2<8)
            if(b[x2][y2+1] =='\0' && x2+1==x1 && y2+2==y1)  
                    return true;
            if(x2<9)
            if(b[x2+1][y2] =='\0' && x2+2==x1 && y2+1 == y1) 
                    return true;
        }
    }
    return false;
}
bool is_C(char **b,int x1,int y1,int x2,int y2){
    int count=0;
    if(x1!=x2) 
    {
        if(y1!=y2) 
            return false;
        else   
        {
            if(x1<x2)  
            {    for(int i=x1+1;i<x2;i++)
                    if(b[i][y1] !='\0')
                        count++;
            }else   
            {
                for(int i=x2+1;i<x1;i++)
                    if(b[i][y1] !='\0')
                        count++;
            }
        }
    }else  
    {
        if(y1<y2)  
        {    for(int i=y1+1;i<y2;i++)
                if(b[x1][i] !='\0')
                    count++;
        }
        else{
            for(int i=y2+1;i<y1;i++)
                if(b[x1][i] !='\0')
                    count++;
        }  
    }
    if(count!=1)
        return false;
    else
        return true;
}
bool is_true(char **b,int x1,int y1,int x2,int y2,char type){
    switch(type){  
        case 'G':
        case 'R':
            if(!is_R(b,x1,y1,x2,y2))
                return false;
            break;
        case 'H':
            if(!is_H(b,x1,y1,x2,y2))
                return false;
            break;
        case 'C':
            if(!is_C(b,x1,y1,x2,y2))
                return false;
            break;
        default:
            break;
    }
    return true;
}
bool is_checkmate(char **b,int N,int **position){
    for(int shuai=1;shuai<=N;shuai++)
        if(b[position[shuai][0]][position[shuai][1]]=='G')
            if(is_R(b,position[0][0],position[0][1],position[shuai][0],position[shuai][1]))
                return false;
    for(int i=1;i<=4;i++){
        int n=N;
        char **temp = (char **)malloc(10*sizeof(char *));
        for(int k=0;k<10;k++)
            temp[k] = (char*)malloc(9*sizeof(char));
        for(int i=0;i<10;++i)
            for(int j=0;j<9;j++)
                temp[i][j] = b[i][j];
        bool flag = false;
        switch(i){  
            case 1:
                    if(position[0][0]==0)   
                        continue;  
                    if(b[position[0][0]-1][position[0][1]]!='\0'){  
                        for(int whoareyou=1;whoareyou<=N;whoareyou++)
                            if(position[whoareyou][0]==position[0][0]-1&&position[whoareyou][1]==position[0][1])
                                while(whoareyou<N){
                                    position[whoareyou][0] = position[whoareyou+1][0];
                                    position[whoareyou][1] = position[whoareyou+1][1];
                                    whoareyou++;
                                }
                        n--;         
                    }
                    temp[position[0][0]-1][position[0][1]] = temp[position[0][0]][position[0][1]];
                    temp[position[0][0]][position[0][1]]  = '\0';
                    for(int i=1;i<=n;i++){
                        if(is_true(temp,position[0][0]-1,position[0][1],position[i][0],position[i][1],
                        temp[position[i][0]][position[i][1]] )){
                            flag = true;
                            break;
                        }
                    }
                    if(!flag)
                        return false;
                    break;
            case 2: 
                    if(position[0][1]==3)
                        continue;  
                    if(b[position[0][0]][position[0][1]-1]!='\0'){  
                        for(int whoareyou=1;whoareyou<=N;whoareyou++)
                            if(position[whoareyou][0]==position[0][0]&&position[whoareyou][1]==position[0][1]-1)
                                while(whoareyou<N){
                                    position[whoareyou][0] = position[whoareyou+1][0];
                                    position[whoareyou][1] = position[whoareyou+1][1];
                                    whoareyou++;
                                }
                        n--;
                    }
                    temp[position[0][0]][position[0][1]-1] = temp[position[0][0]][position[0][1]];
                    temp[position[0][0]][position[0][1]]  = '\0';
                    for(int i=1;i<=n;++i){
                        if(is_true(temp,position[0][0],position[0][1]-1,position[i][0],position[i][1],
                        temp[position[i][0]][position[i][1]] )){
                            flag = true;
                            break;
                        }
                    }
                    if(!flag)
                        return false;
                    break;
            case 3:
                    if(position[0][0]==2 )
                        continue;  
                    if(b[position[0][0]+1][position[0][1]]!='\0'){  
                        for(int whoareyou=1;whoareyou<=N;whoareyou++)
                            if(position[whoareyou][0]==position[0][0]+1&&position[whoareyou][1]==position[0][1])
                                while(whoareyou<N){
                                    position[whoareyou][0] = position[whoareyou+1][0];
                                    position[whoareyou][1] = position[whoareyou+1][1];
                                    whoareyou++;
                                }
                        n--;
                    }
                    temp[position[0][0]+1][position[0][1]] = temp[position[0][0]][position[0][1]];
                    temp[position[0][0]][position[0][1]]  = '\0';
                    for(int i=1;i<=n;++i){
                        if(is_true(temp,position[0][0]+1,position[0][1],position[i][0],position[i][1],
                        temp[position[i][0]][position[i][1]] )){
                            flag = true;
                            break;
                        }
                    }
                    if(!flag)
                        return false;
                    break;
            case 4: 
                    if(position[0][1]==5 )
                        continue;   
                    if(b[position[0][0]][position[0][1]+1]!='\0'){ 
                        for(int whoareyou=1;whoareyou<=N;whoareyou++)
                            if(position[whoareyou][0]==position[0][0]&&position[whoareyou][1]==position[0][1]+1)
                                while(whoareyou<N){
                                    position[whoareyou][0] = position[whoareyou+1][0];
                                    position[whoareyou][1] = position[whoareyou+1][1];
                                    whoareyou++;
                                }
                        n--;
                    }
                    temp[position[0][0]][position[0][1]+1] = temp[position[0][0]][position[0][1]];
                    temp[position[0][0]][position[0][1]]  = '\0';
                    for(int i=1;i<=n;++i){
                        if(is_true(temp,position[0][0],position[0][1]+1,position[i][0],position[i][1],
                        temp[position[i][0]][position[i][1]] )){
                            flag = true;
                            break;
                        }
                    }
                    if(!flag)
                        return false;
                    break;
        }
        free(temp);
    }
    return true;
}
void ffread(int *x,int *y){
    scanf("%d%*c%d%*c",x,y);
}
int main(){
    int N=1,x=1,y=1;
    while(0!=N){
        char **b;
        b = (char**)malloc(10*sizeof(char*));
        for(int i=0;i<10;i++){
            b[i] = (char *)malloc(9*sizeof(char));
            for(int j=0;j<9;j++)
                b[i][j]= '\0'; 
        }
        scanf("%d%*c",&N);
        ffread(&x,&y);
        if(N==0)
            break;
        int **position;
        position = (int**)malloc((N+1)*sizeof(int*));
        for(int i=0;i<N+1;i++)
            position[i] =(int *)malloc(2*sizeof(int));
        position[0][0] = x-1;position[0][1] = y-1;
        b[x-1][y-1] = 'g';   
        for(int i=0;i<N;i++){
            char ch = getchar();
            ffread(&x,&y);
            position[i+1][0] = x-1;
            position[i+1][1] = y-1;
            b[x-1][y-1]= ch;
        }
        if(is_checkmate(b,N,position))
            puts("YES");
        else
           puts("NO");
    }
    return 0;
}
