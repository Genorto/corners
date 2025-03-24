#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <element.h>
#include <field.h>

enum class AppType { menu, pvc, cvc, none };

class App {
 public:
    App(AppType);
    ~App();
    AppType GetAppChoice();
    void Launch();

 private:
    void HandleEvents();
    void RenderGameWindow();
    sf::RenderWindow window_;
    std::vector<Element*> ui_;
    std::pair<int, int> mouse_start_, mouse_finish_;
    bool mouse_holding_;
    AppType type_, app_choice_;
};