#pragma once

#include "Game.h"

class Gallery : public PhaseInterface
{
public:
    Gallery();
    ~Gallery();
    virtual void HandleEvents();
    virtual void Update();
    virtual void Render();

private:
    SDL_Texture* gallery_bg_texture;
    SDL_Rect gallery_bg_source_rect;
    SDL_Rect gallery_bg_destination_rect;

    SDL_Texture* ending_before_texture;
    SDL_Rect ending_before_source_rect;
    SDL_Rect ending_before_destination_rect1;
    SDL_Rect ending_before_destination_rect2;
    SDL_Rect ending_before_destination_rect3;
    SDL_Rect ending_before_destination_rect4;
    SDL_Rect ending_before_destination_rect5;
    SDL_Rect ending_before_destination_rect6;

    SDL_Texture* stage1_happy_ending_texture;
    SDL_Rect stage1_happy_ending_source_rect;
    SDL_Rect stage1_happy_ending_destination_rect;
    SDL_Texture* stage1_sad_ending_texture;
    SDL_Rect stage1_sad_ending_source_rect;
    SDL_Rect stage1_sad_ending_destination_rect;

    SDL_Texture* stage2_happy_ending_texture;
    SDL_Rect stage2_happy_ending_source_rect;
    SDL_Rect stage2_happy_ending_destination_rect;
    SDL_Texture* stage2_sad_ending_texture;
    SDL_Rect stage2_sad_ending_source_rect;
    SDL_Rect stage2_sad_ending_destination_rect;

    SDL_Texture* stage3_happy_ending_texture;
    SDL_Rect stage3_happy_ending_source_rect;
    SDL_Rect stage3_happy_ending_destination_rect;
    SDL_Texture* stage3_sad_ending_texture;
    SDL_Rect stage3_sad_ending_source_rect;
    SDL_Rect stage3_sad_ending_destination_rect;

    SDL_Texture* back_to_main_texture;
    SDL_Rect back_to_main_source_rect;
    SDL_Rect back_to_main_destination_rect;

};