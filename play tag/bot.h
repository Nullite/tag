#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <algorithm>
#include "variables.h"
#include "check.h"
#include <random>

int randomizer(int from, int to)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(from, to);
	return dist(gen);
}

void botGame()
{
	
		system("cls");
		int move;
		int nextMove;
		for (int i = buttonPress.size() - 1; i >= 0; i--)
		{
			move = buttonPress[i];
			if (i > 0)
			{
				nextMove = buttonPress[i - 1];
				if (move + nextMove == 1 || move + nextMove == 5)
				{
					i -= 1;
					continue;
				}
			}
			
			if (move == 0) move = 1;
			else if (move == 1) move = 0;
			else if (move == 2) move = 3;
			else move = 2;
			switch (move)
			{
			case 0:
				if (empty < 4) break;
				temp = board.substr(sqears[empty - 4], 2);
				board.replace(sqears[empty - 4], 2, emptyTile);
				board.replace(sqears[empty], 2, temp);
				empty -= 4;

				break;
			case 1:
				if (empty > 11) break;
				temp = board.substr(sqears[empty + 4], 2);
				board.replace(sqears[empty + 4], 2, emptyTile);
				board.replace(sqears[empty], 2, temp);
				empty += 4;

				break;
			case 2:
				if (empty == 0 || empty == 4 || empty == 8 || empty == 12) break;
				temp = board.substr(sqears[empty - 1], 2);
				board.replace(sqears[empty - 1], 2, emptyTile);
				board.replace(sqears[empty], 2, temp);
				empty -= 1;

				break;
			case 3:
				if (empty == 3 || empty == 7 || empty == 11 || empty == 15) break;
				temp = board.substr(sqears[empty + 1], 2);
				board.replace(sqears[empty + 1], 2, emptyTile);
				board.replace(sqears[empty], 2, temp);
				empty += 1;

				break;

			}
			system("cls");
			std::cout << board;
			Sleep(150);
			
		}
}

void botShuffle()
{
	int count = 0;
	int steps = randomizer(minShuffle, maxShuffle);
	while (count < steps)
	{
		int move;

		move = randomizer(0, 3);
		
		switch (move)
		{
		case 0:
			if (empty < 4) break;
			buttonPress.push_back(move);
			temp = board.substr(sqears[empty - 4], 2);
			board.replace(sqears[empty - 4], 2, emptyTile);
			board.replace(sqears[empty], 2, temp);
			empty -= 4;
			break;
		case 1:
			if (empty > 11) break;
			buttonPress.push_back(move);
			temp = board.substr(sqears[empty + 4], 2);
			board.replace(sqears[empty + 4], 2, emptyTile);
			board.replace(sqears[empty], 2, temp);
			empty += 4;
			break;
		case 2:
			if (empty == 0 || empty == 4 || empty == 8 || empty == 12) break;
			buttonPress.push_back(move);
			temp = board.substr(sqears[empty - 1], 2);
			board.replace(sqears[empty - 1], 2, emptyTile);
			board.replace(sqears[empty], 2, temp);
			empty -= 1;
			break;
		case 3:
			if (empty == 3 || empty == 7 || empty == 11 || empty == 15) break;
			buttonPress.push_back(move);
			temp = board.substr(sqears[empty + 1], 2);
			board.replace(sqears[empty + 1], 2, emptyTile);
			board.replace(sqears[empty], 2, temp);
			empty += 1;
			break;
		}
		count++;
	}
}
