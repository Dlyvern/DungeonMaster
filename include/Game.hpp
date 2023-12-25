#ifndef GAME_HPP
#define GAME_HPP

#include "SFML/Graphics.hpp"
#include "BonfireScene.hpp"
#include "MainScene.hpp"

class Game
{
private:
    static Game* m_Instance;
    sf::String m_GameName{"Dungeon master"};
    sf::RenderWindow m_MainWindow;
    sf::Event m_MainEvent;
    sf::Font m_MainFont;
    std::unique_ptr<Scene>m_CurrentScene{nullptr};
    sf::Clock m_Clock;

    void Update();

    void Draw();

    void Event();

    void GameLoop();
public:
    Game();

    static Game* Instance();

    [[nodiscard]]sf::Font GetFont() const;

    void Start();
};

#endif //GAME_HPP