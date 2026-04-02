// Copyright [2024] <Dhruvkumar Patel>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "Sokoban.hpp"

#define BOOST_TEST_MODULE SokobanTest
#include <boost/test/included/unit_test.hpp>

SB::Sokoban loadLevelFromFile(const std::string& filePath) {
    std::ifstream fileStream(filePath);
    if (!fileStream) {
        throw std::runtime_error("Could not open the level file.");
    }
    SB::Sokoban game;
    fileStream >> game;
    return game;
}

BOOST_AUTO_TEST_CASE(Test_canMove) {
    auto game = loadLevelFromFile("level1.lvl");

    game.movePlayer(SB::Direction::Up);
    game.movePlayer(SB::Direction::Down);
    game.movePlayer(SB::Direction::Left);
    game.movePlayer(SB::Direction::Right);

    sf::Vector2i expectedPosition(3, 6);
    sf::Vector2i player_Position = sf::Vector2i(
    static_cast<int>(game.playerLoc().x),
    static_cast<int>(game.playerLoc().y));

    BOOST_CHECK(player_Position == sf::Vector2i(game.playerLoc()));
}

BOOST_AUTO_TEST_CASE(Test_TwoCrateBox) {
    auto game = loadLevelFromFile("level2.lvl");

    game.movePlayer(SB::Direction::Up);
    game.movePlayer(SB::Direction::Up);
    sf::Vector2i expectedPosition(8, 5);
    sf::Vector2i player_Position = sf::Vector2i(
    static_cast<int>(game.playerLoc().x),
    static_cast<int>(game.playerLoc().y));

    BOOST_CHECK(player_Position == expectedPosition);
}

BOOST_AUTO_TEST_CASE(Test_CannotMoveIntoWall) {
    auto game = loadLevelFromFile("level2.lvl");

    sf::Vector2i startPosition = sf::Vector2i(
    static_cast<int>(game.playerLoc().x),
    static_cast<int>(game.playerLoc().y));
    game.movePlayer(SB::Direction::Left);

    sf::Vector2i newPosition = sf::Vector2i(
    static_cast<int>(game.playerLoc().x),
    static_cast<int>(game.playerLoc().y));

    BOOST_CHECK(startPosition == newPosition);
}

BOOST_AUTO_TEST_CASE(Test_WinCondition) {
    auto game = loadLevelFromFile("level1.lvl");
    game.movePlayer(SB::Direction::Up);
    game.movePlayer(SB::Direction::Up);
    game.movePlayer(SB::Direction::Up);
    game.movePlayer(SB::Direction::Right);
    game.movePlayer(SB::Direction::Right);
    game.movePlayer(SB::Direction::Up);
    game.movePlayer(SB::Direction::Right);
    game.movePlayer(SB::Direction::Down);
    game.movePlayer(SB::Direction::Down);
    game.movePlayer(SB::Direction::Down);
    game.movePlayer(SB::Direction::Down);
    game.movePlayer(SB::Direction::Left);
    game.movePlayer(SB::Direction::Down);
    game.movePlayer(SB::Direction::Right);
    game.movePlayer(SB::Direction::Right);

    BOOST_CHECK(game.isWon());
}

BOOST_AUTO_TEST_CASE(Test_lot_of_boxes) {
    auto game = loadLevelFromFile("level5.lvl");
    game.movePlayer(SB::Direction::Up);
    game.movePlayer(SB::Direction::Up);
    game.movePlayer(SB::Direction::Up);
    game.movePlayer(SB::Direction::Up);
    game.movePlayer(SB::Direction::Right);
    game.movePlayer(SB::Direction::Right);
    game.movePlayer(SB::Direction::Right);
    game.movePlayer(SB::Direction::Right);
    game.movePlayer(SB::Direction::Down);
    game.movePlayer(SB::Direction::Right);
    game.movePlayer(SB::Direction::Up);

    BOOST_CHECK(game.isWon());
}

BOOST_AUTO_TEST_CASE(Test_lot_of_target) {
    auto game = loadLevelFromFile("level6.lvl");
    game.movePlayer(SB::Direction::Right);
    game.movePlayer(SB::Direction::Up);
    game.movePlayer(SB::Direction::Up);
    game.movePlayer(SB::Direction::Up);
    game.movePlayer(SB::Direction::Up);
    game.movePlayer(SB::Direction::Right);
    game.movePlayer(SB::Direction::Up);
    game.movePlayer(SB::Direction::Left);

    game.movePlayer(SB::Direction::Right);
    game.movePlayer(SB::Direction::Right);
    game.movePlayer(SB::Direction::Right);
    game.movePlayer(SB::Direction::Down);
    game.movePlayer(SB::Direction::Down);
    game.movePlayer(SB::Direction::Down);
    game.movePlayer(SB::Direction::Down);
    game.movePlayer(SB::Direction::Left);
    game.movePlayer(SB::Direction::Down);
    game.movePlayer(SB::Direction::Right);

    BOOST_CHECK(game.isWon());
}
