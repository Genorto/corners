#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <element.h>
#include <field.h>
#include <chip.h>

class App {
 public:
    App();
    ~App() = default;
    void Launch();

 private:
    void HandleEvents();
    void RenderGameWindow();
    sf::RenderWindow window_;
    std::vector<Element*> ui_;
};