#include <gtest/gtest.h>
#include <Request/JoinRequest.hpp>

using namespace communication::messages;

using T = request::JoinRequest;

TEST(CommunicationMessagesRequestJoinRequest, SerializeDeserialize) {
    T orig{"abc", "bcdf", "csdsd", true, {"abcdssd"}};
    std::string ser;
    nlohmann::json json;
    T comp;
    EXPECT_NO_THROW(json = orig);
    EXPECT_NO_THROW(ser = json.dump());
    EXPECT_NO_THROW(comp = nlohmann::json::parse(ser).get<T>());
    EXPECT_EQ(comp, orig);
}
