#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution1 {
    bool check(char s){
        if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u')  return true;
        return false;
    }
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int p=0,q=0,maxSize,count=0;
        while(q<k) if(check(s[q++]))  count++;
        maxSize = count;
        while(q<n){
            if(check(s[q++])) count++;
            if(check(s[p++])) count--;
            maxSize = max(count, maxSize);
        }
        return maxSize;
    }
};

class Solution {
public:
    bool isVowels(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    int maxVowels(string s, int k) {
        int sum=0,ret=0;
        int i;
        for(i=0;i<k;i++){
            sum+=isVowels(s[i]);
            ret=sum;
        }
        for(i=k;i<s.size();i++){
            sum-=isVowels(s[i-k]);
            sum+=isVowels(s[i]);
            if(sum>ret) ret=sum;
        }
        return ret;
    }
};