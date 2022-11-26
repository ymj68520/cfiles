def myfunc():
    course = ["高等数学","概率论与数理统计","统计学","Python","计算机网络","数据库",
            "数据结构","管理学","计算机基础","逻辑学"];
    corseSelected = [];
    i=0;
    while i<len(course):
        if (course[i].find("数") != -1):
            corseSelected.append(course[i]);
        i = i + 1;
    print(corseSelected);

def timu1():
    string1 = input();
    string2 = input();
    string3 = "if "+string1 + ", " + string2 + ".";
    print(string3);

def timu2():
    inte = input();
    integer = int(inte);
    print(integer);
    integer = integer - 32;
    integer = integer * 5;
    integer = integer / 9;
    print("%.2f"%integer);

def fast_power(base, power):
    res = 1
    while power > 0:
        if power % 2 == 1:
            res = res * base % 1000
        power = power // 2
        base = base * base % 1000
    return res % 1000

def timu3():
    int1 = int(input());
    int2 = int(input());
    res = 1
    while int2 > 0:
        if(int2 % 2 ==1):
            res = res * int1 % 1000000007;
        int2 = int2 // 2;
        int1 = int1 * int1 % 1000000007;
    return res % 1000000007;

def timu4():
    benjin = float(input());
    lilv = float(input());
    nianshu = int(input());
    huilv = float(input());
    print(int((benjin * huilv) * (1 + lilv)**(nianshu)));
    int123=input().split()
    
def xiaoniuchicao():
    print(input());
    left,right = map(int,input().split(" "));
    bleft = bin(left).replace("0b","");
    bright = bin(right).replace("0b","");
    byu = bin(left & right).replace("0b","");
    find1  = [];pos = byu.find("1");
    while pos != -1:
        find1.append(pos+1);
        pos = byu.find("1",pos+1);
    byu1 = 0;
    for posi in find1:
        byu1 = byu1 + int(bleft[posi]) & int (bright[posi]);
    print(byu1);
    bhuo = bin(left | right).replace("0b","");
    find1 = [];pos = bhuo.find("1");
    while pos != -1:
        find1.append(pos+1);
        pos = bhuo.find("1",pos+1);
    bhuo1 = 0;
    for posi in find1:
        bhuo1 = bhuo1 + int(bleft[posi]) & int (bright[posi]);
    print(bhuo1);
    



if __name__ == "__main__":
    myfunc();
    # timu1();
    # timu2();
    # print(timu3());
    # timu4();
    # xiaoniuchicao();
    str = input();
    left, right = map(int, input().split(" "));
    print(str);
    print(letf & right);
    print(left | right);

    
    


