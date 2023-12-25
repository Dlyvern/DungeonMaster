#ifndef BUTTON_HPP
#define BUTTON_HPP

#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "SFML/Graphics/RenderTarget.hpp"

class Button : public sf::Drawable
{
private:
    sf::RectangleShape m_Button;
    sf::Text m_Text;
    sf::Vector2f m_Position{0,0};
    sf::Font m_Font;
    std::function<void()>m_ClickEvent;
    uint16_t m_FontSize;
protected:
     void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    Button();
    Button(const sf::Vector2f& size, const sf::Vector2f &position, const sf::Color& color, const sf::String& text, const sf::Font& font);
    Button(const sf::Vector2f &size, const sf::Vector2f &position, const sf::String& text, const sf::Font& font);

    void Create(const sf::Vector2f& size, const sf::Vector2f & position, const sf::String& text, const sf::Font& font);

    void Update(sf::RenderWindow& window, const sf::Event& event);

    void SetText(const sf::String& text);
    void SetFont(const sf::Font& font);
    void SetPosition(const sf::Vector2f& position);
    void SetPosition(float x, float y);
    void SetOutlineColor(const sf::Color& color);
    void SetOutlineThickness(float thickness);
    void SetClickedEvent(const std::function<void()>&function);
    void Move(float x, float y);
    void SetTextSize(uint16_t size);
};

#endif //BUTTON_HPP
