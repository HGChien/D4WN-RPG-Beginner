//李潔妮 110916008 Janie
//羅楠凱 110916037 Kevin
//王承吉 110916038 Gemini
//簡郁桓 110916039 Hugo

//大家都有修改跟平衡，所以只有寫主要負責人!工作有平均分配，讚讚!

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <climits>
#include <ctime>
#include <conio.h>

#define DECLARE_GET_FUNCTION(func_name, var_type, var_name)\
var_type Get##func_name##()\
{\
	return this->var_name;\
}

#define DECLARE_SET_GET_FUNCTION_NUM(func_name, var_type, var_name)\
        void Set##func_name##(var_type  var_name)\
{\
	this->var_name += var_name;\
}\
DECLARE_GET_FUNCTION(func_name, var_type, var_name)

using namespace std;

class Player;
class Monster;

template<typename T>
class CallBack
{
public:
	void (T::* function)(T*);

	explicit CallBack(void (T::* func)(T*)) { function = func; }
};

class C_Check //Hugo
{
public:
	C_Check() {}
	virtual ~C_Check() {}

	void Menu(int iNum, int iLayer) {
		string sSelect[17];
		string sLayerName[4] = { "Novice Area", "Silent Hill", "NeverLand", "#$%*()(*&^%$" };
		for (int i = 0; i < 17; i++)
		{
			sSelect[i] = " ";
		}
		sSelect[iNum] = "＞";
		cout << "\nLayer " << iLayer <<" < " + sLayerName[iLayer - 1] + " >" << endl;
		cout << "\n════════ What do you want to do ════════\n" << endl;
		cout << left << setw(22) << sSelect[0] + "  Read Introduction"
			<< left << setw(22) << sSelect[1] + "  Shop" << endl;
		cout << left << setw(22) << sSelect[2] + "  Show Profile"
			<< left << setw(22) << sSelect[3] + "  My Inventory" << endl;
		cout << left << setw(22) << sSelect[4] + "  Hunt Monster "
			<< left << setw(22) << sSelect[5] + "  Craft Equipment" << endl;
		cout << left << setw(22) << sSelect[6] + "  Adventure "
			<< left << setw(22) << sSelect[7] + "  Chop Tree" << endl;
		cout << left << setw(22) << sSelect[8] + "  Dungeon"
			<< left << setw(22) << sSelect[9] + "  Fishing" << endl;
		cout << left << setw(22) << sSelect[10]  + "  Heal"
			<<  left << setw(22) << sSelect[11] + "  Mining" << endl;
		cout << left << setw(22) << sSelect[12] + "  Enchant"
			<< left << setw(22) << sSelect[13] + "  Pet" << endl;
		cout << left << setw(22) << sSelect[14] + "  Move" 
			<< left << setw(22) << sSelect[15] + "  Training" << endl;
		cout << "\n════════════════════════════════════════" << endl;
		cout << left << setw(22) << sSelect[16] + "  Left" << endl;
		cout << "════════════════════════════════════════" << endl;
	}

	int SelectMenu(int iLayer,int iSelect = 0)
	{
		int iState = iSelect;
		while (1)
		{
			Menu(iState, iLayer);
			int iGetKey = _getch();
			if (iGetKey == 224)
			{
				switch (_getch())
				{
				case 72://up
					if (iState == 0 || iState == 1)
						iState = 16;
					else
						iState = (iState - 2) > -1 ? iState - 2 : iState;
					break;
				case 80://down
					if (iState == 15)
						iState = 16;
					else if (iState == 16)
						iState = 0;
					else
						iState = (iState + 2) < 17 ? iState + 2 : iState;
					break;
				case 75://left
					iState = (iState - 1) % 2 ? iState : iState - 1;
					break;
				case 77://right
					iState = (iState + 1) % 2 ? iState + 1 : iState;
					break;
				}
			}
			else
				if (iGetKey == 13)
				{
					if (iState == 16)
						return 0;
					return iState + 1;
				}
			system("cls");
		}
	}
};

class C_Bag //Hugo
{
private:
	int iCoin;
	int iWood;
	int iFish;
	int iRuby;
	int iWolfSkin;
	int iZombieEye;
	int iUnicornHorn;
	int iMermaidHair;
	int iLifePotion;
	int iDungeonKey;

public:
	C_Bag()
		:iCoin(0), iWood(0), iFish(0), iRuby(0), iWolfSkin(0), iZombieEye(0), iUnicornHorn(0),
		iMermaidHair(0), iLifePotion(0), iDungeonKey(0) {}
	virtual ~C_Bag() {}
	DECLARE_SET_GET_FUNCTION_NUM(Coin, int, iCoin);
	DECLARE_SET_GET_FUNCTION_NUM(Wood, int, iWood);
	DECLARE_SET_GET_FUNCTION_NUM(Fish, int, iFish);
	DECLARE_SET_GET_FUNCTION_NUM(Ruby, int, iRuby);
	DECLARE_SET_GET_FUNCTION_NUM(WolfSkin, int, iWolfSkin);
	DECLARE_SET_GET_FUNCTION_NUM(ZombieEye, int, iZombieEye);
	DECLARE_SET_GET_FUNCTION_NUM(MermaidHair, int, iMermaidHair);
	DECLARE_SET_GET_FUNCTION_NUM(UnicornHorn, int, iUnicornHorn);
	DECLARE_SET_GET_FUNCTION_NUM(LifePotion, int, iLifePotion);
	DECLARE_SET_GET_FUNCTION_NUM(DungeonKey, int, iDungeonKey);

	void ShowBag()
	{
		cout << "═════ MY INVENTORY ═════\n" << endl;
		cout << left << setw(14) << "Coin" << iCoin << endl;
		if (iWood != 0)
			cout << left << setw(14) << "Wood" << iWood << endl;
		if (iFish != 0)
			cout << left << setw(14) << "Fish" << iFish << endl;
		if (iRuby != 0)
			cout << left << setw(14) << "Ruby" << iRuby << endl;
		if (iWolfSkin != 0)
			cout << left << setw(14) << "Wolf Skin" << iWolfSkin << endl;
		if (iZombieEye != 0)
			cout << left << setw(14) << "Zombie Eye" << iZombieEye << endl;
		if (iUnicornHorn != 0)
			cout << left << setw(14) << "Unicorn Horn" << iUnicornHorn << endl;
		if (iMermaidHair != 0)
			cout << left << setw(14) << "Mermaid Hair" << iMermaidHair << endl;
		if (iLifePotion != 0)
			cout << left << setw(14) << "LifePotion" << iLifePotion << endl;
		if (iDungeonKey != 0)
			cout << left << setw(14) << "Dungeon Key" << iDungeonKey << endl;
	}
};

class Character //Gemini
{
protected:
	int hp;
	int maxHp;
	int attack;
	int defence;
	int roundDamage;
	int roundDefend;
	vector<CallBack<Character>> actions;

	virtual void actionAttack(Character* other)
	{
		cout << "you choose attack" << endl;
	}

	virtual void actionDefence(Character* other)
	{
		cout << "you choose defence" << endl;
	}

	virtual void actionSkill(Character* other)
	{
		cout << "you choose special attack" << endl;
	}

public:
	Character(int hp, int atk, int dfc)
	{
		this->hp = hp;
		this->maxHp = hp;
		this->attack = atk;
		this->defence = dfc;
		this->roundDamage = 0;
		this->roundDefend = 0;

		CallBack<Character> action1(&Character::actionAttack);
		CallBack<Character> action2(&Character::actionDefence);
		CallBack<Character> action3(&Character::actionSkill);
		actions.push_back(action1);
		actions.push_back(action2);
		actions.push_back(action3);
	}
	~Character() = default;

	int GetHP() { return hp; }
	int GetMaxHP() { return maxHp; }
	void SetATK(int atk) { attack = atk; }
	int GetATK() { return attack; }
	int GetDEF() { return defence; }
	int GetRoundDamage() { return roundDamage; }
	void Heal(int Hp) 
	{
		hp += Hp;
		if ((Hp == -1)||(hp>maxHp))
			hp = maxHp;
	}

	void damaged(int damage) { roundDamage += damage; }

	void defended(int defend) { roundDefend += defend; }

	void enhanceHp(int hp) { this->hp += hp; }

	void enhanceAtk(int atk) { this->attack += atk; }

	void enhanceDfc(int dfc) { this->defence += dfc; }

	virtual void showInfo() {}

	// function doAction is very important and will take the desired action for user.
	virtual void doAction(int action, Character* other)
	{
		// This command will call function among the above three action function
		(this->*(actions[action - 1].function))(other);
	}

	virtual bool isAlive() { return hp > 0; }

	virtual void computeRoundResult()
	{
		int trueDamage = roundDamage - roundDefend;
		trueDamage = ((trueDamage) < 0) ? 0 : trueDamage;
		cout << "get " << trueDamage << " damage" << endl;
		hp -= trueDamage;
		roundDamage = 0;
		roundDefend = 0;
	}
};

class C_Equipment //Hugo
{
protected:
	int iAtk;
	int iDfc;
	int iHp;
	string sName;
public:
	C_Equipment(int hp = 0, int atk = 0, int dfc = 0, string name = "")
	{
		iAtk = atk;
		iDfc = dfc;
		iHp = hp;
		sName = name;
	}
	virtual ~C_Equipment() = default;

	virtual void fightEffect(Player* player, Monster* monster) {}
	virtual void resultEffect(Player* player, Monster* monster) {}
	virtual void EffectDescription(){}
	
	int GetAtk() { return iAtk; }
	int GetDfc() { return iDfc; }
	int GetHp() { return iHp; }
	string GetName() { return sName; }
};

class Player : public Character //Gemini
{
private:
	vector<C_Equipment*> playerArmor;
	vector<C_Equipment*> playerSword;

protected:
	int iLayer;
	int iMaxLayer;
	int lvl;
	int exp;
	int maxExp;
	string sName;
	C_Equipment* Armor;
    C_Equipment* Sword;
	C_Bag* Bag;

	void actionAttack(Character* other) override
	{
		cout << sName << " choose attack" << endl;
		other->damaged(attack);
		this->defended(defence);
	}

	void actionDefence(Character* other) override
	{
		cout << sName << " choose defence and heal some Hp" << endl;
		this->defended(defence);
		this->Heal((int)(defence * 0.2));
	}

public:
	Player(int hp, int atk, int dfc)
		: Character(hp, atk, dfc), lvl(1), exp(0), Armor(NULL), Sword(NULL), sName("")
	{
		Bag = new C_Bag;
		roundDefend = dfc;
		iLayer = 1;
		iMaxLayer = iLayer;
		StatusChange();
	}
	~Player() = default;

	void showInfo() override
	{
		string sExp = to_string(exp) + "/" + to_string(maxExp);
		string sHp = to_string(hp) + "/" + to_string(maxHp);
		cout << "  " << left << setw(9) << "Player" << left << setw(11) << sName << endl;
		cout << "  " << left << setw(9) << "Lv" << left << setw(11) << lvl << endl;
		cout << "  " << left << setw(9) << "Exp" << left << setw(11) << sExp << endl;
		cout << "  " << left << setw(9) << "Hp/MaxHp" << left << setw(11) << sHp << endl;
		cout << "  " << left << setw(9) << "Attack" << left << setw(11) << attack << endl;
		cout << "  " << left << setw(9) << "Defence" << left << setw(11) << defence << endl;
		cout << "  " << left << setw(9) << "Layer" << left << setw(11) << iLayer << endl;
	}

	void StatusChange()
	{
		maxExp = (int)(lvl * sqrt(lvl) * 100);
		maxHp = lvl * 15 + 85;
		hp = maxHp;
		attack = lvl + 2;
		if (sName == "Hugo")
			attack = attack * 100;
		defence = lvl + 2;
		if (NULL != Armor)
			SetArmor(Armor);
		if (NULL != Sword)
			SetSword(Sword);
	}

	virtual void ExpUp(int Exp)
	{

		if (sName == "Hugo")
			Exp = Exp * 10;
		exp += Exp;
		while (exp >= maxExp)
		{
			exp -= maxExp;
			lvl++;
			cout << "\a  level up!!!" << endl;
			StatusChange();
		}
	}

	void LevelDown()
	{
		if (sName != "滅罪真紅")
		{
			if (lvl != 1)
			{
				lvl--;
				StatusChange();
			}
			exp = 0;
		}
		hp = maxHp;
	}

	int GetMaxExp() { return maxExp; }
	int GetLevel() { return lvl; }
	int GetExp() { return exp; }

	void SetName() 
	{ 
		while (1)
		{
			cout << "\n\t\tWhat's your name?" << endl;
			cout << "\t\t->";
			getline(cin, sName);
			if (sName != "")
			{
				if (sName == "Janie")
				{
					lvl = 50;
					StatusChange();
				}
				if (sName == "Hugo")
					attack = (lvl + 2) * 100;
				break;
			}
			system("cls");
		}
	}

	string GetName() { return sName; }
	C_Equipment* GetArmor() { return Armor; }
	C_Equipment* GetSword() { return Sword; }
	C_Bag* GetBag() { return Bag; }

	void SetMaxLayer(int iNum) { iMaxLayer = iNum; }
	void SetCurrentLayer(int iNum) { iLayer = iNum; }
	int GetMaxLayer() { return iMaxLayer; }
	int GetCurrentLayer() { return iLayer; }

	void BoostHeal(int amount) { hp += amount; }

	void SetArmor(C_Equipment* armor)
	{
		if (NULL != Armor && armor != Armor)
		{
			hp -= Armor->GetHp();
			attack -= Armor->GetAtk();
			defence -= Armor->GetDfc();
			maxHp -= Armor->GetHp();
		}
		Armor = armor;
		hp += Armor->GetHp();
		attack += Armor->GetAtk();
		defence += Armor->GetDfc();
		maxHp += Armor->GetHp();
	}

	void SetSword(C_Equipment* sword)
	{
		if (NULL != Sword && sword != Sword)
		{
			hp -= Sword->GetHp();
			attack -= Sword->GetAtk();
			defence -= Sword->GetDfc();
			maxHp -= Sword->GetHp();
		}
		Sword = sword;
		hp += Sword->GetHp();
		attack += Sword->GetAtk();
		defence += Sword->GetDfc();
		maxHp += Sword->GetHp();
	}

	void PrintArmor()
	{
		cout << "  " << Armor->GetName() << endl;
		cout << "  " << left << setw(3) << " " << "Effect" << endl;
		if (Armor->GetAtk() != 0)
			cout << "  " << setw(6) << " " << left << setw(14) << "enhanced ATK " << setw(3) << Armor->GetAtk() << endl;
		if (Armor->GetDfc() != 0)
			cout << "  " << setw(6) << " " << left << setw(14) << "enhanced DEF " << setw(3) << Armor->GetDfc() << endl;
		if (Armor->GetHp() != 0)
			cout << "  " << setw(6) << " " << left << setw(14) << "enhanced HP " << setw(3) << Armor->GetHp() << endl;
		for (auto& equip : playerArmor)
		{
			cout << "  " << left << setw(3) << " " << "Special Effect" << endl;
			cout << "  " << setw(6) << " ";
			equip->EffectDescription();
			break;
		}
	}

	void PrintSword()
	{
		cout << "  " << Sword->GetName() << endl;
		cout << "  " << left << setw(3) << " " << "Effect" << endl;
		if (Sword->GetAtk() != 0)
			cout << "  " << setw(6) << " " << left << setw(14) << "enhanced ATK " << setw(3) << Sword->GetAtk() << endl;
		if (Sword->GetDfc() != 0)
			cout << "  " << setw(6) << " " << left << setw(14) << "enhanced DEF " << setw(3) << Sword->GetDfc() << endl;
		if (Sword->GetHp() != 0)
			cout << "  " << setw(6) << " " << left << setw(14) << "enhanced HP " << setw(3) << Sword->GetHp() << endl;
		for (auto& equip : playerSword)
		{
			cout << "  " << left << setw(3) << " " << "Special Effect" << endl;
			cout << "  " << setw(6) << " ";
			equip->EffectDescription();
		}
	}

	/* This method is trying to iteratively launch the equipment effect
		* If you don't understand the code inside the method, please don't modify it*/
	void launchArmorfightEffect(Monster* monster)
	{
		for (auto& equip : playerArmor)
		{
			equip->fightEffect(this, monster);
		}
	}

	void launchArmorresultEffect(Monster* monster)
	{
		for (auto& equip : playerArmor)
		{
			equip->resultEffect(this, monster);
		}
	}

	void launchSwordfightEffect(Monster* monster)
	{
		for (auto& equip : playerSword)
		{
			equip->fightEffect(this, monster);
		}
	}

	void launchSwordresultEffect(Monster* monster)
	{
		for (auto& equip : playerSword)
		{
			equip->resultEffect(this, monster);
		}
	}

	/* This method is used to equip the equipment*/
	void equipArmor(C_Equipment* equipment)
	{
		playerArmor.push_back(equipment);
	}

	void equipSword(C_Equipment* equipment)
	{
		playerSword.push_back(equipment);
	}

	void VanishSword()
	{
		playerSword.pop_back();
	}

	void VanishArmor()
	{
		playerArmor.pop_back();
	}

	void DeleteSword() 
	{
		delete Sword;
		Sword = NULL;
	}
	void DeleteArmor() 
	{ 
		delete Armor;
		Armor = NULL;
	}
};

class Monster : public Character //Gemini
{
protected:
	string MonsterName;
	string name[3];
	int iExp;
	int iCoin;

	void actionAttack(Character* other) override
	{
		cout << "Monster attack" << endl;
	}

	void actionDefence(Character* other) override
	{
		cout << "Monster defence" << endl;
	}

public:
	Monster(int hp, int atk, int dfc) : Character(hp, atk, dfc), iCoin(0), iExp(0) { srand(time(NULL)); }
	~Monster() = default;

	void showInfo() override
	{
		cout << left << setw(9) << "Monster" << left << setw(11) << MonsterName << endl;
		cout << left << setw(9) << "hp" << left << setw(11) << hp << endl;
		cout << left << setw(9) << "attack" << left << setw(11) << attack << endl;
		cout << left << setw(9) << "defence" << left << setw(11) << defence << endl;
	}

	virtual void selectAction(Character* other)
	{
		int validActions = 2;
		int action = rand() % validActions + 1;
		this->doAction(action, other);
	}

	int GetExp() { return iExp; }
	int GetCoin() { return iCoin; }
	string GetName() { return MonsterName; }

	virtual void reward(Player* player) {}
};

class C_Shop //Hugo //Shop Keeper:Janie 
{
public:
	void Menu(C_Bag* Bag, int iNum)
	{
		string sSelect[8];
		for (int i = 0; i < 8; i++)
		{
			sSelect[i] = "  ";
		}
		sSelect[iNum] = "＞ ";
		cout << "══════════ Welcome to D4wn Shop ═══════════ Your Coin: " << Bag->GetCoin() << endl;
		cout << "\n════════ BUY ═══════════════════════════════════════════════════\n" << endl;
		cout << left << setw(18) << "Item" << left << setw(40) << "Description" << left << setw(8) << "Price" << left << setw(8) <<"I HAVE"<< endl;
		cout << sSelect[0] << left << setw(16) << "Life Potion" << left << setw(40) << "Restore your HP with Heal" << left << setw(8) <<"  25" << right << setw(8) <<Bag->GetLifePotion()<< endl;
		cout << sSelect[1] << left << setw(16) << "Basic Armor" << left << setw(40) << "An ungly armor made of wood" << left << setw(8) << "  200" << endl;
		cout << sSelect[2] << left << setw(16) << "Basic Sword" << left << setw(40) << "Better than nothing huh?" << left << setw(8) << "  150" << endl;
		cout << sSelect[3] << left << setw(16) << "Life Boost A" << left << setw(40) << "+10HP(one time use and not stackable)" << left << setw(8) << "  1000" << endl;
		cout << sSelect[4] << left << setw(16) << "Life Boost B" << left << setw(40) << "+25HP(one time use and not stackable)" << left << setw(8) << "  2500" << endl;
		cout << sSelect[5] << left << setw(16) << "Life Boost C" << left << setw(40) << "+50HP(one time use and not stackable)" << left << setw(8) << "  4500" << endl;
		cout << sSelect[6] << left << setw(16) << "Dungeon Key" << left << setw(40) << "You need this key to enter the Dungeon" << left << setw(8) << "  5000" << right << setw(8) <<Bag->GetDungeonKey()<< endl;
		cout << "\n════════════════════════════════════════════════════════════════" << endl; 
		cout << sSelect[7] << left << setw(16) << "Left" << endl;
		cout << "════════════════════════════════════════════════════════════════" << endl;
	}

	int SelectMenu(C_Bag* Bag, int iSelect = 0)
	{
		int iState = iSelect;
		while (1)
		{
			Menu(Bag, iState);
			int iGetKey = _getch();
			if (iGetKey == 224)
			{
				switch (_getch())
				{
				case 72://up
					if (iState == 0)
						iState = 7;
					else
						iState = (iState - 1) > -1 ? iState - 1 : iState;
					break;
				case 80://down
					if (iState == 7)
						iState = 0;
					else
						iState = (iState + 1) < 8 ? iState + 1 : iState;
					break;
				}
			}
			else
				if (iGetKey == 13)
				{
					if (iState == 7)
						return 0;
					return iState + 1;
				}
			system("cls");
		}
	}

	bool JanietheShopKeeper(Player* player, C_Bag* Bag)
	{
		if (player->GetLevel() <= 10)
		{
			return false;
		}
		else
		{
			int iRate = rand() % 101;
			int iThief = (int)(sqrt(player->GetLevel() - 10) * 1.5);
			int iAmount;
			if (iRate <= iThief)
			{
				cout << "Janie the Shop Keeper appears~ ";
				int iRand = rand() % 9 + 1;
				switch (iRand)
				{
				case 1:
					if (Bag->GetCoin() > 0)
					{
						iAmount = (int)(ceil(Bag->GetCoin() / 100));
						Bag->SetCoin(-iAmount);
						cout << "Stealing" << iAmount << " Coin from you" << endl;
					}
					break;
				case 2:
					if (Bag->GetWood() > 0)
					{
						iAmount = (int)(ceil(Bag->GetCoin() / 100));
						Bag->SetWood(-iAmount);
						cout << "Stealing" << iAmount << " Wood from you" << endl;
					}
					break;
				case 3:
					if (Bag->GetFish() > 0)
					{
						iAmount = (int)(ceil(Bag->GetFish() / 100));
						Bag->SetFish(-iAmount);
						cout << "Stealing" << iAmount << " Fish from you" << endl;
					}
					break;
				case 4:
					if (Bag->GetRuby() > 0)
					{
						iAmount = (int)(ceil(Bag->GetRuby() / 100));
						Bag->SetRuby(-iAmount);
						cout << "Stealing" << iAmount << " Ruby from you" << endl;
					}
					break;
				case 5:
					if (Bag->GetLifePotion() > 0)
					{
						iAmount = (int)(ceil(Bag->GetLifePotion() / 100));
						Bag->SetLifePotion(-iAmount);
						cout << "Stealing" << iAmount << " Life Potion from you" << endl;
					}
					break;
				case 6:
					if (Bag->GetWolfSkin() > 0)
					{
						iAmount = (int)(ceil(Bag->GetWolfSkin() / 100));
						Bag->SetWolfSkin(-iAmount);
						cout << "Stealing" << iAmount << " Wolf Skin from you" << endl;
					}
					break;
				case 7:
					if (Bag->GetZombieEye() > 0)
					{
						iAmount = (int)(ceil(Bag->GetZombieEye() / 100));
						Bag->SetZombieEye(-iAmount);
						cout << "Stealing" << iAmount << " ZombieEye from you" << endl;
					}
					break;
				case 8:
					if (Bag->GetUnicornHorn() > 0)
					{
						iAmount = (int)(ceil(Bag->GetUnicornHorn() / 100));
						Bag->SetUnicornHorn(-iAmount);
						cout << "Stealing" << iAmount << " UnicornHorn from you" << endl;
					}
					break;
				case 9:
					if (Bag->GetMermaidHair() > 0)
					{
						iAmount = (int)(ceil(Bag->GetMermaidHair() / 100));
						Bag->SetMermaidHair(-iAmount);
						cout << "Stealing" << iAmount << " MermaidHair from you" << endl;
					}
					break;
				}
				cout << "Janie also steal your heart <3" << endl;
			}
			return true;
		}
	}

	void Buy(int item, C_Bag* Bag, Player* player)
	{
		C_Equipment* armor = NULL;
		C_Equipment* sword = NULL;
		cout << "\n";
		switch (item)
		{
		case 1://life potion
			if (Bag->GetCoin() >= 25)
			{
				cout << "You successfully buy one life potion" << endl;
				Bag->SetLifePotion(1);
				Bag->SetCoin(-25);
			}
			else
				cout << "You DON'T have enough money QQ" << endl;
			break;
		case 2://basic armor
			armor = player->GetArmor();
			if (NULL != armor)
			{
				cout << "You already have an armor" << endl;
				break;
			}
			if (Bag->GetCoin() >= 200)
			{
				cout << "You successfully buy one basic armor" << endl;
				//put on player armor
				Bag->SetCoin(-200);
				C_Equipment* BasicArmor = new C_Equipment(0, 0, 1, "Basic Armor");
				player->SetArmor(BasicArmor);
			}
			else
				cout << "You DON'T have enough money QQ" << endl;
			break;
		case 3://basic sword
			sword = player->GetSword();
			if (NULL != sword)
			{
				cout << "You already have a sword" << endl;
				break;
			}
			if (Bag->GetCoin() >= 150)
			{
				cout << "You successfully buy one basic sword" << endl;
				//put on player sword
				Bag->SetCoin(-150);
				C_Equipment* BasicSword = new C_Equipment(0, 1, 0, "Basic Sword");
				player->SetSword(BasicSword);
			}
			else
				cout << "You DON'T have enough money QQ" << endl;
			break;
		case 4://life boost A
			if (player->GetHP() > player->GetMaxHP())
			{
				cout << "How dare you. Your hp is already above max!" << endl;
			}
			else if (Bag->GetCoin() >= 1000)
			{
				cout << "You successfully buy life boost A" << endl;
				Bag->SetCoin(-1000);
				player->BoostHeal(10);
			}
			else
				cout << "You DON'T have enough money QQ" << endl;
			break;
		case 5://life boost B
			if (player->GetHP() > player->GetMaxHP())
			{
				cout << "How dare you. Your hp is already  above max!" << endl;
			}
			else if (Bag->GetCoin() >= 2500)
			{
				cout << "You successfully buy life boost B" << endl;
				Bag->SetCoin(-2500);
				player->BoostHeal(25);
			}
			else
				cout << "You DON'T have enough money QQ" << endl;
			break;
		case 6://life boost C
			if (player->GetHP() > player->GetMaxHP())
			{
				cout << "How dare you. Your hp is already above max!" << endl;
			}
			else if (Bag->GetCoin() >= 4500)
			{
				cout << "You successfully buy life boost C" << endl;
				Bag->SetCoin(-4500);
				player->BoostHeal(50);
			}
			else
				cout << "You DON'T have enough money QQ" << endl;
			break;
		case 7://dungeon key
			if (Bag->GetCoin() >= 5000)
			{
				if (Bag->GetDungeonKey() == 1) 
				{
					cout << "You already have a dungeon key" << endl;
					break;
				}
				cout << "You successfully buy one Dungeon key" << endl;
				Bag->SetDungeonKey(1);
				Bag->SetCoin(-5000);
			}
			else
				cout << "You DON'T have enough money QQ" << endl;
			break;
		default:
			cout << "\nWrong input! Press ENTER to select again.\n" << endl;
		}
	}
};

class C_UnicornSword : public C_Equipment //Kevin
{
public:
	void fightEffect(Player* player, Monster* monster)override
	{
		cout << "haha ";
		if ((player->GetHP()) >= (player->GetMaxHP()))
		{
			EffectDescription();
			monster->damaged(monster->GetRoundDamage());
		}
	}

	void EffectDescription()override
	{
		cout << "When I have full HP or more, my ATTACJ become TWICE stronger." << endl;
	}
};

class C_RubySword : public C_Equipment //Kevin
{
	void resultEffect(Player* player, Monster* monster)override
	{
		player->ExpUp(monster->GetExp());
		cout << "Get Extra" << monster->GetExp() << " Exp from Monster~" << endl;
	}

	void EffectDescription()override
	{
		cout << "Get Extra Exp from Monster~" << endl;
	}
};

class C_CoinArmor : public C_Equipment//Kevin
{
	void resultEffect(Player* player, Monster* monster)override
	{
		player->GetBag()->SetCoin(monster->GetCoin());
		cout << "Get Extra" << monster->GetCoin() << " Coin from Monster~" << endl;
	}

	void EffectDescription()override
	{
		cout << "Get Extra Coin from Monster~" << endl;
	}
};

class C_MermaidArmor : public C_Equipment//Kevin
{
	void fightEffect(Player* player, Monster* monster)override
	{
		monster->damaged(player->GetATK());
		cout << "Mermaid Armor's Passive Effect" << endl;
		cout << left << setw(3) << " " << "Done " << player->GetATK() << " damages" << endl;
	}

	void EffectDescription()override
	{
		cout << "Extra ATTACK~" << endl;
	}
};

class C_Craft //Hugo
{
private:
	int iCountS;
	int iCountA;
	C_Equipment* equipment;

public:
	C_Craft()
		:iCountS(0), iCountA(0), equipment(NULL)
	{}
	virtual~C_Craft(){}

	void SetCountS(int iNum) { iCountS = iNum; }
	void SetCountA(int iNum) { iCountS = iNum; }
	int GetCountS() { return iCountS; }
	int GetCountA() { return iCountA; }

	void CraftTable(int iNum)
	{
		string sSelect[11];
		string sEffect[10] = {"None","None", "None", "None", "None", "None", "Extra XP from Monsters","Extra Coin from Monsters"
			,"When I have full HP or more, my ATTACK become TWICE stronger","Extra ATTACK"};
		for (int i = 0; i < 11; i++)
		{
			sSelect[i] = " ";
		}
		sSelect[iNum] = "＞";
		cout << "\n════ Craft Table ══════════════════════════════════════════════════════════════════════════════════════════\n" << endl;
		cout << left << setw(27) << "Sword" << left << setw(25) << "item it need"
			 << " ■ " << left << setw(27) << "Armor" << left << setw(25) << "item it need" << endl;
		cout << left << setw(27) << sSelect[0] + " Wooden Sword(4 ATK) " << left << setw(25) << "40 woods" << " ■ "
			 << left << setw(27) << sSelect[1] + " Fish Armor(9 DEF)"  << left << setw(25) << "20 fish & 10 woods" << endl;
		cout << left << setw(27) << sSelect[2] + " Fish Sword(13 ATK)" << left << setw(25) << "20 fish & 125 woods" << " ■ "
			 << left << setw(27) << sSelect[3] + " Wolf Armor(20 DEF)" << left << setw(25) << "20 wolf skins & 170 woods" << endl;
		cout << left << setw(27) << sSelect[4] + " Zombie Sword(43 ATK)" << left << setw(25) << "40 zombieeye & 980 woods" << " ■ "
			<< left << setw(27) << sSelect[5] + " Coin Armor(42 DEF)" << left << setw(25) << "1500 fish & 3125 woods " << endl;
		cout << left << setw(27) << sSelect[6] + " Ruby Sword(82 ATK)" << left << setw(25) << "40 ruby & 2500 woods" << " ■ "
			<< left << setw(27) << sSelect[7] + " Epic Armor(82 DEF)" << left << setw(25) << "321123 coin & 5000 woods" << endl;
		cout << left << setw(27) << sSelect[8] + " Unicorn Sword(96 ATK)" << left << setw(25) << "50 unicornhorn " << " ■ "
			 << left << setw(27) << sSelect[9] + " Mermaid Armor(96 DEF)" << left << setw(25) << "75 mermaidhair " << endl;
		cout << left << setw(27) << " " << left << setw(25) << "& 500 fish & 2500 woods" << " ■ "
			<< left << setw(27) << " " << left << setw(25) << "& 1650 fish & 10000 woods" << endl;
		cout << "\n════ Effect ═══════════════════════════════════════════════════════════════════════════════════════════════\n" << endl;
		if (iNum < 10)
			cout << "  " << sEffect[iNum];
		cout << "\n\n═══════════════════════════════════════════════════════════════════════════════════════════════════════════" << endl;
		cout << sSelect[10] << " Left" << endl;
		cout << "═══════════════════════════════════════════════════════════════════════════════════════════════════════════" << endl;
	}

	int SelectMenu(C_Bag* Bag, int iSelect = 0)
	{
		int iState = iSelect;
		while (1)
		{
			Bag->ShowBag();
			CraftTable(iState);
			int iGetKey = _getch();
			if (iGetKey == 224)
			{
				switch (_getch())
				{
				case 72://up
					if (iState == 0 || iState == 1)
						iState = 10;
					else
						iState = (iState - 2) > -1 ? iState - 2 : iState;
					break;
				case 80://down
					if (iState == 10)
						iState = 0;
					else if (iState == 9)
						iState = 10;
					else
						iState = (iState + 2) < 11 ? iState + 2 : iState;
					break;
				case 75://left
					iState = (iState - 1) % 2 ? iState : iState - 1;
					break;
				case 77://right
					if (iState == 10)
						break;
					iState = (iState + 1) % 2 ? iState + 1 : iState;
					break;
				}
			}
			else
				if (iGetKey == 13)
				{
					if (iState == 10)
						return 0;
					return iState + 1;
				}
			system("Cls");
		}
	}

	bool CheckSword(Player* player, int item)
	{
		if (NULL != (player->GetSword()))
		{
			string sAns;
			int iState = 0;
			string sSelect[2];
			while (1)
			{
				for (int i = 0; i < 2; i++)
				{
					sSelect[i] = " ";
				}
				sSelect[iState] = "＞";
				cout << "You already have a Sword.\nDo you want to replace it?" << endl;
				cout << sSelect[0] << "YES" << endl;
				cout << sSelect[1] << "NO" << endl;
				int iGetKey = _getch();
				if (iGetKey == 224)
				{
					switch (_getch())
					{
					case 72://up
						iState = (iState - 1) > -1 ? iState - 1 : iState;
						break;
					case 80://down
						iState = (iState + 1) < 2 ? iState + 1 : iState;
						break;
					}
				}
				else
					if (iGetKey == 13)
					{
						if (iState == 0)
						{
							if (iCountS > 0)
							{
								player->VanishSword();
								delete equipment;
								iCountS--;
							}
							player->DeleteSword();
							return true;
						}
						if (iState == 1)
							return false;
					}
				system("Cls");
				player->GetBag()->ShowBag();
				CraftTable(item-1);
				cout << "\n";
			}
		}
		return true;
	}

	bool CheckArmor(Player* player, int item)
	{
		if (NULL != (player->GetArmor()))
		{
			string sAns;
			int iState = 0;
			string sSelect[2];
			while (1)
			{
				for (int i = 0; i < 2; i++)
				{
					sSelect[i] = " ";
				}
				sSelect[iState] = "＞";
				cout << "You already have a Armor.\n\nDo you want to replace it?" << endl;
				cout << sSelect[0] << "YES" << endl;
				cout << sSelect[1] << "NO" << endl;
				int iGetKey = _getch();
				if (iGetKey == 224)
				{
					switch (_getch())
					{
					case 72://up
						iState = (iState - 1) > -1 ? iState - 1 : iState;
						break;
					case 80://down
						iState = (iState + 1) < 2 ? iState + 1 : iState;
						break;
					}
				}
				else
					if (iGetKey == 13)
					{
						if (iState == 0)
						{
							if (iCountA > 0)
							{
								player->VanishArmor();
								delete equipment;
								iCountA--;
							}
							player->DeleteArmor();
							return true;
						}
						if (iState == 1)
							return false;
					}
				system("Cls");
				player->GetBag()->ShowBag();
				CraftTable(item-1);
				cout << "\n";
			}
		}
		return true;
	}

	void Crafting(int item, C_Bag* Bag, Player* player)
	{
		cout << "\n";
		switch (item)
		{
		case 0:
			break;
		case 1://wooden sword
			if (CheckSword(player, item))
			{
				if (Bag->GetWood() >= 40)
				{
					cout << "You successfully craft a Wooden Sword" << endl;
					Bag->SetWood(-40);
					C_Equipment* WoodenSword = new C_Equipment(0, 4, 0, "Wooden Sword");
					player->SetSword(WoodenSword);
				}
				else
					cout << "You DON'T have enough items QQ" << endl;
			}
			break;
		case 3://fish sword
			if (CheckSword(player, item))
			{
				if ((Bag->GetWood() >= 125) && (Bag->GetFish() >= 20))
				{
					cout << "You successfully craft a Fish Sword" << endl;
					Bag->SetWood(-125);
					Bag->SetFish(-20);
					C_Equipment* FishSword = new C_Equipment(0, 13, 0, "Fish Sword");
					player->SetSword(FishSword);
				}
				else
					cout << "You DON'T have enough items QQ" << endl;
			}
			break;
		case 5://zombie sword
			if (CheckSword(player, item))
			{
				if ((Bag->GetWood() >= 900) && (Bag->GetZombieEye() >= 40))
				{
					cout << "You successfully craft a Zombie Sword" << endl;
					Bag->SetWood(-900);
					Bag->SetZombieEye(-40);
					C_Equipment* ZombieSword = new C_Equipment(100, 43, -10, "Zombie Sword");
					player->SetSword(ZombieSword);
				}
				else
					cout << "You DON'T have enough items QQ" << endl;
			}
			break;
		case 7://ruby sword
			if (CheckSword(player, item))
			{
				if ((Bag->GetWood() >= 2500) && (Bag->GetRuby() >= 40))
				{
					cout << "You successfully craft a Ruby Sword" << endl;
					Bag->SetWood(-2500);
					Bag->SetRuby(-40);
					C_Equipment* RubySword = new C_Equipment(0, 82, 0, "Ruby Sword");
					equipment = new C_RubySword;
					player->SetSword(RubySword);
					player->equipSword(equipment);
					iCountS++;
				}
				else
					cout << "You DON'T have enough items QQ" << endl;
			}
			break;
		case 9://unicorn sword
			if (CheckSword(player, item))
			{
				if ((Bag->GetWood() >= 2500) && (Bag->GetUnicornHorn() >= 50) && (Bag->GetFish() >= 500))
				{
					cout << "You successfully craft a Unicorn Sword" << endl;
					Bag->SetWood(-2500);
					Bag->SetUnicornHorn(-50);
					Bag->SetFish(-500);
					C_Equipment* UnicornSword = new C_Equipment(300, 96, 0, "Unicorn Sword");
					equipment = new C_UnicornSword;
					player->SetSword(UnicornSword);
					player->equipSword(equipment);
					iCountS++;
				}
				else
					cout << "You DON'T have enough items QQ" << endl;
			}
			break;
		case 2://fish armor
			if (CheckArmor(player, item))
			{
				if ((Bag->GetWood() >= 10) && (Bag->GetFish() >= 20))
				{
					cout << "You successfully craft a Fish Armor" << endl;
					Bag->SetWood(-10);
					Bag->SetFish(-20);
					C_Equipment* FishArmor = new C_Equipment(0, 0, 9, "Fish Armor");
					player->SetArmor(FishArmor);
				}
				else
					cout << "You DON'T have enough items QQ" << endl;
			}
			break;
		case 4://wolf armor
			if (CheckArmor(player, item))
			{
				if ((Bag->GetWood() >= 170) && (Bag->GetWolfSkin() >= 20))
				{
					cout << "You successfully craft a Wolf Armor" << endl;
					Bag->SetWood(-170);
					Bag->SetWolfSkin(-20);
					C_Equipment* WolfArmor = new C_Equipment(20, 0, 20, "Wolf Armor");
					player->SetArmor(WolfArmor);
				}
				else
					cout << "You DON'T have enough items QQ" << endl;
			}
			break;
		case 6://coin armor
			if (CheckArmor(player, item))
			{
				if ((Bag->GetWood() >= 3125) && (Bag->GetFish() >= 1500))
				{
					cout << "You successfully craft a Coin Armor" << endl;
					Bag->SetWood(-3125);
					Bag->SetFish(-1500);
					C_Equipment* CoinArmor = new C_Equipment(0, 0, 42, "Coin Armor");
					equipment = new C_CoinArmor;
					player->SetArmor(CoinArmor);
					player->equipArmor(equipment);
					iCountA++;
				}
				else
					cout << "You DON'T have enough items QQ" << endl;
			}
			break;
		case 8://epic armor
			if (CheckArmor(player, item))
			{
				if ((Bag->GetWood() >= 5000) && (Bag->GetCoin() >= 321123))
				{
					cout << "You successfully craft a Epic Armor" << endl;
					Bag->SetWood(-5000);
					Bag->SetCoin(-321123);
					C_Equipment* EpicArmor = new C_Equipment(200, 0, 82, "Epic Armor");
					player->SetArmor(EpicArmor);
				}
				else
					cout << "You DON'T have enough items QQ" << endl;
			}
			break;
		case 10://mermaid armor
			if (CheckArmor(player, item))
			{
				if ((Bag->GetWood() >= 10000) && (Bag->GetFish() >= 1650) && (Bag->GetMermaidHair() >= 75))
				{
					cout << "You successfully craft a Mermaid Armor" << endl;
					Bag->SetWood(-10000);
					Bag->SetFish(-1650);
					Bag->SetMermaidHair(-75);
					C_Equipment* MermaidArmor = new C_Equipment(300, 0, 96, "Mermaid Armor");
					equipment = new C_MermaidArmor;
					player->SetArmor(MermaidArmor);
					player->equipArmor(equipment);
					iCountA++;
				}
				else
					cout << "You DON'T have enough items QQ" << endl;
			}
			break;
		default:
			cout << "\nWrong input! Press ENTER to select again.\n" << endl;
		}
	}
};

class Layer1Hunt : public Monster//Janie
{
protected:

	void actionAttack(Character* other) override
	{
		cout << MonsterName << " choose attack" << endl;
		int damage = (int)(attack);
		other->damaged(damage);
	}

	void actionDefence(Character* other) override
	{
		cout << MonsterName << " choose defence" << endl;
		int defend = (int)(defence * 0.6 + hp * 0.4);
		this->defended(defend);
	}

public:
	Layer1Hunt(int hp, int atk, int dfc) : Monster(hp, atk, dfc)
	{
		name[0] = "Slime";
		name[1] = "Goblin";
		name[2] = "Wolf";
		int iNumber = rand()%3;
		MonsterName = name[iNumber];
	}

	void reward(Player* player) override
	{
		//player->equip(equipment);
		iCoin = rand() % 11 + 20;
		iExp = rand() % 11 + 10;
		player->ExpUp(iExp);
		cout << "  You earn " << iExp << "exp" << endl;
		player->GetBag()->SetCoin(iCoin);
		cout << "  You get " << iCoin << "coin" << endl;
		if (MonsterName == "Wolf")
		{
			int iPercent = rand() % 100 + 1;
			if (iPercent < 25)
			{
				player->GetBag()->SetWolfSkin(1);
				cout << "\n  WOW! You get a Wolf Skin!" << endl;
			}
		}
	}
};

class Layer1Adventure : public Monster//Janie
{
protected:
	void actionAttack(Character* other) override
	{
		cout << MonsterName << " choose attack" << endl;
		int damage = (int)(attack + hp * 0.1);
		other->damaged(damage);
	}

	void actionDefence(Character* other) override
	{
		cout << MonsterName << " choose defence" << endl;
		int defend = (int)(defence * 0.7 + hp * 0.3);
		this->defended(defend);
	}

public:
	Layer1Adventure(int hp, int atk, int dfc) : Monster(hp, atk, dfc)
	{
		name[0] = "Giant Spider";
		name[1] = "Bunch of Bees";
		name[2] = "Ogre";
		int iNumber = rand() % 3;
		MonsterName = name[iNumber];
	}

	void reward(Player* player) override
	{
		//player->equip(equipment);
		iCoin = rand() % 11 + 40;
		iExp = rand() % 11 + 20;
		player->ExpUp(iExp);
		cout << "  You earn " << iExp << "exp" << endl;
		player->GetBag()->SetCoin(iCoin);
		cout << "  You get " << iCoin << "coin" << endl;
	}
};

class Layer1Dungeon : public Monster //Hugo
{
protected:
	void actionAttack(Character* other) override
	{
		cout << MonsterName << " choose attack" << endl;
		int damage = (int)(attack);
		other->damaged(damage);
	}

	void actionDefence(Character* other) override
	{
		cout << MonsterName << " choose defence" << endl;
		int defend = (int)(defence * 0.6 + hp * 0.4);
		this->defended(defend);
	}

	void actionSkill(Character* other) override
	{
		cout << MonsterName << " choose special attack" << endl;
		cout << "  H.U.G.O COUNTER ATTACK" << endl;
		cout << "  Give back TWICE you damaged" << endl;
		int damage = roundDamage*2;
		other->damaged(damage);
	}
public:
	Layer1Dungeon(int hp, int atk, int dfc) : Monster(hp, atk, dfc)
	{
		MonsterName = "Hugo Golem";
	}

	void reward(Player* player) override
	{
		//player->equip(equipment);
		iCoin = 1000;
		iExp = 800;
		player->ExpUp(iExp);
		cout << "  You earn " << iExp << "exp" << endl;
		player->GetBag()->SetCoin(iCoin);
		cout << "  You get " << iCoin << "coin" << endl;
		player->SetCurrentLayer(2);
		if (player->GetMaxLayer() == 1)
			player->SetMaxLayer(2);
		cout << "  You are now in Layer 2 : Silent Hill" << endl;
		cout << "  Your work skills get improved " << endl;
		cout << "      " << left << setw(5) << "CHOP" << "axe" << endl;
		cout << "      " << left << setw(5) << "FISH" << "fish net" << endl;
		cout << "  You get new skill !!! " << endl;
		cout << "      " << left << setw(5) << "MINE" << "pickaxe" << endl;
	}

	void selectAction(Character* other) override
	{
		cout << "Monster choose an action" << endl;
		int validActions = 3;
		int action = rand() % validActions + 1;
		this->doAction(action, other);
	}
};

class Layer2Hunt : public Monster//Janie
{
protected:

	void actionAttack(Character* other) override
	{
		cout << MonsterName << " choose attack" << endl;
		int damage = (int)(attack);
		other->damaged(damage);
	}

	void actionDefence(Character* other) override
	{
		cout << MonsterName << " choose defence" << endl;
		int defend = (int)(defence * 0.7 + hp * 0.3);
		this->defended(defend);
	}

public:
	Layer2Hunt(int hp, int atk, int dfc) : Monster(hp, atk, dfc)
	{
		name[0] = "Ghost";
		name[1] = "Zombie";
		name[2] = "Skeleton";
		int iNumber = rand() % 3;
		MonsterName = name[iNumber];
	}

	void reward(Player* player) override
	{
		//player->equip(equipment);
		iCoin = rand() % 11 + 60;
		iExp = rand() % 11 + 30;
		player->ExpUp(iExp);
		cout << "  You earn " << iExp << "exp" << endl;
		player->GetBag()->SetCoin(iCoin);
		cout << "  You get " << iCoin << "coin" << endl;
		if (MonsterName == "Zombie")
		{
			int iPercent = rand() % 100 + 1;
			if (iPercent < 25)
			{
				player->GetBag()->SetZombieEye(1);
				cout << "\n  WOW! You get a Zombie Eye!" << endl;
			}
		}
	}
};

class Layer2Adventure : public Monster//Janie
{
protected:
	void actionAttack(Character* other) override
	{
		cout << MonsterName << " choose attack" << endl;
		int damage = (int)(attack + hp * 0.2);
		other->damaged(damage);
	}

	void actionDefence(Character* other) override
	{
		cout << MonsterName << " choose defence" << endl;
		int defend = (int)(defence * 0.7 + hp * 0.3);
		this->defended(defend);
	}

public:
	Layer2Adventure(int hp, int atk, int dfc) : Monster(hp, atk, dfc)
	{
		name[0] = "Knight";
		name[1] = "Werewolf";
		name[2] = "Demon";
		int iNumber = rand() % 3;
		MonsterName = name[iNumber];
	}

	void reward(Player* player) override
	{
		//player->equip(equipment);
		iCoin = rand() % 11 + 80;
		iExp = rand() % 11 + 40;
		player->ExpUp(iExp);
		cout << "  You earn " << iExp << "exp" << endl;
		player->GetBag()->SetCoin(iCoin);
		cout << "  You get " << iCoin << "coin" << endl;
	}
};

class Layer2Dungeon : public Monster//Kevin
{
protected:
	void actionAttack(Character* other) override
	{
		cout << MonsterName << " choose attack" << endl;
		int damage = (int)(attack);
		other->damaged(damage);
	}

	void actionDefence(Character* other) override
	{
		cout << MonsterName << " choose defence" << endl;
		int defend = (int)(defence * 0.6 + hp * 0.4);
		this->defended(defend);
	}

	void actionSkill(Character* other) override
	{
		cout << MonsterName << " choose special attack" << endl;
		cout << "  Absolute Power Force! " << endl;
		cout << "  Give you the feel of DESPAIR!" << endl;
		int damage = 222;
		other->damaged(damage);
	}
public:
	Layer2Dungeon(int hp, int atk, int dfc) : Monster(hp, atk, dfc)
	{
		MonsterName = "K. Satan";
	}

	void reward(Player* player) override
	{
		//player->equip(equipment);
		iCoin = 2000;
		iExp = 1600;
		player->ExpUp(iExp);
		cout << "  You earn " << iExp << "exp" << endl;
		player->GetBag()->SetCoin(iCoin);
		cout << "  You get " << iCoin << "coin" << endl;
		player->SetCurrentLayer(3);
		if (player->GetMaxLayer() == 2)
			player->SetMaxLayer(3);
		cout << "  You are now in Layer 3 : NeverLand" << endl;
		cout << "  Your work skills get improved " << endl;
		cout << "      " << left << setw(5) << "CHOP" << "bowsaw" << endl;
		cout << "      " << left << setw(5) << "FISH" << "boat" << endl;
		cout << "      " << left << setw(5) << "MINE" << "drill" << endl;
	}
	

	void selectAction(Character* other) override
	{
		cout << "Monster choose an action" << endl;
		int validActions = 3;
		int action = rand() % validActions + 1;
		this->doAction(action, other);
	}
};

class Layer3Hunt : public Monster//Janie
{
protected:

	void actionAttack(Character* other) override
	{
		cout << MonsterName << " choose attack" << endl;
		int damage = (int)(attack);
		other->damaged(damage);
	}

	void actionDefence(Character* other) override
	{
		cout << MonsterName << " choose defence" << endl;
		int defend = (int)(defence * 0.6 + hp * 0.4);
		this->defended(defend);
	}

public:
	Layer3Hunt(int hp, int atk, int dfc) : Monster(hp, atk, dfc)
	{
		name[0] = "Mermaid";
		name[1] = "Scorpion";
		name[2] = "Sorcerer";
		int iNumber = rand() % 3;
		MonsterName = name[iNumber];
	}

	void reward(Player* player) override
	{
		//player->equip(equipment);
		iCoin = rand() % 11 + 100;
		iExp = rand() % 11 + 50;
		player->ExpUp(iExp);
		cout << "  You earn " << iExp << "exp" << endl;
		player->GetBag()->SetCoin(iCoin);
		cout << "  You get " << iCoin << "coin" << endl;
		if (MonsterName == "Mermaid")
		{
			int iPercent = rand() % 100 + 1;
			if (iPercent < 25)
			{
				player->GetBag()->SetMermaidHair(1);
				cout << "\n  WOW! You get a mermaid hair!" << endl;
			}
		}
	}
};

class Layer3Adventure : public Monster//Janie
{
protected:
	void actionAttack(Character* other) override
	{
		cout << MonsterName << " choose attack" << endl;
		int damage = (int)(attack + hp * 0.3);
		other->damaged(damage);
	}

	void actionDefence(Character* other) override
	{
		cout << MonsterName << " choose defence" << endl;
		int defend = (int)(defence * 0.6 + hp * 0.4);
		this->defended(defend);
	}

public:
	Layer3Adventure(int hp, int atk, int dfc) : Monster(hp, atk, dfc)
	{
		name[0] = "Mammoth";
		name[1] = "Unicorn";
		name[2] = "Cyclops";
		int iNumber = rand() % 3;
		MonsterName = name[iNumber];
	}

	void reward(Player* player) override
	{
		//player->equip(equipment);
		iCoin = rand() % 11 + 120;
		iExp = rand() % 11 + 60;
		player->ExpUp(iExp);
		cout << "  You earn " << iExp << "exp" << endl;
		player->GetBag()->SetCoin(iCoin);
		cout << "  You get " << iCoin << "coin" << endl;
		if (MonsterName == "Unicorn")
		{
			int iPercent = rand() % 100 + 1;
			if (iPercent < 25)
			{
				player->GetBag()->SetUnicornHorn(1);
				cout << "\n  WOW! You get a unicorn \"corn\", HaHa!" << endl;
			}
		}
	}
};

class Layer3Dungeon : public Monster//Kevin
{
protected:
	int iChosen;
	int iCheck = 65;

	void actionAttack(Character* other) override
	{
		do
		{
			cout << MonsterName << " choose attack" << endl;
			int damage = (int)(attack);
			other->damaged(damage);
			iChosen = rand() % 101;
			if(iCheck > 20)
				iCheck = iCheck - 5;
		} while (iChosen < iCheck);
	}

	void actionDefence(Character* other) override
	{
		cout << MonsterName << " choose defence" << endl;
		cout << "  Wait, he changed his mind!" << endl;
		do
		{
			cout <<"\n  "<< MonsterName << "still choose attack" << endl;
			int damage = (int)(attack);
			other->damaged(damage);
			iChosen = rand() % 101;
			if (iCheck > 20)
				iCheck = iCheck - 5;
		} while (iChosen < iCheck);
	}

	void actionSkill(Character* other) override
	{
		cout << MonsterName << " choose special attack" << endl;
		cout <<"  Wait, he changed his mind!" << endl;
		do
		{
			cout << "\n  " << MonsterName << "still choose attack" << endl;
			int damage = (int)(attack);
			other->damaged(damage);
			iChosen = rand() % 101;
			if (iCheck > 20)
				iCheck = iCheck - 5;
		} while (iChosen < iCheck);
	}
public:
	Layer3Dungeon(int hp, int atk, int dfc) : Monster(hp, atk, dfc), iChosen(0), iCheck(65)
	{
		MonsterName = "Fallen Gemini";
	}

	void reward(Player* player) override
	{
		//player->equip(equipment);
		iCoin = 3000;
		iExp = 2400;
		player->ExpUp(iExp);
		cout << "You earn " << iExp << "exp" << endl;
		player->GetBag()->SetCoin(iCoin);
		cout << "You get " << iCoin << "coin" << endl;
		player->SetCurrentLayer(4);
		if (player->GetMaxLayer() == 3)
		{
			player->SetMaxLayer(4);
			cout << "  Your work skills get improved " << endl;
			cout << "      " << left << setw(5) << "CHOP" << "chainsaw" << endl;
			cout << "      " << left << setw(5) << "FISH" << "bigboat" << endl;
			cout << "      " << left << setw(5) << "MINE" << "dynamite" << endl;
			cout << "\n  Congratulations!!! You conquer this GAME~" << endl;
			cout << "  N0w you are fr*e to do 4nyth1ng in this Game" << endl;
			cout << "\n  ps. Th3r3 is 4 surpr*se in $H0P ;)" << endl;
		}
		cout << "  Y0\ 4/3 n0vv |\ L4y3r A : @#$%^%^&*" << endl;
	}

	void selectAction(Character* other) override
	{
		cout << "Monster choose an action" << endl;
		int validActions = 3;
		int action = rand() % validActions + 1;
		this->doAction(action, other);
	}
};

class Layer4Special : public Monster //Janie
{
protected:
	void actionAttack(Character* other) override
	{
		cout  << MonsterName << " use The Cry" << endl;
		cout << "  Your attack become healing point" << endl;
		roundDamage = roundDamage * 100;
	}

	void actionDefence(Character* other) override
	{
		cout << MonsterName << " use MEGA吸奶 " << endl;
		cout << "  Your attack become healing point" << endl;
		roundDamage = roundDamage * 10000;
	}

	void actionSkill(Character* other) override
	{
		roundDamage = 0;
		hp -= other->GetATK() * 10;
		if (hp < 0)
		{
			hp = 1;
		}
		cout << MonsterName << " use 轉守為攻 by 胖叔叔" << endl;
		cout << "  j06ru8 yl4t/6g61o4g; c94" << endl;
	}
public:
	Layer4Special(int hp, int atk, int dfc) : Monster(hp, atk, dfc)
	{
		MonsterName = "Janie The Shop Keeper";
	}

	void reward(Player* player) override
	{
		//player->equip(equipment);
		iCoin = INT_MAX-player->GetBag()->GetCoin();
		for (int i = 0; i < 10; i++)
		{
			cout << '\a';
			player->ExpUp(INT_MAX/2);
		}
		cout << "  You earn tons of exp" << endl;
		player->GetBag()->SetCoin(iCoin);
		cout << "  You get tons of coin" << endl;
		cout << "\n═══════════════════════════════" << endl;
		cout << "\n  Congratulations!!!!!!! You finally pass D4WN RPG" << endl;
		cout << "  Wish you have a great time in this game :)" << endl;

	}

	void selectAction(Character* other) override
	{
		int validActions = 3;
		int action = rand() % validActions + 1;
		this->doAction(action, other);
	}

	void computeRoundResult()override
	{
		cout << "heal " << roundDamage << " Hp" << endl;
		hp += roundDamage;
		roundDamage = 0;
	}
};

class Game
{
private:
	Player* player;
	Monster* monster;

	const vector<string> status = { "Game Over", "Playing" };

	void showStartScreen() //Hugo
	{
		                            
		cout << "\n\t\t╔═════════════════════════════╗" << endl;
		cout << "\t\t║                             ║" << endl;
		cout << "\t\t║     Weclome to D4WN RPG     ║" << endl;
		cout << "\t\t║                             ║" << endl;
		cout << "\t\t╚═════════════════════════════╝" << endl;
		cout << "\n═══════════════════════════════════════════════════════════════" << endl;
		cout << "\t\t     -PRESS ENTER TO START-" << endl;
		cout << "═══════════════════════════════════════════════════════════════" << endl;
		GoContinue();
		system("cls");
		cout << "\n    ╒══════════════════════ WARNING ══════════════════════╕" << endl;
		cout << "    │                                                     │" << endl;
		cout << "    │           This Game DOESN'T SUPPORT CLION           │" << endl;
		cout << "    │   Cause need to use UP DOWN LEFT RIGHT key to MOVE  │" << endl;
		cout << "    │                                                     │" << endl;
		cout << "    └─────────────────────────────────────────────────────┘" << endl;
		cout << "\n═══════════════════════════════════════════════════════════════" << endl;
		cout << "                   -PRESS ENTER TO COUNTINUE-" << endl;
		cout << "═══════════════════════════════════════════════════════════════" << endl;
		GoContinue();
		system("cls");
		player->SetName();
		cout << "\n\t\tHello ~ " << player->GetName() << endl;
		cout << "\t\tLet's get started!!!" << "\n\t\tFirst, Read the Introduction about D4WN RPG~" << endl;
		cout << "\n════════════════════════════════════════════════════════════" << endl;
		cout << "\t\t-PRESS ENTER TO COUNTINUE-" << endl;
		cout << "════════════════════════════════════════════════════════════" << endl;
		GoContinue();
		system("cls");
		showStartInfo();
		cout << "                         -PRESS ENTER TO COUNTINUE-" << endl;
		cout << " ═══════════════════════════════════════════════════════════════════════════" << endl;
		GoContinue();
		system("cls");
	}

	void showStartInfo() //Hugo
	{
		cout << "\n╒═══════════════════════════════ INTRODUCTION ══════════════════════════════╕" << endl;
		cout << "│                                                                           │" << endl;
		cout << "│ The main purpose of the game is to unlock higher areas to become stronger │" << endl;
		cout << "│            There's a total of 3 areas, and you start in area #1           │" << endl;
		cout << "│                                                                           │" << endl;
		cout << "├────────────────────────── ALRIGHT, HOW DO I PLAY ─────────────────────────┤" << endl;
		cout << "│                                                                           │" << endl;
		cout << "│                  Get XP and COIN with HUNT and ADVENTURE                  │" << endl;
		cout << "│                                ─ WARNING ─                                │" << endl;
		cout << "│                     You will lose a level if you die!                     │" << endl;
		cout << "│                                                                           │" << endl;
		cout << "├──────────────────────────── WHAT ELSE CAN I DO ───────────────────────────┤" << endl;
		cout << "│                                                                           │" << endl;
		cout << "│                         Use your COIN in the SHOP                         │" << endl;
		cout << "│          Get items with CHOP, FISH and MINE to CRAFT equipment!           │" << endl;
		cout << "│                                                                           │" << endl;
		cout << "├──────────────────────── HOW DOES THE DUNGEON WORK ────────────────────────┤" << endl;
		cout << "│                                                                           │" << endl;
		cout << "│       When you feel ready, buy a dungeon key and enter with DUNGEON!      │" << endl;
		cout << "│             If you kill the boss, you will unlock the next AREA!          │" << endl;
		cout << "│      New areas means new items, recipes, enemies and a harder dungeon     │" << endl;
		cout << "│                  Finally, try your best~ And Good Luck :)                 │" << endl;
		cout << "│                                                                           │" << endl;
		cout << "╘═══════════════════════════════════════════════════════════════════════════╛" << endl;
	}

	int ChooseLayer(Player* player) //Gemini
	{
		int iState = 0;
		string sSelect[4];
		while (1)
		{
			cout << "Which layer do you want to go?" << endl;
			for (int i = 0; i < 4; i++)
			{
				sSelect[i] = " ";
			}
			sSelect[iState] = "＞";
			cout << sSelect[0] + " Layer 1" << endl;
			if (player->GetMaxLayer() > 1)
				cout << sSelect[1] + " Layer 2" << endl;
			if (player->GetMaxLayer() > 2)
				cout << sSelect[2] + " Layer 3" << endl;
			if (player->GetMaxLayer() > 3)
				cout << sSelect[3] + " ⌋4y3r 4" << endl;
			int iGetKey = _getch();
			if (iGetKey == 224)
			{
				switch (_getch())
				{
				case 72://up
					iState = (iState - 1) > -1 ? iState - 1 : iState;
					break;
				case 80://down
					if (player->GetMaxLayer() > 3)
						iState = (iState + 1) < 4 ? iState + 1 : iState;
					else if (player->GetMaxLayer() > 2)
						iState = (iState + 1) < 3 ? iState + 1 : iState;
					else if (player->GetMaxLayer() > 1)
						iState = (iState + 1) < 2 ? iState + 1 : iState;
					break;
				}
			}
			else
				if (iGetKey == 13)
					return iState + 1;
			system("cls");
		}
	}

	int chooseBattleAction(int bossLayer = 0) //Gemini
	{
		int iState = 0;
		string sSelect[2];
		while(1)
		{
			monsterPicture(bossLayer);
			cout << "═══════════ BATTLE INFORMATION ═══════════\n" << endl;
			// Show monster and player information
			showBattleInfo(player, monster);
			cout << "\n═══════════════════════════════════════════\n" << endl;
			for (int i = 0; i < 2; i++)
			{
				sSelect[i] = " ";
			}
			sSelect[iState] = "＞";
			cout << "Select your action:" << endl;
			cout << sSelect[0] + " attack" << endl;
			cout << sSelect[1] + " defence" << endl;
			int iGetKey = _getch();
			if (iGetKey == 224)
			{
				switch (_getch())
				{
				case 72://up
					iState = (iState - 1) > -1 ? iState - 1 : iState;
					break;
				case 80://down
					iState = (iState + 1) < 2 ? iState + 1 : iState;
					break;
				}
			}
			else
				if (iGetKey == 13)
					return iState + 1;
			system("cls");
		}
	}

	void showBattleInfo(Player* player, Monster *monster) //Gemini
	{
		string sExp = to_string(player->GetExp()) + "/" + to_string(player->GetMaxExp());
		string sPlayerHp = to_string(player->GetHP()) + "/" + to_string(player->GetMaxHP());
		string sMonsterHp = to_string(monster->GetHP()) + "/" + to_string(monster->GetMaxHP());
		cout << left << setw(20) << player->GetName() << "■ " << left << setw(20)<< monster->GetName() << endl;
		cout << left << setw(9) << "Lv" << left << setw(11) << player->GetLevel() << "■ " << endl;
		cout << left << setw(9) << "Exp" << left << setw(11) << sExp << "■ "  << endl;
		cout << left << setw(9) << "HP" << left << setw(11) << sPlayerHp << "■ " << left << setw(9) << "HP" << sMonsterHp << endl;
		cout << left << setw(9) << "ATK" << left << setw(11) << player->GetATK() << "■ " << left << setw(9) << "ATK" << left << setw(11) << monster->GetATK() << endl;
		cout << left << setw(9) << "DEF" << left << setw(11) << player->GetDEF() << "■ " << left << setw(9) << "DEF" << left << setw(11) << monster->GetDEF() << endl;
	}

	void showPlayerInfo() //Gemini
	{
		cout << "══════ YOUR INFORMATION ══════\n" << endl;
		player->showInfo();
	}

	void showResult()  //Gemini
	{
		if (!(player->isAlive()))
		{
			// Player lose the game
			player->LevelDown();
			cout << "\n═══════════════════════════════\n" << endl;
			cout << "  You lose one level" << endl; 
			cout << "\n═══════════════════════════════\n" << endl;
		}
	}

	void monsterPicture(int iLayer) //Kevin
	{
		switch (iLayer)
		{
		case 1:
			cout << "      ■■■■■■      ■■■■■■\n";
			cout << "      ■■■■■■  ■  ■■■■■■\n";
			cout << "      ■■■■■■      ■■■■■■\n";
			cout << "      ■■                      ■■\n";
			cout << "      ■    ■■          ■■    ■\n";
			cout << "      ■    ■■          ■■    ■\n";
			cout << "      ■  ■■■■      ■■■■  ■\n";
			cout << "      ■  ■■■■      ■■■■  ■\n";
			cout << "      ■    ■■■      ■■■    ■\n";
			cout << "      ■■■■■          ■■■■■\n";
			cout << "      ■■■■    ■■■    ■■■■\n";
			cout << "      ■■■■    ■■■    ■■■■\n";
			cout << "      ■■■■■  ■■■  ■■■■■\n";
			cout << "      ■■■■    ■■■    ■■■■\n";
			break;
		case 2:
			cout << "            ■■■■■■■■■        \n";
			cout << "        ■■                  ■■    \n";
			cout << "      ■                          ■  \n";
			cout << "      ■                          ■  \n";
			cout << "    ■                              ■\n";
			cout << "    ■    ■■■          ■■■    ■\n";
			cout << "    ■    ■■■          ■■■    ■\n";
			cout << "    ■    ■■■    ■    ■■■    ■\n";
			cout << "      ■          ■■■          ■  \n";
			cout << "    ■■  ■                  ■  ■■\n";
			cout << "    ■    ■■■■■■■■■■■    ■\n";
			cout << "    ■      ■  ■  ■  ■  ■      ■\n";
			cout << "      ■■    ■■■■■■■    ■■  \n";
			cout << "          ■■              ■■      \n";
			cout << "              ■■■■■■■          \n";
			break;
		case 3:
			cout << "    ■■■■■■■■■■■■■■■\n";
			cout << "    ■■■  ■■■■■■■  ■■■\n";
			cout << "    ■■■  ■    ■■■■  ■■■\n";
			cout << "    ■■■      ■■■■■  ■■■\n";
			cout << "    ■■■■  ■■■■■      ■■\n";
			cout << "    ■■■    ■■■■■■  ■■■\n";
			cout << "    ■■■ ■   ■■■   ■ ■■■\n";
			cout << "    ■■■ ■   ■■■   ■ ■■■\n";
			cout << "    ■■■  ■■■■■■    ■■■\n";
			cout << "    ■■      ■■■■■  ■■■■\n";
			cout << "    ■■■  ■■■■■      ■■■\n";
			cout << "    ■■■  ■■■■    ■  ■■■\n";
			cout << "    ■■■  ■■■■■■■  ■■■\n";
			cout << "    ■■■■■■■■■■■■■■■\n";
			break;
		case 4:
			cout << "      ■■■    ■■■■■■■    ■■■\n";
			cout << "      ■■                          ■■\n";
			cout << "      ■■          ■■■          ■■\n";
			cout << "      ■    ■■  ■■■■■  ■■    ■\n";
			cout << "      ■    ■  ■■  ■  ■■  ■    ■\n";
			cout << "      ■    ■  ■■■■■■■  ■    ■\n";
			cout << "      ■    ■  ■■■■■■■  ■    ■\n";
			cout << "      ■■  ■■  ■■■■■  ■■  ■■\n";
			cout << "      ■■■  ■■  ■■■  ■■  ■■■\n";
			cout << "      ■■■■■■■      ■■■■■■■\n";
			cout << "      ■■■■  ■    ■    ■  ■■■■\n";
			cout << "      ■■■■    ■■■■■    ■■■■\n";
			cout << "      ■■■  ■  ■■■■■  ■  ■■■\n";
			cout << "      ■■    ■■  ■■■  ■■    ■■\n";
			cout << "      ■■■■■  ■■■■■  ■■■■■\n";
			cout << "      ■■      ■■■■■■■      ■■\n";
			cout << "      ■■■■■              ■■■■■\n";
			cout << "      ■■■■■■    ■    ■■■■■■\n";
			cout << "      ■■■■■■■  ■  ■■■■■■■\n";
			cout << "      ■■■■■■■  ■  ■■■■■■■\n";
			cout << "      ■■■■■■  ■■  ■■■■■■■\n";
			cout << "      ■■■■■    ■■    ■■■■■■\n";
			break;
		}
	}

public:
	Game()
	{
		player = new Player(100, 3, 3);
		monster = NULL;
	}

	void GoContinue()
	{
		while (1)
		{
			int iGetKey = _getch();
			if (iGetKey == 13)
				break;
		}
	}

	void MonsterCreateLayer1Hunt() //Janie
	{
		int iHp = rand() % 10 + 11;
		int iAtk = rand() % 10 + 1;
		int iDfc = rand() % 5 + 1;
		monster = new Layer1Hunt(iHp, iAtk, iDfc);
	}

	void MonsterCreateLayer1Adventure()//Janie
	{
		int iHp = rand() % 10 + 41;
		int iAtk = rand() % 10 + 21;
		int iDfc = rand() % 5 + 11;
		monster = new Layer1Adventure(iHp, iAtk, iDfc);
	}

	void MonsterCreateLayer1Dungeon() //Kevin
	{
		int iHp = 500;
		int iAtk = 30;
		int iDfc = 100;
		if(player->GetName() == "jatosalo")
		{
			iHp = 50;
			iAtk = 3;
			iDfc = 10;
			cout << "Praise thou, my lord." << endl;
		}
		monster = new Layer1Dungeon(iHp, iAtk, iDfc);
	}

	void MonsterCreateLayer2Hunt()//Janie
	{
		int iHp = rand() % 10 + 51;
		int iAtk = rand() % 10 + 31;
		int iDfc = rand() % 5 + 21;
		monster = new Layer2Hunt(iHp, iAtk, iDfc);
	}

	void MonsterCreateLayer2Adventure()//Janie
	{
		int iHp = rand() % 10 + 71;
		int iAtk = rand() % 10 + 51;
		int iDfc = rand() % 5 + 31;
		monster = new Layer2Adventure(iHp, iAtk, iDfc);
	}

	void MonsterCreateLayer2Dungeon() //Kevin
	{
		int iHp = 666;
		int iAtk = 66;
		int iDfc = 66;
		if(player->GetName() == "jatosalo")
		{
			iHp = 66;
			iAtk = 6;
			iDfc = 6;
			cout << "Praise thou, my lord." << endl;
		}
		monster = new Layer2Dungeon(iHp, iAtk, iDfc);
	}

	void MonsterCreateLayer3Hunt()//Janie
	{
		int iHp = rand() % 10 + 81;
		int iAtk = rand() % 10 + 61;
		int iDfc = rand() % 5 + 41;
		monster = new Layer3Hunt(iHp, iAtk, iDfc);
	}

	void MonsterCreateLayer3Adventure()//Janie
	{
		int iHp = rand() % 10 + 101;
		int iAtk = rand() % 10 + 81;
		int iDfc = rand() % 5 + 51;
		monster = new Layer3Adventure(iHp, iAtk, iDfc);
	}

	void MonsterCreateLayer3Dungeon() //Kevin
	{
		int iHp = 1109;
		int iAtk = 160;
		int iDfc = 38;
		if(player->GetName() == "jatosalo")
		{
			iHp = 110;
			iAtk = 16;
			iDfc = 3;
			cout << "Praise thou, my lord." << endl;
		}
		monster = new Layer3Dungeon(iHp, iAtk, iDfc);
	}

	void MonsterCreateLayer4Special()//Janie
	{
		monster = new Layer4Special(1,0,INT_MAX);
	}

	void MonsterVanish()
	{
		delete monster;
	}

	// Check the current game status
	string gameState() 
	{
		if ((player->isAlive()) && (monster->isAlive())) {
			return status[1];
		}
		else {
			return status[0];
		}
	}

	bool Battle(int bossLayer = 0) //Hugo
	{
		while (gameState() == status[1])
		{
			while (player->isAlive() && monster->isAlive()) {
				// Player choose an action
				int action = chooseBattleAction(bossLayer);
				system("cls");
				// Battle start, both character do their action
				cout << "════════ PLAYER ACTION ═════════\n" << endl;
				cout << "  ";
				player->doAction(action, monster);
				if (NULL != (player->GetSword()))
					player->launchSwordfightEffect(monster);
				if (NULL != (player->GetArmor()))
					player->launchArmorfightEffect(monster);
				cout << "\n═══════ MONSTER ACTION ════════\n" << endl;
				cout << "  ";
				monster->selectAction(player);
				cout << "\n═══════════════════════════════\n" << endl;
				cout << "  ";
				cout << monster->GetName() << " ";
				monster->computeRoundResult();
				if (player->isAlive() && !monster->isAlive()) 
				{
					cout << "\n  You defeat the Monster!" << endl;
					cout << "\n═════════════ LOOT ════════════\n" << endl;
					monster->reward(player);
					if (NULL != (player->GetSword()))
						player->launchSwordresultEffect(monster);
					if (NULL != (player->GetArmor()))
						player->launchArmorresultEffect(monster);
					cout << "\n═══════════════════════════════\n" << endl;
					break;
				}
				cout << "\n  " <<player->GetName() << " ";
				player->computeRoundResult();
				cout << "\n═══════════════════════════════" << endl;
				cout << "Press ENTER to continue..." << endl;
				GoContinue();
				system("cls");
			}
		}
		showResult();
		MonsterVanish();
		return true;
	}

	void GameCenter() //Hugo
	{
		C_Check Check;
		C_Shop	Shop;
		C_Craft Craft;
		string sFish[4] = { "fishing rod","fish net","boat","bigboat" };
		string sChop[4] = { "hand","axe","bowsaw","chainsaw" };
		string sMine[3] = { "pickaxe","drill","dynamite" };
		int iSelect = 1;
		int iPurchase;
		int iAmount;
		int iGear;
		int iChoose = 1;
		showStartScreen();
		while (iSelect = Check.SelectMenu(player->GetCurrentLayer(), iSelect-1))
		{
			switch (iSelect)
			{
			case 1://intro
				system("cls");
				showStartInfo();
				cout << "                          -PRESS ENTER TO CONTINURE-" << endl;
				cout << " ═══════════════════════════════════════════════════════════════════════════" << endl;
				GoContinue();
				system("cls");
				break;
			case 5://hunt
				system("cls");
				if (player->GetCurrentLayer() == 4)
				{
					cout << "@#$%^&*()*&^%$#$%^&\n" << endl;
				}
				else
				{
					if (player->GetCurrentLayer() == 1)
						MonsterCreateLayer1Hunt();
					else if (player->GetCurrentLayer() == 2)
						MonsterCreateLayer2Hunt();
					else if (player->GetCurrentLayer() == 3)
						MonsterCreateLayer3Hunt();
					Battle();
				}
				cout << "Press ENTER to continue..." << endl;
				GoContinue();

				system("cls");
				break;
			case 7://adv
				system("cls");
				if (player->GetCurrentLayer() == 4)
				{
					cout << "@#$%^&*()*&^%$#$%^&\n" << endl;
				}
				else
				{
					if (player->GetCurrentLayer() == 1)
						MonsterCreateLayer1Adventure();
					else if (player->GetCurrentLayer() == 2)
						MonsterCreateLayer2Adventure();
					else if (player->GetCurrentLayer() == 3)
						MonsterCreateLayer3Adventure();
					Battle();
				}
				cout << "Press ENTER to continue..." << endl;
				GoContinue();
				system("cls");
				break;
				break;
			case 9://dungeon
				system("cls");
				if (player->GetCurrentLayer() == 4)
				{
					cout << "@#$%^&*()*&^%$#$%^&\n" << endl;
				}
				else
				{
					if (player->GetBag()->GetDungeonKey() == 0)
						cout << "You DON'T have the key to enter the Dungeon" << endl;
					else
					{
						cout << "You enter the Dungeon" << endl;
						player->GetBag()->SetDungeonKey(-1);
						if (player->GetCurrentLayer() == 1)
						{
							MonsterCreateLayer1Dungeon();
						}
						else if (player->GetCurrentLayer() == 2)
						{
							MonsterCreateLayer2Dungeon();
						}
						else if (player->GetCurrentLayer() == 3)
						{
							MonsterCreateLayer3Dungeon();
						}
						iChoose = Battle(player->GetCurrentLayer());
					}
				}
				cout << "Press ENTER to continue..." << endl;
				GoContinue();
				system("cls");
				break;
			case 2://shop
				system("cls");
				if (player->GetCurrentLayer() == 4)
				{
					MonsterCreateLayer4Special();
					/*if (Craft.GetCountA() > 0)
					{
						player->VanishArmor();
						Craft.SetCountA(0);
					}
					if (Craft.GetCountS() > 0) //Janie check it! Hugo's mistake. 
					{
						player->VanishSword();
						Craft.SetCountS(0);
					}*/
					player->DeleteArmor();
					player->DeleteSword();
					player->StatusChange();
					Battle(4);
					cout << "Press ENTER to continue..." << endl;
					GoContinue();
					system("cls");
				}
				else
				{
					iPurchase = 1;
					Shop.JanietheShopKeeper(player, player->GetBag());
					while (iPurchase = Shop.SelectMenu(player->GetBag(), iPurchase-1))
					{
						Shop.Buy(iPurchase, player->GetBag(), player);
						cout << "\nPress ENTER to continue..." << endl;
						GoContinue();
						system("cls");
					}
					system("cls");
				}
				break;
			case 4://bag
				system("cls");
				player->GetBag()->ShowBag();
				cout << "\n═════════════════════════" << endl;
				cout << "\nPress ENTER to continue..." << endl;
				GoContinue();
				system("cls");
				break;
			case 11://heal
				system("cls");
				cout << "════════════════════════════════\n" << endl;
				if (player->GetBag()->GetLifePotion() != 0)
				{
					if (player->GetHP() >= player->GetMaxHP())
						cout << "  You already have full HP LUL" << endl;
					else
					{
						player->GetBag()->SetLifePotion(-1);
						player->Heal(player->GetMaxHP());
						cout << "You Become Healthy :)" << endl;
					}
				}
				else {
					cout << "  You DON'T have any life potion !" << endl;
				}
				cout << "\n════════════════════════════════" << endl;
				cout << "Press ENTER to continue..." << endl;
				GoContinue();
				system("cls");
				break;
			case 3://show player info
				system("cls");
				showPlayerInfo();
				if (NULL != (player->GetSword()))
				{
					cout << "═══════════ SWORD ═══════════\n" << endl;
					player->PrintSword();
				}
				if (NULL != (player->GetArmor()))
				{
					cout << "═══════════ ARMOR ═══════════\n" << endl;
					player->PrintArmor();
				}
				cout << "\n════════ WORK SKILL ═════════\n" << endl;
				cout << "  " << left << setw(9) << "CHOP " << sChop[player->GetMaxLayer() - 1] << endl;
				cout << "  " << left << setw(9) << "FISH " << sFish[player->GetMaxLayer() - 1] << endl;
				if (player->GetMaxLayer() > 1)
				{
					cout << "  " << left << setw(9) << "MINE " << sMine[player->GetMaxLayer() - 2] << endl;
				}
				cout << "\n═════════════════════════════" << endl;
				cout << "\nPress ENTER to continue..." << endl;
				GoContinue();
				system("cls");
				break;
			case 8://chop
				system("cls");
				iAmount = rand() % 5 + (10 * (player->GetMaxLayer() - 1)) + 1;
				player->GetBag()->SetWood(iAmount);
				cout << "\n═══════════════════════════════════════\n" << endl;
				cout << "    You use " << sChop[(player->GetMaxLayer()) - 1] << " to chop tree..." << endl;
				cout << "    You get " << iAmount << " woods" << endl;
				cout << "\n═══════════════════════════════════════" << endl;
				cout << "Press ENTER to continue..." << endl;
				GoContinue();
				system("cls");
				break;
			case 10://fish
				system("cls");
				iAmount = rand() % 5 + (10 * (player->GetMaxLayer() - 1)) + 1;
				player->GetBag()->SetFish(iAmount);
				cout << "\n═══════════════════════════════════════\n" << endl;
				cout << "    You use " << sFish[(player->GetMaxLayer()) - 1] << " to catch fish..." << endl;
				cout << "    You get " << iAmount << " fish" << endl;
				cout << "\n═══════════════════════════════════════" << endl;
				cout << "Press ENTER to continue..." << endl;
				GoContinue();
				system("cls");
				break;
			case 6://craft
				system("cls");
				iGear = 1;
				while (iGear = Craft.SelectMenu(player->GetBag(), iGear-1))
				{
					Craft.Crafting(iGear, player->GetBag(), player);
					cout << "\nPress ENTER to continue..." << endl;
					GoContinue();
					system("cls");
				}
				system("cls");
				break;
			case 12://mining
				system("cls");
				if (player->GetMaxLayer() > 1)
				{
					if (rand()%101 < 20)
					{
						iAmount = rand() % (2 * (player->GetMaxLayer() - 1)) + 1;
						player->GetBag()->SetRuby(iAmount);
						cout << "\n═══════════════════════════════════════\n" << endl;
						cout << "    You use " << sMine[(player->GetMaxLayer()) - 2] << " to mine..." << endl;
						cout << "    You get " << iAmount << " Ruby!!!" << endl;
						cout << "\n═══════════════════════════════════════" << endl;
					}
					else
					{
						iAmount = rand() % 50 + (100 * (player->GetMaxLayer() - 1)) + 1;
						player->GetBag()->SetCoin(iAmount);
						cout << "\n═══════════════════════════════════════\n" << endl;
						cout << "    You use " << sMine[(player->GetMaxLayer()) - 2] << " to mine..." << endl;
						cout << "    You get " << iAmount << " coin" << endl;
						cout << "\n═══════════════════════════════════════" << endl;
					}
				}
				else
				{
					cout << "\n═══════════════════════════════════════\n" << endl;
					cout << "    You DONT have the ability to MINE" << endl;
					cout << "\n═══════════════════════════════════════" << endl;
				}
				cout << "Press ENTER to continue..." << endl;
				GoContinue();
				system("cls");
				break;
			case 15://move layer
				system("cls");
				iChoose = ChooseLayer(player);
				cout << "═════════════════════════════\n" << endl;
				if ((player->GetCurrentLayer()) == iChoose)
					cout << "  You ALREADY in THIS Layer LUL" << endl;
				else
				{
					player->SetCurrentLayer(iChoose);
					cout << "     You move to Layer " << iChoose << endl;
				}
				cout << "\n═════════════════════════════" << endl;
				cout << "Press ENTER to continue..." << endl;
				GoContinue();
				system("cls");
				break;
			case 13://enchant
				system("cls");
				cout << "\n═══════════════════════════════════════\n" << endl;
				cout << "    STILL TESTING NOT YET, SORRY..." << endl;
				cout << "\n═══════════════════════════════════════" << endl;
				cout << "Press ENTER to continue..." << endl;
				GoContinue();
				system("cls");
				break;
			case 14://pet
				system("cls");
				cout << "\n═══════════════════════════════════════\n" << endl;
				cout << "    STILL TESTING NOT YET, SORRY..." << endl;
				cout << "\n═══════════════════════════════════════" << endl;
				cout << "Press ENTER to continue..." << endl;
				GoContinue();
				system("cls");
				break;
			case 16://training
				system("cls");
				cout << "\n═══════════════════════════════════════\n" << endl;
				cout << "    STILL TESTING NOT YET, SORRY..." << endl;
				cout << "\n═══════════════════════════════════════" << endl;
				cout << "Press ENTER to continue..." << endl;
				GoContinue();
				system("cls");
				break;
			}
		}
	}
};

int main() 
{
	Game monsterKiller;
	monsterKiller.GameCenter();
	system("cls");
	cout << "\n═════════════════════════════\n" << endl;
	cout << "      THANKS FOR PLAYING" << endl;
	cout << "\n═════════════════════════════" << endl;
	cout << "Press ENTER to close..." << endl;
	monsterKiller.GoContinue();
	return 0;
}