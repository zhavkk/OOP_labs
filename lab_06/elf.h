#pragma once
#include "NPC.h"


class Elf: public NPC {
public:
    Elf(const int&, const int&, const std::string&);

    void print(std::ostream&) override;

    void accept(NPC*, const int&) override;

    friend std::ostream& operator<<(std::ostream&, const Elf&);
};