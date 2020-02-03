#include"GameObject.h"
#include"Player.h"

int main()
{
	//  Set App: 
	const float AppW = 2000, AppH = 1500;
	sf::RenderWindow App(sf::VideoMode((unsigned int)AppW, (unsigned int)AppH), "MakeMap", CannotResize);
	//////////////////////////////////////////
	//  Set Frames
	float Frames = 170.0f;
	long TimeDelay = (long)(1000.0f / Frames);
	time_t StartTime = 0;
	time_t EndTime = 0;
	//////////////////////////////////////////
	//  Setup
	////
	while (App.isOpen())
	{
		////
		StartTime = clock();
		//  Start FPS count
		////
		sf::Event Appev;
		while (App.pollEvent(Appev))
		{
			if (Appev.type == sf::Event::Closed) {
				App.close();
			}
			else if (KeyPressing and KeyEvent(Escape)) {
				App.close();
			}
		}
		/////////////
		//  Game Loop:
		App.clear();
		////
		//  Update
		////
		//  View Loop:
		//  Get from ViewList, Set View
		//  Draw in View World
		////
		App.display();
		/////////////
		//  Get FPS
		while (EndTime - StartTime <= TimeDelay) {
			EndTime = clock();
		}
		////////////
	}

}