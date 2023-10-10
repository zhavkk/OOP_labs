
#include <iostream>
#include <string>


class Eleven {
    public:
        Eleven(); //default constr
        Eleven(const std::size_t &size,unsigned char t=0);
        Eleven(const std::initializer_list<unsigned char> &t);
        Eleven(const std::string &t);
        Eleven(const Eleven& other);
        Eleven(Eleven&& other) noexcept;
        ~Eleven() noexcept; //десткруктор

        //getter
        size_t get_size();
        std::string get_array();

        Eleven operator+(const Eleven& other);
        Eleven operator-(const Eleven& other);
        Eleven operator=(const Eleven& other);
        bool operator<(const Eleven& other);
        bool operator>(const Eleven& other);
        bool operator==(const Eleven& other);



    private:
        size_t _size;
        unsigned char *_array;
        void resize(size_t);
        
};
