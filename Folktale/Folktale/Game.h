#pragma once


#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_image.h"

// Game Phases
const int PHASE_INTRO = 0;
const int PHASE_STAGE1 = 1;
const int PHASE_STAGE2 = 2;
const int PHASE_STAGE3 = 3;
const int PHASE_GALLERY = 4;
const int PHASE_ENDING = 5;

void InitGame();
void ClearGame();

extern int g_current_game_phase;
extern bool g_flag_running;
extern SDL_Renderer* g_renderer;
extern SDL_Window* g_window;
extern int screenWidth;
extern int screenHeight;

// 스테이지 당 엔딩의 수를 선언하는 상수
const int ENDINGS_PER_STAGE = 2;

// 스테이지의 수를 선언하는 상수
const int NUMBER_OF_STAGES = 3; // 실제 스테이지 수로 변경하세요

// 각 스테이지에서 본 엔딩을 저장하는 배열 선언
extern bool viewedEndings[NUMBER_OF_STAGES][ENDINGS_PER_STAGE];

class PhaseInterface
{
public:
	PhaseInterface() {};
	virtual ~PhaseInterface() {};

	virtual void HandleEvents() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

};