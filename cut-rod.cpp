#include <iostream>
#include <iomanip>
#include <climits>

// Extended-Bottom-Up-Cut-Rod from Cormen
void cutRod(int p[],int n,int r[],int s[])
{
    int q;
    r[0] = 0;

    for (int j = 1; j <= n; j++)
    {
        q = INT_MIN;
        for (int i = 1; i <= j; i++)
        {
            if(q < (p[i] + r[j-i]))
            {
                q = p[i] + r[j-i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
}

// Print-Cut-Rod-Solution from Cormen
void printCutRod(int p[],int n,int r[],int s[])
{
    cutRod(p, n, r, s);
    std::cout << std::setw(4) << std::right << n << std::setw(8) << std::right << r[n] << std::setw(9);
    while(n > 0)
    {
        std::cout << s[n];
        n = n - s[n];
        if(n > 0)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

int main()
{
    int const n = 15; // Rod size n
    int p[n+1] = {0,1,5,8,9,10,17,17,20,24,30}; // rod price p[n]

    int r[n+1];
    int s[n+1];
    
    std::cout << "Length" << std::setw(8) << "Value" << std::setw(8) << "Cuts" << std::endl;
    for(int i = 1; i <= n; i++)
        printCutRod(p,i,r,s);

    return 0;
}