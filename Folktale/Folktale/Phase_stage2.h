#pragma once
#include <SDL.h>
#include "Creature_stage2.h"

extern SDL_Renderer* g_renderer;
extern SDL_Window* g_window;
extern bool g_flag_running;


class Stage2 {
public:
    Stage2();
    ~Stage2();

    void HandleEvents();
    void Update();
    void Render();
    void Reset();

    int getResult() {
        return this->game_result;
    }

private:
    Turtle* turtle;
    Rabbit* rabbit;
    Coral* coral;

    // ����Ű ���� ������
    bool f_list[4];
    int f_state; // ���� ���� Ű ����
    bool stop; // ���� ����

    // ���� Ȯ�� ����
    int game_result = 0;

    //�̷�




    //�ؽ���
    SDL_Texture* stage2_bg_texture;
    SDL_Texture* turtle_texture;
    SDL_Texture* rabbit_texture;
    SDL_Texture* coral_texture;
    SDL_Texture* gan_texture;
    SDL_Texture* heart0_texture;
    SDL_Texture* heart2_texture;


    //�ؽ��� �簢��
    SDL_Rect turtle_destination_rect;
    SDL_Rect rabbit_destination_rect;
    SDL_Rect coral_destination_rect;
    SDL_Rect stage2_bg_destination_rect;
    SDL_Rect gan_destination_rect;
    SDL_Rect heart0_destination_rect;
    SDL_Rect heart2_destination_rect;

};

