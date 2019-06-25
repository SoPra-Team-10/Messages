#include <gtest/gtest.h>
#include <src/Unicast/PrivateDebug.hpp>

using namespace communication::messages;

using T = unicast::PrivateDebug;

TEST(UnicastPrivateDebug, SerializeDeserialize) {
    T orig{"Test"};
    std::string ser;
    nlohmann::json json;
    T comp;
    ASSERT_NO_THROW(json = orig);
    ASSERT_NO_THROW(ser = json.dump());
    ASSERT_NO_THROW(comp = nlohmann::json::parse(ser).get<T>());
    ASSERT_EQ(comp, orig);
}
