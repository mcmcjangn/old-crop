#include "Game.h"
#include "Phase_Gallery.h"

Gallery::Gallery()
{
    //배경 이미지 불러오기
    SDL_Surface* gallery_bg_surface = IMG_Load("../../Resources/gallery/gallery_bg.png");
    gallery_bg_texture = SDL_CreateTextureFromSurface(g_renderer, gallery_bg_surface);
    SDL_FreeSurface(gallery_bg_surface);

    gallery_bg_source_rect = { 0, 0, 1080, 720 };
    gallery_bg_destination_rect = { 0, 0, 1080, 720 };

    //엔딩 보기 전 이미지
    SDL_Surface* ending_before_surface = IMG_Load("../../Resources/gallery/ending_before.png");
    ending_before_texture = SDL_CreateTextureFromSurface(g_renderer, ending_before_surface);
    SDL_FreeSurface(ending_before_surface);

    ending_before_source_rect = { 0, 0, ending_before_surface->w, ending_before_surface->h };
    ending_before_destination_rect1 = { 85, 158, ending_before_source_rect.w, ending_before_source_rect.h };
    ending_before_destination_rect2 = { 300, 158, ending_before_source_rect.w, ending_before_source_rect.h };
    ending_before_destination_rect3 = { 85, 457, ending_before_source_rect.w, ending_before_source_rect.h };
    ending_before_destination_rect4 = { 300, 457, ending_before_source_rect.w, ending_before_source_rect.h };
    ending_before_destination_rect5 = { 617, 158, ending_before_source_rect.w, ending_before_source_rect.h };
    ending_before_destination_rect6 = { 832, 158, ending_before_source_rect.w, ending_before_source_rect.h };

    ////stage1 해피 엔딩
    //SDL_Surface* stage1_happy_ending_surface = IMG_Load("../../Resources/gallery/stage1_happy_ending.png");
    //stage1_happy_ending_texture = SDL_CreateTextureFromSurface(g_renderer, stage1_happy_ending_surface);
    //SDL_FreeSurface(stage1_happy_ending_surface);

    //stage1_happy_ending_source_rect = { 0, 0, stage1_happy_ending_source_rect.w, stage1_happy_ending_source_rect.h };
    //

    ////stage1 새드 엔딩
    //SDL_Surface* stage1_sad_ending_surface = IMG_Load("../../Resources/gallery/stage1_sad_ending.png");
    //stage1_sad_ending_texture = SDL_CreateTextureFromSurface(g_renderer, stage1_sad_ending_surface);
    //SDL_FreeSurface(stage1_sad_ending_surface);

    //stage1_sad_ending_source_rect = { 0, 0, stage1_sad_ending_source_rect.w, stage1_sad_ending_source_rect.h };
    //

    ////stage2 해피 엔딩
    //SDL_Surface* stage2_happy_ending_surface = IMG_Load("../../Resources/gallery/stage2_happy_ending.png");
    //stage2_happy_ending_texture = SDL_CreateTextureFromSurface(g_renderer, stage2_happy_ending_surface);
    //SDL_FreeSurface(stage2_happy_ending_surface);

    //stage2_happy_ending_source_rect = { 0, 0, stage2_happy_ending_source_rect.w, stage2_happy_ending_source_rect.h };


    ////stage2 새드 엔딩
    //SDL_Surface* stage2_sad_ending_surface = IMG_Load("../../Resources/gallery/stage2_sad_ending.png");
    //stage2_sad_ending_texture = SDL_CreateTextureFromSurface(g_renderer, stage2_sad_ending_surface);
    //SDL_FreeSurface(stage2_sad_ending_surface);

    //stage2_sad_ending_source_rect = { 0, 0, stage2_sad_ending_source_rect.w, stage2_sad_ending_source_rect.h };


    ////stage3 해피 엔딩
    //SDL_Surface* stage3_happy_ending_surface = IMG_Load("../../Resources/gallery/stage3_happy_ending.png");
    //stage3_happy_ending_texture = SDL_CreateTextureFromSurface(g_renderer, stage3_happy_ending_surface);
    //SDL_FreeSurface(stage3_happy_ending_surface);

    //stage3_happy_ending_source_rect = { 0, 0, stage3_happy_ending_source_rect.w, stage3_happy_ending_source_rect.h };


    ////stage3 새드 엔딩
    //SDL_Surface* stage3_sad_ending_surface = IMG_Load("../../Resources/gallery/stage3_sad_ending.png");
    //stage3_sad_ending_texture = SDL_CreateTextureFromSurface(g_renderer, stage3_sad_ending_surface);
    //SDL_FreeSurface(stage3_sad_ending_surface);

    //stage3_sad_ending_source_rect = { 0, 0, stage3_sad_ending_source_rect.w, stage3_sad_ending_source_rect.h };


    //메인으로 돌아가기 버튼
    SDL_Surface* back_to_main_surface = IMG_Load("../../Resources/gallery/back_to_main.png");
    back_to_main_texture = SDL_CreateTextureFromSurface(g_renderer, back_to_main_surface);
    SDL_FreeSurface(back_to_main_surface);

    back_to_main_source_rect = { 0, 0, back_to_main_surface->w, back_to_main_surface->h };
    back_to_main_destination_rect = { 620, 395, back_to_main_source_rect.w, back_to_main_source_rect.h };
}

Gallery::~Gallery()
{
    SDL_DestroyTexture(gallery_bg_texture);
    SDL_DestroyTexture(ending_before_texture);
    /*SDL_DestroyTexture(stage1_happy_ending_texture);
    SDL_DestroyTexture(stage1_sad_ending_texture);
    SDL_DestroyTexture(stage2_happy_ending_texture);
    SDL_DestroyTexture(stage2_sad_ending_texture);
    SDL_DestroyTexture(stage3_happy_ending_texture);
    SDL_DestroyTexture(stage3_sad_ending_texture);*/
    SDL_DestroyTexture(back_to_main_texture);

}

void Gallery::Update()
{
    //본 엔딩 확인
}

void Gallery::Render()
{
    SDL_SetRenderDrawColor(g_renderer, 255, 255, 255, 255);
    SDL_RenderClear(g_renderer); // clear the renderer to the draw color

    SDL_RenderCopy(g_renderer, gallery_bg_texture, &gallery_bg_source_rect, &gallery_bg_destination_rect);
    SDL_RenderCopy(g_renderer, ending_before_texture, &ending_before_source_rect, &ending_before_destination_rect1);
    SDL_RenderCopy(g_renderer, ending_before_texture, &ending_before_source_rect, &ending_before_destination_rect2);
    SDL_RenderCopy(g_renderer, ending_before_texture, &ending_before_source_rect, &ending_before_destination_rect3);
    SDL_RenderCopy(g_renderer, ending_before_texture, &ending_before_source_rect, &ending_before_destination_rect4);
    SDL_RenderCopy(g_renderer, ending_before_texture, &ending_before_source_rect, &ending_before_destination_rect5);
    SDL_RenderCopy(g_renderer, ending_before_texture, &ending_before_source_rect, &ending_before_destination_rect6);
    SDL_RenderCopy(g_renderer, stage1_happy_ending_texture, &stage1_happy_ending_source_rect, &stage1_happy_ending_destination_rect);
    /*SDL_RenderCopy(g_renderer, stage1_sad_ending_texture, &stage1_sad_ending_source_rect, &stage1_sad_ending_destination_rect);
    SDL_RenderCopy(g_renderer, stage2_happy_ending_texture, &stage2_happy_ending_source_rect, &stage2_happy_ending_destination_rect);
    SDL_RenderCopy(g_renderer, stage2_sad_ending_texture, &stage2_sad_ending_source_rect, &stage2_sad_ending_destination_rect);
    SDL_RenderCopy(g_renderer, stage3_happy_ending_texture, &stage3_happy_ending_source_rect, &stage3_happy_ending_destination_rect);
    SDL_RenderCopy(g_renderer, stage3_sad_ending_texture, &stage3_sad_ending_source_rect, &stage3_sad_ending_destination_rect);*/
    SDL_RenderCopy(g_renderer, back_to_main_texture, &back_to_main_source_rect, &back_to_main_destination_rect);


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
        case SDL_MOUSEMOTION:
        {
            int mouseX = event.motion.x;
            int mouseY = event.motion.y;

            if (mouseX >= back_to_main_destination_rect.x && mouseX <= back_to_main_destination_rect.x + back_to_main_destination_rect.w &&
                mouseY >= back_to_main_destination_rect.y && mouseY <= back_to_main_destination_rect.y + back_to_main_destination_rect.h)
            {
                // Mouse is over the button, use the dark image
                SDL_SetTextureColorMod(back_to_main_texture, 255, 0, 0);
            }
            else
            {
                // Mouse is not over the button, use the normal image
                SDL_SetTextureColorMod(back_to_main_texture, 255, 255, 255);
            }
            break;
        }
        case SDL_MOUSEBUTTONDOWN:
        {
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                if (event.button.x > back_to_main_destination_rect.x && event.button.x < back_to_main_destination_rect.x + back_to_main_destination_rect.w &&
                    event.button.y > back_to_main_destination_rect.y && event.button.y < back_to_main_destination_rect.y + back_to_main_destination_rect.h)
                {
                    g_current_game_phase = PHASE_INTRO;
                }
            }
            break;
        }
        default:
            break;
        }
    }
}
