#include <gtest/gtest.h>
#include <Mods/Request/SendChat.h>

using namespace communication::messages::mods;

using T = request::SendChat;

TEST(ModsRequestSendChat, SerializeDeserialize) {
    T orig{"abc"};
    std::string ser;
    nlohmann::json json;
    T comp;
    EXPECT_NO_THROW(json = orig);
    EXPECT_NO_THROW(ser = json.dump());
    EXPECT_NO_THROW(comp = nlohmann::json::parse(ser).get<T>());
    EXPECT_EQ(comp, orig);
}
