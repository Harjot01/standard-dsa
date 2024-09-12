// Don't Overthink, Just Code
#include <bits/stdc++.h>
using namespace std;

bool validate(char *name)
{
    int i(0);
    while (name[i] != '\0')
    {
        if (!(name[i] >= 65 && name[i] <= 90) && !(name[i] >= 97 && name[i] <= 122) && !(name[i] >= 48 && name[i] <= 57))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int main()
{
    char name[] = "harjot23423";
    if (validate(name))
        cout << "Valid" << endl;
    else
        cout << "Invalid" << endl;
    return 0;
}