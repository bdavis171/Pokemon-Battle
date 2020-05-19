#include <iostream>
using namespace std;

// create a class for Moves that has the following properties: name,type,pwr,and acc.
class Moves
{
public:
    string name, type;
    int pwr, acc;
    void setValues(string, string, int, int);
};

// method to set values for Moves class
void Moves::setValues(string moveName, string moveType, int power, int accuracy)
{
    name = moveName;
    type = moveType;
    pwr = power;
    acc = accuracy;
};

// create a class for Pokemon that has the following properties: name, type, hp, atk, def, spAtk, spDef, and spd
class Pokemon
{
public:
    string name, type;
    int hp, atk, def, spAtk, spDef, spd;
    Moves move1, move2, move3, move4;
    void setValues(string, string, int, int, int, int, int, int, Moves, Moves, Moves, Moves);
    void changeHp(int);
};

// method to set values for Pokemon class
void Pokemon::setValues(string pokeName, string pokeType, int health, int attack, int defense, int specialAttack, int specialDefense, int speed, Moves pokeMove1, Moves pokeMove2, Moves pokeMove3, Moves pokeMove4)
{
    name = pokeName;
    type = pokeType;
    hp = health;
    atk = attack;
    def = defense;
    spAtk = specialAttack;
    spDef = specialDefense;
    spd = speed;
    move1 = pokeMove1;
    move2 = pokeMove2;
    move3 = pokeMove3;
    move4 = pokeMove4;
};

// method to change the pokemon's hp
void Pokemon::changeHp(int newHealth){
    hp = newHealth;
};

// create a function for Typhlosion to use Flamthrower (Move 1)
int useFlamthrower(Pokemon typhlosion, Pokemon blastoise)
{
    // modifier
    float modifier = 0.5;
    // critical hit modifier
    float criticalModifier = 2;
    // possible damage dealt
    int damage = (int)((((2 * 100 / 5) + 2) + 2) * typhlosion.move1.pwr * (typhlosion.spAtk / blastoise.spDef) / 50 + 2)* modifier;
    // calculate accuracy
    int hitChance = (int) rand() % 100 + 1;
    // calculate critical hit
    int criticalChance = (int) rand() % 100 + 1;
    cout << "Typholsion used Flamthrower!" << "\n";
    if (hitChance > typhlosion.move1.acc){
        cout << "The attack missed..." << "\n";
    } else {
        if (criticalChance <= 6){
            damage = damage * criticalModifier;
            cout << "Critical hit!"  << "\n";
        }
        cout << "It's not very effective!" << "damage: " << damage << "\n";
       int damageDealt = blastoise.hp - damage;
       blastoise.changeHp(damageDealt);
        
    }

}

// declaration function
int main()
{
    // create a new instance of the Pokemon class called Typhlosion
    Pokemon typhlosion;

    // create a new instance of the Pokemon class called Blastoise
    Pokemon blastoise;

    // (Typhlosion) create new instances of the Moves class for the following moves and set their values to the appropriate ones: Flamethrower,Wild Charge,Extrasensory, and Brick Break
    Moves flamethrower, wildCharge, extrasensory, brickBreak;
    // (Typhlosion) Move 1
    flamethrower.setValues("Flamethrower", "Fire", 90, 100);
    // (Typhlosion) Move 2
    wildCharge.setValues("Wild Charge", "Electric", 90, 100);
    // (Typhlosion) Move 3
    extrasensory.setValues("Extrasensory", "Psychic", 80, 100);
    // (Typhlosion) Move 4
    brickBreak.setValues("Brick Break", "Fighting", 75, 100);

    // (Blastoise) create new instances of the Moves class for the following moves and set their values to the appropriate ones: Hydro Pump, Dragon Pulse, Flash Cannon, and Dark Pulse
    Moves hydroPump, dragonPulse, flashCannon, darkPulse;
    // (Blastoise) Move 1
    hydroPump.setValues("Hydro Pump", "Water", 110, 80);
    // (Blastoise) Move 2
    dragonPulse.setValues("Dragon Pulse", "Dragon", 85, 100);
    // (Blastoise) Move 3
    flashCannon.setValues("Flash Cannon", "Steel", 80, 100);
    // (Blastoise) Move 4
    darkPulse.setValues("Dark Pulse", "Dark", 80, 100);

    // set typhlosion's values to the appropriate ones
    typhlosion.setValues("Typhlosion", "Fire", 322, 204, 192, 254, 231, 236, flamethrower, wildCharge, extrasensory, brickBreak);

    // set blastoise's values to the appropriate ones
    blastoise.setValues("Blastoise","Water",299,171,236,206,246,192,hydroPump,dragonPulse,flashCannon,darkPulse);

    // get the original hp for both pokemon each
    int typhlosionOriginHp = typhlosion.hp;
    int blastoiseOriginHp = blastoise.hp;

    useFlamthrower(typhlosion,blastoise);
    cout << blastoise.hp << "/" << blastoiseOriginHp << "\n";
    
}