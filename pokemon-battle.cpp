#include <iostream>
using namespace std;

// create a class for Moves that has the following properties: name,type,pwr,and acc.
class Moves{
    public:
    string name,type;
    int pwr,acc;
    void setValues(string,string,int,int);
};

// method to set values for Moves class
void Moves::setValues(string moveName, string moveType, int power, int accuracy){
    name = moveName;
    type = moveType;
    pwr = power;
    acc = accuracy;
};

// create a class for Pokemon that has the following properties: name, type, hp, atk, def, spAtk, spDef, and spd
class Pokemon
{
public:
    string name,type;
    int hp,atk,def,spAtk,spDef,spd;
    void setValues(string, string, int, int, int, int, int, int);
};

// method to set values for Pokemon class
void Pokemon::setValues(string pokeName, string pokeType, int health, int attack, int defense, int specialAttack, int specialDefense, int speed){
    name = pokeName;
    type = pokeType;
    hp = health;
    atk = attack;
    def = defense;
    spAtk = specialAttack;
    spDef = specialDefense;
    spd = speed;
};


// declaration function
int main() {
    // create a new instance of the Pokemon class called Typholsion
    Pokemon typholsion;
    // create new instances of the Moves class for the following moves and set their values to the appropriate ones: Flamethrower,Wild Charge,Extrasensory, and Brick Break
    Moves flamethrower,wildCharge,extrasensory,brickBreak;
    flamethrower.setValues("Flamethrower","Fire",90,100);
    wildCharge.setValues("Wild Charge","Electric",90,100);
    extrasensory.setValues("Extrasensory","Psychic",80,100);
    brickBreak.setValues("Brick Break","Fighting",75,100);
    // set typholsion's values to the appropriate ones
    typholsion.setValues("Typhlosion","Fire",322,204,192,254,231,236);
    cout << "Name: " << typholsion.name << "\n";
}