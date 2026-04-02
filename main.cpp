// "Copyright [2024] <Dhruvkumar Patel>"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Sokoban.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <level file>" << std::endl;
        return 1;
    }
    std::string inputF = argv[1];

    SB::Sokoban sb;

    std::ifstream levelFile(inputF);

    if (!levelFile) {
        std::cout << "Unable to open" << std::endl;
        return 1;
    }

    levelFile >> sb;

    levelFile.close();

    sf::RenderWindow window(sf::VideoMode(
    sb.pixelWidth(), sb.pixelHeight()),
    "Sokoban Game");
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Unable to load font\n";
        return 1;
    }
    sf::Text winText;
    winText.setFont(font);
    winText.setString("Congratulation You win!");
    winText.setFillColor(sf::Color::Red);
    winText.setPosition(sb.width() *32 -winText.getLocalBounds().width/2,
    sb.height() *32 -winText.getLocalBounds().height/2);

    bool gameWon = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        if (!gameWon && event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up
            || event.key.code == sf::Keyboard::W) {
                sb.movePlayer(SB::Direction::Up);
            } else if (event.key.code == sf::Keyboard::Down
            || event.key.code == sf::Keyboard::S) {
                sb.movePlayer(SB::Direction::Down);
            } else if (event.key.code == sf::Keyboard::Left
            || event.key.code == sf::Keyboard::A) {
                sb.movePlayer(SB::Direction::Left);
            } else if (event.key.code == sf::Keyboard::Right
            || event.key.code == sf::Keyboard::D) {
                sb.movePlayer(SB::Direction::Right);
            } else if (event.key.code == sf::Keyboard::R) {
                sb.resetGame();
            }
        }
        }
        if (!gameWon && sb.isWon()) {
            gameWon = true;
        }
        window.clear();
        window.draw(sb);
        if (gameWon) {
            window.draw(winText);
        }
        window.display();
    }
    return 0;
}

