#include <iostream>
#include <vector>
#include <string>
#include <string.h>
struct BigInteger{
    static const int BASE = 100000000;    // c++中的struct是特殊的class，class中使用static
    static const int WIDTH = 8;     // 表明所有此类型的类共享此变量，在定义加载类后分配
    std::vector<int> s;
    BigInteger(long long num = 0){*this = num;} // 构造函数
    BigInteger operator = (long long num){  // 赋值运算符
        s.clear();
        do{
            s.push_back(num%BASE);
            num /= BASE;
        }while(num>0);
        return *this;
    }
    BigInteger operator = (const std::string &str){ // 重載賦值運算符
        s.clear();
        int x,len = (str.length()-1)/WIDTH + 1;
        for(int i=0;i<len;i++){
            int end = str.length() - i*WIDTH;
            int start = std::max(0,end-WIDTH);
            sscanf(str.substr(start,end-start).c_str(),"%d",&x);
            // substr()返回一个子串，c_str返回指向这个string变量内的字符数组的指针
            s.push_back(x);
        }
        return *this;
    }
    BigInteger operator + (const BigInteger &b)const{
        BigInteger c;
        c.s.clear();
        for(int i=0,g=0;;i++){
            if(g==0 && i>=s.size()&&i>=b.s.size()) break;
            int x =g;
            if(i<s.size()) x+=s[i];
            if(i<b.s.size()) x += b.s[i];
            c.s.push_back(x%BASE);
            g = x /BASE;
        }
        return c;
    }
    BigInteger operator += (const BigInteger &b){
        *this = *this + b;
        return *this;
    }
    // 前提为没有前导零
    bool operator < (const BigInteger &b) const {
        if(s.size() != b.s.size())  return s.size() < b.s.size();
        for(int i=s.size()-1;i>=0;i--)  // 从高位一直到最低位，存储为逆序
            if(s[i] !=b.s[i]) return s[i]<b.s[i];
        return false;   // 相等
    }
    bool operator > (const BigInteger &b) const { return b < *this;}
    bool operator <= (const BigInteger &b) const { return !(b<*this);}
    bool operator >= (const BigInteger &b) const { return !(*this<b);}
    bool operator != (const BigInteger &b) const { return b<*this||*this<b;}
    bool operator == (const BigInteger &b) const { return !(b<*this)&&!(*this<b);}

};
std::ostream& operator << (std::ostream &out,const BigInteger &x){
    out << x.s.back();
    for(int i=x.s.size()-2;i>=0;i--){
        char buff[20];
        sprintf(buff,"%08d",x.s[i]);
        for(int j=0;j<strlen(buff);j++)  out << buff[j];
    }
    return out;
}
std::istream& operator >> (std::istream &in,BigInteger &x){
    std::string s;
    if(!(in>>s))    return in;
    x = s;
    return in;
}
