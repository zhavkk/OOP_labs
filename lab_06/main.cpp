#include <iostream>
#include <vector>
#include "dragon.h"
#include "druid.h"
#include "elf.h"
#include "observer.h"
#include "factory.h"


void load(std::vector<std::shared_ptr<NPC>>& array, std::ifstream& file) {
    while (file) {
        auto tmp = factory(file);
        if (tmp)
            array.push_back(tmp);
    }
}

void save(std::vector<std::shared_ptr<NPC>>& array, std::ofstream& file) {
    for (std::shared_ptr<NPC>& elem : array) {
        elem->print(file);
        file << std::endl;
    }
}

int main() {
    ConsoleObserver cobs;
    std::ofstream filelog("log.txt");
    FileObserver fobs(filelog);

    std::vector<std::shared_ptr<NPC>> persons;

    std::string query;
    do {
        std::cin >> query;
        if (query == "load") {
            std::ifstream file_for_load;
            std::string filename;
            std::cin >> filename;
            file_for_load.open(filename);
            load(persons, file_for_load);
        }
        else if (query == "save") {
            std::ofstream file_for_save;
            std::string filename;
            std::cin >> filename;
            file_for_save.open(filename);
            save(persons, file_for_save);
        }
        else if (query == "add") {
            auto new_npc = factory(std::cin);
            if (new_npc)
                persons.push_back(new_npc);
        }
        else if (query == "show") {
            for (auto& elem : persons) {
                elem->print(std::cout);
                std::cout << std::endl;
            }
        }
    } while(query != "fight");

    for (auto& elem : persons) {
        elem->attach(&cobs);
        elem->attach(&fobs);
    }
    std::cout << "Enter a distance" << std::endl;
    
    int distance;
    std::cin >> distance;

    for (auto& defender : persons) {
        for (auto& attacker : persons) {
            defender->accept(attacker.get(), distance);
        }
    }
}