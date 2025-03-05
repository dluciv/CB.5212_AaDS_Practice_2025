#include <iostream>
#include <sstream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "lib.h"

class mock_std_ostream : public std::ostream {
public:
    mock_std_ostream() : std::ostream(&buffer) {}
    MOCK_METHOD2(write, std::ostream&(const char* s, std::streamsize n));
    MOCK_METHOD0(flush, std::ostream&());

private:
    std::stringbuf buffer;
};



TEST(LibTest, NameIsOleg) {
    // Для строк C -- EXPECT_STREQ
    EXPECT_EQ(who_am_i(), "Олег");
}

TEST(LibTest, OutputTest) {
    mock_std_ostream cout_mock;

    // Ожидаем, что будет вызваны методы с определенными аргументами
    EXPECT_CALL(cout_mock, write(testing::_, 5)).Times(1).WillOnce(testing::ReturnRef(cout_mock));
    EXPECT_CALL(cout_mock, flush).Times(1).WillOnce(testing::ReturnRef(cout_mock));

    // И всё это работать не будет...
    // cout_mock << "Hello!" << std::endl;
    // writesmth(cout_mock);
    // А будет только так. А кто скажет, почему?

    cout_mock.write("Azaza", 5);
    cout_mock.flush();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
