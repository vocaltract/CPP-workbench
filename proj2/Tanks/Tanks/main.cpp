
#include "Screen.h"
#include "common.h"
#include <ctime>
int main()
{
	Screen myscreen;
	srand(time(NULL));
	while (true)
	{
		myscreen.do_enemy();
		myscreen.update_draw_bullets();
		myscreen.get_input();
		myscreen.act_key();
		system("cls");
		myscreen.print_graphic();
		myscreen.print_text();
		if (myscreen.judge_game()) break;
	}
	cout << "Gameover!" << endl;
	system("pause");
}