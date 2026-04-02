// "Copyright [2024] <Dhruvkumar>"
#ifndef _HOME_DHRUV5291_COMPUTING4_PS3A_SOKOBAN_HPP_
#define _HOME_DHRUV5291_COMPUTING4_PS3A_SOKOBAN_HPP_

#include <vector>
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>

namespace SB {
enum class Direction {
    Up,
    Down,
    Left,
    Right
    };

class Sokoban : public sf::Drawable {
 public:
  Sokoban();
  ~Sokoban();

  int width() const;
  int height() const;

  sf::Vector2i playerLoc() const;

  void movePlayer(Direction direction);
  bool isWon() const;
  void resetGame();

  int pixelWidth() const;
  int pixelHeight() const;
  static const int TILE_SIZE = 64;

  friend std::istream& operator>>(std::istream& input, Sokoban& sb);
  friend std::ostream& operator<<(std::ostream& output, const Sokoban& sb);

 protected:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

 private:
  int W, H;
  std::vector<std::vector<char>> grid;
  std::map<char, sf::Sprite> sprites;
  std::map<char, sf::Texture> textures;
  sf::Sprite GroundFloor;
  sf::Sprite CrateBox;
  sf::Sprite Wall;
  sf::Sprite Storagefloor;
  sf::Sprite Player;
  sf::Vector2i playerPosition;
  bool playerOnStorage;
  std::vector<std::vector<char>> initialGrid;
  std::vector<sf::Vector2i> initialCratePos;
  sf::Vector2i initialPlayerPos;
  std::vector<sf::Vector2i> cratePosition;
};
  std::istream& operator>>(std::istream& input, Sokoban& sb);
  std::ostream& operator<<(std::ostream& output, const Sokoban& sb);
}  // namespace SB
#endif  // _HOME_DHRUV5291_COMPUTING4_PS3A_SOKOBAN_HPP_"
