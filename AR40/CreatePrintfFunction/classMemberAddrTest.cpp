
#include <iostream>

int Value = 0;
int Global = 0;

class Player
{
    // ¸É¹öº¯¼ö
public:
    char a;
    char b;
    int Hp;
    char c;
    int Att;
    char d;
    char e;

    void Damage(int _Damage)
    {
        Hp -= _Damage;
    }

    void Jump() {

    }
};

void Func()
{

}

int main()
{
    Player NewPlayer = Player();

    char* a = &NewPlayer.a;
    char* b = &NewPlayer.b;
    int* Hp = &NewPlayer.Hp;
    char* c = &NewPlayer.c;
    int* Att = &NewPlayer.Att;
    char* d = &NewPlayer.d;
    char* e = &NewPlayer.e;

    int Value = int();
}
