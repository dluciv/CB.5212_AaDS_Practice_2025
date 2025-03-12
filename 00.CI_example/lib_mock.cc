#include <iostream>
#include <sstream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "lib.h"

class MockC: public C
{
public:
    MOCK_METHOD(int, do_smth, (int), (override));
};

TEST(LibTest, MockTest) {
    MockC m;

    EXPECT_CALL(m, do_smth(1))
        .Times(1)
        .WillOnce(::testing::Return(2));

    EXPECT_EQ(m.do_smth(1), 2);
}
