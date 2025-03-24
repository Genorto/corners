#include <chip.h>

Chip::Chip() : Element() {
    pos_ = { 0, 0 };
    color_ = Color::white;
    enabled_ = true;
}

void Chip::SetPos(std::pair<int, int> pos) {
    pos_ = pos;
}

void Chip::SetPos(int x, int y) {
    pos_ = std::pair<int, int>(x, y);
}

void Chip::SetColor(Color color) {
    color_ = color;
}

std::pair<int, int> Chip::GetPos() {
    return pos_;
}

Color Chip::GetColor() {
    return color_;
}

bool Chip::IsEnabled() {
    return enabled_;
}

void Chip::Enable() {
    enabled_ = true;
}

void Chip::Disable() {
    enabled_ = false;
}

void Chip::Draw(sf::RenderWindow& window) {
    sf::CircleShape chip;
    chip.setFillColor(color_ == Color::white ? sf::Color(50, 205, 50) : sf::Color::Black);
    chip.setRadius(kCellSize / 2 - 4);
    chip.setPosition(sf::Vector2f(pos_.second * kCellSize + 4, pos_.first * kCellSize + 4));
    if (enabled_) window.draw(chip);
}
