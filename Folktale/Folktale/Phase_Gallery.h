#pragma once
#include "SDL.h"
#include "Game.h"

class Gallery : public PhaseInterface
{
public:
	Gallery();
	~Gallery();
	virtual void HandleEvents();
	virtual void Update();
	virtual void Render();
};