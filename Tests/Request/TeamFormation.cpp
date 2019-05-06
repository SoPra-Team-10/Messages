#include <gtest/gtest.h>
#include <Request/TeamFormation.hpp>

using namespace communication::messages;

using T = request::TeamFormation;

TEST(RequestTeamFormation, SerializeDeserialize) {
    T orig{1,2,3,4,5,6,7,8,9,10,11,10,1,4};
    std::string ser;
    nlohmann::json json;
    T comp;
    ASSERT_NO_THROW(json = orig);
    ASSERT_NO_THROW(ser = json.dump());
    ASSERT_NO_THROW(comp = nlohmann::json::parse(ser).get<T>());
    ASSERT_EQ(comp, orig);
}
