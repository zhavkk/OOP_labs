#include <iostream>
#include "Eleven.h"
using namespace std;

int main(){
    {
    try
    {
        string s1, s2;

        cin >> s1 >> s2;

        Eleven num1 = Eleven(s1);
        Eleven num2 = Eleven(s2);

        char op;

        cin >> op;

        bool res;
        switch (op) 
        {
            case '+':
                cout << "Result: " << (num1 + num2).get_array() << '\n';
                break;

            // case '-':
            //     cout << "Result: " << (num1 - num2).get_stringified() << '\n';
            //     break;

            // case '>':
            //     res = num1 > num2;
            //     cout << "Result: " << res << '\n';
            //     break;

            // case '<':
            //     res = num1 < num2;
            //     cout << "Result: " << res << '\n';
            //     break;

            // case '=':
            //     res = num1 == num2;
            //     cout << "Result: " << res << '\n';
            //     break;

            default:
                cout << "No such operation" << '\n';
                break;
        }
    }
    catch(const exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}






}