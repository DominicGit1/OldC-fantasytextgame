/*Dominic Grant,
5/1/2019
game project program*/
#include <iostream> //preprocessor directive
#include <iomanip>//preprocessor directive
#include <cmath>//preprocessor directive
#include <string>//preprocessor directive
#include <cstdlib>//preprocessor directive
using namespace std;

//-----------------------------CLASS DEFINITIONS WITH ATTRIBUTES AND INLINE MEMBER FUNCTIONS---------------------------------
//Abstract class that has a pool common resources needed by all derived classes
class Resources {
	//Member variables/attributes to be inherited by all derived classes. Not all classes will be needing all resources but they are available for future enhancements
public:
	string playerName, beastName, beastRank, choice, questyes;
	//const int QUEST_SIZE = 10;
	/* In the quest array, First number is the amount of monsters that need to be killed. The second number is the amount of XP to be given upon quest completion,
	and third number is the gold to be given. The rest of the numbers are used to represent the monsters from highest to lowest odds, from dragons to boars.
	I use 1 to say that monster is the one that needs to be killed, and 0 to say that they aren't the quest object.*/
	int quest[10] = { 0 };//Quest system which uses 1 and 0 to determine which monster needs killing.
	int qloop = 3; //int to help with the while loop. set to 3 to ignore the 1dt 3 elemenst of the array, namely, the amount of monsters, the gold, and the xp parts of the array
	int generalquestloop = 0;
	int monsterquestremove = 0;
	int beastGrade = 0;//1-60 is common, 61-80 is uncommon, 81-95 is rare, 96-100 is legendary
	int beastRandom = 0;//1-20 is a boar, 21-35 is a slime, 36-50 is a goblin, 51-65 is a troll, 66-80 is a skeleton, 81-95 is a bandit, 96-100 is a dragon
	int shop, shopLoop, beastNum, goldtoGive, xptoGive; //list of variables we made for various parts of the program
	int playerLevel = 1;
	int playerBaseDamage = 5;
	int playerExtraDamage = 0;
	int playerExp = 0;
	int playerExpToGive = 0;
	int playerGold = 5;
	int playerGoldToGive = 0;
	int playerExpNeeded = 10;
	int playerHealth = 100;
	int playerMaxHealth = 100;
	int enemyHealth = 100;
	int playerPotionCount = 3;
	int dragonOwned = 0;
	int enemyAttack = 0;
	int gameContinue = 0;

	//INLINE Member functions with complete definitions
	//This method gets the player name from the user
	void getPlayerName()
	{
		cout << "Enter your player name: "; //ask for the name of playerene
		getline(cin, playerName);
		cin.clear();
	}

	//This method displays the initial menu for the program
	void displayMenu()
	{
		//prints out options
		cout << "What do you want to do " << playerName <<
			"?\n\n[1] Go adventuring.\n[2] Go to the shop.\n[3] See your stats and inventory.\n[4] See the quest board\n[5] End the game.\n\n";
	}

	//This method executes if the user chooses to go on an adventure by Entering 1
	void Choice1()
	{

		system("CLS");
		srand(time(NULL));//sets random set to current time so always unique
		beastRandom = rand() % 100 + 1;
		beastGrade = rand() % 100 + 1;
		if (beastRandom >= 96 && beastRandom <= 100)//list of monsters with their different values and stats with a few different percentages of getting,
													//5 percent chance of getting a dragonas well as rarity randomizer
		{

			beastName = "dragon";//name of monster
			playerGoldToGive = 100;//gold to give upon death
			playerExpToGive = 75;//exp to give upon death
			enemyAttack = 50; //attack of enemy per turn
			enemyHealth = 150; //enemy health
			if (quest[3] == 1)
			{//this code checks if there is quest for this monster. if there is it sets a code to minus the requied monsters for the quest by one if the player wins.
				monsterquestremove = 1;
			}
			else
			{
				monsterquestremove = 0;
			}
		}//this is the same further on
		else if (beastRandom > 80 && beastRandom < 96)
		{
			beastName = "bandit";
			playerGoldToGive = 5;
			playerExpToGive = 15;
			enemyAttack = 15;
			enemyHealth = 60;
			if (quest[4] == 1)
			{
				monsterquestremove = 1;
			}
			else
			{
				monsterquestremove = 0;
			}
		}
		else if (beastRandom >= 66 && beastRandom <= 80)
		{
			beastName = "skeleton";
			playerGoldToGive = 3;
			playerExpToGive = 5;
			enemyAttack = 8;
			enemyHealth = 30;
			if (quest[5] == 1)
			{
				monsterquestremove = 1;
			}
			else
			{
				monsterquestremove = 0;
			}
		}
		else if (beastRandom >= 51 && beastRandom < 66)
		{
			beastName = "troll";
			playerGoldToGive = 7;
			playerExpToGive = 20;
			enemyAttack = 20;
			enemyHealth = 70;
			if (quest[6] == 1)
			{
				monsterquestremove = 1;
			}
			else
			{
				monsterquestremove = 0;
			}
		}
		else if (beastRandom >= 36 && beastRandom < 51)
		{
			beastName = "goblin";
			playerGoldToGive = 2;
			playerExpToGive = 3;
			enemyAttack = 5;
			enemyHealth = 20;
			if (quest[7] == 1)
			{
				monsterquestremove = 1;
			}
			else
			{
				monsterquestremove = 0;
			}
		}
		else if (beastRandom >= 21 && beastRandom < 36)
		{
			beastName = "slime";
			playerGoldToGive = 5;
			playerExpToGive = 3;
			enemyAttack = 5;
			enemyHealth = 10;
			if (quest[8] == 1)
			{
				monsterquestremove = 1;
			}
			else
			{
				monsterquestremove = 0;
			}
		}
		else if (beastRandom >= 0 && beastRandom < 21)
		{
			beastName = "boar";
			playerGoldToGive = 1;
			playerExpToGive = 5;
			enemyAttack = 5;
			enemyHealth = 15;
			if (quest[9] == 1)
			{
				monsterquestremove = 1;
			}
			else
			{
				monsterquestremove = 0;
			}
		}
		if (beastGrade >= 96 && beastGrade <= 100)
		{
			beastRank = "legendary";// grade of monster
			playerGoldToGive *= 5; //multiply gold amount to be given upon defeat
			playerExpToGive *= 3; //multiply exp amount to be given upon defeat
			enemyAttack *= 4; //multiply attack power
			enemyHealth *= 4; //multiply health
		}
		else if (beastGrade > 80 && beastGrade < 96)
		{
			beastRank = "rare";
			playerGoldToGive *= 3;
			playerExpToGive *= 2;
			enemyAttack *= 3;
			enemyHealth *= 3;
		}
		else if (beastGrade >= 61 && beastGrade <= 80)
		{
			beastRank = "uncommon";
			playerGoldToGive *= 2;
			playerExpToGive *= 1.5;
			enemyAttack *= 2;
			enemyHealth *= 2;
		}
		else if (beastGrade >= 0 && beastGrade < 61)
		{
			beastRank = "common";
			playerGoldToGive *= 1;
		}
		cout << "You've encountered a " << beastRank << " " << beastName << "." << endl;
		cout << "What do you want to do " << playerName << "?\n\n[1] Fight.\n[2] Run.\n";
		cin >> choice;
		//give player chance to run or fight
		if (choice == "1")
		{
			cout << "enemy health is: " << enemyHealth << endl;//print out enemy health
			string beastFullName = beastRank + " " + beastName;

			int dragonCooldown = 0;//dragon has a one turn cooldown which is reset here just in case program could go bonkers
			int attackChoice = 0; //set up a local int to be used for the players action choice during battle

			while (enemyHealth > 0 && playerHealth > 0) //keep this program going until someone dies
			{
				cout << "\n\n Pick an attack: \n[1] Punch \n[2] Sword Slash.\n";
				if (dragonOwned == 1 && dragonCooldown == 0)//hide dragon attack if in cooldown or if player doesnt own a dragon
				{
					cout << "[3] Dragon attack \n" << endl;
				}
				if (playerPotionCount > 0)//hide potion option if player doesnt have any health potions
				{
					cout << "[0] Health potion \n" << endl;
				}
				cin >> attackChoice;
				system("CLS");//keeps screen neat
				if (attackChoice == 1) //punch attack which only does the players base damage.
				{

					enemyHealth = enemyHealth - playerBaseDamage;
					cout << "The enemy health is:" << enemyHealth << endl;
					dragonCooldown = 0;//set cooldown to 0 so one can use their dragon again if it was previously used
					if (enemyHealth > 0)//if enemy isnt dead it attacks you
					{
						cout << "The " << beastFullName << " attacks you and deals you " << enemyAttack << " damage." << endl;//prints out the damage you took and your remaining health
						playerHealth -= enemyAttack;
						cout << "You now have " << playerHealth << " health remaining from your max health of " << playerMaxHealth << "." << endl;
						if (playerHealth <= 0)//checks if the player has died, and prints out a message if true
						{
							cout << "You died to the monster. You resurrect at a church." << endl;
						}
					}

				}

				else if (attackChoice == 2) //sword attack, adds base damage along with the players extra damage that comes from better swords along with a 5 for the normal base damage from a normal sword
				{

					enemyHealth = enemyHealth - (playerBaseDamage + playerExtraDamage + 5);//5 is what im calling the damage for a basic beginner sword
					cout << "The enemy health is: " << enemyHealth << endl;
					dragonCooldown = 0;
					if (enemyHealth > 0)
					{
						cout << "The " << beastFullName << " attacks you and deals you " << enemyAttack << " damage." << endl;
						playerHealth -= enemyAttack;
						cout << "You now have " << playerHealth << " health remaining from your max health of " << playerMaxHealth << "." << endl;
						if (playerHealth <= 0)
						{
							cout << "You died to the monster. You resurrect at a church." << endl;
						}
					}
				}
				else if (attackChoice == 3 && dragonOwned == 1 && dragonCooldown == 0)//only if the player owns a dragon and the cooldown is done can the player use the dragon attack
				{

					enemyHealth = enemyHealth - 50;//do base 50 damage against enemy
					cout << "The enemy health is: " << enemyHealth << endl;
					dragonCooldown = 1;//starts cooldown
					if (enemyHealth > 0)
					{
						cout << "The " << beastFullName << " attacks you and deals you " << enemyAttack << " damage." << endl;
						playerHealth -= enemyAttack;
						cout << "You now have " << playerHealth << " health remaining from your max health of " << playerMaxHealth << "." << endl;
						if (playerHealth <= 0)
						{
							cout << "You died to the monster. You resurrect at a church." << endl;
						}
					}
				}
				else if (attackChoice == 0 && playerPotionCount > 0)//potion option which heals you by 50, must have potions
				{

					playerHealth += 50;
					playerPotionCount -= 1;
					if (playerHealth > playerMaxHealth)
					{
						playerHealth = playerMaxHealth;
					}
					cout << "Your health has increased by 50." << endl;
					cout << "The enemy health is: " << enemyHealth << endl;
					dragonCooldown = 0;
					if (enemyHealth > 0)
					{
						cout << "The " << beastFullName << " attacks you and deals you " << enemyAttack << " damage." << endl;
						playerHealth -= enemyAttack;
						cout << "You now have " << playerHealth << " health remaining from your max health of " << playerMaxHealth << "." << endl;
						if (playerHealth <= 0)
						{
							cout << "You died to the monster. You resurrect at a church." << endl;
						}
					}
				}
				else//catch all
				{
					cout << "Pick a valid option." << endl;
				}

			}
			if (playerHealth > 0)//if the player is alive it gives the gold and experience and checks if player has gathered enough xp to level up
			{
				cout << beastFullName << "  has been eliminated. You have gained " << playerGoldToGive << " gold." << endl;
				playerGold += playerGoldToGive;
				playerExp += playerExpToGive;
				cout << "You have gained " << playerExpToGive << " XP. Your current XP is : [" << playerExp << "/" << playerExpNeeded << "]" << endl;
				if (playerExp >= playerExpNeeded)//if player has gotten enough xp the xp is changed, the health and base damage increased, health restored, and the exp is doubled to reach the next level
				{
					playerExp -= playerExpNeeded;
					playerLevel += 1;
					playerMaxHealth += 10;
					playerExpNeeded *= 2;
					playerBaseDamage += 2;
					playerHealth = playerMaxHealth;
					cout << "You have leveled up! You are now level " << playerLevel << ". Your health has been replenished and you now have a max health of " << playerMaxHealth << "." << endl;
				}
				cout << "Gold amount: \n" << playerGold << endl;
				if (monsterquestremove == 1)//code that removes one from the quest if you killed a required monster
				{
					if (quest[0] > 0)//only minuses if you still have more monsters you need to kill
					{
						quest[0] -= monsterquestremove;
						cout << "You killed a monster required by your quest.\n";
						cout << "You only need to kill " << quest[0] << " more of this monster.\n";
					}
					else
					{
						cout << "You're quest for this type of monster was already completed. Go to the quest board to get your rewards.\n";
					}
				}
			}
			else//if you died you respawn with half your health.
			{
				playerHealth = (playerMaxHealth / 2);
			}
			enemyHealth = 100;
			//reset enemy health just in case program goes bonkers
		}
		else //code for running away
		{
			cout << "you ran away...\n";
		}
		system("pause");

	}

	//This method executes if the user chooses to purchase an item from the shop by Entering 2
	void Choice2()
	{
		system("CLS");
		shopLoop = 0;
		//clear screen and set up loop for the shop
		while (shopLoop == 0)
		{
			system("CLS");
			cout << "You've come to the shop. There's several items on display.\n\n[1] Health potion << 5 Gold\n[2] Steel Sword +10 damage << 30 Gold\n[3] Strength potion. Increases base attack by 2 << 25 gold\n";
			cout << "[4] Pet Dragon. Battle option to do 50 damage. 1 turn cooldown << 100 gold\n[5] XP potion. Gives 50 XP<< 25 Gold\n[6] Bronze Sword +20 damage << 60 Gold\n";
			cout << "[7] 5 Strength potions. Increases base attack by 10 << 125 gold\n[8] 5 XP potions. Gives 250 XP << 125 gold\n[9] 5 Health potions. << 25 gold\n";
			cout << "[10] Leave the shop\n";
			cin >> shop;//print out options and ask for choice
			if (shop == 1)//checks if have enough gold and if so gives you health potion in exchange for gold, and if dont have enough gold it tells you to go away
			{
				if (playerGold >= 5)
				{
					system("CLS");
					playerGold -= 5;
					playerPotionCount += 1;
					cout << "You've bought a Health potion.\n";
					system("pause");
				}
				else
				{
					system("CLS");
					cout << "You don't have enough money to buy a Health potion.\n";
					system("pause");
				}
			}
			else if (shop == 2)//like previous except it checks if you have bought the sword before checking if you have enough gold
			{
				if (playerExtraDamage == 0 || playerExtraDamage == 20)
				{
					if (playerGold >= 30)
					{
						system("CLS");
						playerExtraDamage += 10;
						playerGold -= 30;
						cout << "You've bought a Steel Sword!. We are now out of stock.\n";
						system("pause");
					}
					else
					{
						system("CLS");
						cout << "You don't have enough money to buy the Steel Sword.\n";
						system("pause");
					}
				}
				else
				{
					system("CLS");
					cout << "You have already bought the Steel Sword. We are out of stock.\n";
					system("pause");
				}
			}
			else if (shop == 3)//same as health pot except this pot increases your base damage instead of adding to the potion count
			{
				if (playerGold >= 25)
				{
					system("CLS");
					playerGold -= 25;
					cout << "You've purchased a Strength potion!\n";
					cout << "Your base attack has increased by 2\n";
					playerBaseDamage += 2;
					system("pause");
				}
				else
				{
					system("CLS");
					cout << "You do not have enough currency for a Strength potion.\n";
					system("pause");
				}
			}
			else if (shop == 4)//same as swords except it checks if you bought the dragon before the gold
			{
				if (dragonOwned == 0)
				{
					if (playerGold >= 100)
					{
						system("CLS");
						dragonOwned = 1;
						playerGold -= 100;
						cout << "You've purchased the pet dragon! We are out of stock\n";
						system("pause");
					}
					else
					{
						system("CLS");
						cout << "You do not have enough money for the pet dragon\n";
						system("pause");
					}
				}
				else
				{
					system("CLS");
					cout << "You have already bought the pet dragon. We longer have this.\n";
					system("pause");
				}
			}
			else if (shop == 5)//same as strength pot
			{
				if (playerGold >= 25)
				{
					system("CLS");
					playerGold -= 25;
					cout << "You have purchased a XP potion!\n";
					cout << "You have gained 50 XP\n";
					playerExp += 50;
					system("pause");
				}
				else
				{
					system("CLS");
					cout << "You do not have the required money for a XP potion.\n";
					system("pause");
				}
			}
			else if (shop == 6)//same as steel sword code
			{
				if (playerExtraDamage < 20)
				{
					if (playerGold >= 60)
					{
						system("CLS");
						playerExtraDamage += 20;
						playerGold -= 60;
						cout << "You've purchased a Bronze Sword! We are out of stock now.\n";
						system("pause");
					}
					else
					{
						system("CLS");
						cout << "You do not enough money for the Bronze Sword.\n";
						system("pause");
					}
				}
				else
				{
					system("CLS");
					cout << "You have already bought the Bronze Sword. There are no more available.\n";
					system("pause");
				}
			}
			else if (shop == 7)//same as health pot except this pot increases your base damage instead of adding to the potion count
			{
				if (playerGold >= 125)
				{
					system("CLS");
					playerGold -= 125;
					cout << "You've purchased 5 Strength potions!\n";
					cout << "Your base attack has increased by 10\n";
					playerBaseDamage += 10;
					system("pause");
				}
				else
				{
					system("CLS");
					cout << "You do not have enough currency for 5 Strength potions.\n";
					system("pause");
				}
			}
			else if (shop == 8)//same as strength pot
			{
				if (playerGold >= 125)
				{
					system("CLS");
					playerGold -= 125;
					cout << "You have purchased 5 XP potiona!\n";
					cout << "You have gained 250 XP\n";
					playerExp += 250;
					system("pause");
				}
				else
				{
					system("CLS");
					cout << "You do not have the required money for 5 XP potions.\n";
					system("pause");
				}
			}
			else if (shop == 9)//checks if have enough gold and if so gives you health potion in exchange for gold, and if dont have enough gold it tells you to go away
			{
				if (playerGold >= 25)
				{
					system("CLS");
					playerGold -= 25;
					playerPotionCount += 5;
					cout << "You've bought 5 Health potions.\n";
					system("pause");
				}
				else
				{
					system("CLS");
					cout << "You don't have enough money to buy 5 Health potions.\n";
					system("pause");
				}
			}
			else if (shop == 10)//exits out of the shop
			{
				system("CLS");
				shopLoop = 1;
			}
			else
			{
				shopLoop = 1;
				cin.clear();
				cout << "Leaving the shop due to invalid input." << endl;
				system("pause");
			}
		}
	}

	//This method executes if the user chooses to see and printout his/her stats by Entering 3
	void Choice3()
	{
		system("CLS");
		cout << "Your stats:\nHealth: " << playerHealth << "/" << playerMaxHealth << endl;//General stats are printed out here
		cout << "Level: " << playerLevel << endl;
		cout << "Gold: " << playerGold << endl;
		cout << "Potions: " << playerPotionCount << endl;
		cout << "Weapons and Equipment:\n";
		if (playerExtraDamage >= 10 && playerExtraDamage < 20 && dragonOwned == 0)//For these codes I use a bunch of if and things using what range of extra damage the player has to discover
		{//what weapons they have, and the extra damage comes from the attack of the swords themselves
			cout << "-Steel Sword +10 Damage\n";

		}
		else if (playerExtraDamage >= 20 && playerExtraDamage < 30 && dragonOwned == 0)
		{
			cout << "-Bronze Sword +20 Damage\n";
		}
		else if (playerExtraDamage == 30 && dragonOwned == 0)
		{
			cout << "-Steel Sword +10 Damage\n";
			cout << "-Bronze Sword +20 Damage\n";
		}
		else if (playerExtraDamage == 0 && dragonOwned == 1)
		{
			cout << "-Pet Dragon +50 Damage\n";
		}
		else if (playerExtraDamage == 10 && dragonOwned == 1)
		{
			cout << "-Steel Sword +10 Damage\n";
			cout << "-Pet Dragon +50 Damage\n";
		}
		else if (playerExtraDamage == 20 && dragonOwned == 1)
		{
			cout << "-Bronze Sword +20 Damage\n";
			cout << "-Pet Dragon +50 Damage\n";
		}
		else if (playerExtraDamage == 30 && dragonOwned == 1)
		{
			cout << "-Steel Sword +10 Damage\n";
			cout << "-Bronze Sword +20 Damage\n";
			cout << "-Pet Dragon +50 Damage\n";
		}
		else
		{
			cout << "No weapons and/or equipment.\n";
		}
		system("pause");
		system("CLS");

	}

	//This method executes if the user chooses to go on a quest by Entering 3
	void Choice4()
	{
		while (generalquestloop == 0)
		{
			system("CLS");
			int sumer = 0;
			qloop = 3;
			cout << "Quest board. You can only choose one quest at a time\n";
			while (qloop <= 9)//count the elements in the quest array to determine if there's any ongoing quests or finished quests
			{
				sumer += quest[qloop];
				qloop++;
			}
			if (sumer == 0)
			{
				cout << "You have no current ongoing quests or completed quests. You can choose a quest from here.\n";
				srand(time(NULL));
				beastRandom = rand() % 100 + 1;
				srand(time(NULL));
				beastNum = rand() % 10 + 1;
				goldtoGive = 100;
				xptoGive = 100;
				if (beastRandom >= 96 && beastRandom <= 100)//list of monsters
				{//5 percent chance of getting a dragon
					beastName = "dragon";//name of monster
					xptoGive *= (2 * beastNum);//I did a multiplier here for the various monsters as a dragon would need more rewards than a slime
					goldtoGive *= (2 * beastNum);
				}//this is the same further on
				else if (beastRandom > 80 && beastRandom < 96)
				{
					beastName = "bandit";
					xptoGive *= (0.5 * beastNum);
					goldtoGive *= (0.5 * beastNum);
				}
				else if (beastRandom >= 66 && beastRandom <= 80)
				{
					beastName = "skeleton";
					xptoGive *= (0.5 * beastNum);
					goldtoGive *= (0.5 * beastNum);
				}
				else if (beastRandom >= 51 && beastRandom < 66)
				{
					beastName = "troll";
					xptoGive *= (1 * beastNum);
					goldtoGive *= (1 * beastNum);
				}
				else if (beastRandom >= 36 && beastRandom < 51)
				{
					beastName = "goblin";
					xptoGive *= (0.5 * beastNum);
					goldtoGive *= (0.5 * beastNum);
				}
				else if (beastRandom >= 21 && beastRandom < 36)
				{
					beastName = "slime";
					xptoGive *= (0.2 * beastNum);
					goldtoGive *= (0.2 * beastNum);
				}
				else if (beastRandom >= 0 && beastRandom < 21)
				{
					beastName = "boar";
					xptoGive *= (0.2 * beastNum);
					goldtoGive *= (0.2 * beastNum);
				}
				cout << "The quest of the day is a request to slay " << beastNum << " " << beastName << "'s.\nYou will gain " << xptoGive << " XP and " << goldtoGive << " gold upon completion.\n";
				cout << "Do you accept? 1 for yes and anything else for no.\n";
				cin >> questyes;
				if (questyes == "1")
				{
					quest[0] = beastNum;
					quest[1] = xptoGive;
					quest[2] = goldtoGive;
					if (beastRandom >= 96 && beastRandom <= 100)
					{
						quest[3] = 1;
					}
					else if (beastRandom > 80 && beastRandom < 96)
					{
						quest[4] = 1;
					}
					else if (beastRandom >= 66 && beastRandom <= 80)
					{
						quest[5] = 1;
					}
					else if (beastRandom >= 51 && beastRandom < 66)
					{
						quest[6] = 1;
					}
					else if (beastRandom >= 36 && beastRandom < 51)
					{
						quest[7] = 1;
					}
					else if (beastRandom >= 21 && beastRandom < 36)
					{
						quest[8] = 1;
					}
					else if (beastRandom >= 0 && beastRandom < 21)
					{
						quest[9] = 1;
					}
					cout << "You've accepted the quest. Leaving the quest board.\n";
					generalquestloop = 1;//stops the loop
					system("pause");
				}
				else
				{
					cout << "You've chosen to not accept the quest. Leaving the quest board.\n";
					generalquestloop = 1;
					system("pause");
				}
			}
			else if (sumer == 1 && (quest[0] == 0))//if there is a quest that the user has completed
			{
				cout << "You've completed your quest. Confirming and giving rewards.\n";//gives rewards to player and resets the gold and xp in array to 0
				playerExp += quest[1];
				playerGold += quest[2];
				cout << "You've gained " << quest[1] << " xp and " << quest[2] << " gold.\n";
				int quickloop = 0;
				while (quickloop <= 9)//clears the entire array and resets it.
				{
					quest[quickloop] = 0;
					quickloop++;
				}
				if (playerExp >= playerExpNeeded)//if player has gotten enough xp the xp is changed, the health and base damage increased, health restored, and the exp is doubled to reach the next level
				{
					playerExp -= playerExpNeeded;
					playerLevel += 1;
					playerMaxHealth += 10;
					playerExpNeeded *= 2;
					playerBaseDamage += 2;
					playerHealth = playerMaxHealth;
					cout << "You have leveled up! You are now level " << playerLevel << ". Your health has been replenished and you now have a max health of " << playerMaxHealth << "." << endl;
				}
				cout << "You've accepted the rewards. Leaving the quest board.\n";
				generalquestloop = 1;
				system("pause");
			}
			else if (sumer == 1 && (quest[0] > 0))//if there is a ongoing quest and the user hasnt killed enough monsters yet
			{
				cout << "You have an ongoing quest.\n";
				cout << "You still have " << quest[0] << " more ";
				if (quest[3] == 1)
				{
					cout << "dragons to kill.\n";
				}
				else if (quest[4] == 1)
				{
					cout << "bandits to kill.\n";
				}
				else if (quest[5] == 1)
				{
					cout << "skeletons to kill.\n";
				}
				else if (quest[6] == 1)
				{
					cout << "trolls to kill.\n";
				}
				else if (quest[7] == 1)
				{
					cout << "goblins to kill.\n";
				}
				else if (quest[8] == 1)
				{
					cout << "slimes to kill.\n";
				}
				else if (quest[9] == 1)
				{
					cout << "boars to kill.\n";
				}
				cout << "Leaving the quest board.\n";
				generalquestloop = 1;
				system("pause");

			}
		}
		generalquestloop = 0;//reset the loop counter so it doesnt break the code when trying to go back into the quest board
		system("CLS");
	}

	//This method executes if the user chooses to quit the game by Entering 5
	void Choice5()
	{

		system("CLS");
		gameContinue = 1;
		cout << "Thanks for playing!\n";
	}
};

//This class serves both the current release of the game and allows for future enhancements to the game based on user feedback
class Gamer : public Resources {
	/*No methods/defiitions have been overridden here. This Derived is mainly used for 2 purpose:
	1) To serve the current release of the game by inheriting form the Base class
	2) To provide new definitions and overrides for future releases of the game
	*/
};

int main()
{
	Gamer game1; //Object of the Derived class, Gamer, that inherits all the resources of the Base class, Resources.
	game1.getPlayerName(); // Gets the user-chosen playername from the user

	while (game1.gameContinue == 0) //keeps the game running
	{
		game1.displayMenu(); // Displays the main program menu

		cin >> game1.choice; // Gets input from the user

		if (game1.choice == "1")
			game1.Choice1();

		else if (game1.choice == "2")//code for shop
			game1.Choice2();

		else if (game1.choice == "3") //prints out stats
			game1.Choice3();

		else if (game1.choice == "4") //Displays Questboard options
			game1.Choice4();

		else if (game1.choice == "5")//ends game
			game1.Choice5();

		else//catch all
		{
			system("CLS");
			cout << "Invalid input.\n";
			system("pause");

		}
	}

	system("pause");
	return 0;
}