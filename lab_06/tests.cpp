#include <gtest/gtest.h>
#include <sstream>
#include <vector>
#include <memory>
#include "dragon.h"
#include "druid.h"
#include "elf.h"
#include "factory.h"

TEST(Constructors, Dragon) {
    Dragon s(0, 0, "Drakon");
    std::stringstream out;
    s.print(out);
    ASSERT_EQ(out.str(), "Dragon Drakon {0, 0}");
}

TEST(Constructors, Druid) {
    Druid t(1, 1, "Dru");
    std::stringstream out;
    t.print(out);
    ASSERT_EQ(out.str(), "Druid Dru {1, 1}");
}

TEST(Constructors, Elf) {
    Elf e(2, 2, "Dobbi");
    std::stringstream out;
    e.print(out);
    ASSERT_EQ(out.str(), "Elf Dobbi {2, 2}");
}

TEST(Fabric, basic) {
    std::vector<std::shared_ptr<NPC>> persons;
    persons.push_back(factory("Dragon", "Name", 0, 0));
    persons.push_back(factory("Druid", "Name", 0, 0));
    persons.push_back(factory("Elf", "Name", 0, 0));

    std::stringstream out;
    for (auto& elem : persons) {
        elem->print(out);
    }
    ASSERT_EQ(out.str(), "Dragon Name {0, 0}Druid Name {0, 0}Elf Name {0, 0}");
}

TEST(Fighting, basic) {
    std::vector<std::shared_ptr<NPC>> persons;
    persons.push_back(factory("Dragon", "Name", 0, 0));
    persons.push_back(factory("Druid", "Name", 0, 0));
    persons.push_back(factory("Elf", "Name", 0, 0));

    for (auto& defender : persons) {
        for (auto& attacker : persons) {
            defender->accept(attacker.get(), 0);
        }
    }
    for (auto& elem : persons) {
        ASSERT_FALSE(elem->is_alive());
    }
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}