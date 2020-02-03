#pragma once
#include"Tot.h"
namespace Tot
{
	class Player;
	////
	class GameObject
	{
	friend class ObjectManager;
		////
	public:
		GameObject();
		////
		GameObject(std::string objectname, DRAWLEVEL drawlevel);
		////
		virtual ~GameObject() {}
		////
		///////////////////////////
		//  Get Object Name
		std::string GetName();
		////
		//  Get Sprite Position
		sf::Vector2f GetPosition();
		////
		//  Get Sprite Scale
		sf::Vector2f GetScale();
		///////////////////////////
		//  Set sprite position
		void SetPosition(sf::Vector2f const& position);
		void SetPosition(float const& x, float const& y); 
		////
		//  Set sprite Scale
		void SetScale(sf::Vector2f const& scale);
		////
		//  Set texture
		void SetTexture(sf::Texture const& texture);
		////
	protected:
		std::string ObjectName; //  
		////
		sf::Sprite m_sprite;
		////
		DRAWLEVEL DrawLevel;
		////
	};

}

