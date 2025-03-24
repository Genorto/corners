#pragma once
#include <element.h>
enum class Color { white, black };

class Chip : public Element {
 public:
    Chip();
    ~Chip() = default;
    void SetPos(std::pair<int, int>);
    void SetPos(int, int);
    void SetColor(Color);
    std::pair<int, int> GetPos();
    Color GetColor();
    bool IsEnabled();
    void Enable();
    void Disable();
    virtual void Draw(sf::RenderWindow&);

 private:
    std::pair<int, int> pos_;
    Color color_;
    bool enabled_;
};
