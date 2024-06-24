#include<bits/stdc++.h>
using namespace std;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int i1 = s1.length()-1;
    int i2 = s2.length()-1;
    while(i1!=-1&&i2!=-1&&s1[i1]==s2[i2]){
        i1--;
        i2--;
    }
    cout<<i1+i2+2<<endl;
    return 0;
}
