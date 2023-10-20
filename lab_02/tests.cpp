#include <gtest/gtest.h>
#include "Eleven.h"

TEST(test_1, AllMetods)
{
	Eleven a("123");
    Eleven b("2");

	size_t sizea = a.get_size();
	size_t expectSizea = 3;
    size_t sizeb = b.get_size();
	size_t expectSizeb = 1;

	unsigned char* numsa = a.get_array();
	unsigned char expectNumsa[] = {'3', '2', '1'};
    unsigned char* numsb = b.get_array();
	unsigned char expectNumsb[] = {'2'};

    int to_10a = a.translate_to_10();
    int expectto_10a = 386;
    int to_10b = b.translate_to_10();
    int expectto_10b = 2;
    
    std::string ab = a.plus(b);
    std::string expectab = ("323");
    std::string a_b = a.minus(b);
    std::string expecta_b = ("31A");

    std::string aab = a.bigger(b);
    std::string expectaab = ("true");
    std::string abb = a.smaller(b);
    std::string expectabb = ("false");
    std::string aabb = a.equall(b);
    std::string expectaabb = ("false");

    ASSERT_EQ(sizea, expectSizea);
    ASSERT_EQ(sizeb, expectSizeb);

	for (size_t q = 0; q < sizea; q++) 
		ASSERT_EQ(numsa[q], expectNumsa[q]);
    for (size_t q = 0; q < sizeb; q++) 
		ASSERT_EQ(numsb[q], expectNumsb[q]);

    ASSERT_EQ(to_10a, expectto_10a);
    ASSERT_EQ(to_10b, expectto_10b);

    ASSERT_EQ(ab, expectab);
    ASSERT_EQ(a_b, expecta_b);

    ASSERT_EQ(aab, expectaab);
    ASSERT_EQ(abb, expectabb);
    ASSERT_EQ(aabb, expectaabb);

}