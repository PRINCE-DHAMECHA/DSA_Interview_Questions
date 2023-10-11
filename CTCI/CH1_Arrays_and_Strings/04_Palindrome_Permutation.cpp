//& Question:  Given string,Write a function to check if it a permutation of palindrome.

//^ Solution:

//~ Intuition
//* Palindrome has twice time all characters(repetition can be there like 2,4,6,...) and at most one single character for middle
//* For even length string there must be no unique character and for odd length there must be exactly one unique character

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach-1 :-
//* use hashtable (pretty much straight forward)

//~ Approach-2 :-
//* We can use similar approach which we used in problem-01, i.e. using bit vector with single int
//* We can make bit to 1 if it's odd and 0 for even
//* At the end we need to check that at most 1 bit should be 1
//^ Trick: How to check for at most one bit is 1?
//* Compare first with 0 -> if same return true
//* (i) AND (i-1) -> if 0 return true else false
//* Ex:- i=0010000, i-1=0001111 -> ans:- 0000000 -> true

bool checkExactlyOneBitSet(int bitVector)
{
    return (bitVector & (bitVector - 1)) == 0;
}

int toggle(int bitVector, int index)
{
    if (index < 0)
    {
        return bitVector;
    }
    int mask = 1 << index;
    //* If bit is 0 make it 1
    if ((bitVector & mask) == 0)
    {
        bitVector |= mask;
    }
    //* If bit is 1 make it 0
    else
    {
        bitVector &= ~mask;
    }
    return bitVector;
}

int createBitVector(string str)
{
    int bitVector = 0;
    for (auto i : str)
    {
        bitVector = toggle(bitVector, i - 'a');
    }
    return bitVector;
}

bool isPermutationOfPalindrome(string str)
{
    int bitVector = createBitVector(str);
    return bitVector == 0 || checkExactlyOneBitSet(bitVector);
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    cout << isPermutationOfPalindrome("tactcoapapa") << endl;
    cout << isPermutationOfPalindrome("abba") << endl;
    cout << isPermutationOfPalindrome("abcba") << endl;
    cout << isPermutationOfPalindrome("adcba") << endl;
    cout << isPermutationOfPalindrome("adcad") << endl;
    return 0;
}
