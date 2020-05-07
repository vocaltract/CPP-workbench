#pragma once
#include "Block.h"
#include "Tank.h"
#define WIDTH 50
#define LEN 30
#include "Bullets.h"
class Screen
{
public:
	Screen();
	void print_text();
	void print_graphic();
	~Screen();
	void get_input();
	void act_key();
	bool check_walk(int key, const Vector2D& in_loc);
	void move(int key,Item* tank);
	Block& get_block(const Vector2D& loc);
	Block& get_block(int x, int y);
	void do_enemy();
	void update_draw_bullets();
	bool judge_game();
private:
	Block** blocks;
	Item* mytank;
	int cur_key;
	Item* enemy[MAXENEMIES];
	int cur_enemy;
	Bullets all_bullets;
};

