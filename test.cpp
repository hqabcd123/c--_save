#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void menu()
{
    cout << "nep";
}

class character
{
    public:
        character(float Health, float Mana);
        void set_health(float Health);
        void set_mana(float Mana);
        void print_character();

    private:
        float Health = 0.0;
        float Mana = 0.0;
};

character::character(float Health, float Mana)
{
    this->Health = Health;
    this->Mana = Mana;
}

void character::set_health(float Health)
{
    this->Health = Health;
}

void character::set_mana(float Mana)
{
    this->Mana = Mana;
}

void character::print_character()
{
    cout << "Hp: " << Health << endl;
    cout << "Mp: " << Mana << endl;
}

int main()
{
    double min = 100;
    double max = 0;
    //cout << "test" << endl;
    double ran1 = (max-min) * rand() / (RAND_MAX + 1.0) + min;
    double ran2 = (max-min) * rand() / (RAND_MAX + 1.0) + min;
    character cha(ran1, ran2);
    cha.print_character();
    return 1;
}

