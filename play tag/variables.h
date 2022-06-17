#pragma once
#include <vector>
std::string board = "+------+------+------+------+\n|      |      |      |      |\n|      |      |      |      |\n|      |      |      |      |\n+------+------+------+------+\n|      |      |      |      |\n|      |      |      |      |\n|      |      |      |      |\n+------+------+------+------+\n|      |      |      |      |\n|      |      |      |      |\n|      |      |      |      |\n+------+------+------+------+\n|      |      |      |      |\n|      |      |      |      |\n|      |      |      |      |\n+------+------+------+------+\n";
int sqears[16]{ 63, 70, 77, 84, 183, 190, 197, 204, 303, 310, 317, 324, 423, 430, 437, 444 };
int tiles[15]{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
std::string emptyTile = "  ";
std::string temp;
int empty = 15;
std::vector<int> buttonPress;
bool whosePlay;
int difficulty;
int minShuffle;
int maxShuffle;