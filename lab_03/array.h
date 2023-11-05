#pragma once
#include "figure.h"

class Array{


    public:
        Array();
        Array(size_t size);

        virtual ~Array();
            
        void del_figure(size_t index);
        double avg_ploshad(); //srednya ploshad
        
        Figure* operator[](size_t index) const;

        void changefigures(size_t index, Figure *other);

        

    private:
        size_t _size;
        Figure** _figures;


};