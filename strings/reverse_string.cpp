// Don't Overthink, Just Code
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char A[] = "121";
    char B[7];
    int i(0), j;
    while (A[i] != '\0')
    {
        i++;
    }
    i--;
    for (j = 0; i >= 0; i--, j++)
    {
        B[j] = A[i];
    }
    B[j] = '\0';
    cout << B << endl;
    
    if (A == B)
        cout << "palindrome";
    else
        cout << "not a palindrome";
    return 0;
}
