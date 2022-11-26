/*
    输入若干行代码，要求各列单词的左边界对齐且尽量靠左。
    单词之间至少要空一格。每个单词不超过80个字符，
    每行不超过180个字符，一共最多1000行。
    注意输出时每行的最后一列后面没有空格符。
*/
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
vector<string> txt[1314];
string code,te;
int max_len[250];//将每一列中最长的单词的长度保存下来，以便保证格式！
void print(const string &s,int len)
{//格式化输出 单词长度不足len时补齐空格
    for(int i=0; i<s.size(); i++)
        cout<<s[i];
    for(int i=0; i<=len-s.size(); i++)
        cout<<' ';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int col=0,row=0;//代码行数,col表示每一行的“单词”个数
    while(getline(cin,code))
    {
        stringstream tran(code);//创建一个“字符串流”——tran，接下来只需要像读取cin那样读取tran即可！
        while(tran>>te)
        {
            max_len[col]=max(max_len[col],(int)te.size());//比较长度取大值。
            col++;
            txt[row].push_back(te);//将每一个单词存进容器里面
        }
        row++,col=0;
    }
    for(int i=0; i<row; i++)
    {
        int j=0;
        for(; j<txt[i].size()-1; j++)   // 输出前面需要补齐的
            print(txt[i][j],max_len[j]);
        cout<<txt[i][j]<<endl;//每行的最后一列是不用输出空格的
    }
    return 0;
}