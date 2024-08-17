#include "Creature.h"
#include "Creature_stage2.h"
#include "Phase_stage2.h"

//�̷�----------------------------------------------------------------------------------------------------------------


int Maze::maze[SCREEN_HEIGHT_][SCREEN_WIDTH_] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} ,
    {1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
}; // maze �迭 �ܺ� ����

bool Maze::isCoral(int x, int y) {
    return maze[y][x] == 1;
}

//��ȣ----------------------------------------------------------------------------------------------------------------
Coral::Coral(int x, int y, int speed, double health, int attackPower) : Ally(x, y, speed, health, attackPower) {
    //������
    C_output = '#';
}

void Coral::Draw() {
}

void Coral::attackDamage(int attackPower) {

}

void Coral::move(int newX, int newY) {
}

void Coral::GetAttackted(int damage) {

}

Coral::~Coral() {}




//�ź���----------------------------------------------------------------------------------------------------------------
Turtle::Turtle(int x, int y, int speed, double health, int attackPower) :Ally(x, y, speed, health, attackPower) {
    //������

    T_output = '*';
}

void Turtle::Draw() {

}

//�ź��̰� ���ݹ޾�����
void Turtle::GetAttackted(int damage) {
    //�ź��� ü�� ����
    //�ź��� ü���� 0���ϸ� ����
    int hp = getHealth();
    hp -= damage;
    if (hp <= 0) {
        //�ź��� ����
        hp = 0;
    }
    setHealth(hp);
}

void Turtle::move(int newX, int newY) {
    //�ź��� �̵�
    this->setXY(newX, newY);


}

void Turtle::attackDamage(int attackPower) {
}

bool Turtle::isCollision_Coral(Coral* coral) {
    bool isCollision = false;//�浹����
    //�ź��̿� ��ȣ�� ��ǥ�� ������ �浹
    if (this->getX() == coral->getX() && this->getY() == coral->getY()) {
        isCollision = true;

    }
    return isCollision;

}

bool Turtle::isCollision_Rabbit(Rabbit* rabbit) {
    bool isCollision = false;//�浹����
    //�ź��̿� �䳢�� ��ǥ�� ������ �浹
    if (this->getX() == rabbit->getX() && this->getY() == rabbit->getY()) {
        isCollision = true;
        // setIsFace �޼��� ȣ��
        rabbit->setIsFace(!rabbit->getIsFace());
    }
    return isCollision;
}

char Turtle::get_output() {
    return this->T_output;
}
//�Ҹ�������
Turtle::~Turtle() {}

//�䳢----------------------------------------------------------------------------------------------------------------
Rabbit::Rabbit(int x, int y, int speed, double health) : bellAndRabbit(x, y, speed, health) {
    R_output = '^';
}

void Rabbit::Draw() {
}

void Rabbit::GetAttackted(int damage) {
}

void Rabbit::move(int newX, int newY) {
}
void Rabbit::spawn() {
    uniform_int_distribution<int> distributionX(0, SCREEN_WIDTH_ - 1);
    uniform_int_distribution<int> distributionY(0, SCREEN_HEIGHT_ - 1);

    if (this->getIsFace()) { // ���� �ź��̸� �����ٸ�
        this->setIsFace(!this->getIsFace()); // ������ �� �� �����ٰ� ����

        // ��ȣ�� ��ġ�� �ʴ� ��ǥ�� ã��
        int newX, newY;
        do {
            newX = distributionX(generator);
            newY = distributionY(generator);
        } while (Maze::isCoral(newX, newY));

        // ��ǥ ����
        this->setXY(newX, newY);
    }
}
char Rabbit::get_output() {
    return this->R_output;
}

Rabbit::~Rabbit() {}
