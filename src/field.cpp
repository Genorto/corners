#include <field.h>

Field::Field() : Element() {
    accent_color_ = sf::Color::White;
    ambient_color_ = sf::Color::Black;
}

void Field::SetAccentColor(sf::Color color) {
    accent_color_ = color;
}

void Field::SetAmbientColor(sf::Color color) {
    ambient_color_ = color;
}

sf::Color Field::GetAccentColor() {
    return accent_color_;
}

sf::Color Field::GetAmbientColor() {
    return ambient_color_;
}

void Field::Draw(sf::RenderWindow& window) {
    for (int row = 0; row < 8; ++row) {
        for (int column = 0; column < 8; ++column) {
            sf::RectangleShape cell;
            cell.setFillColor((row + column) % 2 ? accent_color_ : ambient_color_);
            cell.setSize(sf::Vector2f(kCellSize, kCellSize));
            cell.setPosition(sf::Vector2f(row * kCellSize, column * kCellSize));
            window.draw(cell);
        }
    }
}
