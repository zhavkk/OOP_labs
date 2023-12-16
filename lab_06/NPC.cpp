#include "NPC.h"
#include <algorithm>

bool NPC::is_close(const NPC& other, const int& distance) const noexcept {
    return (x - other.x) * (x - other.x)
        + (y - other.y) * (y - other.y) 
        <= distance * distance;
}

void NPC::notify(NPC* attacker, bool win) {
    if (win) {
        for (auto &elem : NPC::observers) {
            elem->update(this, attacker, win);
        }
    }
}

std::ostream& operator<<(std::ostream& out, const NPC& other) {
    return out << "$NPC {" << other.x << ", " << other.y << '}';
}

void NPC::attach(Observer* observer) {
    observers.push_back(observer);
}
void NPC::detach(Observer* observer) {
    observers.erase(
        std::find(NPC::observers.begin(), NPC::observers.end(), observer));
}

bool NPC::is_alive() const noexcept { return alive; }