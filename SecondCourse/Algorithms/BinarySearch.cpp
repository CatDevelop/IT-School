    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <iostream>

    int main()
    {
        int key = 0;
        int start = 0;
        int end = 27;

        std::cin >> key;

        int m[end];

        for(int i = start; i<end+1; i++)
        {
            m[i] = i*2;
            std::cout << m[i] << " ";
        }

        for(int i = 0; i < end+2; i++)
        {
            if(m[(end+start)/2] != key)
            {
                if(m[(end+start)/2] > key)
                {
                    end = (end+start)/2;
                }else{
                    start = (end+start)/2;
                }
            }else{
                std::cout << "\nMatches found. This is element " << (end+start)/2+1 << ".\n";
                system ("pause");
                return 1;
            }
        }
        
        std::cout << "\nNo matches found.\n";    
        system ("pause");
        return 1;
    }
