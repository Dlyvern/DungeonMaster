#include "MainScene.hpp"

MainScene::MainScene() : Scene()
{
    m_Font = Game::Instance()->GetFont();
}

void MainScene::ProcessEvents(const sf::Event &event)
{
    if(event.key.code == sf::Keyboard::BackSpace)
    {
        if(!m_PlayerName.isEmpty())
            m_PlayerName.erase(m_PlayerName.getSize() - 1);
    }

    else if (event.type == sf::Event::TextEntered)
    {
        m_PlayerName += event.text.unicode;
    }
}

void MainScene::Update(const sf::Event &event, sf::RenderWindow &window, float deltaTime)
{
    Button plus_button{{70, 40}, {750, 700}, "Add", m_Font};

    Button minus_button{{120, 40}, {900, 700}, "Reduce", m_Font};

    plus_button.SetOutlineColor(sf::Color::White);
    minus_button.SetOutlineColor(sf::Color::White);

    plus_button.Update(window, event);
    minus_button.Update(window, event);

    window.draw(plus_button);
    window.draw(minus_button);
}


void MainScene::ProcessDrawing(sf::RenderWindow &window)
{
    sf::Text enter_your_name{"Enter your name ", m_Font};
    sf::Text player_name{"", m_Font};

    sf::Text left_points_text{"Left points ", m_Font};
    sf::Text left_points{std::to_string(m_LeftPoints), m_Font};

    sf::Text strength_text{"Strength points ", m_Font};
    strength_text.move(750, 200);

    sf::Text strength_points{std::to_string(m_StrengthPoints), m_Font};
    strength_points.move(1050, 200);

    player_name.setString(m_PlayerName);

    enter_your_name.move(750, 50);
    player_name.move(1050, 50);

    left_points_text.move(750, 150);
    left_points.move(1000, 150);

    window.draw(enter_your_name);
    window.draw(player_name);
    window.draw(left_points_text);
    window.draw(left_points);
    window.draw(strength_text);
    window.draw(strength_points);
}

