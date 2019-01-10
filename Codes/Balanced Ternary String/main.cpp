#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[3]={0},n;
    string s;
    cin  >> n >> s;
    for(int i=0;i<n;i++)
        a[s[i]-'0']++;
    n/=3;
    for(int i=0,x=0,y=0;i<s.size();i++)
    {
        if(s[i]=='2' && a[2]>n)
        {
            if(a[0]<n)
                s[i]='0',a[0]++,a[2]--;
            else if(a[1]<n)
                s[i]='1',a[1]++,a[2]--;
        }
        if(s[i]=='1' && a[1]>n)
        {
            y++;
            if(a[0]<n)
                s[i]='0',a[0]++,a[1]--,y--;
            else if(a[2]<n && y>n)
                s[i]='2',a[2]++,a[1]--;
        }
        if(s[i]=='0' && a[0]>n)
        {
            x++;
            if(a[1]<n && x>n)
                s[i]='1',a[1]++,a[0]--;
            else if(a[2]<n && x>n)
                s[i]='2',a[2]++,a[0]--;
        }
    }
    cout << s << endl;
    return 0;
}
