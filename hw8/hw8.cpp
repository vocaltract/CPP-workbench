#include <iostream>
#include <cstdio>
#include <Windows.h>
#include <cstring>
#include<time.h>
using std::cout;
using std::endl;
using std::cin;
#pragma warning(disable:4996)
class Screen
{
public:
	void display(char* message, int len);
	Screen(int l, int w);
private:
	int length;
	int width;
};
int code[200];

class Mainboard
{
public:
	Mainboard();
	Mainboard(int d);
	void encode(char* message, int* code, int len);
	void decode(char* message, int* code, int len);
	int decoding(char s);
	int encoding(char s);
private:
	int delay;
};

class TestPhone
{
public:
	TestPhone();
	void sendMessage();
	void sendMessage(char* message);
	void receiveMessage();
	void inputAndDisplay();
	void inputAndDisplay(char* message);
protected:
	Mainboard mainboard;
	Screen screen;
	int code_len;
};

class ReleasePhone:public TestPhone
{
public:
	void dateAndTime();
};

Screen::Screen(int l, int w)
{
	length = l;
	width = w;
}

void Screen::display(char* message, int len)
{
	len--;
	char* s = new char[width+1];
	s[width] = '\0';
	int outp_cont = len / width * width == len ? len / width : len / width + 1;
	for (int i = 0; i < outp_cont; i++)
	{
		if (i % length == 0 && i >= length)
		{
			printf("\n");
		}
		if (i < outp_cont - 1)
		{
			strncpy(s, &message[i * width], width);
			printf("%s\n", s);
		}
		else
		{
			strncpy(s, &message[i * width], len-i*width);
			s[len - i * width] = '\0';
			printf("%s", s);
		}
	}
}

Mainboard::Mainboard()
{
	delay = 0;
}
Mainboard::Mainboard(int d)
{
	delay = d;
}
int Mainboard::encoding(char s)
{
	if (s >= 'a' && s <= 'z')
	{
		return s - 'a';
	}
	if (s == ' ')
	{
		return 26;
	}
	if (s == '\0')
	{
		return -1;
	}
	return s;
}

int Mainboard::decoding(char s)
{
	if (s >= 0 && s <= 25)
	{
		return s + 'a';
	}
	if (s == 26)
	{
		return ' ';
	}
	if (s == -1)
	{
		return '\0';
	}
	return s;
}

void Mainboard::encode(char* message, int* code, int len)
{
	for (int i = 0;i < len; i++)
	{
		code[i] = encoding(message[i]);
		Sleep(delay);
	}
}

void Mainboard::decode(char* message, int* code, int len)
{
	for (int i = 0; i < len; i++)
	{
		message[i] = decoding(code[i]);
		Sleep(delay);
	}
}

TestPhone::TestPhone()
	:mainboard(1), screen(8,12)
{
	code_len = 0;
}

void TestPhone::sendMessage()
{
	char s[200];
	cin.get(s, 200);
	code_len = strlen(s)+1;
	mainboard.encode(s, code, code_len);
}

void TestPhone::receiveMessage()
{
	char s[200];
	mainboard.decode(s, code, code_len);
	screen.display(s, code_len);
}

void TestPhone::inputAndDisplay()
{
	sendMessage();
	receiveMessage();
}

void TestPhone::sendMessage(char* message)
{
	code_len = strlen(message) + 1;
	mainboard.encode(message, code, code_len);
}

void TestPhone::inputAndDisplay(char* message)
{
	sendMessage(message);
	receiveMessage();
}

void ReleasePhone::dateAndTime()
{
	char system_time[200];
	time_t now_time = time(NULL);
	strcpy(system_time, asctime(localtime(&now_time)));
	system_time[strlen(system_time) - 1] = '\0';
	inputAndDisplay(system_time);
}


