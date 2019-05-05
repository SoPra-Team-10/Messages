#include <gtest/gtest.h>
#include <Common/types.hpp>

using namespace communication::messages::types;

TEST(CommonTypes, EntityIdLeftSeeker) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::LEFT_SEEKER)), EntityId::LEFT_SEEKER);
}
TEST(CommonTypes, EntityIdLeftKeeper) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::LEFT_KEEPER)), EntityId::LEFT_KEEPER);
}
TEST(CommonTypes, EntityIdLeftChaser1) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::LEFT_CHASER1)), EntityId::LEFT_CHASER1);
}
TEST(CommonTypes, EntityIdLeftChaser2) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::LEFT_CHASER2)), EntityId::LEFT_CHASER2);
}
TEST(CommonTypes, EntityIdLeftChaser3) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::LEFT_CHASER3)), EntityId::LEFT_CHASER3);
}
TEST(CommonTypes, EntityIdLeftBeater1) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::LEFT_BEATER1)), EntityId::LEFT_BEATER1);
}
TEST(CommonTypes, EntityIdLeftBeater2) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::LEFT_BEATER2)), EntityId::LEFT_BEATER2);
}
TEST(CommonTypes, EntityIdRightSeeker) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::RIGHT_SEEKER)), EntityId::RIGHT_SEEKER);
}
TEST(CommonTypes, EntityIdRightKeeper) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::RIGHT_KEEPER)), EntityId::RIGHT_KEEPER);
}
TEST(CommonTypes, EntityIdRightChaser1) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::RIGHT_CHASER1)), EntityId::RIGHT_CHASER1);
}
TEST(CommonTypes, EntityIdRightChaser2) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::RIGHT_CHASER2)), EntityId::RIGHT_CHASER2);
}
TEST(CommonTypes, EntityIdRightChaser3) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::RIGHT_CHASER3)), EntityId::RIGHT_CHASER3);
}
TEST(CommonTypes, EntityIdRightBeater1) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::RIGHT_BEATER1)), EntityId::RIGHT_BEATER1);
}
TEST(CommonTypes, EntityIdRightBeater2) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::RIGHT_BEATER2)), EntityId::RIGHT_BEATER2);
}
TEST(CommonTypes, EntityIdSnitch) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::SNITCH)), EntityId::SNITCH);
}
TEST(CommonTypes, EntityIdBludger1) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::BLUDGER1)), EntityId::BLUDGER1);
}
TEST(CommonTypes, EntityIdBludger2) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::BLUDGER2)), EntityId::BLUDGER2);
}
TEST(CommonTypes, EntityIdQuaffle) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::QUAFFLE)), EntityId::QUAFFLE);
}
TEST(CommonTypes, EntityIdLeftGoblin) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::LEFT_GOBLIN)), EntityId::LEFT_GOBLIN);
}
TEST(CommonTypes, EntityIdLeftTroll) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::LEFT_TROLL)), EntityId::LEFT_TROLL);
}
TEST(CommonTypes, EntityIdLeftElf) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::LEFT_ELF)), EntityId::LEFT_ELF);
}
TEST(CommonTypes, EntityIdLeftNiffler) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::LEFT_NIFFLER)), EntityId::LEFT_NIFFLER);
}
TEST(CommonTypes, EntityIdRightGoblin) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::RIGHT_GOBLIN)), EntityId::RIGHT_GOBLIN);
}
TEST(CommonTypes, EntityIdRightTroll) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::RIGHT_TROLL)), EntityId::RIGHT_TROLL);
}
TEST(CommonTypes, EntityIdRightElf) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::RIGHT_ELF)), EntityId::RIGHT_ELF);
}
TEST(CommonTypes, EntityIdRightNiffler) {
    EXPECT_EQ(fromStringEntityId(toString(EntityId::RIGHT_NIFFLER)), EntityId::RIGHT_NIFFLER);
}

TEST(CommonTypes, TurnTypeMove) {
    EXPECT_EQ(fromStringTurnType(toString(TurnType::MOVE)), TurnType::MOVE);
}
TEST(CommonTypes, TurnTypeAction) {
    EXPECT_EQ(fromStringTurnType(toString(TurnType::ACTION)), TurnType::ACTION);
}
TEST(CommonTypes, TurnTypeFan) {
    EXPECT_EQ(fromStringTurnType(toString(TurnType::FAN)), TurnType::FAN);
}
TEST(CommonTypes, TurnTypeRemoveBan) {
    EXPECT_EQ(fromStringTurnType(toString(TurnType::REMOVE_BAN)), TurnType::REMOVE_BAN);
}

TEST(CommonTypes, VictoryReasonDisqualification) {
    EXPECT_EQ(fromStringVictoryReason(toString(VictoryReason::DISQUALIFICATION)), VictoryReason::DISQUALIFICATION);
}
TEST(CommonTypes, VictoryReasonBothDisMostPoints) {
    EXPECT_EQ(fromStringVictoryReason(toString(VictoryReason::BOTH_DISQUALIFICATION_MOST_POINTS)), VictoryReason::BOTH_DISQUALIFICATION_MOST_POINTS);
}
TEST(CommonTypes, VictoryReasonBothDisPointsEqualSnitch) {
    EXPECT_EQ(fromStringVictoryReason(toString(VictoryReason::BOTH_DISQUALIFICATION_POINTS_EQUAL_SNITCH_CATCH)), VictoryReason::BOTH_DISQUALIFICATION_POINTS_EQUAL_SNITCH_CATCH);
}
TEST(CommonTypes, VictoryReasonBothDisPointsEqualLast) {
    EXPECT_EQ(fromStringVictoryReason(toString(VictoryReason::BOTH_DISQUALIFICATION_POINTS_EQUAL_LAST_DISQUALIFICATION)), VictoryReason::BOTH_DISQUALIFICATION_POINTS_EQUAL_LAST_DISQUALIFICATION);
}
TEST(CommonTypes, VictoryReasonMostPoints) {
    EXPECT_EQ(fromStringVictoryReason(toString(VictoryReason::MOST_POINTS)), VictoryReason::MOST_POINTS);
}
TEST(CommonTypes, VictoryReasonPointsEqualSnitch) {
    EXPECT_EQ(fromStringVictoryReason(toString(VictoryReason::POINTS_EQUAL_SNITCH_CATCH)), VictoryReason::POINTS_EQUAL_SNITCH_CATCH);
}
TEST(CommonTypes, VictoryReasonViolationOfProt) {
    EXPECT_EQ(fromStringVictoryReason(toString(VictoryReason::VIOLATION_OF_PROTOCOL)), VictoryReason::VIOLATION_OF_PROTOCOL);
}

TEST(CommonTypes, FanTypeGoblin) {
    EXPECT_EQ(fromStringFanType(toString(FanType::GOBLIN)), FanType::GOBLIN);
}
TEST(CommonTypes, FanTypeTroll) {
    EXPECT_EQ(fromStringFanType(toString(FanType::TROLL)), FanType::TROLL);
}
TEST(CommonTypes, FanTypeElf) {
    EXPECT_EQ(fromStringFanType(toString(FanType::ELF)), FanType::ELF);
}
TEST(CommonTypes, FanTypeNiffler) {
    EXPECT_EQ(fromStringFanType(toString(FanType::NIFFLER)), FanType::NIFFLER);
}

TEST(CommonTypes, BroomTinderblast) {
    EXPECT_EQ(fromStringBroom(toString(Broom::TINDERBLAST)), Broom::TINDERBLAST);
}
TEST(CommonTypes, BroomCleansweep) {
    EXPECT_EQ(fromStringBroom(toString(Broom::CLEANSWEEP11)), Broom::CLEANSWEEP11);
}
TEST(CommonTypes, BroomComet) {
    EXPECT_EQ(fromStringBroom(toString(Broom::COMET260)), Broom::COMET260);
}
TEST(CommonTypes, BroomNimbus) {
    EXPECT_EQ(fromStringBroom(toString(Broom::NIMBUS2001)), Broom::NIMBUS2001);
}
TEST(CommonTypes, BroomFirebolt) {
    EXPECT_EQ(fromStringBroom(toString(Broom::FIREBOLT)), Broom::FIREBOLT);
}

TEST(CommonTypes, SexM) {
    EXPECT_EQ(fromStringSex(toString(Sex::M)), Sex::M);
}
TEST(CommonTypes, SexF) {
    EXPECT_EQ(fromStringSex(toString(Sex::F)), Sex::F);
}

TEST(CommonTypes, DeltaTypeSnitchCatch) {
    EXPECT_EQ(fromStringDeltaType(toString(DeltaType::SNITCH_CATCH)), DeltaType::SNITCH_CATCH);
}
TEST(CommonTypes, DeltaTypeBludgerBeating) {
    EXPECT_EQ(fromStringDeltaType(toString(DeltaType::BLUDGER_BEATING)), DeltaType::BLUDGER_BEATING);
}
TEST(CommonTypes, DeltaTypeQuaffleThrow) {
    EXPECT_EQ(fromStringDeltaType(toString(DeltaType::QUAFFLE_THROW)), DeltaType::QUAFFLE_THROW);
}
TEST(CommonTypes, DeltaTypeSnitchSnatch) {
    EXPECT_EQ(fromStringDeltaType(toString(DeltaType::SNITCH_SNATCH)), DeltaType::SNITCH_SNATCH);
}
TEST(CommonTypes, DeltaTypeTrollRoard) {
    EXPECT_EQ(fromStringDeltaType(toString(DeltaType::TROLL_ROAR)), DeltaType::TROLL_ROAR);
}
TEST(CommonTypes, DeltaTypeElfTeleportation) {
    EXPECT_EQ(fromStringDeltaType(toString(DeltaType::ELF_TELEPORTATION)), DeltaType::ELF_TELEPORTATION);
}
TEST(CommonTypes, DeltaTypeGoblinShock) {
    EXPECT_EQ(fromStringDeltaType(toString(DeltaType::GOBLIN_SHOCK)), DeltaType::GOBLIN_SHOCK);
}
TEST(CommonTypes, DeltaTypeBan) {
    EXPECT_EQ(fromStringDeltaType(toString(DeltaType::BAN)), DeltaType::BAN);
}
TEST(CommonTypes, DeltaTypeBludgerKnockout) {
    EXPECT_EQ(fromStringDeltaType(toString(DeltaType::BLUDGER_KNOCKOUT)), DeltaType::BLUDGER_KNOCKOUT);
}
TEST(CommonTypes, DeltaTypeMove) {
    EXPECT_EQ(fromStringDeltaType(toString(DeltaType::MOVE)), DeltaType::MOVE);
}

TEST(CommonTypes, PhaseTypeBallPhase) {
    EXPECT_EQ(fromStringPhaseType(toString(PhaseType::BALL_PHASE)), PhaseType::BALL_PHASE);
}
TEST(CommonTypes, PhaseTypePlayerPhase) {
    EXPECT_EQ(fromStringPhaseType(toString(PhaseType::PLAYER_PHASE)), PhaseType::PLAYER_PHASE);
}
TEST(CommonTypes, PhaseTypeFanPhase) {
    EXPECT_EQ(fromStringPhaseType(toString(PhaseType::FAN_PHASE)), PhaseType::FAN_PHASE);
}
TEST(CommonTypes, PhaseTypeGameFinish) {
    EXPECT_EQ(fromStringPhaseType(toString(PhaseType::GAME_FINISH)), PhaseType::GAME_FINISH);
}

TEST(CommonTypes, ModsChat) {
    EXPECT_EQ(fromStringMod(toString(Mods::CHAT)), Mods::CHAT);
}
TEST(CommonTypes, ModsDisableGenderBalance) {
    EXPECT_EQ(fromStringMod(toString(Mods::DISABLE_GENDER_BALANCE)), Mods::DISABLE_GENDER_BALANCE);
}
TEST(CommonTypes, ModsReplayWithSnapshot) {
    EXPECT_EQ(fromStringMod(toString(Mods::REPLAY_WITH_SNAPSHOT)), Mods::REPLAY_WITH_SNAPSHOT);
}
TEST(CommonTypes, ModsError) {
    EXPECT_EQ(fromStringMod(toString(Mods::ERROR)), Mods::ERROR);
}
TEST(CommonTypes, ModsWarning) {
    EXPECT_EQ(fromStringMod(toString(Mods::WARNING)), Mods::WARNING);
}
TEST(CommonTypes, ModsLobbies) {
    EXPECT_EQ(fromStringMod(toString(Mods::LOBBIES)), Mods::LOBBIES);
}
