#include "GameObject.h"

Tot::GameObject::GameObject()
    :ObjectName("UNKNOW"), DrawLevel(DRAWLEVEL::la)
{

}

Tot::GameObject::GameObject(std::string objectname, DRAWLEVEL drawlevel)
    :ObjectName(objectname), DrawLevel(drawlevel)
{

}

std::string Tot::GameObject::GetName()
{
    return ObjectName;
}

sf::Vector2f Tot::GameObject::GetPosition()
{
    return m_sprite.getPosition();
}

sf::Vector2f Tot::GameObject::GetScale()
{
    return m_sprite.getScale();
}

void Tot::GameObject::SetPosition(sf::Vector2f const& position)
{
    m_sprite.setPosition(position);
}

void Tot::GameObject::SetPosition(float const& x, float const& y)
{
    m_sprite.setPosition(x, y);
}

void Tot::GameObject::SetScale(sf::Vector2f const& scale)
{
    m_sprite.setScale(scale);
}

void Tot::GameObject::SetTexture(sf::Texture const& texture)
{
    m_sprite.setTexture(texture);
}

