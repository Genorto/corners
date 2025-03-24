#pragma once
#include <element.h>
#include <chip.h>

class Field : public Element {
 public:
    Field();
    ~Field();
    void SetAccentColor(sf::Color);
    void SetAmbientColor(sf::Color);
    sf::Color GetAccentColor();
    sf::Color GetAmbientColor();
    void Move(std::pair<int, int>, std::pair<int, int>);
    void Analyze(Color);
    virtual void Draw(sf::RenderWindow&);

 private:
    bool IsReacable(std::pair<int, int>, std::pair<int, int>, bool);
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> GenerateMoves(std::pair<int, int>);
    sf::Color accent_color_, ambient_color_;
    std::vector<std::vector<Chip*>> field_;
    std::vector<std::vector<bool>> used_;
    bool is_white_;
};