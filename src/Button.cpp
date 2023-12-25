#include <SFML/Window/Mouse.hpp>
#include "Button.hpp"

Button::Button() = default;

Button::Button(const sf::Vector2f& size,const sf::Vector2f &position, const sf::Color &color, const sf::String& text, const sf::Font &font) : m_Button(size)
{
    m_Text.setString(text);
    m_Text.setFont(font);
    m_FontSize = m_Text.getCharacterSize();
    m_Font = font;

    m_Text.setOrigin(m_Text.getGlobalBounds().width / 2, m_Text.getGlobalBounds().height / 2);

    m_Button.setFillColor(color);
    m_Button.setOutlineColor(sf::Color::Black);
    m_Button.setOutlineThickness(2);

    m_Button.setOrigin(m_Button.getGlobalBounds().width / 2, m_Button.getGlobalBounds().height / 2);
    m_Button.setPosition(position);

    m_Text.setPosition(sf::Vector2f(m_Button.getPosition().x, m_Button.getPosition().y - m_Text.getGlobalBounds().height / 2));
}

Button::Button(const sf::Vector2f &size, const sf::Vector2f &position, const sf::String &text, const sf::Font &font) : m_Button(size)
{
    m_Text.setString(text);
    m_Text.setFont(font);
    m_Font = font;

    m_Text.setOrigin(m_Text.getGlobalBounds().width / 2, m_Text.getGlobalBounds().height / 2);

    m_Button.setFillColor(sf::Color::Transparent);
    m_Button.setOutlineColor(sf::Color::Black);
    m_Button.setOutlineThickness(2);

    m_Button.setOrigin(m_Button.getGlobalBounds().width / 2, m_Button.getGlobalBounds().height / 2);
    m_Button.setPosition(position);

    m_Text.setPosition(sf::Vector2f(m_Button.getPosition().x, m_Button.getPosition().y - m_Text.getGlobalBounds().height / 2));
}

void Button::Create(const sf::Vector2f &size, const sf::Vector2f &position, const sf::String &text, const sf::Font &font)
{
    m_Button.setSize(size);

    m_Text.setString(text);
    m_Text.setFont(font);
    m_Font = font;

    m_Text.setOrigin(m_Text.getGlobalBounds().width / 2, m_Text.getGlobalBounds().height / 2);

    m_Button.setFillColor(sf::Color::Transparent);
    m_Button.setOutlineColor(sf::Color::Black);
    m_Button.setOutlineThickness(2);

    m_Button.setOrigin(m_Button.getGlobalBounds().width / 2, m_Button.getGlobalBounds().height / 2);
    m_Button.setPosition(position);

    m_Text.setPosition(sf::Vector2f(m_Button.getPosition().x, m_Button.getPosition().y - m_Text.getGlobalBounds().height / 2));
}

void Button::SetOutlineColor(const sf::Color &color)
{
    m_Button.setOutlineColor(color);
}

void Button::SetOutlineThickness(float thickness)
{
    m_Button.setOutlineThickness(thickness);
}

void Button::SetText(const sf::String &text)
{
    if(m_Text.getString() == text) return;

    m_Text.setString(text);
}

void Button::SetFont(const sf::Font &font)
{
    m_Font = font;
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_Button, states);
    target.draw(m_Text, states);
}

void Button::SetPosition(const sf::Vector2f &position)
{
    m_Position.x = position.x;
    m_Position.y = position.y;

    m_Button.setPosition(m_Position);
}

void Button::SetPosition(const float x, const float y)
{
    m_Position.x = x;
    m_Position.y = y;

    m_Button.setPosition(m_Position);
}

void Button::SetClickedEvent(const std::function<void()> &function)
{
    m_ClickEvent = function;
}

void Button::Update(sf::RenderWindow &window, const sf::Event &event)
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    bool mouse_in_button = m_Button.getGlobalBounds().contains(mousePos);

    if (event.type == sf::Event::MouseButtonPressed)
    {
        switch(event.mouseButton.button)
        {
            case sf::Mouse::Left:
            {
                if(mouse_in_button)
                {
                    if(m_ClickEvent)
                        m_ClickEvent();
                }

                else
                {
                }
            }
                break;
        }
    }
}

void Button::Move(float x, float y)
{
    m_Button.move(x, y);
    m_Text.move(x, y);
}

void Button::SetTextSize(uint16_t size)
{
    m_FontSize = size;
    m_Text.setCharacterSize(m_FontSize);
    m_Text.setOrigin(m_Text.getGlobalBounds().width/2, m_Text.getGlobalBounds().height/2);
//    m_shadow.setCharacterSize(m_FontSize);
//    m_shadow.setOrigin(m_shadow.getGlobalBounds().width/2, m_shadow.getGlobalBounds().height/2);
m_Button.setSize( sf::Vector2f(m_Text.getGlobalBounds().width * 1.5f, (m_Text.getGlobalBounds().m_Text + m_text.getGlobalBounds().height) * 1.5f))
//    m_button = thor::Shapes::roundedRect(m_size, m_borderRadius, m_bgNormal, m_borderThickness, m_border);
}
