#include "Game.h"
#include "Phase_Intro.h"

Intro::Intro()
{
    // For Texture
    SDL_Surface* introBG_surface = IMG_Load("../../Resources/gallery/gallery_bg.png");
    texture_ = SDL_CreateTextureFromSurface(g_renderer, introBG_surface);
    SDL_FreeSurface(introBG_surface);

    SDL_QueryTexture(texture_, NULL, NULL, &source_rectangle_.w, &source_rectangle_.h);
    source_rectangle_ = { 0, 0, source_rectangle_.w, source_rectangle_.h };
    destination_rectangle_ = { 0, 0, 1080, 720 };

    //강아지똥 스테이지
    SDL_Surface* stagePoop_surface = IMG_Load("../../Resources/Intro/stage1_icon.png");
    stagePoop_texture_ = SDL_CreateTextureFromSurface(g_renderer, stagePoop_surface);
    SDL_FreeSurface(stagePoop_surface);

    SDL_QueryTexture(stagePoop_texture_, NULL, NULL, &stagePoop_source_rectangle_.w, &stagePoop_source_rectangle_.h);
    stagePoop_source_rectangle_ = { 0, 0, stagePoop_source_rectangle_.w, stagePoop_source_rectangle_.h };
    stagePoop_destination_rectangle_ = { 194, 140, stagePoop_source_rectangle_.w, stagePoop_source_rectangle_.h };

    //뱀 스테이지
    SDL_Surface* stageSnake_surface = IMG_Load("../../Resources/Intro/stage2_icon.png");
    stageSnake_texture_ = SDL_CreateTextureFromSurface(g_renderer, stageSnake_surface);
    SDL_FreeSurface(stageSnake_surface);

    SDL_QueryTexture(stageSnake_texture_, NULL, NULL, &stageSnake_source_rectangle_.w, &stageSnake_source_rectangle_.h);
    stageSnake_source_rectangle_ = { 0, 0, stageSnake_source_rectangle_.w, stageSnake_source_rectangle_.h };
    stageSnake_destination_rectangle_ = { 88, 357, stageSnake_source_rectangle_.w, stageSnake_source_rectangle_.h };

    //토끼 스테이지
    SDL_Surface* stageRabbit_surface = IMG_Load("../../Resources/Intro/stage3_icon.png");
    stageRabbit_texture_ = SDL_CreateTextureFromSurface(g_renderer, stageRabbit_surface);
    SDL_FreeSurface(stageRabbit_surface);

    SDL_QueryTexture(stageRabbit_texture_, NULL, NULL, &stageRabbit_source_rectangle_.w, &stageRabbit_source_rectangle_.h);
    stageRabbit_source_rectangle_ = { 0, 0, stageRabbit_source_rectangle_.w, stageRabbit_source_rectangle_.h };
    stageRabbit_destination_rectangle_ = { 297, 357, stageRabbit_source_rectangle_.w, stageRabbit_source_rectangle_.h };

    //Start버튼
    SDL_Surface* start_button_surface = IMG_Load("../../Resources/Intro/start_button.png");
    start_button_texture_ = SDL_CreateTextureFromSurface(g_renderer, start_button_surface);
    SDL_FreeSurface(start_button_surface);

    SDL_QueryTexture(start_button_texture_, NULL, NULL, &start_button_source_rectangle_.w, &start_button_source_rectangle_.h);
    start_button_source_rectangle_ = { 0, 0, 349, 109 };
    start_button_destination_rectangle_ = { 616, 111, start_button_source_rectangle_.w, start_button_source_rectangle_.h };

    //Gallery버튼
    SDL_Surface* gallery_button_surface = IMG_Load("../../Resources/Intro/gallery_button.png");
    gallery_button_texture_ = SDL_CreateTextureFromSurface(g_renderer, gallery_button_surface);
    SDL_FreeSurface(gallery_button_surface);

    SDL_QueryTexture(gallery_button_texture_, NULL, NULL, &gallery_button_source_rectangle_.w, &gallery_button_source_rectangle_.h);
    gallery_button_source_rectangle_ = { 0, 0, 349, 109 };
    gallery_button_destination_rectangle_ = { 616, 133, gallery_button_source_rectangle_.w, gallery_button_source_rectangle_.h };

    //option버튼
    SDL_Surface* option_button_surface = IMG_Load("../../Resources/Intro/option_button.png");
    option_button_texture_ = SDL_CreateTextureFromSurface(g_renderer, option_button_surface);
    SDL_FreeSurface(option_button_surface);

    SDL_QueryTexture(option_button_texture_, NULL, NULL, &option_button_source_rectangle_.w, &option_button_source_rectangle_.h);
    option_button_source_rectangle_ = { 0, 0, 349, 109 };
    option_button_destination_rectangle_ = { 616, 155, option_button_source_rectangle_.w, option_button_source_rectangle_.h };

    //Exit버튼
    SDL_Surface* exit_button_surface = IMG_Load("../../Resources/Intro/exit_button.png");
    exit_button_texture_ = SDL_CreateTextureFromSurface(g_renderer, exit_button_surface);
    SDL_FreeSurface(exit_button_surface);

    SDL_QueryTexture(exit_button_texture_, NULL, NULL, &exit_button_source_rectangle_.w, &exit_button_source_rectangle_.h);
    exit_button_source_rectangle_ = { 0, 0, 349, 109 };
    exit_button_destination_rectangle_ = { 616, 177, exit_button_source_rectangle_.w, exit_button_source_rectangle_.h };
}

Intro::~Intro()
{
    SDL_DestroyTexture(texture_);
    SDL_DestroyTexture(stagePoop_texture_);
    SDL_DestroyTexture(stageSnake_texture_);
    SDL_DestroyTexture(stageRabbit_texture_);
    SDL_DestroyTexture(start_button_texture_);
    SDL_DestroyTexture(gallery_button_texture_);
    SDL_DestroyTexture(option_button_texture_);
    SDL_DestroyTexture(exit_button_texture_);
}

void Intro::Update()
{

}


void Intro::Render()
{
    SDL_SetRenderDrawColor(g_renderer, 255, 255, 255, 255);
    SDL_RenderClear(g_renderer); // clear the renderer to the draw color

    SDL_RenderCopy(g_renderer, texture_, &source_rectangle_, &destination_rectangle_);
    SDL_RenderCopy(g_renderer, stagePoop_texture_, &stagePoop_source_rectangle_, &stagePoop_destination_rectangle_);
    SDL_RenderCopy(g_renderer, stageSnake_texture_, &stageSnake_source_rectangle_, &stageSnake_destination_rectangle_);
    SDL_RenderCopy(g_renderer, stageRabbit_texture_, &stageRabbit_source_rectangle_, &stageRabbit_destination_rectangle_);
    SDL_RenderCopy(g_renderer, start_button_texture_, &start_button_source_rectangle_, &start_button_destination_rectangle_);
    SDL_RenderCopy(g_renderer, gallery_button_texture_, &gallery_button_source_rectangle_, &gallery_button_destination_rectangle_);
    SDL_RenderCopy(g_renderer, option_button_texture_, &option_button_source_rectangle_, &option_button_destination_rectangle_);
    SDL_RenderCopy(g_renderer, exit_button_texture_, &exit_button_source_rectangle_, &exit_button_destination_rectangle_);


    //선택한 스테이지에 따라서 테두리를 그려줌
    if (selected_stage[0] == true)
    {
        SDL_SetRenderDrawColor(g_renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(g_renderer, &stagePoop_destination_rectangle_);
    }
    else if (selected_stage[1] == true)
    {
        SDL_SetRenderDrawColor(g_renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(g_renderer, &stageRabbit_destination_rectangle_);
    }
    else if (selected_stage[2] == true)
    {
        SDL_SetRenderDrawColor(g_renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(g_renderer, &stageSnake_destination_rectangle_);
    }

    SDL_RenderPresent(g_renderer); // draw to the screen
}



void Intro::HandleEvents()
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

            //stagePoop버튼을 누르고 Start버튼을 누르면 Stage1로 넘어감
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                if (event.button.x > stagePoop_destination_rectangle_.x && event.button.x < stagePoop_destination_rectangle_.x + stagePoop_source_rectangle_.w &&
                    event.button.y > stagePoop_destination_rectangle_.y && event.button.y < stagePoop_destination_rectangle_.y + stagePoop_source_rectangle_.h)
                {
                    selected_stage[0] = true;
                    selected_stage[1] = false;
                    selected_stage[2] = false;
                }
                //stageSnake버튼을 누르고 Start버튼을 누르면 Stage2로 넘어감
                else if (event.button.x > stageSnake_destination_rectangle_.x && event.button.x < stageSnake_destination_rectangle_.x + stageSnake_source_rectangle_.w &&
                    event.button.y > stageSnake_destination_rectangle_.y && event.button.y < stageSnake_destination_rectangle_.y + stageSnake_source_rectangle_.h)
                {
                    selected_stage[1] = true;
                    selected_stage[0] = false;
                    selected_stage[2] = false;
                }
                //stageRabbit버튼을 누르고 Start버튼을 누르면 Stage3로 넘어감
                else if (event.button.x > stageRabbit_destination_rectangle_.x && event.button.x < stageRabbit_destination_rectangle_.x + stageRabbit_source_rectangle_.w &&
                    event.button.y > stageRabbit_destination_rectangle_.y && event.button.y < stageRabbit_destination_rectangle_.y + stageRabbit_source_rectangle_.h)
                {
                    selected_stage[2] = true;
                    selected_stage[0] = false;
                    selected_stage[1] = false;
                }
                //Start버튼을 누르면 Stage1로 넘어감
                else if (event.button.x > 327 && event.button.x < 327 + start_button_source_rectangle_.w &&
                    event.button.y > 78 && event.button.y < 78 + start_button_source_rectangle_.h)
                {

                    if (selected_stage[0] == true)
                    {
                        g_current_game_phase = PHASE_STAGE1;
                    }
                    else if (selected_stage[1] == true)
                    {
                        g_current_game_phase = PHASE_STAGE2;
                    }
                    else if (selected_stage[2] == true)
                    {
                        g_current_game_phase = PHASE_STAGE3;
                    }
                }
                //Gallery버튼을 누르면 Gallery로 넘어감
                if (event.button.x > 327 && event.button.x < 327 + gallery_button_source_rectangle_.w &&
                    event.button.y > 198 && event.button.y < 198 + gallery_button_source_rectangle_.h)
                {
                    g_current_game_phase = PHASE_GALLERY;
                }

                //Exit버튼을 누르면 게임이 종료됨
                else if (event.button.x > 327 && event.button.x < 327 + exit_button_source_rectangle_.w &&
                    event.button.y > 390 && event.button.y < 390 + exit_button_source_rectangle_.h)
                {
                    g_flag_running = false;
                }

            }

        case SDL_MOUSEMOTION:
            //start버튼 위에 마우스가 올라가면 색이 변함
            if (event.motion.x > 327 && event.motion.x < 327 + start_button_source_rectangle_.w &&
                event.motion.y > 78 && event.motion.y < 78 + start_button_source_rectangle_.h)
            {
                start_button_source_rectangle_ = { 349, 0, 349, 109 };
            }
            else
            {
                start_button_source_rectangle_ = { 0, 0, 349, 109 };
            }
            //gallery버튼 위에 마우스가 올라가면 색이 변함
            if (event.motion.x > 327 && event.motion.x < 327 + gallery_button_source_rectangle_.w &&
                event.motion.y > 198 && event.motion.y < 198 + gallery_button_source_rectangle_.h)
            {
                gallery_button_source_rectangle_ = { 349, 0, 349, 109 };
            }
            else
            {
                gallery_button_source_rectangle_ = { 0, 0, 349, 109 };
            }
            //option버튼 위에 마우스가 올라가면 색이 변함
            if (event.motion.x > 327 && event.motion.x < 327 + option_button_source_rectangle_.w &&
                event.motion.y > 318 && event.motion.y < 318 + option_button_source_rectangle_.h)
            {
                option_button_source_rectangle_ = { 349, 0, 349, 109 };
            }
            else
            {
                option_button_source_rectangle_ = { 0, 0, 349, 109 };
            }
            //exit버튼 위에 마우스가 올라가면 색이 변함
            if (event.motion.x > 327 && event.motion.x < 327 + exit_button_source_rectangle_.w &&
                event.motion.y > 390 && event.motion.y < 390 + exit_button_source_rectangle_.h)
            {
                exit_button_source_rectangle_ = { 349, 0, 349, 109 };
            }
            else
            {
                exit_button_source_rectangle_ = { 0, 0, 349, 109 };
            }
        default:
            break;
        }
    }
}
