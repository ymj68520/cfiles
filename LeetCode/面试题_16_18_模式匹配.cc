#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    bool patternMatching(string pattern, string value) {
        int plen = pattern.length(), vlen = value.length();
        if(plen==0 && vlen==0)  return true;
        if(plen == 0)   return false;

        int acnt=0,bcnt=0;
        for(char &c : pattern){
            if(c == 'a')    acnt++;
            else            bcnt++;
        }

        int alen=0,blen=0;
        if(acnt)    alen = vlen/acnt;
        if(bcnt)    blen = vlen/bcnt;

        for(int i=0;i<=alen;++i){
            for(int j=0;j<=blen;++j){
                if(i*acnt + j*bcnt == vlen){
                    string sa="",sb="";
                    int index = 0;
                    for(int k=0;k<=plen;++k){
                        if(pattern[k] == 'a'){
                            if(sa.empty())  sa = value.substr(index,i);
                            else if(sa != value.substr(index,i)) break;
                            index += i;
                        }
                        else{
                            if(sb.empty())  sa = value.substr(index,j);
                            else if(sb != value.substr(index,j))    break;
                            index += j;
                        }
                    }
                    if(index == vlen && sa != sb)   return true;
                }
            }
        }
        return false;
    }
};
class Solution {
public:
    bool patternMatching(string pattern, string value) {
    	int plen = pattern.size(), vlen = value.size();
    	if (plen == 0 && vlen == 0) return true;
    	if (plen == 0) return false;

    	int ac = 0, bc = 0;
    	for (int i = 0; i < plen; ++i) {
    		if (pattern[i] == 'a') ac++;
    		else bc++;
    	} 

    	int la = 0, lb = 0;
    	if (ac != 0) la = vlen / ac;
    	if (bc != 0) lb = vlen / bc;

    	for (int i = 0; i <= la; ++i) {
    		for (int j = 0; j <= lb; ++j) {
    			if (i * ac + j * bc == vlen) {
    				string sa = "#"; // 标志作用
    				string sb = "#";
    				int index = 0;
    				for (int k = 0; k < plen; ++k) {
    					if (pattern[k] == 'a') {
    						if (sa == "#") sa = value.substr(index, i);
    						else if (sa != value.substr(index, i)) break;
    						index += i;
    					}
    					else {
    						if (sb == "#") sb = value.substr(index, j);
    						else if (sb != value.substr(index, j)) break;
    						index += j;
    					}
    				}
    				if (index == vlen && sa != sb) return true;
    			}
    		}
    	}

    	return false;
    }
};

int main(){
    string p = "abba";
    string v = "dogcatcatdog";
    Solution sol;

    cout << sol.patternMatching(p,v) << endl;

    return 0;
}