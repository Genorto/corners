#include <chip.h>

Chip::Chip() : Element() {
    pos_ = { 0, 0 };
    radius_ = kCellSize / 2;
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

void Chip::Enable() {
    enabled_ = true;
}

void Chip::Disable() {
    enabled_ = false;
}

void Chip::Draw(sf::RenderWindow& window) {
    sf::CircleShape chip;
    chip.setFillColor(color_ == Color::white ? sf::Color::White : sf::Color::Black);
    chip.setRadius(radius_);
    chip.setPosition(sf::Vector2f(pos_.second * kCellSize, pos_.first * kCellSize));
    window.draw(chip);
}