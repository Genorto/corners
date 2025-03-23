#pragma once
#include <SFML/Graphics.hpp>
const int kWindowSize = 800;
const int kCellSize = kWindowSize / 8;
// explicit std::pair<int, int> last_position = { 0, 0 };

class Element {
 public:
    virtual void Draw(sf::RenderWindow&) = 0;
};