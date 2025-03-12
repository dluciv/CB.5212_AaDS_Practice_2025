#include <iostream>
#include <sstream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "lib.h"

class MockC: public C
{
public:
    MOCK_METHOD0(void, do_smth, (), (override));
};

TEST(LibTest, MockTest) {
    MockC m;

    EXPECT_CALL(m, do_smth())
        .Times(1)
        .WillOnce(testing::Return());

    m.do_smth();
}
