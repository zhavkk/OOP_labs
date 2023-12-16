#include "elf.h"
#include "dragon.h"
#include "druid.h"

Elf::Elf(int x, int y) : NPC(ElfType, x, y) {}
Elf::Elf(std::istream &is) : NPC(ElfType, is) {}

bool Elf::accept(std::shared_ptr<NPC> visitor){
    return visitor->fight(std::shared_ptr<Elf>(this,[](Elf*){}));
}

void Elf::print()
{
    std::cout << *this;
}

void Elf::save(std::ostream &os)
{
    os << ElfType << std::endl;
    NPC::save(os);
}


bool Elf::fight(std::shared_ptr<Dragon> other)
{
    fight_notify(other, false);
    return true;
}

bool Elf::fight(std::shared_ptr<Druid> other)
{
    fight_notify(other, true);
    return true;
}

bool Elf::fight(std::shared_ptr<Elf> other)
{
    fight_notify(other, false);
    return true;
}

std::ostream &operator<<(std::ostream &os, Elf &Elf)
{
    os << "Elf: " << *static_cast<NPC *>(&Elf) << std::endl;
    return os;
}