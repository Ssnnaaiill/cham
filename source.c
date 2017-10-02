#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "graphic.h"
#include "tutorial.h"

int bestScore = 0;

void cham();
void reset();
char printScore(int score);

void main() {
	reset();
	system("color E0");
	bgmPlayer();
	while (1) {
		tutoMain();
		cham();
	}
}

void cham() {
	int choice, hand, score = 0, flag = 0;
	srand((unsigned)time(NULL));
	FILE *pFile;
	fopen_s(&pFile, "interface.dat", "r");
	
	interf(pFile);
	while (flag == 0) {
		hand = rand() % 4;
		choice = _getch();
		system("cls");
		fopen_s(&pFile, "interface.dat", "r");
		interf(pFile);

		if (choice == 224) {
			choice = _getch();
			switch (choice) {
			case 75: choice = 0; break;
			case 77: choice = 1; break;
			case 72: choice = 2; break;
			case 80: choice = 3; break;
			default: break;
			}
		}
		if(choice >= 0 && choice < 4) comArrow(hand);
		myArrow(choice);
		if (choice == hand) flag++;
		else if((choice >= 0 && choice < 4) && choice != hand) score += 100;
	}

	char c = printScore(score);
	if (c == 27 || c == 'n' || c == 'N') { loading(3); system("cls"); }
	else { system("cls"); cham(); }
}

char printScore(int score) {
	int x = 22, y = 10, i;
	char c;

	gotoxy(x, y);	  printf("¦£"); for (i = 0; i < 10; i++) printf("¦¡"); printf("¦¤");
	gotoxy(x, y + 1); printf("¦¢                    ¦¢");
	gotoxy(x, y + 2); printf("¦¢                    ¦¢");
	gotoxy(x, y + 3); printf("¦¢                    ¦¢");
	gotoxy(x, y + 4); printf("¦¦"); for (i = 0; i < 10; i++) printf("¦¡"); printf("¦¥");

	if (score < 100) gotoxy(x + 3, y + 1);
	else if (score >= 100) gotoxy(x + 2, y + 1);
	else if (score >= 10000) gotoxy(x + 1, y + 1);
	else gotoxy(x, y + 1);
	printf("¡Ø score : %d", score);
	if (score > bestScore) {
		gotoxy(x + 2, y + 2);
		printf("¡Ù BEST SCORE! ¡Ú");
		bestScore = score;
		FILE* file;
		fopen_s(&file, "score", "wt");
		if (file == 0) {
			gotoxy(0, 0);
			printf("FILE ERROR: SYSTEM CANNOT WRITE BEST SCORE ON \"SCORE\"");
		}
		else {
			fprintf(file, "%d", score);
			fclose(file);
		}
	}
	else { gotoxy(x + 2, y + 2); printf(" Best Score : %d", bestScore); }
	gotoxy(x + 1, y + 3); printf(" Press ESC for MENU");
	c = _getch();
	return c;
}

void reset() {
	FILE *file;
	fopen_s(&file, "score", "rt");
	if (file == 0) bestScore = 0;
	else {
		fscanf_s(file, "%d", &bestScore);
		fclose(file);
	}
}