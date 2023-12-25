#include "BonfireScene.hpp"
#include "Game.hpp"

BonfireScene::BonfireScene() : Scene()
{

}

void BonfireScene::ProcessEvents(const sf::Event &event)
{
    m_Font = Game::Instance()->GetFont();
}

void BonfireScene::ProcessDrawing(sf::RenderWindow &window)
{
    sf::Text welcome_text{"---------------------------\n      Welcome to home adventurer      \n---------------------------", m_Font};
    Button button({100, 100}, {100, 100}, "Text", m_Font);

    welcome_text.move(650, 0);

    button.Move(500, 100);

    window.draw(welcome_text);
    window.draw(button);
}

void BonfireScene::Update(const sf::Event &event, sf::RenderWindow &window, float deltaTime) {

}
