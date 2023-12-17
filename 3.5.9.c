#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 31
#define M 21


int input(char str[][M]) {
	char ch;
	int n = 0, i = 0, j = 0, flag = 1, c = 0;
    printf("Enter sentence:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            scanf_s("%c", &ch);
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                c++;
                if (c == M) {
                    printf("Error, word is full!");
                    return 0;
                }
                str[i][j] = ch;
            }
            else if (ch == ' ') {
                if (c != 0) {
                    str[i][j] = '\0';
                    n++;
                    if (n == N) {
                        printf("Error, sentence is full!");
                        return 0;
                    }
                    c = 0;
                    break;
                }
                else
                    j--;
            }
            else if ((ch == '.') || (ch == '!') || (ch == '?')) {
                if (c == 0) {
                    printf("Enter void string.");
                    return 0;
                }
                str[i][j] = '\0';
                n++;
                if (n == N) {
                    printf("Error, sentence is full!");
                    return 0;
                }
                flag = 0;
                break;
            }
            else {
                printf("Error. Invalid character entered.");
                return 0;
            }
        }
        if (flag == 0)
            break;
    }
	return n;
}

int output(char str[][M], int n , int k, char ch) {
    int i, j, count;
    for (i = 0; i < n; i++) {
        count = 0;
        for (j = 0; str[i][j] != '\0'; j++) {
            count++;
        }
        if (count >= k) {
            str[i][count - k] = ch;
            printf("%s ", str[i]);
        }
    }
    return 0;
}

int main(){
	char str[N][M], ch, tmp;
	int n, i, j, k = 0, count = 0;
	n = input(str);
    if (!n) return 0;
    scanf("%c", &tmp);
    scanf("%c", &ch);
    if (!(('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z'))) {
        printf("U cannot use prohibited characters!");
        return 0;
    }
    if (!scanf("%d", &k)) {
        printf("You can only use numbers!");
        return 0;
    }
    output(str, n, k, ch);
	return 0;
}