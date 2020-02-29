#include <iostream>

int main()
{
    unsigned long n, elem, i = 0;
    long answer = 0, k5 = 0;
    
    std::cin >> n;
    std::cin >> elem;
    
    while(i < n)
    {
        while(i < n && elem == 5)
        {
	        k5 += 1;
	        i += 1;
	        if(i < n)
	            std::cin >> elem;
        }
	    
        while(i < n && elem != 5)
        {
            k5 -= (elem - 5) / 5;
            i += 1;
            if(i < n)
	            std::cin >> elem;
        }
        
        if(k5 < 0)
        {
            answer -= k5;
            k5 = 0;
        }
        
    }

    if(answer <= 0)
        std::cout << 0;
    else
        std::cout << answer;

    return 0;
}