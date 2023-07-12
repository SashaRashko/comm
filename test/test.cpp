#include "comm.hpp"
#include <gtest/gtest.h>
using namespace Sasha;

class Commtest : public ::testing::Test
{
    protected: 
    Sasha::Comm * comm;
};

TEST_F(Commtest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    auto url = std::string("//udp:127.0.0.1:1234");
    Commtest::comm = Sasha::Comm::create(url, true);
    EXPECT_EQ(nullptr, comm);
}
