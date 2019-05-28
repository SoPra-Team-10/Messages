#include <gtest/gtest.h>
#include <Common/types.hpp>

using namespace communication::messages::types;

TEST(CommonTypes, EntityIdLeftSeeker) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::LEFT_SEEKER)), EntityId::LEFT_SEEKER);
}
TEST(CommonTypes, EntityIdLeftKeeper) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::LEFT_KEEPER)), EntityId::LEFT_KEEPER);
}
TEST(CommonTypes, EntityIdLeftChaser1) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::LEFT_CHASER1)), EntityId::LEFT_CHASER1);
}
TEST(CommonTypes, EntityIdLeftChaser2) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::LEFT_CHASER2)), EntityId::LEFT_CHASER2);
}
TEST(CommonTypes, EntityIdLeftChaser3) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::LEFT_CHASER3)), EntityId::LEFT_CHASER3);
}
TEST(CommonTypes, EntityIdLeftBeater1) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::LEFT_BEATER1)), EntityId::LEFT_BEATER1);
}
TEST(CommonTypes, EntityIdLeftBeater2) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::LEFT_BEATER2)), EntityId::LEFT_BEATER2);
}
TEST(CommonTypes, EntityIdRightSeeker) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::RIGHT_SEEKER)), EntityId::RIGHT_SEEKER);
}
TEST(CommonTypes, EntityIdRightKeeper) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::RIGHT_KEEPER)), EntityId::RIGHT_KEEPER);
}
TEST(CommonTypes, EntityIdRightChaser1) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::RIGHT_CHASER1)), EntityId::RIGHT_CHASER1);
}
TEST(CommonTypes, EntityIdRightChaser2) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::RIGHT_CHASER2)), EntityId::RIGHT_CHASER2);
}
TEST(CommonTypes, EntityIdRightChaser3) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::RIGHT_CHASER3)), EntityId::RIGHT_CHASER3);
}
TEST(CommonTypes, EntityIdRightBeater1) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::RIGHT_BEATER1)), EntityId::RIGHT_BEATER1);
}
TEST(CommonTypes, EntityIdRightBeater2) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::RIGHT_BEATER2)), EntityId::RIGHT_BEATER2);
}
TEST(CommonTypes, EntityIdSnitch) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::SNITCH)), EntityId::SNITCH);
}
TEST(CommonTypes, EntityIdBludger1) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::BLUDGER1)), EntityId::BLUDGER1);
}
TEST(CommonTypes, EntityIdBludger2) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::BLUDGER2)), EntityId::BLUDGER2);
}
TEST(CommonTypes, EntityIdQuaffle) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::QUAFFLE)), EntityId::QUAFFLE);
}
TEST(CommonTypes, EntityIdLeftGoblin) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::LEFT_GOBLIN)), EntityId::LEFT_GOBLIN);
}
TEST(CommonTypes, EntityIdLeftTroll) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::LEFT_TROLL)), EntityId::LEFT_TROLL);
}
TEST(CommonTypes, EntityIdLeftElf) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::LEFT_ELF)), EntityId::LEFT_ELF);
}
TEST(CommonTypes, EntityIdLeftNiffler) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::LEFT_NIFFLER)), EntityId::LEFT_NIFFLER);
}
TEST(CommonTypes, EntityIdRightGoblin) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::RIGHT_GOBLIN)), EntityId::RIGHT_GOBLIN);
}
TEST(CommonTypes, EntityIdRightTroll) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::RIGHT_TROLL)), EntityId::RIGHT_TROLL);
}
TEST(CommonTypes, EntityIdRightElf) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::RIGHT_ELF)), EntityId::RIGHT_ELF);
}
TEST(CommonTypes, EntityIdRightNiffler) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::RIGHT_NIFFLER)), EntityId::RIGHT_NIFFLER);
}
TEST(CommonTypes, EntityIdLeftWombat) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::LEFT_WOMBAT)), EntityId::LEFT_WOMBAT);
}
TEST(CommonTypes, EntityIdRightWombat) {
    ASSERT_EQ(fromStringEntityId(toString(EntityId::RIGHT_WOMBAT)), EntityId::RIGHT_WOMBAT);
}

TEST(CommonTypes, TurnTypeMove) {
    ASSERT_EQ(fromStringTurnType(toString(TurnType::MOVE)), TurnType::MOVE);
}
TEST(CommonTypes, TurnTypeAction) {
    ASSERT_EQ(fromStringTurnType(toString(TurnType::ACTION)), TurnType::ACTION);
}
TEST(CommonTypes, TurnTypeFan) {
    ASSERT_EQ(fromStringTurnType(toString(TurnType::FAN)), TurnType::FAN);
}
TEST(CommonTypes, TurnTypeRemoveBan) {
    ASSERT_EQ(fromStringTurnType(toString(TurnType::REMOVE_BAN)), TurnType::REMOVE_BAN);
}

TEST(CommonTypes, VictoryReasonDisqualification) {
    ASSERT_EQ(fromStringVictoryReason(toString(VictoryReason::DISQUALIFICATION)), VictoryReason::DISQUALIFICATION);
}
TEST(CommonTypes, VictoryReasonBothDisMostPoints) {
    ASSERT_EQ(fromStringVictoryReason(toString(VictoryReason::BOTH_DISQUALIFICATION_MOST_POINTS)), VictoryReason::BOTH_DISQUALIFICATION_MOST_POINTS);
}
TEST(CommonTypes, VictoryReasonBothDisPointsEqualSnitch) {
    ASSERT_EQ(fromStringVictoryReason(toString(VictoryReason::BOTH_DISQUALIFICATION_POINTS_EQUAL_SNITCH_CATCH)), VictoryReason::BOTH_DISQUALIFICATION_POINTS_EQUAL_SNITCH_CATCH);
}
TEST(CommonTypes, VictoryReasonBothDisPointsEqualLast) {
    ASSERT_EQ(fromStringVictoryReason(toString(VictoryReason::BOTH_DISQUALIFICATION_POINTS_EQUAL_LAST_DISQUALIFICATION)), VictoryReason::BOTH_DISQUALIFICATION_POINTS_EQUAL_LAST_DISQUALIFICATION);
}
TEST(CommonTypes, VictoryReasonMostPoints) {
    ASSERT_EQ(fromStringVictoryReason(toString(VictoryReason::MOST_POINTS)), VictoryReason::MOST_POINTS);
}
TEST(CommonTypes, VictoryReasonPointsEqualSnitch) {
    ASSERT_EQ(fromStringVictoryReason(toString(VictoryReason::POINTS_EQUAL_SNITCH_CATCH)), VictoryReason::POINTS_EQUAL_SNITCH_CATCH);
}
TEST(CommonTypes, VictoryReasonViolationOfProt) {
    ASSERT_EQ(fromStringVictoryReason(toString(VictoryReason::VIOLATION_OF_PROTOCOL)), VictoryReason::VIOLATION_OF_PROTOCOL);
}

TEST(CommonTypes, FanTypeGoblin) {
    ASSERT_EQ(fromStringFanType(toString(FanType::GOBLIN)), FanType::GOBLIN);
}
TEST(CommonTypes, FanTypeTroll) {
    ASSERT_EQ(fromStringFanType(toString(FanType::TROLL)), FanType::TROLL);
}
TEST(CommonTypes, FanTypeElf) {
    ASSERT_EQ(fromStringFanType(toString(FanType::ELF)), FanType::ELF);
}
TEST(CommonTypes, FanTypeNiffler) {
    ASSERT_EQ(fromStringFanType(toString(FanType::NIFFLER)), FanType::NIFFLER);
}
TEST(CommonTypes, FanTypeWombat) {
    ASSERT_EQ(fromStringFanType(toString(FanType::WOMBAT)), FanType::WOMBAT);
}

TEST(CommonTypes, BroomTinderblast) {
    ASSERT_EQ(fromStringBroom(toString(Broom::TINDERBLAST)), Broom::TINDERBLAST);
}
TEST(CommonTypes, BroomCleansweep) {
    ASSERT_EQ(fromStringBroom(toString(Broom::CLEANSWEEP11)), Broom::CLEANSWEEP11);
}
TEST(CommonTypes, BroomComet) {
    ASSERT_EQ(fromStringBroom(toString(Broom::COMET260)), Broom::COMET260);
}
TEST(CommonTypes, BroomNimbus) {
    ASSERT_EQ(fromStringBroom(toString(Broom::NIMBUS2001)), Broom::NIMBUS2001);
}
TEST(CommonTypes, BroomFirebolt) {
    ASSERT_EQ(fromStringBroom(toString(Broom::FIREBOLT)), Broom::FIREBOLT);
}

TEST(CommonTypes, SexM) {
    ASSERT_EQ(fromStringSex(toString(Sex::M)), Sex::M);
}
TEST(CommonTypes, SexF) {
    ASSERT_EQ(fromStringSex(toString(Sex::F)), Sex::F);
}

TEST(CommonTypes, DeltaTypeSnitchCatch) {
    ASSERT_EQ(fromStringDeltaType(toString(DeltaType::SNITCH_CATCH)), DeltaType::SNITCH_CATCH);
}
TEST(CommonTypes, DeltaTypeBludgerBeating) {
    ASSERT_EQ(fromStringDeltaType(toString(DeltaType::BLUDGER_BEATING)), DeltaType::BLUDGER_BEATING);
}
TEST(CommonTypes, DeltaTypeQuaffleThrow) {
    ASSERT_EQ(fromStringDeltaType(toString(DeltaType::QUAFFLE_THROW)), DeltaType::QUAFFLE_THROW);
}
TEST(CommonTypes, DeltaTypeSnitchSnatch) {
    ASSERT_EQ(fromStringDeltaType(toString(DeltaType::SNITCH_SNATCH)), DeltaType::SNITCH_SNATCH);
}
TEST(CommonTypes, DeltaTypeTrollRoard) {
    ASSERT_EQ(fromStringDeltaType(toString(DeltaType::TROLL_ROAR)), DeltaType::TROLL_ROAR);
}
TEST(CommonTypes, DeltaTypeElfTeleportation) {
    ASSERT_EQ(fromStringDeltaType(toString(DeltaType::ELF_TELEPORTATION)), DeltaType::ELF_TELEPORTATION);
}
TEST(CommonTypes, DeltaTypeGoblinShock) {
    ASSERT_EQ(fromStringDeltaType(toString(DeltaType::GOBLIN_SHOCK)), DeltaType::GOBLIN_SHOCK);
}
TEST(CommonTypes, DeltaTypeBan) {
    ASSERT_EQ(fromStringDeltaType(toString(DeltaType::BAN)), DeltaType::BAN);
}
TEST(CommonTypes, DeltaTypeBludgerKnockout) {
    ASSERT_EQ(fromStringDeltaType(toString(DeltaType::BLUDGER_KNOCKOUT)), DeltaType::BLUDGER_KNOCKOUT);
}
TEST(CommonTypes, DeltaTypeMove) {
    ASSERT_EQ(fromStringDeltaType(toString(DeltaType::MOVE)), DeltaType::MOVE);
}
TEST(CommonTypes, DeltaTypePhaseChange) {
    ASSERT_EQ(fromStringDeltaType(toString(DeltaType::PHASE_CHANGE)), DeltaType::PHASE_CHANGE);
}
TEST(CommonTypes, DeltaTypeGoalPointsChange) {
    ASSERT_EQ(fromStringDeltaType(toString(DeltaType::GOAL_POINTS_CHANGE)), DeltaType::GOAL_POINTS_CHANGE);
}
TEST(CommonTypes, DeltaTypeRoundChange) {
    ASSERT_EQ(fromStringDeltaType(toString(DeltaType::ROUND_CHANGE)), DeltaType::ROUND_CHANGE);
}
TEST(CommonTypes, DeltaTypeSkip) {
    ASSERT_EQ(fromStringDeltaType(toString(DeltaType::SKIP)), DeltaType::SKIP);
}
TEST(CommonTypes, DeltaTypeUnban) {
    ASSERT_EQ(fromStringDeltaType(toString(DeltaType::UNBAN)), DeltaType::UNBAN);
}
TEST(CommonTypes, DeltaTypeWrestQuaffle) {
    ASSERT_EQ(fromStringDeltaType(toString(DeltaType::WREST_QUAFFLE)), DeltaType::WREST_QUAFFLE);
}
TEST(CommonTypes, DeltaTypeFoolAway) {
    ASSERT_EQ(fromStringDeltaType(toString(DeltaType::FOOL_AWAY)), DeltaType::FOOL_AWAY);
}
TEST(CommonTypes, DeltaTypeTurnUsed) {
    ASSERT_EQ(fromStringDeltaType(toString(DeltaType::TURN_USED)), DeltaType::TURN_USED);
}
TEST(CommonTypes, DeltaTypeWombatPoo) {
    ASSERT_EQ(fromStringDeltaType(toString(DeltaType::WOMBAT_POO)), DeltaType::WOMBAT_POO);
}
TEST(CommonTypes, DeltaTypeRemovePoo) {
    ASSERT_EQ(fromStringDeltaType(toString(DeltaType::REMOVE_POO)), DeltaType::REMOVE_POO);
}

TEST(CommonTypes, PhaseTypeBallPhase) {
    ASSERT_EQ(fromStringPhaseType(toString(PhaseType::BALL_PHASE)), PhaseType::BALL_PHASE);
}
TEST(CommonTypes, PhaseTypePlayerPhase) {
    ASSERT_EQ(fromStringPhaseType(toString(PhaseType::PLAYER_PHASE)), PhaseType::PLAYER_PHASE);
}
TEST(CommonTypes, PhaseTypeFanPhase) {
    ASSERT_EQ(fromStringPhaseType(toString(PhaseType::FAN_PHASE)), PhaseType::FAN_PHASE);
}
TEST(CommonTypes, PhaseTypeGameFinish) {
    ASSERT_EQ(fromStringPhaseType(toString(PhaseType::GAME_FINISH)), PhaseType::GAME_FINISH);
}
TEST(CommonTypes, PhaseTypeUnbanPhase) {
    ASSERT_EQ(fromStringPhaseType(toString(PhaseType::UNBAN_PHASE)), PhaseType::UNBAN_PHASE);
}

TEST(CommonTypes, ModsChat) {
    ASSERT_EQ(fromStringMod(toString(Mods::CHAT)), Mods::CHAT);
}
TEST(CommonTypes, ModsDisableGenderBalance) {
    ASSERT_EQ(fromStringMod(toString(Mods::DISABLE_GENDER_BALANCE)), Mods::DISABLE_GENDER_BALANCE);
}
TEST(CommonTypes, ModsReplayWithSnapshot) {
    ASSERT_EQ(fromStringMod(toString(Mods::REPLAY_WITH_SNAPSHOT)), Mods::REPLAY_WITH_SNAPSHOT);
}
TEST(CommonTypes, ModsError) {
    ASSERT_EQ(fromStringMod(toString(Mods::ERROR)), Mods::ERROR);
}
TEST(CommonTypes, ModsWarning) {
    ASSERT_EQ(fromStringMod(toString(Mods::WARNING)), Mods::WARNING);
}
TEST(CommonTypes, ModsLobbies) {
    ASSERT_EQ(fromStringMod(toString(Mods::LOBBIES)), Mods::LOBBIES);
}

TEST(CommonTypes, BanReasonStooging) {
    ASSERT_EQ(fromStringBanReason(toString(BanReason::STOOGING)), BanReason::STOOGING);
}
TEST(CommonTypes, BanReasonBlatching) {
    ASSERT_EQ(fromStringBanReason(toString(BanReason::BLATCHING)), BanReason::BLATCHING);
}
TEST(CommonTypes, BanReasonFlacking) {
    ASSERT_EQ(fromStringBanReason(toString(BanReason::FLACKING)), BanReason::FLACKING);
}
TEST(CommonTypes, BanReasonHaversacking) {
    ASSERT_EQ(fromStringBanReason(toString(BanReason::HAVERSACKING)), BanReason::HAVERSACKING);
}
TEST(CommonTypes, BanReasonSnitchnip) {
    ASSERT_EQ(fromStringBanReason(toString(BanReason::SNITCHNIP)), BanReason::SNITCHNIP);
}
TEST(CommonTypes, BanReasonSnitchSnatch) {
    ASSERT_EQ(fromStringBanReason(toString(BanReason::SNITCH_SNATCH)), BanReason::SNITCH_SNATCH);
}
TEST(CommonTypes, BanReasonElfTeleportation) {
    ASSERT_EQ(fromStringBanReason(toString(BanReason::ELF_TELEPORTATION)), BanReason::ELF_TELEPORTATION);
}
TEST(CommonTypes, BanReasonGoblinShock) {
    ASSERT_EQ(fromStringBanReason(toString(BanReason::GOBLIN_SHOCK)), BanReason::GOBLIN_SHOCK);
}
TEST(CommonTypes, BanReasonTrollRoar) {
    ASSERT_EQ(fromStringBanReason(toString(BanReason::TROLL_ROAR)), BanReason::TROLL_ROAR);
}
TEST(CommonTypes, BanReasonWombatPoo) {
    ASSERT_EQ(fromStringBanReason(toString(BanReason::WOMBAT_POO)), BanReason::WOMBAT_POO);
}
