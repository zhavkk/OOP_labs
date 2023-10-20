
#include <iostream>
#include <string>


class Eleven {
    public:
        Eleven(); //default constr
        Eleven(const std::size_t &size,unsigned char t=0);
        Eleven(const std::initializer_list<unsigned char> &t);
        Eleven(const std::string &t);
        Eleven(const Eleven& other);
        Eleven copy();

        Eleven(Eleven&& other) noexcept;
        ~Eleven() noexcept;

    
        size_t get_size();
        unsigned char* get_array();
        std::string get_string();
        int translate_to_10();
        // static std::string translate_to_11(int number);

        std::string plus(const Eleven& other);
        std::string minus(const Eleven& other);
        std::string bigger(const Eleven& other);
        std::string smaller(const Eleven& other);
        std::string equall(const Eleven& other);



    private:
        size_t _size;
        unsigned char *_array;
        int to_10;
        
};
