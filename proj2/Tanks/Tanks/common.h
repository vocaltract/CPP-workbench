#pragma once
#define BULLET 0
#define BLANK 1
#define TOUGHWALL 2
#define LIGHTWALL 3
#define TANK 4
#define BASE 7
#define NOP 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define SHOOT 5
#include <string>
#include <Windows.h>
#include <iostream>
#include <cassert>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;
using std::string;
extern const string shape_buf[];
extern const int color_buf[];
#define WHITE (FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE)
#define GREEN (FOREGROUND_INTENSITY|FOREGROUND_GREEN)
#define RED (FOREGROUND_INTENSITY|FOREGROUND_RED)
#define BLUE (FOREGROUND_INTENSITY|FOREGROUND_BLUE)
int map(char inch);
#define MAXENEMIES 3
extern const int act_buf[];
extern bool is_gameover;
#define ACTLEN 6
#define MAXBULLETS 50
extern int score;