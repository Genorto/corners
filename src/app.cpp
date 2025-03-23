#include <app.h>

App::App() {
    window_ = sf::RenderWindow(sf::VideoMode({kWindowSize, kWindowSize}), "Corners");
    window_.setFramerateLimit(144);
    ui_.push_back(new Field);
    ui_.push_back(new Chip);
    dynamic_cast<Chip*>(ui_[1])->SetPos(1, 2);
    dynamic_cast<Chip*>(ui_[1])->SetColor(Color::black);
}

void App::Launch() {
    while (window_.isOpen()) {
        HandleEvents();
        RenderGameWindow();
    }
}

void App::HandleEvents() {
    while (const std::optional event = window_.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window_.close();
        }
    }
}

void App::RenderGameWindow() {
    window_.clear();
    for (auto element: ui_) {
        element->Draw(window_);
    }
    window_.display();
}