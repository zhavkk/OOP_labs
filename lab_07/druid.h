#pragma once
#include "npc.h"

struct Druid : public NPC
{
    Druid(int x, int y);
    Druid(std::istream &is);

    void print() override;

    bool fight(std::shared_ptr<Dragon> other) override;
    bool fight(std::shared_ptr<Druid> other) override;
    bool fight(std::shared_ptr<Elf> other) override;
    bool accept(std::shared_ptr<NPC> visitor) override;
    

    void save(std::ostream &os) override;

    friend std::ostream &operator<<(std::ostream &os, Druid &dragon);
};