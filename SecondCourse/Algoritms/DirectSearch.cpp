    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <iostream>

    int main()
    {
        int key = 0;
        int cnt = 0;

        std::cin >> key;

        int m[20];
        srand(time(NULL));
        for(int i = 0; i<20; i++)
        {
            m[i] = rand()%20+1;
            std::cout << m[i] << " ";
            if(m[i] == key)
            {
                cnt++;
            }
        }

        if(cnt > 0)
        {
            std::cout << "\nDetected " << cnt << " keys: \n";
        }else{
            std::cout << "I don't find keys.\n";
        }

        for(int i = 0; i<20; i++)
        {
            if(m[i] == key)
            {
                std::cout << i+1 << " ";
            }
        }
        return 0;
    }
