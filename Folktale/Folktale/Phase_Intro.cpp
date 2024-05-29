#include "Game.h"
#include "Phase_Intro.h"

Intro::Intro()
{
    // For Texture
    SDL_Surface* introBG_surface = IMG_Load("../../Resources/Intro/intro.png");
    texture_ = SDL_CreateTextureFromSurface(g_renderer, introBG_surface);
    SDL_FreeSurface(introBG_surface);

    SDL_QueryTexture(texture_, NULL, NULL, &source_rectangle_.w, &source_rectangle_.h);
    source_rectangle_ = { 0, 0, source_rectangle_.w, source_rectangle_.h };
    destination_rectangle_ = { 0, 0, source_rectangle_.w, source_rectangle_.h };

    //강아지똥 스테이지
    SDL_Surface* stagePoop_surface = IMG_Load("../../Resources/Intro/Stage_poop.png");
    stagePoop_texture_ = SDL_CreateTextureFromSurface(g_renderer, stagePoop_surface);
    SDL_FreeSurface(stagePoop_surface);

    SDL_QueryTexture(stagePoop_texture_, NULL, NULL, &stagePoop_source_rectangle_.w, &stagePoop_source_rectangle_.h);
    stagePoop_source_rectangle_ = { 0, 0, stagePoop_source_rectangle_.w, stagePoop_source_rectangle_.h };
    stagePoop_destination_rectangle_ = { 145, 160, stagePoop_source_rectangle_.w, stagePoop_source_rectangle_.h };

    //뱀 스테이지
    SDL_Surface* stageSnake_surface = IMG_Load("../../Resources/Intro/Stage_snake.png");
    stageSnake_texture_ = SDL_CreateTextureFromSurface(g_renderer, stageSnake_surface);
    SDL_FreeSurface(stageSnake_surface);

    SDL_QueryTexture(stageSnake_texture_, NULL, NULL, &stageSnake_source_rectangle_.w, &stageSnake_source_rectangle_.h);
    stageSnake_source_rectangle_ = { 0, 0, stageSnake_source_rectangle_.w, stageSnake_source_rectangle_.h };
    stageSnake_destination_rectangle_ = { 210, 290, stageSnake_source_rectangle_.w, stageSnake_source_rectangle_.h };

    //토끼 스테이지
    SDL_Surface* stageRabbit_surface = IMG_Load("../../Resources/Intro/Stage_rabbit.png");
    stageRabbit_texture_ = SDL_CreateTextureFromSurface(g_renderer, stageRabbit_surface);
    SDL_FreeSurface(stageRabbit_surface);

    SDL_QueryTexture(stageRabbit_texture_, NULL, NULL, &stageRabbit_source_rectangle_.w, &stageRabbit_source_rectangle_.h);
    stageRabbit_source_rectangle_ = { 0, 0, stageRabbit_source_rectangle_.w, stageRabbit_source_rectangle_.h };
    stageRabbit_destination_rectangle_ = { 90, 290, stageRabbit_source_rectangle_.w, stageRabbit_source_rectangle_.h };

    //Start버튼
    SDL_Surface* start_button_surface = IMG_Load("../../Resources/Intro/intro_button.png");
    start_button_texture_ = SDL_CreateTextureFromSurface(g_renderer, start_button_surface);
    SDL_FreeSurface(start_button_surface);

    SDL_QueryTexture(start_button_texture_, NULL, NULL, &start_button_source_rectangle_.w, &start_button_source_rectangle_.h);
    start_button_source_rectangle_ = { 10, 20, 120, 85 };
    start_button_destination_rectangle_ = { 327, 78, start_button_source_rectangle_.w, start_button_source_rectangle_.h };

    //Gallery버튼
    SDL_Surface* gallery_button_surface = IMG_Load("../../Resources/Intro/intro_button.png");
    gallery_button_texture_ = SDL_CreateTextureFromSurface(g_renderer, gallery_button_surface);
    SDL_FreeSurface(gallery_button_surface);

    SDL_QueryTexture(gallery_button_texture_, NULL, NULL, &gallery_button_source_rectangle_.w, &gallery_button_source_rectangle_.h);
    gallery_button_source_rectangle_ = { 10, 140, 120, 95 };
    gallery_button_destination_rectangle_ = { 327, 198, gallery_button_source_rectangle_.w, gallery_button_source_rectangle_.h };

    //Manual버튼
    SDL_Surface* manual_button_surface = IMG_Load("../../Resources/Intro/intro_button.png");
    manual_button_texture_ = SDL_CreateTextureFromSurface(g_renderer, manual_button_surface);
    SDL_FreeSurface(manual_button_surface);

    SDL_QueryTexture(manual_button_texture_, NULL, NULL, &manual_button_source_rectangle_.w, &manual_button_source_rectangle_.h);
    manual_button_source_rectangle_ = { 10, 250, 120, 95 };
    manual_button_destination_rectangle_ = { 327, 290, manual_button_source_rectangle_.w, manual_button_source_rectangle_.h };

    //Exit버튼
    SDL_Surface* exit_button_surface = IMG_Load("../../Resources/Intro/intro_button.png");
    exit_button_texture_ = SDL_CreateTextureFromSurface(g_renderer, exit_button_surface);
    SDL_FreeSurface(exit_button_surface);

    SDL_QueryTexture(exit_button_texture_, NULL, NULL, &exit_button_source_rectangle_.w, &exit_button_source_rectangle_.h);
    exit_button_source_rectangle_ = { 10, 365, 120, 115 };
    exit_button_destination_rectangle_ = { 327, 390, exit_button_source_rectangle_.w, exit_button_source_rectangle_.h };

    //Manual 이미지
    SDL_Surface* manual_surface = IMG_Load("../../Resources/Intro/manual.png");
    manual_texture_ = SDL_CreateTextureFromSurface(g_renderer, manual_surface);
    SDL_FreeSurface(manual_surface);

    SDL_QueryTexture(manual_texture_, NULL, NULL, &manual_source_rectangle_.w, &manual_source_rectangle_.h);
    manual_source_rectangle_ = { 0, 0, manual_source_rectangle_.w, manual_source_rectangle_.h };
    manual_destination_rectangle_ = { 110, 125, manual_source_rectangle_.w, manual_source_rectangle_.h };
}

Intro::~Intro()
{
    SDL_DestroyTexture(texture_);
    SDL_DestroyTexture(stagePoop_texture_);
    SDL_DestroyTexture(stageSnake_texture_);
    SDL_DestroyTexture(stageRabbit_texture_);
    SDL_DestroyTexture(start_button_texture_);
    SDL_DestroyTexture(gallery_button_texture_);
    SDL_DestroyTexture(manual_button_texture_);
    SDL_DestroyTexture(exit_button_texture_);
    SDL_DestroyTexture(manual_texture_);
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
    SDL_RenderCopy(g_renderer, manual_button_texture_, &manual_button_source_rectangle_, &manual_button_destination_rectangle_);
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

    //Manual버튼을 누르면 Manual 이미지가 뜸
    if (manualTF[0] == true)
    {
        SDL_SetTextureColorMod(manual_texture_, 255, 255, 255);
        SDL_RenderCopy(g_renderer, manual_texture_, &manual_source_rectangle_, &manual_destination_rectangle_);
    }
    else if (manualTF[1] == true)
    {
        SDL_SetTextureColorMod(manual_texture_, 0, 255, 0);
        SDL_RenderCopy(g_renderer, manual_texture_, &manual_source_rectangle_, &manual_destination_rectangle_);
    }
    else if (manualTF[2] == true)
    {
        SDL_SetTextureColorMod(manual_texture_, 0, 0, 255);
        SDL_RenderCopy(g_renderer, manual_texture_, &manual_source_rectangle_, &manual_destination_rectangle_);
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
                if (event.button.x > 145 && event.button.x < 145 + stagePoop_source_rectangle_.w &&
                    event.button.y > 160 && event.button.y < 160 + stagePoop_source_rectangle_.h)
                {
                    selected_stage[0] = true;
                    selected_stage[1] = false;
                    selected_stage[2] = false;
                }
                //stageSnake버튼을 누르고 Start버튼을 누르면 Stage2로 넘어감
                else if (event.button.x > 90 && event.button.x < 90 + stageSnake_source_rectangle_.w &&
                    event.button.y > 290 && event.button.y < 290 + stageSnake_source_rectangle_.h)
                {
                    selected_stage[1] = true;
                    selected_stage[0] = false;
                    selected_stage[2] = false;
                }
                //stageRabbit버튼을 누르고 Start버튼을 누르면 Stage3로 넘어감
                else if (event.button.x > 210 && event.button.x < 210 + stageRabbit_source_rectangle_.w &&
                    event.button.y > 290 && event.button.y < 290 + stageRabbit_source_rectangle_.h)
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
            //마우스가 Manual버튼에 올라가면 Manual 이미지가 뜸
            if (event.motion.x > 327 && event.motion.x < 327 + manual_button_source_rectangle_.w &&
                event.motion.y > 290 && event.motion.y < 290 + manual_button_source_rectangle_.h)
            {
                if (selected_stage[0] == true)
                {
                    manualTF[0] = true;
                    manualTF[1] = false;
                    manualTF[2] = false;
                }
                else if (selected_stage[1] == true)
                {
                    manualTF[1] = true;
                    manualTF[0] = false;
                    manualTF[2] = false;
                }
                else if (selected_stage[2] == true)
                {
                    manualTF[2] = true;
                    manualTF[0] = false;
                    manualTF[1] = false;
                }
            }
            else
            {
                manualTF[0] = false;
                manualTF[1] = false;
                manualTF[2] = false;
            }
        default:
            break;
        }
    }
}
