#include <iostream>
#include <sstream>
#include <gtest/gtest.h>

#include "lib.h"

TEST(LibTest, NameIsOleg) {
    // Для строк C -- EXPECT_STREQ
    EXPECT_EQ(who_am_i(), "Олег");
}

TEST(LibTest, OutputTest) {
    std::ostringstream mocked_ostream;
    auto cout_buf = std::cout.rdbuf();       // Сохраняем текущий буфер cout
    std::cout.rdbuf(mocked_ostream.rdbuf()); // и заменяем его на фальшивый

    greet();

    std::cout.rdbuf(cout_buf);

    EXPECT_EQ(mocked_ostream.str(), "Привет, Олег!\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
