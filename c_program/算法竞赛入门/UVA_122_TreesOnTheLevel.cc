#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 256 + 5;
struct Node{
    bool have_value;
    int v;
    Node *left,*right;
    Node():have_value(false),left(NULL),right(NULL){}   // 构造函数
};
Node * root;
bool failed;
Node * newnode(){ return new Node();}

void addnode(int v,char*s){
    int n = strlen(s);
    Node *u = root;
    for(int i=0;i<n;i++)
        if(s[i] == 'L'){
            if(u->left==NULL)   u->left = newnode();
            u = u->left;
        }
        else if(s[i]=='R'){
            if(u->right==NULL) u->right = newnode();
            u = u->right;
        }   // 此处忽略其他情况包括结束符
    if(u->have_value)   failed = true;
    u->v = v;
    u->have_value = true;
}

char s[maxn];
bool red_input(){
    failed = false;
    root = newnode();
    for(;;){
        if(scanf("%s",s) != 1) return false;
        if(!strcmp(s,"()")) break;
        int v;
        sscanf(&s[1],"%d",&v);
        addnode(v,strchr(s,',')+1);
    }
    return true;
}
#include <queue>
bool bfs(vector<int>&ans){
    queue<Node*> q;
    ans.clear();
    q.push(root);
    while(!q.empty()){
        Node *u = q.front();
        q.pop();
        if(!u->have_value)  return false;
        ans.push_back(u->v);
        if(u->left!=NULL)   q.push(u->left);
        if(u->right!=NULL)  q.push(u->right);
    }
    return true;
}

void remove_tree(Node *u){
    if(u==NULL) return;
    remove_tree(u->left);
    remove_tree(u->right);
    delete u;
}

// 二叉树不用指针实现 完全去掉指针
/*
const int root = 1;
void newtree(){
    left[root] = right[root] = 0;
    have_value[root] = false;
    cnt = root;
} // 用来代替remove_tree(root)和root = newcode() 两条调用
int newnode(){
    int u = ++cnt;
    left[u] = right[u] = 0;
    have_value[u] = false;
    return u;
}
// 动态化静态
Node* newnode(){
    Node * u = &node[++cnt];
    u->left = u->right = NULL;
    u->have_value = false;
    return u;
}

// 内存池处理内存溢出问题
queue<Node*> freenodes;
Node node[maxn];
// 使用空闲队列，固定内存大小 限制溢出
void init(){
    for(int i=0;i<maxn;i++)
        freenodes.push(&node[i]);   // chushihua
}
Node *newcode(){
    Node *u = freenodes.front();
    u->left = u->right = NULL;
    u->have_value = false;  // chushihuajiedian
    freenodes.pop();
    return u;
}
*/

