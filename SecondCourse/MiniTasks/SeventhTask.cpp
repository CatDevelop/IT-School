/*
    Написать функцию, формирующую по заданному списку целых чисел вектор из элементов списка с четными значениями и распечатывающую его.
*/
    #include <iostream>
    #include <vector>
    #include <list>
    using namespace std;

    void foo(vector<int> &v, list<int> &l);


    int main()
    {
        vector<int> v(20);
        list<int> l;

        for (int i = 1; i<20; ++i)
        {
            l.push_back(i);
        }
        cout << "list is created" << endl;
        foo(v, l);
        return 0;
    }

    void foo(vector<int> &v, list<int> &l)
    {
        list<int>::const_iterator p = l.begin ();

        while (p != l.end())
        {
            if ( !(*p % 2) ) v.push_back(*p);
            ++p;
        }

        for ( int i = 0; i < v.size(); ++i )
        {
            if(v[i] != 0)
            {
                cout << v[i] << endl;
            }
        }
    }
