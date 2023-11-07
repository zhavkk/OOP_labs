#include "figure.h"

class Array{


    public:
        Array();
        Array(size_t size);

        ~Array();
            
        void del_figure(size_t index);
        double avg_ploshad(); //srednya ploshad
        
        Figure *operator[](size_t index);

        void changefigures(size_t index, Figure *other);
        size_t get_size(){
            return _size;
        }
        

    private:
        size_t _size;
        Figure** _figures;


};