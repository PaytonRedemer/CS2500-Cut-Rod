#include <iostream>
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
    std::cout << "Length: " << n << " Value: " << r[n] << " Cuts: ";
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
    int const n = 15;
    int p[n+1] = {0,1,5,8,9,10,17,17,20,24,30};
    int r[n+1];
    int s[n+1];
    for(int i = 1; i <= n; i++)
        printCutRod(p,i,r,s);
    


    // cutRod(p, n, r, s);

    // for(int i = 0; i <= n; i++)
    // {
    //     std::cout << i << ": r[" << i << "] = " << r[i] << ", s[" << i << "] = " << s[i] << std::endl;
    // }
    return 0;
}