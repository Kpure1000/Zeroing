#include "Animator.h"
Animator::Animation& Animator::CreateAnimation(string const& name, string const& texturename, Time const& duration, bool loop )
{
	Animations.push_back(Animator::Animation(name, texturename, duration, loop));
	if (CurrentAnimation == nullptr)
	{
		SwitchAnimation(&Animations.back());
	}
	return Animations.back();
}

void Animator::SwitchAnimation(Animator::Animation* animation)
{
	if (animation != nullptr)
	{
		sprite.setTexture(AssetManager::GetTexture(animation->TextureName));
	}
	CurrentAnimation = animation;
	CurrentTime = Time::Zero;
}

bool Animator::SwitchAnimation(string const& name)
{
	auto animation = FindAnimation(name);
	
	if (animation != nullptr)
	{
		if (animation == CurrentAnimation)return true;
		SwitchAnimation(animation);
		return true;
	}
	return false;
}

Animator::Animation* Animator::FindAnimation(string const& name)
{
	for (auto it = Animations.begin(); it != Animations.end(); it++)
	{
		if (it->Name == name)
			return &*it;
	}
	return nullptr;

}

string Animator::GetCurrentAnimation()const
{
	if (CurrentAnimation != nullptr)
	{
		return CurrentAnimation->Name;
	}
	return "";
}

void Animator::Update(Time const& dt)
{
	if (CurrentAnimation == nullptr)
		return;
	if (CurrentAnimation->Frames.size() == 0)
	{
		cout << "ERROR: " << CurrentAnimation->Name << " \'Frames is empty" << endl;
		if (Animations.size() == 0)
		{
			sprite.setTextureRect(IntRect(0, 0, 0, 0));
			return;
		}
		cout << "Now trying to Change Animation...:" << endl;
		auto it = Animations.begin();
		for (; it != Animations.end(); it++)
		{
			cout << it->Name << "..." << endl;
			if (it->Frames.size() != 0)
			{
				*CurrentAnimation = *it;
				cout << "Succeeded. Animate is Changed to " << it->Name << endl;
				cout << endl;
				break;
			}	
		}
		if (it == Animations.end())
		{
			cout << "Failed." << endl;
			sprite.setTextureRect(IntRect(0, 0, 0, 0));
			return;
		}
	}

	CurrentTime += dt;
	float scaletime = CurrentTime.asSeconds() / CurrentAnimation->Duration.asSeconds();
	int framesnum = (int)CurrentAnimation->Frames.size(); //  Sum num of Frames
	int CurrentFrame = static_cast<int>(scaletime * framesnum);

	if (CurrentAnimation->Looping)
	{
		CurrentFrame %= framesnum;
	}
	else if (CurrentFrame >= framesnum)
	{
		CurrentFrame = framesnum - 1;
	}
	sprite.setTextureRect(CurrentAnimation->Frames[CurrentFrame]);
}