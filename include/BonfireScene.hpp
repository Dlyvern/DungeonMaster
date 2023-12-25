#ifndef BONFIRE_SCENE_HPP
#define BONFIRE_SCENE_HPP

#include "Scene.hpp"

#include <SFML/Graphics/Text.hpp>

#include "Button.hpp"

class BonfireScene : public Scene
{
private:
    sf::Font m_Font;
public:
    BonfireScene();

    void ProcessEvents(const sf::Event& event) override;

    void ProcessDrawing(sf::RenderWindow & window) override;

    void Update(const sf::Event& event, sf::RenderWindow& window, float deltaTime) override;
};

#endif //BONFIRE_SCENE_HPP