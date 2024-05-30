
#include "Game.h"
#include "Phase_Intro.h"
#include "Phase_Stage1.h"
#include "Phase_Stage2.h"
#include "Phase_Stage3.h"
#include "Phase_Ending.h"
#include "Phase_Gallery.h"
#include <Windows.h>

/////////////////////////////////////////////////
// Declaration
SDL_Window* g_window;
SDL_Renderer* g_renderer;
bool g_flag_running = true;
Uint32 g_last_time_ms = 0;

// Game Phases
int g_current_game_phase;
int screenWidth = 1080;
int screenHeight = 720;

bool viewedEndings[NUMBER_OF_STAGES][ENDINGS_PER_STAGE] = { false };

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG); // 이미지 라이브러리 초기화
    TTF_Init();

    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
        std::cout << "Mix_OpenAudio " << Mix_GetError() << std::endl;
        exit(1);
    }

    g_window = SDL_CreateWindow("First Window", 100, 100, screenWidth, screenHeight, 0);
    g_renderer = SDL_CreateRenderer(g_window, -1, 0);


    InitGame();

    Intro intro;
    Stage1 stage1;
    Stage2 stage2;
    Stage3 stage3;
    Gallery gallery;
    Ending ending;

    g_current_game_phase = PHASE_INTRO;

    while (g_flag_running)
    {
        Uint32 cur_time_ms = SDL_GetTicks();

        if (cur_time_ms - g_last_time_ms < 33)
            continue;


        if (g_current_game_phase == PHASE_INTRO)
        {
            stage1.~Stage1();
            stage2.~Stage2();
            stage3.~Stage3();
            gallery.~Gallery();
            ending.~Ending();

            intro.HandleEvents();
            intro.Update();
            intro.Render();
        }
        else if (g_current_game_phase == PHASE_STAGE1)
        {
            bool is_intro_initialized = false;

            if (!is_intro_initialized) {
                stage1.Reset();
                is_intro_initialized = true;
            }

            intro.~Intro();

            stage1.HandleEvents();
            stage1.Update();
            stage1.Render();

            Sleep(33);
            g_last_time_ms = cur_time_ms;
        }
        else if (g_current_game_phase == PHASE_STAGE2)
        {
            if (stage2.getResult() == 1 || stage2.getResult() == 2) { //�¸��� ���� ����
                g_current_game_phase = PHASE_INTRO;
            }

            intro.~Intro();

            stage2.HandleEvents();
            stage2.Update();
            stage2.Render();
        }
        else if (g_current_game_phase == PHASE_STAGE3)
        {
            if (stage3.getResult() == 1 || stage3.getResult() == 2) { // 게임 승리 또는 패배시 다시 인트로로 돌아오도록 설정해둠
                g_current_game_phase = PHASE_INTRO;
            }

            intro.~Intro();

            stage3.HandleEvents();
            stage3.Update();
            stage3.Render();
        }
        else if (g_current_game_phase == PHASE_GALLERY)
        {
            intro.~Intro();

            gallery.HandleEvents();
            gallery.Update();
            gallery.Render();
        }
        else if (g_current_game_phase == PHASE_ENDING)
        {
            ending.HandleEvents();
            ending.Update();
            ending.Render();
        }

        ClearGame();
    }

    SDL_DestroyRenderer(g_renderer);
    SDL_DestroyWindow(g_window);


    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}