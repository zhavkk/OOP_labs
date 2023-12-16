#include "elf.h"
#include "dragon.h"
#include "druid.h"
#include <algorithm>

Druid::Druid(const int& _x, const int& _y, const std::string& _name) {
    x = _x;
    y = _y;
    name = _name;
    alive = true;
}

void Druid::print(std::ostream& out) {
    out << *this;
}

void Druid::accept(NPC* attacker, const int& distance) {
    if (alive && dynamic_cast<Elf*>(attacker) && attacker != this) {
        bool win = is_close(*attacker, distance);
        if (win) 
            alive = false;
        notify(attacker, win);
    }
}

std::ostream& operator<<(std::ostream& out, const Druid& other) {
    return out << "Druid " << other.name << " {" << other.x << ", " << other.y << '}';
}