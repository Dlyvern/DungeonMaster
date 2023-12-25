#ifndef SCENE_HPP
#define SCENE_HPP
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Scene
{
public:
    virtual void ProcessEvents(const sf::Event& event) = 0;

    virtual void Update(const sf::Event& event, sf::RenderWindow& window, float deltaTime) = 0;

    virtual void ProcessDrawing(sf::RenderWindow & window) = 0;
};

#endif //SCENE_HPP
