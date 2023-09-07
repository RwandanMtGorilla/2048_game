#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#define  n 8	//size of the map
long num, a[n][n],err,score;
void swap(int* a, int* b) {
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
int rnd(unsigned int a) {
	int ans = a/2;
	float b=rand();
	ans = (int)a * (b / 32767.0);
	return ans;
}
void display() {
	int i, m;
	for (i = 0; i < n; i++) {//output
		for (m = 0; m < n; m++) {
			if (a[i][m] == 0) { printf("     "); }
			else { printf("%5d", a[i][m]); }
		}
		printf("\n\n");
	}
	printf("\n\n");
}
void merge(char mode) {
	int i, m,k,tmp;
	char in;
	if (mode == '4' || mode == 'a') {
		for (i = 0; i < n; i++) {
			m = 1;
			while (m < n&&m>=1) {
				while (a[i][m - 1] == 0 && a[i][m] != 0&&m>0) {
					swap(&a[i][m - 1], &a[i][m]);
					//display();
					m--;
				}
				m++;
			}
		}
		//display();
		for (i = 0; i < n; i++) {
			for (m = 0; m < n-1; m++) {
				if (a[i][m + 1] == a[i][m]&& a[i][m]!=0) {
					a[i][m] = a[i][m] * 2;
					score += a[i][m];
					a[i][m+1] = 0;
					num++;
					m++;
				}
			}
		}
		//display();
		for (i = 0; i < n; i++) {
			m = 1;
			while (m < n && m >= 1) {
				while (a[i][m - 1] == 0 && a[i][m] != 0 && m > 0) {
					swap(&a[i][m - 1], &a[i][m]);
					m--;
				}
				m++;
			}
		}
	}
	else if (mode == '8'|| mode == 'w') {
		for (m = 0; m < n; m++) {
			i = 1;
			while (i < n && i >= 1) {
				while (a[i-1][m] == 0 && a[i][m] != 0 && i > 0) {
					swap(&a[i-1][m], &a[i][m]);
					//display();
					i--;
				}
				i++;
			}
		}
		//display();
		for (m = 0; m < n; m++) {
			for (i = 0; i < n - 1; i++) {
				if (a[i+1][m] == a[i][m] && a[i][m] != 0) {
					a[i][m] = a[i][m] * 2;
					score += a[i][m];
					a[i+1][m] = 0;
					num++;
					i++;
				}
			}
		}
		//display();
		for (m = 0; m < n; m++) {
			i = 1;
			while (i < n && i >= 1) {
				while (a[i - 1][m] == 0 && a[i][m] != 0 && i > 0) {
					swap(&a[i - 1][m], &a[i][m]);
					//display();
					i--;
				}
				i++;
			}
		}
	}
	else if (mode == '6' || mode == 'd') {
		for (i = 0; i < n; i++) {
			m = n-2;
			while (m < n-1 && m >= 0) {
				while (a[i][m + 1] == 0 && a[i][m] != 0 && m < n-1) {
					swap(&a[i][m + 1], &a[i][m]);
					//display();
					m++;
				}
				m--;
			}
		}
		//display();
		for (i = 0; i < n; i++) {
			for (m = n-1; m >0; m--) {
				if (a[i][m - 1] == a[i][m] && a[i][m] != 0) {
					a[i][m] = a[i][m] * 2;
					score += a[i][m];
					a[i][m - 1] = 0;
					num++;
					m--;
				}
			}
		}
		//display();
		for (i = 0; i < n; i++) {
			m = n - 2;
			while (m < n-1 && m >= 0) {
				while (a[i][m + 1] == 0 && a[i][m] != 0 && m < n - 1) {
					swap(&a[i][m + 1], &a[i][m]);
					//display();
					m++;
				}
				m--;
			}
		}
	}
	else if (mode == '2' || mode == 's' || mode == '5') {
		for (m = 0; m < n; m++) {
			i = n - 2;
			while (i < n - 1 && i >= 0) {
				while (a[i+1][m] == 0 && a[i][m] != 0 && i < n - 1) {
					swap(&a[i+1][m], &a[i][m]);
					//display();
					i++;
				}
				i--;
			}
		}
		//display();
		for (m = 0; m < n; m++) {
			for (i = n - 1; i > 0; i--) {
				if (a[i-1][m] == a[i][m] && a[i][m] != 0) {
					a[i][m] = a[i][m] * 2;
					score += a[i][m];
					a[i-1][m] = 0;
					num++;
					i--;
				}
			}
		}
		//display();
		for (m = 0; m < n; m++) {
			i = n - 2;
			while (i < n - 1 && i >= 0) {
				while (a[i + 1][m] == 0 && a[i][m] != 0 && i < n - 1) {
					swap(&a[i + 1][m], &a[i][m]);
					//display();
					i++;
				}
				i--;
			}
		}
	}
	else {
	printf("Press'8''6''4''2'to play..\n");
	in = getch();
	merge(in);
	}
}
void initialize() {
	printf("Initializing...\n");
	int i, m;
	srand((unsigned int)time(NULL));
	for (i = 0; i < n; i++) {//start
		for (m = 0; m < n; m++) {
			a[i][m] = 0;
		}
	}
	num = n * n;
	err = 0;
	score = 0;
	printf("Done!\n");
}
void gameloop() {
	int i, m, k, tmp;
	char in;
	while (err == 0) {
		//check empty boxes
		tmp = rnd(num) + 1;
		for (i = 0; i < n; i++) {//rnd new box
			for (m = 0; m < n; m++) {
				if (a[i][m] == 0) {
					tmp--;
					if (tmp == 0) {
						a[i][m] = 2;
						num--;
						if (num == 0) {
							err = 1;
						}
						break;
					}
				}
			}
			if (tmp == 0) { break; }
		}
		display();
		//scanf("%c\n", &in);
		in = getch();
		merge(in);
	}
}
void end() {
	printf("Gameover...\n\nScore=%ld",score);
	while (1) {
		getch();
	}
}
int main(){
	initialize();
	gameloop();
	end();
}
