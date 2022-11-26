#include <iostream>
#include <string>
#include <vector>
using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1) return s;
    
	vector<string> rows(min(numRows, int(s.size()))); // 防止s的长度小于行数
	int curRow = 0;
	bool goingDown = false;
	
    for (char c : s) {
		rows[curRow] += c;
		if (curRow == 0 || curRow == numRows - 1) {// 当前行curRow为0或numRows -1时，箭头发生反向转折
			goingDown = !goingDown;
		}
		curRow += goingDown ? 1 : -1;
	}

	string ret;
	for (string row : rows) {// 从上到下遍历行
		ret += row;
	}

	return ret;
}

int main(){
    string s = "PAYPALISHIRING";
    int n = 3;

    cout << convert(s,n) << endl;

    return 0;
}