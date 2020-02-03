#pragma once
#include"Tot.h"
#include"GameObject.h"
namespace Tot
{
	////
	class Player : public GameObject
	{
	public:
		Player() {}
		////
		Player(std::string objectname, DRAWLEVEL drawlevel);
		////
		~Player() {}
		////
		
	private:

	};
}

