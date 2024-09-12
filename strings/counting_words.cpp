// Don't Overthink, Just Code
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char name[] = "My name   is Harjot Singh ";
    int i = 0, ct(0);
    while (name[i] != '\0')
    {
        if (name[i] == ' ' && name[i - 1] != ' ')
            ct++;
        i++;
    }
    cout << ct + 1;
    return 0;
}