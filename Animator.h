#pragma once
#include "AssetManager.h"
#include"Tot.h"
#include<list>
#include<string>

using namespace std;
using namespace sf;

class Animator
{
private:
	class Animation
	{
	public:
		string Name;
		string TextureName;
		vector<IntRect>Frames;
		Time Duration; //  lasting time
		bool Looping;

		Animation(string const& name, string const& texturename,
			Time const& duration, bool looping) : 
			Name(name),	TextureName(texturename), 
			Duration(duration), Looping(looping) {}

		void AddFrames(Vector2i const& StartForm, Vector2i const& FrameSize, unsigned int frames)
		{
			Vector2i current = StartForm;
			for (unsigned int i = 0; i < frames; i++)
			{
				Frames.push_back(IntRect(current.x, current.y, FrameSize.x, FrameSize.y));
				current.x += FrameSize.x;
			}
		}
		~Animation() 
		{ 
			//cout << "Animation: \"" << Name << "\" has been distructed." << endl; 
		}
	
	};

private:
	Animation* FindAnimation(string const& name);

	void SwitchAnimation(Animator::Animation* animation);

	Sprite& sprite;
	Time CurrentTime;
	list<Animation>Animations;
	Animator::Animation* CurrentAnimation;


public:
	Animator(Sprite& sprite) : sprite(sprite), CurrentTime(), CurrentAnimation(nullptr) {}
	Animation& CreateAnimation(string const& name, string const& texturename, Time const& duration, bool loop = false);
	
	void Update(Time const& dt); //  deltatime

	bool SwitchAnimation(string const& name);
	string GetCurrentAnimation()const;
};

