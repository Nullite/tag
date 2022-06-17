#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <algorithm>
#include "variables.h"
#include "check.h"


void fillBoard()
{
	for (int i = 0; i < 15; i++)
	{
		std::string a = std::to_string(tiles[i]);
		if (a.length() == 1)
			a.insert(a.begin(), ' ');
		board.replace(sqears[i], 2, a);
	}
}

void ShuffleTiles()
{
	srand(time(nullptr));
	std::random_shuffle(tiles, std::end(tiles));
}

void game()
{
	while (!numsInPosition())
	{
		system("cls");
		char move;
		std::cout << board;
		while (!_kbhit())
		{
			move = _getch();
			if (move != -32) continue;

		}
		move = _getch();
		switch (move)
		{
		case 'P':
			if (empty < 4) break;
			temp = board.substr(sqears[empty - 4], 2);
			board.replace(sqears[empty - 4], 2, emptyTile);
			board.replace(sqears[empty], 2, temp);
			empty -= 4;
			break;
		case 'H':
			if (empty > 11) break;
			temp = board.substr(sqears[empty + 4], 2);
			board.replace(sqears[empty + 4], 2, emptyTile);
			board.replace(sqears[empty], 2, temp);
			empty += 4;
			break;
		case 'M':
			if (empty == 0 || empty == 4 || empty == 8 || empty == 12) break;
			temp = board.substr(sqears[empty - 1], 2);
			board.replace(sqears[empty -1], 2, emptyTile);
			board.replace(sqears[empty], 2, temp);
			empty -= 1;
			break;
		case 'K':
			if (empty == 3 || empty == 7 || empty == 11 || empty == 15) break;
			temp = board.substr(sqears[empty + 1], 2);
			board.replace(sqears[empty + 1], 2, emptyTile);
			board.replace(sqears[empty], 2, temp);
			empty += 1;
			break;

		}
		system("cls");
		std::cout << board;
	}
}

void congratulations(bool whosePlay)
{
	switch (whosePlay)
	{
	case true:
		std::cout << "\n\n\n\n\n\n\t\t\t\tCONGRATIULATIONS!!! YOU SOLVE THE TAG!";
		Sleep(5000);
		system("cls");
		break;
	case false:
		std::cout << "\n\n\n\n\n\n\t\t\t\t\t\tComputer solve the tag!";
		Sleep(5000);
		system("cls");
		break;
	}
	
}

bool isUserPlay()
{
	while (1)
	{
		system("cls");
		std::cout << "choose player: 1 - user\n\t       2 - computer\n";
		std::string player;
		int choice;
		std::getline(std::cin, player);
		try
		{
			choice = stoi(player);
		}
		catch (std::exception&)
		{
			continue;
		}
		if (choice == 1) return true;
		if (choice == 2) return false;
	}
	system("cls");
}

void setDifficulty(int &difficulty, int &minShuffle, int &maxShuffle)
{
	int choice;
	while (1)
	{
		system("cls");
		std::cout << "choose difficulty: 1 - easy\n\t           2 - medium\n\t           3 - hard\n";
		std::string difficulty;	
		std::getline(std::cin, difficulty);
		try
		{
			choice = stoi(difficulty);
		}
		catch (std::exception&)
		{
			continue;
		}
		if (choice == 1 || choice == 2 || choice == 3) break;
	}
	system("cls");
	minShuffle = choice == 1 ? 60 : choice == 2 ? 300 : 700;
	maxShuffle = choice == 1 ? 100 : choice == 2 ? 450 : 850;
}
