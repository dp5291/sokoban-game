// "Copyright [2024] <Dhruvkumar Patel>"
#include <iostream>
#include <cctype>
#include <limits>
#include <stdexcept>
#include <string>
#include <SFML/Graphics.hpp>
#include "Sokoban.hpp"


SB::Sokoban::Sokoban() {
    textures['#'].loadFromFile("block_06.png");       // This is the block wall
    textures['A'].loadFromFile("crate_03.png");        // This is the crate box
    textures['.'].loadFromFile("ground_01.png");      // This is the floor
    textures['a'].loadFromFile("ground_04.png");    // This is the storage floor
    textures['@'].loadFromFile("player_05.png");      // player looking front

    playerPosition = sf::Vector2i(0, 0);
    sf::Sprite GroundFloor;
    GroundFloor.setTexture(textures.at('.'));

    sf::Sprite CrateBox;
    CrateBox.setTexture(textures.at('A'));

    sf::Sprite Wall;
    Wall.setTexture(textures.at('#'));

    sf::Sprite Storagefloor;
    Storagefloor.setTexture(textures.at('a'));

    sf::Sprite Player;
    Player.setTexture(textures.at('@'));
    }

SB::Sokoban::~Sokoban() {}

int SB::Sokoban::width() const {
    return W;
}

int SB::Sokoban::height() const {
    return H;
}
int SB::Sokoban::pixelWidth() const {
    return W * TILE_SIZE;
}

int SB::Sokoban::pixelHeight() const {
    return H * TILE_SIZE;
}
sf::Vector2i SB::Sokoban::playerLoc() const {
    sf::Vector2i pos = playerPosition;
    return pos;
}

void SB::Sokoban::movePlayer(Direction direction) {
    int dx = 0, dy = 0;
    switch (direction) {
        case Direction::Up:
            dy = -1;
            break;
        case Direction::Down:
            dy = 1;
            break;
        case Direction::Left:
            dx = -1;
            break;
        case Direction::Right:
            dx = 1;
            break;
    }

    //  It calculate the new position
    int newX = playerPosition.x + dx;
    int newY = playerPosition.y + dy;
    // Check if the move is blocked by boundaries or walls
    auto MoveBlocked = [&](int x, int y) -> bool {
    if (x < 0 || x >= W || y < 0 || y >= H) return true;
    if (grid[y][x] == '#') return true;
    if (grid[y][x] == 'A') {
        int nextX = x + dx;
        int nextY = y + dy;
        if (nextX < 0 || nextY >= W || nextY < 0 || nextY >= H) return true;
        char nextCell = grid[nextY][nextX];
        if (nextCell != '.' && nextCell != 'a') return true;
    }
    return false;
};

    if (MoveBlocked(newX, newY)) {
        return;
    }
    if (grid[newY][newX] == 'A'|| grid[newY][newX] == '1') {
        int boxNewX = newX + dx;
        int boxNewY = newY + dy;
        if (MoveBlocked(boxNewX, boxNewY)) {
            return;
        }
        if (grid[newY][newX] == '1') {  // Crate box is on storage
            grid[newY][newX] = 'a';  // Leave the storage symbol behind
        } else {
            grid[newY][newX] = '.';  // otherwise it is an empty space
        }

        if (grid[boxNewY][boxNewX] == 'a') {  // If the next position is the storage location
            grid[boxNewY][boxNewX] = '1';  // It marks crate on storage
        } else {
            grid[boxNewY][boxNewX] = 'A';  // OR its just a Crate
        }
    }
    if (grid[playerPosition.y][playerPosition.x] == 'a') {
        playerOnStorage = true;
    } else {
        playerOnStorage = false;
    }
    if (playerOnStorage) {
        grid[playerPosition.y][playerPosition.x] = 'a';
    } else {
        grid[playerPosition.y][playerPosition.x] = '.';
    }

    playerPosition.x = newX;
    playerPosition.y = newY;

    if (grid[newY][newX] == 'a') {
        playerOnStorage = true;
    } else {
        playerOnStorage = false;
    }
}

void SB::Sokoban::resetGame() {
    grid = initialGrid;
    playerPosition = initialPlayerPos;
    cratePosition = initialCratePos;
}

bool SB::Sokoban::isWon() const {
    int boxesOnStorage = 0;
    int totalStorage = 0;
    int totalBoxes = 0;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            char cell = grid[y][x];
            if (cell == 'a' || cell == '1') {
                totalStorage++;
            }
            if (cell == '1') {
                boxesOnStorage++;
            }
            if (cell == 'A' || cell == '1') {
                totalBoxes++;
            }
        }
    }
    return  (boxesOnStorage == totalStorage) || (totalBoxes == boxesOnStorage);
}



void SB::Sokoban::draw(sf::RenderTarget& target,
sf::RenderStates states) const {
    sf::Sprite gfloorSprite;
    gfloorSprite.setTexture(textures.at('.'));
    for (int j = 0; j < H ; ++j) {
        for (int i = 0; i < W ; ++i) {
            char gridchar = grid[j][i];
            if (gridchar != '#') {
            gfloorSprite.setPosition((i * 64), (j * 64));
            target.draw(gfloorSprite, states);
            }
        }
    }
    for (int j = 0; j < H ; ++j) {
     for (int i = 0; i < W ; ++i) {
      char gridchar = grid[j][i];
      if (textures.find(gridchar)
          != textures.end() && gridchar != '@' && gridchar != '.') {
                sf::Sprite sprite(textures.at(gridchar));
                sprite.setPosition((i * 64), (j * 64));
                target.draw(sprite, states);
            }
      if (gridchar == '1') {
        sf::Sprite Storagefloor(textures.at('a'));
        Storagefloor.setPosition(i * 64, j* 64);
        target.draw(Storagefloor, states);

        sf::Sprite CrateBox(textures.at('A'));
        CrateBox.setPosition(i*64, j*64);
        target.draw(CrateBox, states);
      }
     }
    }
    if (playerOnStorage) {
            sf::Sprite Storagefloor(textures.at('a'));
            Storagefloor.setPosition(playerPosition.x * 64, playerPosition.y * 64);
            target.draw(Storagefloor, states);
        }

        sf::Sprite Player(textures.at('@'));
        Player.setPosition(playerPosition.x * 64, playerPosition.y * 64);
        target.draw(Player, states);
    }

std::ostream& SB::operator<<(std::ostream& output, const Sokoban& sb) {
    for (int j = 0; j < sb.H; j++) {
        for (int i = 0; i < sb.W; i++) {
            output << sb.grid[i][j];
        }
        output << std::endl;
    }
    return output;
}

std::istream& SB::operator>>(std::istream& input, Sokoban& sb) {
    input >> sb.H >> sb.W;
    std::string unused;
    std::getline(input, unused);  // Skip the rest of the line
    sb.grid.clear();
    sb.cratePosition.clear();
    for (int y = 0; y < sb.H; ++y) {
        std::vector<char> row(sb.W, ' ');
        for (int x = 0; x < sb.W; ++x) {
            input >> row[x];
            if (row[x] == '@') {
                sb.playerPosition = sf::Vector2i(x, y);
                sb.initialPlayerPos = sf::Vector2i(x, y);
            } else if (row[x] == 'A') {
                sb.cratePosition.push_back(sf::Vector2i(x, y));
                sb.initialCratePos.push_back(sf::Vector2i(x, y));
            }
        }
        sb.grid.push_back(row);
        std::getline(input, unused);  // Skip the newline character
    }
    sb.initialGrid = sb.grid;
    return input;
}

