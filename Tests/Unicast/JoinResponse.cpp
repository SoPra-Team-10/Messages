#include <gtest/gtest.h>
#include <Unicast/JoinResponse.hpp>

using namespace communication::messages;

using T = unicast::JoinResponse;

TEST(UnicastJoinResponse, SerializeDeserialize) {
    T orig{"Test"};
    std::string ser;
    nlohmann::json json;
    T comp;
    ASSERT_NO_THROW(json = orig);
    ASSERT_NO_THROW(ser = json.dump());
    ASSERT_NO_THROW(comp = nlohmann::json::parse(ser).get<T>());
    ASSERT_EQ(comp, orig);
}
