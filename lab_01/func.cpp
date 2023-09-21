#include <bits/stdc++.h>


std::string func(std::string s){


    std::string ans = ""; 

    std::string number = ""; 


    for(char c : s){ 
        if(std::isdigit(c)){ 
            number+=c;
        }
        else{ 
            if(!number.empty()){
                ans=ans+number+" ";
                number="";
            }
        }
    }

    if(!number.empty()){
        ans=ans+number+" ";
        
    }
    
    return ans;   
}

