#include <app.h>

App::App(AppType type) {
    type_ = type;
    app_choice_ = AppType::none;
    window_ = sf::RenderWindow(sf::VideoMode({kWindowSize, kWindowSize}), "Corners");
    window_.setFramerateLimit(144);
    if (type == AppType::pvc || type == AppType::cvc) {
        ui_.push_back(new Field);
        mouse_start_ = { 0, 0 };
        mouse_finish_ = { 0, 0 };
        mouse_holding_ = false;
    }
}

App::~App() {
    for (auto element : ui_) {
        delete element;
    }
}

AppType App::GetAppChoice() {
    return app_choice_;
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
        if (type_ == AppType::menu) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                app_choice_ = AppType::pvc;
                window_.close();
            }
        } else if (type_ == AppType::pvc) {
            /* mouse */
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !mouse_holding_) {
                mouse_start_ = { sf::Mouse::getPosition(window_).y / kCellSize, sf::Mouse::getPosition(window_).x / kCellSize };
                mouse_holding_ = true;
            } else if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && mouse_holding_) {
                mouse_finish_ = { sf::Mouse::getPosition(window_).y / kCellSize, sf::Mouse::getPosition(window_).x / kCellSize };
                mouse_holding_ = false;
                dynamic_cast<Field*>(ui_[0])->Move(mouse_start_, mouse_finish_);
            }
        }
    }
}

void App::RenderGameWindow() {
    window_.clear();
    for (auto element : ui_) {
        element->Draw(window_);
    }
    window_.display();
}