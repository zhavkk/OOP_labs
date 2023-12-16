#include "factory.h"
#include "dragon.h"
#include "druid.h"
#include "elf.h"

std::shared_ptr<NPC> factory(std::istream& in) {
    std::string type, name;
    int x, y;
    char c;
    in >> type >> name >> c >> x >> c >> y >> c;
    std::shared_ptr<NPC> res;
    if (type == "Dragon") {
        res = std::make_shared<Dragon>(x, y, name);
    }
    else if (type == "Druid") {
        res = std::make_shared<Druid>(x, y, name);
    }
    else if (type == "Elf") {
        res = std::make_shared<Elf>(x, y, name);
    }
    else if (type != "") {
        std::cerr << "Unknown type" << std::endl;
    }
    return res;
}

std::shared_ptr<NPC> factory(const std::string& type, const std::string& name, const int& x, const int& y) {
    std::shared_ptr<NPC> res;
    if (type == "Dragon") {
        res = std::make_shared<Dragon>(x, y, name);
    }
    else if (type == "Druid") {
        res = std::make_shared<Druid>(x, y, name);
    }
    else if (type == "Elf") {
        res = std::make_shared<Elf>(x, y, name);
    }
    else {
        std::cerr << "Unknown type" << std::endl;
    }
    return res;
}