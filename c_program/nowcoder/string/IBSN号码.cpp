#include<bits/stdc++.h>
using namespace std;
int main()
{
    int len=0,tle=0,ans=0;
    string a;
    cin>>a;
    len=a.size();
    char s[len];
    for(int i=0;i<len;i++)
    {
        if(a[i]!='-')s[++tle]=a[i];
    }
    for(int i=1;i<tle;i++)
    {
        ans+=i*(s[i]-'0');
    }
    ans=ans%11;       
    if(ans==s[tle]-'0')cout<<"Right";
     else if(ans==10&&s[tle]=='X')cout<<"Right";
    else
    { for(int i=0;i<len-1;i++)
        {
            cout<<a[i];
        }   if(ans==10)cout<<"X";
             else cout<<ans;
    }
    return 0;
}