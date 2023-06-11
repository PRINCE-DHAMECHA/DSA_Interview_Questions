//& Question:  Find whether s2 is right rotation of s1 or not using only one call to isSubstring.

//^ Solution:
//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* s1=x+y
//* s2=y+x
//* s1+s1= x+y+x+y
//* check isSubstring(s1+s1,s2);

bool isRotate(string s1, string s2)
{
    return s1.size() == s2.size() && (s1 + s1).find(s2) < (s1 + s1).size() ? true : false;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    cout << isRotate("waterbottle", "erbottlewat") << endl;
    cout << isRotate("waterbottle", "erbotlewate") << endl;
    return 0;
}
