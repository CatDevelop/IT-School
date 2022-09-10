    #include <iostream>
    #include <cstring>
    #include <stdio.h>
    #include <locale>
    using namespace std;

    int main()
    {
        char buffer[50] = {0};
        int flag;
        char c;
        int key, operation;

        cout<<"Enter the text: ";
        cin>>buffer;

        cout<<"Enter the key: ";
        cin>>key;

        cout<<"What do you want to do? (0-encode, 1-decode): ";
        cin>>operation;

        if(operation)
        {
            cout<<"Decode: ";
            for(int i = 0; i<strlen(buffer); i++)
            {
                c = buffer[i];
                flag = 0;
                if (c >= 'A' && c <= 'Z')
                {
                    c = c - (key % 26);
                    if (c < 'A') c = 'Z' - ('A' - c) + 1;
                    cout<<c;
                    flag = 1;
                }
                if (c >= 'a' && c <= 'z')
                {
                    c = c - (key % 26);
                    if (c < 'a') c = 'z' - ('a' - c) + 1;
                    cout<<c;
                    flag = 1;
                }
                if (!flag)
                {
                    cout<<c;
                }
            }
        }else{
            cout<<"Encode: ";
            for(int i = 0; i<strlen(buffer); i++)
            {
                c = buffer[i];
                flag = 0;

                if (c >= 'A' && c <= 'Z')
                {
                    c = c + (key % 26);
                    if (c > 'Z') { c = 'A' + (c - 'Z') - 1; }
                    cout<<c;
                    flag = 1;
                }
                if (c >= 'a' && c <= 'z')
                {
                    c = c + (key % 26);
                    if (c > 'z') { c = 'a' + (c - 'z') - 1; }
                    cout<<c;
                    flag = 1;
                }
                if (!flag)
                {
                    cout<<c;
                }
            }
        }
        cout<<endl;
        return 0;
    }
