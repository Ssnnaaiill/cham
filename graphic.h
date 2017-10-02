#pragma once
#include <stdio.h>
#include <windows.h>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#define BGM "8bit24.wav"

void bgmPlayer() { PlaySound(TEXT(BGM), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); }

void gotoxy(int x, int y) {
	COORD pos = { 2 * x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void interf(FILE *pFile) {
	if (pFile != NULL) {
		char strTemp[255], *pStr;
		while (!feof(pFile)) {
			pStr = fgets(strTemp, sizeof(strTemp), pFile);
			printf("%s", pStr);
		}
		fclose(pFile);
	}
}

void comArrow(int hand) {
	int x = 13, y = 10;
	switch (hand) {
	case 0:
		gotoxy(x, y);	  printf("    ﹥");
		gotoxy(x, y + 1); printf("  ﹥﹥");
		gotoxy(x, y + 2); printf("﹥﹥﹥﹥﹥﹥﹥");
		gotoxy(x, y + 3); printf("  ﹥﹥");
		gotoxy(x, y + 4); printf("    ﹥");
		break;
	case 1:
		gotoxy(x, y);	  printf("        ﹥");
		gotoxy(x, y + 1); printf("        ﹥﹥");
		gotoxy(x, y + 2); printf("﹥﹥﹥﹥﹥﹥﹥");
		gotoxy(x, y + 3); printf("        ﹥﹥");
		gotoxy(x, y + 4); printf("        ﹥");
		break;
	case 2:
		gotoxy(x + 1, y - 1); printf("    ﹥");
		gotoxy(x + 1, y);	  printf("  ﹥﹥﹥");
		gotoxy(x + 1, y + 1); printf("﹥﹥﹥﹥﹥");
		gotoxy(x + 1, y + 2); printf("    ﹥");
		gotoxy(x + 1, y + 3); printf("    ﹥");
		gotoxy(x + 1, y + 4); printf("    ﹥");
		gotoxy(x + 1, y + 5); printf("    ﹥");
		break;
	case 3:
		gotoxy(x + 1, y - 1); printf("    ﹥");
		gotoxy(x + 1, y);	  printf("    ﹥");
		gotoxy(x + 1, y + 1); printf("    ﹥");
		gotoxy(x + 1, y + 2); printf("    ﹥");
		gotoxy(x + 1, y + 3); printf("﹥﹥﹥﹥﹥");
		gotoxy(x + 1, y + 4); printf("  ﹥﹥﹥");
		gotoxy(x + 1, y + 5); printf("    ﹥");
		break;
	default:break;
	}
}

void myArrow(int choice) {
	int x = 36, y = 10;
	switch (choice) {
	case 0:
		gotoxy(x, y);	  printf("    ﹥");
		gotoxy(x, y + 1); printf("  ﹥﹥");
		gotoxy(x, y + 2); printf("﹥﹥﹥﹥﹥﹥﹥");
		gotoxy(x, y + 3); printf("  ﹥﹥");
		gotoxy(x, y + 4); printf("    ﹥");
		break;
	case 1:
		gotoxy(x, y);	  printf("        ﹥");
		gotoxy(x, y + 1); printf("        ﹥﹥");
		gotoxy(x, y + 2); printf("﹥﹥﹥﹥﹥﹥﹥");
		gotoxy(x, y + 3); printf("        ﹥﹥");
		gotoxy(x, y + 4); printf("        ﹥");
		break;
	case 2:
		gotoxy(x + 1, y - 1); printf("    ﹥");
		gotoxy(x + 1, y);	  printf("  ﹥﹥﹥");
		gotoxy(x + 1, y + 1); printf("﹥﹥﹥﹥﹥");
		gotoxy(x + 1, y + 2); printf("    ﹥");
		gotoxy(x + 1, y + 3); printf("    ﹥");
		gotoxy(x + 1, y + 4); printf("    ﹥");
		gotoxy(x + 1, y + 5); printf("    ﹥");
		break;
	case 3:
		gotoxy(x + 1, y - 1); printf("    ﹥");
		gotoxy(x + 1, y);	  printf("    ﹥");
		gotoxy(x + 1, y + 1); printf("    ﹥");
		gotoxy(x + 1, y + 2); printf("    ﹥");
		gotoxy(x + 1, y + 3); printf("﹥﹥﹥﹥﹥");
		gotoxy(x + 1, y + 4); printf("  ﹥﹥﹥");
		gotoxy(x + 1, y + 5); printf("    ﹥");
		break;
	default:break;
	}
}

void loading(int option) {
	if (option < 3) {
		gotoxy(24, 11); printf("忙式式式式式式式式式式忖");
		gotoxy(24, 12);
		if (option == 1) printf("弛 Ⅱ Loading Game... 弛");
		else if (option == 2) printf("弛 Ⅱ Leaving Game... 弛");
		gotoxy(24, 13); printf("戌式式式式式式式式式式戎");
	}
	else {
		gotoxy(22, 10); printf("                        ");
		gotoxy(22, 11); printf("忙式式式式式式式式式式忖");
		gotoxy(22, 12); printf("弛 Ⅱ Loading Menu... 弛");
		gotoxy(22, 13); printf("戌式式式式式式式式式式戎");
		gotoxy(22, 14); printf("                        ");
	}
	Sleep(1000);
}