#include "Game.hpp"

Game* Game::m_Instance{nullptr};

Game::Game()
{

}

Game *Game::Instance()
{
    if(!m_Instance)
        m_Instance = new Game;

    return m_Instance;
}

void Game::Start()
{
    m_MainFont.loadFromFile("resources/fonts/main_font.ttf");
    m_CurrentScene = std::make_unique<MainScene>();

    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;

    m_MainWindow.create(sf::VideoMode(1920, 1080), m_GameName, sf::Style::Default, settings);
    m_MainWindow.setFramerateLimit(60);
    GameLoop();
}

void Game::Update()
{
    float deltaTime = m_Clock.restart().asSeconds();

    m_CurrentScene->Update(m_MainEvent, m_MainWindow, deltaTime);
}

sf::Font Game::GetFont() const
{
    return m_MainFont;
}

void Game::GameLoop()
{
    while (m_MainWindow.isOpen())
    {
        Event();
        m_MainWindow.clear();
        Update();
        Draw();
        m_MainWindow.display();

    }
}

void Game::Draw()
{
    if(m_CurrentScene)
        m_CurrentScene->ProcessDrawing(m_MainWindow);
}

void Game::Event()
{
    while (m_MainWindow.pollEvent(m_MainEvent))
    {
        if (m_MainEvent.type == sf::Event::Closed)
            m_MainWindow.close();

        if(m_CurrentScene)
            m_CurrentScene->ProcessEvents(m_MainEvent);
    }

}
