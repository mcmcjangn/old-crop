#include "Game.h"
#include "Phase_Gallery.h"

Gallery::Gallery()
{

}

Gallery::~Gallery()
{

}

void Gallery::Update()
{
}

void Gallery::Render()
{
	SDL_SetRenderDrawColor(g_renderer, 255, 0, 0, 255);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

    SDL_RenderPresent(g_renderer);
}

void Gallery::HandleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			g_flag_running = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				g_current_game_phase = PHASE_ENDING;
			}
			break;
		}
		default:
			break;
		}
	}
}
