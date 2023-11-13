#pragma once

class Figure{
    public:
        Figure()=default;
        virtual ~Figure()=default;

        virtual explicit operator double() const{
            return 0.0;
        }
};