#pragma once
#include"Tot.h"
#include"GameObject.h"
#include"Player.h"

namespace Tot
{
	class GameObject;
	////////
	class ObjectManager : public sf::Drawable
	{
	friend class Tot::GameObject;
	////
	public:
		ObjectManager(std::string spfilename);
		////
		void GetSpriteFromFile();
		////
	private:
		////
		//  instanced only once
		static ObjectManager* IsInstanced;
		////////
		std::vector<GameObject*>GameObjects;
		////
		std::vector<Player>Players;
		////
		
		////////
		std::string m_SpFileName;
		////
		//  Loaded only once
		bool m_SpiteLoaded;
		////
		virtual void draw(sf::RenderTarget& target, sf::RenderStates state)const;
		////
	};
	////
}
