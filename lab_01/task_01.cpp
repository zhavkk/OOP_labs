#include <iostream>
#include "func.h"
#include <string>

int main(){
    std::string s;
    std::getline(std::cin, s);
    std::cout<<"result : "<<func(s);
    
}