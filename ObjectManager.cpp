#include "ObjectManager.h"

Tot::ObjectManager* Tot::ObjectManager::IsInstanced = nullptr;
////
Tot::ObjectManager::ObjectManager(std::string spfilename) :m_SpFileName(spfilename)
{
	//  if instanced, warning
	assert(IsInstanced == nullptr);
	//  if not, instance
	////
	IsInstanced = this;
	////
	m_SpiteLoaded = false;
}
////
void Tot::ObjectManager::GetSpriteFromFile()
{
	//  only call once this function
	if (m_SpiteLoaded) return;
	////
	m_SpiteLoaded = true;
	////
	std::ifstream InputFile(m_SpFileName);
	////
	if (InputFile.is_open())
	{
		for (auto it = GameObjects.begin(); it != GameObjects.end(); it++)
		{
			if (InputFile.eof())
				break;
			//  InputFile >> ... 
			////
		}
	}
	////
	InputFile.close();
	////
}
////
void Tot::ObjectManager::draw(sf::RenderTarget& target, sf::RenderStates state)const
{
	for (auto Git = GameObjects.begin(); Git != GameObjects.end(); Git++)
	{
		target.draw((*Git)->m_sprite, state);
	}
	////
}
////////
