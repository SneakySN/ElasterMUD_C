#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "cJSON.h"
#include "cJSON_Utils.h"
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
/* Struct */
/* charData - for storing basic details about the character */

/* Functions */
/* getInput - executes the Input function */
/* eventCase - executes the dialogues by the events that occurs. calls diagCase if needed. */
/* eventExecute - executes the event by the case presented */
/* diagCase - executes the dialogue's events by case, and sometimes char*. */
/* sysCase - executes the system events, such as "Level Up" & "Mob Encounter", etc */

/* Additional Ideas */

/* 1. Enchantment of the Gears */

/* Each gears can have an enchantment level up to 25 - Success Rates will be provided later. */
/* Gear Enchantments can have random stats enabled - this will be saved as the "Enchantment Stats" variable. */
/* First enchantment will decide what sort of stats will be increased. */
/* STR - STR/VIT/DEF/ATK */
/* DEX - DEX/AGI/DEF/ATK */
/* INT - INT/MP /DEF/ATK */
/* AGI - AGI/DEX/DEF/ATK */
/* VIT - VIT/HP /DEF/ATK */
/* In these stat increases, DEF and ATK will be provided every enchantment, but the stat increases will be random. */
/* LUK can not be added via enchantments, and it's only provided with gears/buffs. */

/* 2. Classes & Stat Tables */

/* Stats are decided by calculation & leveling up */

typedef struct charDataStorage {
	/* User Stats/Data - Character Name, Character Class, Stats */
	char* charName;
	int charClass;
	int charLevel;
	int charExp;
	int curGold;

	/* Stat Order: HP, MP, STR, DEX, INT, AGI, VIT, LUK, ATK, DEF */
	int charStat[10];
	/* Calculated Stats */
	int charATK; /* Calculated with the main stat by class + weapon attack */
	int charDEF; /* Calculated with armor + subarmor defense stat */

	/* Equipments */
	int weaponCode;
	int subWeaponCode;

	/* Armor Order: Headwear, Chestwear, Legwear, Shoes */
	int equipArmor[4];

	/* Sub Armor Order: Ring, Ring, Necklace, Aura */
	int equipSubArmor[4];

	/* Enchantments - Order: Enchantment Level, Enchantment Stats, follows the order of Equiptments */
	/* Order: Level, 1st stat code, 2nd stat code, 1st stat increment, 2nd stat increment, ATK increment, DEF increment */

	/* Weapon */
	int weaponEnchantData[7];
	int subWeaponEnchantData[7];

	/* Armor */
	int headwearEnchantData[7];
	int chestwearEnchantData[7];
	int legwearEnchantData[7];
	int shoesEnchantData[7];

	/* Sub Armor */
	int ring_aEnchantData[7];
	int ring_bEnchantData[7];
	int necklaceEnchantData[7];

	/* Game Variables */
	int curMapLocation;
	int curXY[2];

	/* For Display - Data only for displaying, not for calculations */
	char* className;
} charData;

/* Base Stat/Item Table */

/* Stats */
int warriorBase[8] = { 100, 30, 5, 5, 5, 5, 5, 0 };
int archerBase[8] = { 80, 50, 5, 5, 5, 5, 5, 0 };
int wizardBase[8] = { 50, 80, 5, 5, 5, 5, 5, 0 };
int thiefBase[8] = { 75, 55, 5, 5, 5, 5, 5, 0 };

/* Base Armor */
int BaseArmor[4] = { 1, 1, 1, 1 };

/* Base Sub Armor */
int BaseSubArmor[4] = { 1, 1, 1, 1 };

/* Base Enchantment Reset Array */
int enchantEraseBase[7] = { 0, 0, 0, 0, 0, 0, 0 };

/* Functions */
void getInput(char* temp);
void getInput(int* temp);

void charInitialize (charData *mainChar) {
	/* Weapon */
	mainChar->weaponCode = 1;
	mainChar->subWeaponCode = 1;
	copyArr(enchantEraseBase, mainChar->weaponEnchantData, 7);
	copyArr(enchantEraseBase, mainChar->subWeaponEnchantData, 7);

	/* Armor */
	copyArr(BaseArmor, mainChar->equipArmor, 4);
	copyArr(enchantEraseBase, mainChar->chestwearEnchantData, 7);
	copyArr(enchantEraseBase, mainChar->headwearEnchantData, 7);
	copyArr(enchantEraseBase, mainChar->legwearEnchantData, 7);
	copyArr(enchantEraseBase, mainChar->shoesEnchantData, 7);

	/* Sub Armor*/
	copyArr(BaseSubArmor, mainChar->equipSubArmor, 4);
	copyArr(enchantEraseBase, mainChar->necklaceEnchantData, 7);
	copyArr(enchantEraseBase, mainChar->ring_aEnchantData, 7);
	copyArr(enchantEraseBase, mainChar->ring_bEnchantData, 7);

	/* Etc. */
	mainChar->curGold = 3000;
}
void copyArr(int* inputArr, int* outputArr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		outputArr[i] = inputArr[i];
	}
}

void statCalculate(int charClass) {

}

void getInput(char* temp) {
	printf(" > ");
	scanf("%s", temp);
}

void getInput(int* temp) {
	printf(" > ");
	scanf("%s", temp);
}

void mapCase(int caseNum, charData* mainChar, char* temp) {
	/* Function which takes care of map menus */
	switch (caseNum) {
		case 1:
			/* Starting Village aka First Village */
			clscr();
			printf("\n[First Village]\n\n1 Villager, 1 Shop, and 1 Well exists.\n\n");
			getInput(&temp);
			if (strstr(&temp, "shop")) {
				sysCase(4, )
			}
	}
}

void eventCase(int caseNum) {

}

void eventExecute(int caseNum) {

}

void diagCase(int caseNum, char* temp) {

}

void sysCase(int caseNum, char* temp, charData *mainChar) {
	/* Function which takes care of the core results */
	/* Will be taking more of the system, rather than scenarios */
	char Answer;

	switch (caseNum) {
	case 1: 
		/* Character information input section */
		while (1) {
			printf("\nFirst, we need your information.\n");
			printf("\nFirst, enter your username.");
			while (1) {
				printf("\nUsername: ");
				getInput(mainChar->charName);
				printf("Username: %s\nIs this correct? [Y/N] :", mainChar->charName);
				getInput(&Answer);
				if (Answer == "Y") {
					break;
				}
				else if (Answer == "N") {
					printf("Alright, go pick again.\n");
				}
				else {
					printf("Well, go pick again then. \n");
				}
			}
			printf("\nSecondary, pick your class.\n\n[1. Warrior]\n[2. Archer]\n[3. Wizard]\n[4. Thief]\n\n");
			while (1) {
				printf("\nClass: ");
				getInput(mainChar->charClass);
				if (1 <= mainChar->charClass <= 4) sysCase(2, &temp, &mainChar);
				else {
					printf("\nError - No such class exists. CODE : 1");
					printf("\n\nType Again.");
					continue;
				}
				printf("\nClass: %s\nIs this correct? [Y/N] :", mainChar->className);
				getInput(&Answer);
				if (Answer == "Y") {
					break;
				}
				else if (Answer == "N") {
					printf("Alright, go pick again.\n");
				}
				else {
					printf("Well, go pick again then. \n");
				}
			}
			printf("\nAlright, setting up your character...");
			sysCase(3, &temp, &mainChar);
			printf("\nDone!");
			printf("\nYou will be sent to the first village.\n\nWe hope you enjoy your stay!");
			mainChar->curMapLocation = 1;
			break;
		}
		break;
	case 2:
		/* Character class detection */
		if (mainChar->charClass == 1) mainChar->className = "Warrior";
		else if (mainChar->charClass == 2) mainChar->className = "Archer";
		else if (mainChar->charClass == 3) mainChar->className = "Wizard";
		else if (mainChar->charClass == 4) mainChar->className = "Thief";
		else mainChar->className = "MissingClass";
		break;
	case 3:
		/* Character stat calculation & initialization */
		/* Base Stat */
		mainChar->charLevel = 1;
		mainChar->charExp = 0;
		if (mainChar->charClass == 1) copyArr(warriorBase, mainChar->charStat, 8);
		else if (mainChar->charClass == 2) copyArr(archerBase, mainChar->charStat, 8);
		else if (mainChar->charClass == 3) copyArr(wizardBase, mainChar->charStat, 8);
		else if (mainChar->charClass == 4) copyArr(thiefBase, mainChar->charStat, 8);
		else {
			printf("Error - Class is out of range. CODE : 2");
			break;
		}
		/* Initialization */
		charInitialize(&mainChar);
		break;
	case 4:
		/* Shop execution */
		switch (mainChar->curMapLocation) {
		case 1:
			printf("\nShop has 3 items.\n Items: Health Potion[hp], Mana Potion[mp], Return Scroll to First Village[rs].\n\n");
			getInput(&temp);
			if (strstr(&temp, "buy")) {
				if (strstr(&temp, "hp")) {

				}
			}
		}
	default: 
		printf("Error - No such case exists. CODE : 0");
	}
}

int main() {
	/* Main Storyboard */
	/* Variables */
	char* temp = malloc(sizeof(temp)*64);
	charData mainChar;

	/* Dialogues & Basic Structure of the game */
	printf("Test Message: Hello World!\n");
	printf("\nWelcome to the world we call, Elaster.\n");
	printf("\nWant to start your adventures, right?\n");
	sysCase(1, &temp, &mainChar); /* case 0 - Information for the account.*/
	mapCase(mainChar.curMapLocation, &mainChar, &temp);
}