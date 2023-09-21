#include <bits/stdc++.h>


std::string func(std::string s){


    std::string ans = ""; // Заводим переменную , которая будет содержать результат

    std::string number = ""; // Заводим переменную, которая будет содержать в себе число


    for(char c : s){ // Посимвольно идем по строке s 
        if(std::isdigit(c)){ // Если символ является цифрой, то добавляем его в переменную number
            number+=c;
        }
        else{ // Нашли символ, который не является цифрой, 
        //далее если переменная number не пустая, то в ans добавляем number + " " и обнуляем number
            if(!number.empty()){
                ans=ans+number+" ";
                number="";
            }
        }
    }

    if(!number.empty()){//Проверяем граничный случай, при котором возможно нахождение числа в конце строки
        ans=ans+number+" ";
        
    }
    
    return ans;   
}

