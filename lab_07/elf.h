#pragma once
#include "npc.h"

struct Elf : public NPC
{
    Elf(int x, int y);
    Elf(std::istream &is);

    void print() override;

    bool fight(std::shared_ptr<Dragon> other) override;
    bool fight(std::shared_ptr<Druid> other) override;
    bool fight(std::shared_ptr<Elf> other) override;
    bool accept(std::shared_ptr<NPC> visitor) override;
    

    void save(std::ostream &os) override;

    friend std::ostream &operator<<(std::ostream &os, Elf &dragon);
};