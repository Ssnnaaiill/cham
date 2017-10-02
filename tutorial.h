#pragma once
#include <conio.h>
#include <windows.h>
#include "graphic.h"

void gameTutorial() {
	FILE *pFile;
	fopen_s(&pFile, "gameTutorial.dat", "r");
	interf(pFile);
	_getch(); system("cls");
}

void developer() {
	FILE *pFile;
	fopen_s(&pFile, "developer.dat", "r");
	interf(pFile);
	_getch(); system("cls");
}

void tutoMain() {
	char c;
	FILE *pFile;
	fopen_s(&pFile, "tutoinfo.dat", "r");
	interf(pFile); gotoxy(30, 12);
	while(1) {
		c = _getch();
		if (c == '1') { loading(1); break; }
		system("cls");
		switch (c) {
		case '2': gameTutorial(); break;
		case '3': developer(); break;
		case '4': loading(2); exit(1); break;
		default: fopen_s(&pFile, "tutoinfo.dat", "r"); break;
		}
		fopen_s(&pFile, "tutoinfo.dat", "r");
		interf(pFile); gotoxy(30, 12);
	}
	Sleep(500); system("cls");
}