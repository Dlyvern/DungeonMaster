#ifndef MAIN_SCENE_HPP
#define MAIN_SCENE_HPP

#include <SFML/Graphics/Text.hpp>
#include "Scene.hpp"
#include "Game.hpp"
#include "Button.hpp"

class MainScene : public Scene
{
private:
    sf::String m_PlayerName;
    sf::Font m_Font;
    int m_LeftPoints{20};

    Button m_AddButton;
    Button m_ReduceButton;

    int m_StrengthPoints{4};
    int m_CharismaPoints{2};
    int m_LuckPoints{1};
    int m_EndurancePoints{5};
public:
    MainScene();

    void ProcessEvents(const sf::Event& event) override;

    void ProcessDrawing(sf::RenderWindow & window) override;

    void Update(const sf::Event& event, sf::RenderWindow& window, float deltaTime) override;
};


#endif //MAIN_SCENE_HPP
