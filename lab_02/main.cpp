#include <iostream>
#include <string>
#include "Eleven.h"
#include <cmath>
int main(){
    std::string s1,s2;
    std::cout << "Enter 1 num: \n num1 = ";
    std::cin >> s1;

    std::cout << "Enter 2 num: \n num2 = ";
    std::cin >> s2;

    Eleven num1(s1);
    Eleven num2(s2);

    std::cout << "Number1 v 10 s.s = " << num1.translate_to_10() << '\n';
    std::cout << "Number2 v 10 s.s = " << num2.translate_to_10() << '\n' << '\n';

    std::cout << "a plus b = " << num1.plus(num2) << '\n';
    std::cout << "a minus b = " << num1.minus(num2) << '\n';
    std::cout << "a > b : " << num1.bigger(num2) << '\n';
    std::cout << "a < b : " << num1.smaller(num2) << '\n';
    std::cout << "a = b : " << num1.equall(num2) << '\n' << '\n';


    std::cout << std::endl << "length num1 : " << num1.get_size() << std::endl;
    std::cout << "length num2 : " << num2.get_size() << std::endl << std::endl;
    std::cout<<"ffff"<<std::endl;

    Eleven copy_num1 = num1.copy();
    std::cout<<"ffff"<<std::endl;
    std::cout << "Copy of num1:  " << copy_num1.get_array() << std::endl;
    Eleven copy_num2=num2.copy();
    std::cout<<"ffff"<<std::endl;
    std::cout<<"Copy of num2 : "<<copy_num2.get_array()<<std::endl;
    std::cout<<" GET STRING : "<<num1.get_string()<<std::endl;
    return 0;
}