#include <iostream>
#include <vector>
#include <string>
using namespace std;

int magicalString(int n) {
    if(n<=3) return 1;
    int cnt = 1;
    int i=2;
    int j=2;
    string nums = "122";
    while(j<n-1){
        if(nums[i] == '2'){
            if(nums[j] == '2'){
                nums.append("11");
                cnt+=2;
            }
            else
                nums.append("22");
            j += 2;
        }
        else{
            if(nums[j] == '2'){
                nums.push_back('1');
                cnt++;
            }
            else
                nums.push_back('2');
            j++;
        }
        i++;
    }
    if(j>n-1 && nums[j]=='1') cnt = cnt - 1;
    return cnt;
}

int main(){
    cout << magicalString(4) << endl;

    return 0;
}