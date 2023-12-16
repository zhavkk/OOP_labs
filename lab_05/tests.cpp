#include<gtest/gtest.h>
#include <list>
#include "list.h"
#include "allocator.h"

TEST(test_1, push_back)
{   
    List<int, Allocator<int, 10>> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    List<int> list2;
    list2.push_back(1);
    list2.push_back(2);
    list2.push_back(3);

    List<int>::Iterator it2 = list2.begin();
    List<int, Allocator<int, 10>>::Iterator it1 = list1.begin();

    for (it1; it1 != list1.end(); ++it1){
        ASSERT_EQ(*it1, *it2);
        ++it2;
    }

    list1.push_back(-1);
    list1.push_back(0);
    list1.push_back(12345);

    list2.push_back(-1);
    list2.push_back(0);
    list2.push_back(12345);

    for (it1; it1 != list1.end(); ++it1){
        ASSERT_EQ(*it1, *it2);
        ++it2;
    }
}

TEST(test_2, push_front)
{   
    List<int, Allocator<int, 10>> list1;
    list1.push_front(11);
    list1.push_front(2);
    list1.push_front(-3);

    List<int> list2;
    list2.push_front(11);
    list2.push_front(2);
    list2.push_front(-3);

    List<int>::Iterator it2 = list2.begin();
    List<int, Allocator<int, 10>>::Iterator it1 = list1.begin();

    for (it1; it1 != list1.end(); ++it1){
        ASSERT_EQ(*it1, *it2);
        ++it2;
    }

    list1.push_front(-1);
    list1.push_front(0);
    list1.push_front(12345);

    list2.push_front(-1);
    list2.push_front(0);
    list2.push_front(12345);

    for (it1; it1 != list1.end(); ++it1){
        ASSERT_EQ(*it1, *it2);
        ++it2;
    }
}

TEST(test_3, pop_back)
{   
    List<int, Allocator<int, 10>> list1;
    list1.push_back(1);
    list1.push_back(0);
    list1.push_back(3);
    list1.pop_back();

    List<int> list2;
    list2.push_back(1);
    list2.push_back(0);
    list2.push_back(3);
    list2.pop_back();

    List<int>::Iterator it2 = list2.begin();
    List<int, Allocator<int, 10>>::Iterator it1 = list1.begin();

    for (it1; it1 != list1.end(); ++it1){
        ASSERT_EQ(*it1, *it2);
        ++it2;
    }
}

TEST(test_4, pop_front)
{   
    List<int, Allocator<int, 10>> list1;
    list1.push_back(-1);
    list1.push_back(2);
    list1.push_back(-3);
    list1.pop_front();

    List<int> list2;
    list2.push_back(-1);
    list2.push_back(2);
    list2.push_back(-3);
    list2.pop_front();

    List<int>::Iterator it2 = list2.begin();
    List<int, Allocator<int, 10>>::Iterator it1 = list1.begin();

    for (it1; it1 != list1.end(); ++it1){
        ASSERT_EQ(*it1, *it2);
        ++it2;
    }
}

TEST(test_5, insert)
{   
    List<int, Allocator<int, 10>> list1;
    list1.push_front(10);
    list1.push_front(2);
    list1.push_front(39);

    List<int> list2;
    list2.push_front(10);
    list2.push_front(2);
    list2.push_front(39);

    list1.insert(0, -1);
    list1.insert(3, 100);

    list2.insert(0, -1);
    list2.insert(3, 100);

    List<int>::Iterator it2 = list2.begin();
    List<int, Allocator<int, 10>>::Iterator it1 = list1.begin();

    for (it1; it1 != list1.end(); ++it1){
        ASSERT_EQ(*it1, *it2);
        ++it2;
    }
}

TEST(test_6, erase)
{   
    List<int, Allocator<int, 10>> list1;
    list1.push_front(10);
    list1.push_front(2);
    list1.push_front(39);

    List<int> list2;
    list2.push_front(10);
    list2.push_front(2);
    list2.push_front(39);

    list1.erase(0);

    list2.erase(0);

    List<int>::Iterator it2 = list2.begin();
    List<int, Allocator<int, 10>>::Iterator it1 = list1.begin();

    for (it1; it1 != list1.end(); ++it1){
        ASSERT_EQ(*it1, *it2);
        ++it2;
    }

    list1.erase(1);

    list2.erase(1);

    for (it1; it1 != list1.end(); ++it1){
        ASSERT_EQ(*it1, *it2);
        ++it2;
    }
}

TEST(test_7, size)
{   
    List<int, Allocator<int, 10>> list1;
    list1.push_front(10);
    list1.push_front(2);
    list1.push_front(39);

    List<int> list2;
    list2.push_front(10);
    list2.push_front(2);
    list2.push_front(39);

    ASSERT_EQ(list1.get_size(), list2.get_size());

    list1.insert(0, -1);

    list2.insert(0, -1);

    ASSERT_EQ(list1.get_size(), list2.get_size());

    list1.push_front(39);

    list2.push_front(39);

    ASSERT_EQ(list1.get_size(), list2.get_size());
}