#pragma once
#include "NPC.h"

class Druid : public NPC{
    public:
        Druid(const int&, const int&, const std::string&);

        void print(std::ostream&) override;

        void accept(NPC*, const int&) override;

        friend std::ostream& operator<<(std::ostream&, const Druid&);

};