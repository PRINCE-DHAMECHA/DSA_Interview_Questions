//& Question: Implement the "paint fill" function that one might see on many image editing programs. That is, given a screen(2D Array), A point, and a new color, fill in the surrounding area until the color changes from the original color.

//^ Solution:

//* We simply check neighbors and do recursive paint on them

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

enum Color
{
    Black,
    White,
    Red,
    Yellow,
    Green
};

bool paintFill(vector<vector<Color>> screen, int r, int c, Color nColor)
{
    if (screen[r][c] == nColor)
    {
        return false;
    }
    return paintFill(screen, r, c, screen[r][c], nColor);
}

bool paintFill(vector<vector<Color>> screen, int r, int c, Color oColor, Color nColor)
{
    if (r < 0 || r > screen.size() || c < 0 || c >= screen[0].size())
    {
        screen[r][c] = nColor;
        paintFill(screen, r - 1, c, oColor, nColor);
        paintFill(screen, r + 1, c, oColor, nColor);
        paintFill(screen, r, c - 1, oColor, nColor);
        paintFill(screen, r, c + 1, oColor, nColor);
    }
    return true;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}