#include <field.h>
#include <iostream>

Field::Field() {
    accent_color_ = sf::Color(220, 220, 220);
    ambient_color_ = sf::Color::White;
    is_white_ = true;
    for(int row = 0; row < 8; ++row) {
        field_.emplace_back(std::vector<Chip*>());
        for(int column = 0; column < 8; ++column) {
            field_[row].push_back(new Chip);
            field_[row][column]->SetPos(row, column);
            if (row < 3 && column < 3) {
                field_[row][column]->SetColor(Color::black);
                field_[row][column]->Enable();
            } else if (row > 4 && column > 4) {
                field_[row][column]->SetColor(Color::white);
                field_[row][column]->Enable();
            } else {
                field_[row][column]->Disable();
            }
        }
    }
}

Field::~Field() {
    for (auto row : field_) {
        for (auto column : row) {
            delete column;
        }
    }
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

void Field::Move(std::pair<int, int> start, std::pair<int, int> finish) {
    if (IsReacable(start, finish)) {
        field_[finish.first][finish.second]->SetColor(field_[start.first][start.second]->GetColor());
        field_[finish.first][finish.second]->Enable();
        field_[start.first][start.second]->Disable();  
        is_white_ = !is_white_; 
    }
}

void Field::Analyze(Color player) {
    used_.assign(8, std::vector<bool>(8, false));
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> first_moves = GenerateMoves(, player);

}

void Field::Draw(sf::RenderWindow& window) {
    for (int row = 0; row < 8; ++row) {
        for (int column = 0; column < 8; ++column) {
            sf::RectangleShape cell;
            cell.setFillColor((row + column) % 2 ? accent_color_ : ambient_color_);
            cell.setSize(sf::Vector2f(kCellSize, kCellSize));
            cell.setPosition(sf::Vector2f(column * kCellSize, row * kCellSize));
            window.draw(cell);
            field_[row][column]->Draw(window);
        }
    }
}

bool Field::IsReacable(std::pair<int, int> start, std::pair<int, int> finish, bool is_first = true) {
    if (start.first < 0 || start.first > 7 || start.second < 0 || start.second > 7 ||
        finish.first < 0 || finish.first > 7 || finish.second < 0 || finish.second > 7) return false;
    if (is_first) {
        if (!field_[start.first][start.second]->IsEnabled() || field_[finish.first][finish.second]->IsEnabled() ||
            (field_[start.first][start.second]->GetColor() == Color::white) != is_white_) {
            return false;
        }
        used_.assign(8, std::vector<bool>(8, false));
        if ((start.first == finish.first && start.second + 1 == finish.second || start.second - 1 == finish.second) ||
            (start.second == finish.second && start.first + 1 == finish.first || start.first - 1 == finish.first)) {
            return true;
        }
    }
    if (start.first == finish.first && start.second == finish.second) return true;
    used_[start.first][start.second] = true;
    bool result = false;
    if (start.first > 1 && !field_[start.first - 2][start.second]->IsEnabled() &&
        field_[start.first - 1][start.second]->IsEnabled() && !used_[start.first - 2][start.second]) {
        result = result || IsReacable({ start.first - 2, start.second }, finish, false);
    }
    if (start.first < 6 && !field_[start.first + 2][start.second]->IsEnabled() &&
        field_[start.first + 1][start.second]->IsEnabled() && !used_[start.first + 2][start.second]) {
        result = result || IsReacable({ start.first + 2, start.second }, finish, false);
    }
    if (start.second > 1 && !field_[start.first][start.second - 2]->IsEnabled() &&
        field_[start.first][start.second - 1]->IsEnabled() && !used_[start.first][start.second - 2]) {
        result = result || IsReacable({ start.first, start.second - 2 }, finish, false);
    }
    if (start.second < 6 && !field_[start.first][start.second + 2]->IsEnabled() &&
        field_[start.first][start.second + 1]->IsEnabled() && !used_[start.first][start.second + 2]) {
        result = result || IsReacable({ start.first, start.second + 2 }, finish, false);
    }
    return result;
}

std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> Field::GenerateMoves(std::pair<int, int> chip) {
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> result;
    if (chip.first > 1 && !field_[chip.first - 2][chip.second]->IsEnabled() &&
        field_[chip.first - 1][chip.second]->IsEnabled() && !used_[chip.first - 2][chip.second]) {
        result.emplace_back(GenerateMoves({ chip.first - 2, chip.second }));
    }
}