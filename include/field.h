#pragma once
#include <element.h>

class Field : public Element {
 public:
    Field();
    ~Field() = default;
    void SetAccentColor(sf::Color);
    void SetAmbientColor(sf::Color);
    sf::Color GetAccentColor();
    sf::Color GetAmbientColor();
    virtual void Draw(sf::RenderWindow&);

 private:
    sf::Color accent_color_, ambient_color_;
};