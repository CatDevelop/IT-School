    #include <stack>
    #include <stdlib.h>
    #include <string>
    #include <iostream>
    using namespace std;

    int main()
    {
        stack <char> stk;

        string str;
        cin >> str;

        for(int i = 0; i<str.length(); i++)
        {
            if(str[i] != ']' && str[i] != '}' && str[i] != ')')
            {
                cout << "Push: " << str[i] << endl;
                stk.push(str[i]);
                continue;
            }else{
                cout << "Top: "<< stk.top();
                cout << " ? " << str[i] << endl;
                if((str[i] == '}' && stk.top() == '{') || (str[i] == ']' && stk.top() == '[') || (str[i] == ')' && stk.top() == '('))
                {
                    cout << "Pop: "<< str[i] << endl;
                    stk.pop();
                    continue;
                }else{
                    cout << "No";
                    return 0;
                }
            }
        }
        cout << "Yes";
        return 0;
    }
