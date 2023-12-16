#include <gtest/gtest.h>
#include <memory>
#include "npc.h"
#include "elf.h"
#include "dragon.h"
#include "druid.h"

TEST(test_01, Elf_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Elf>(x, y);

    EXPECT_EQ((a->position()).first,100);
}

TEST(test_02, Elf_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Elf>(x, y);
    EXPECT_EQ(ElfType,a->get_type());
}

TEST(test_03, Elf_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Elf>(x, y);
    EXPECT_TRUE(a->is_alive());
}



TEST(test_04, dragon_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Dragon>(x, y);

    EXPECT_EQ((a->position()).first,100);
}

TEST(test_05, dragon_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Dragon>(x, y);
    EXPECT_EQ(DragonType,a->get_type());
}

TEST(test_06, dragon_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Dragon>(x, y);
    EXPECT_TRUE(a->is_alive());
}


TEST(test_07, dragon_constructor){
    int x{10};
    int y{10};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Dragon>(x, y);

    a->move(50,50,100,100);
    EXPECT_EQ((a->position()).first,60);
}


TEST(test_08, Druid_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Druid>(x, y);

    EXPECT_EQ((a->position()).second,100);
}

TEST(test_09, Druid_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Druid>(x, y);
    EXPECT_EQ(DruidType,a->get_type());
}

TEST(test_10, Druid_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Druid>(x, y);
    EXPECT_TRUE(a->is_alive());
}

