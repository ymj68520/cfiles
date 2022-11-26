#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

string multiply(string num1, string num2) {
    string ret = "";
    if(num1[0]=='0' || num2[0] == '0')  return "0";
    int n1 = num1.length();
    int n2 = num2.length();
    bool flag = 0;
    long sum = 0;
    for(int i=n1-1;i>=0;i--){
        int temp = 0;
        for(int j=n2-1;j>=0;j--){
            temp += (num1[i]-'0') * (num2[j]-'0') * pow(10,(n2-1)-j);
        }
        sum += temp * pow(10,n1-1-i);
    }
    ret.append(to_string(sum));
    return ret;
    // while(i>=0 && j>=0){
    //     int mul = (num1[i]-'0') * (num2[j]-'0') + flag;
    //     flag = 0;
    //     if(mul>9){ flag=1; mul%=10;}
    //     ans.append(to_string(mul));

    //     i--;j--;
    // }
    // if(flag)    ans.push_back('1');
    // reverse(ans.begin(),ans.end());
    // return ans;
}
string addstrings(string num1, string num2){
    string ans="";
    int carry=0;
    for (int i = num1.length() - 1, j = num2.length() - 1;
             i >= 0 || j >= 0 || carry != 0;
             i--, j--) {
            int x = i < 0 ? 0 : num1[i] - '0';
            int y = j < 0 ? 0 : num2[j] - '0';
            int sum = (x + y + carry) % 10;
            ans.append(to_string(sum));
            carry = (x + y + carry) / 10;
        }
    reverse(ans.begin(),ans.end());
    return ans;
}
string multiply1(string num1, string num2){
    if(num1[0] == '0' || num2[0] == '0')    return "0";
    string ans="";
    for(int i=num2.length()-1;i>=0;i--){
        int carry = 0;
        string temp="";
        int n2 = num2[i]-'0';

        for(int j=num1.length()-1;j>=0 || carry != 0;j--){
            int n1 = j < 0 ? 0 : num1[j] - '0';
            int product = (n1 * n2 + carry) % 10;
            temp.append(to_string(product));
            carry = (n1 * n2 + carry) / 10;
        }
        reverse(temp.begin(),temp.end());
        addstrings(ans,temp);
    }
    return ans;
}
string multiply2(string num1, string num2){
    if(num1 == "0" || num2 == "0")  return "0";
    
    int size1 = num1.length(), size2 = num2.length();
    vector<int> memo(size1+size2, 0);
    string res = "";
    for(int i = size1-1; i>=0; i--){
        int n1 = num1[i]-'0';
        for(int j = size2-1; j>=0; j--){
            int n2 = num2[j]-'0';
            int tempSum = memo[i+j+1]+n1*n2;
            memo[i+j+1] = tempSum % 10;
            memo[i+j] += tempSum / 10;
        }
    }
    bool flag = true;
    for(int i = 0; i<memo.size(); i++){
        if(memo[i] != 0 || !flag){
            flag = false;
            res.push_back((char)(memo[i]+'0'));
        }
    }
    return res;
}

int main(){
    string s1="2",s2="3";

    string ans = multiply2(s1,s2);

    for(auto const c:ans)   cout << c;
    cout << endl;

    return 0;
}