#include <iostream>
#include <string>
#include <vector>

using namespace std;
string countAndSay(int n) {
    if(n == 1)  return "1";

    string ans = "1";
    for(int i=1;i<n;i++){
        string temp = "";
        for(int j=0;j<ans.length();j++){
            int cnt = 1;
            char ch = ans[j];
            while(j<ans.length()&&ans[j+1]==ch){
                j++;
                cnt++;
            }
            temp.append(to_string(cnt));
            temp.push_back(ch);
        }
        ans = temp;
    }

    return ans;
}
int main(){
    for(int i=1;i<=10;i++)
        cout << countAndSay(i) << endl;

    return 0;
}