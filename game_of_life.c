#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define W 80
#define H 25

void game_of_life(int matrix[][W], int temp[][W]);
void read_position(int matrix[][W]);
void print_matrix(int matrix[][W]);
int check_matrix(int matrix[][W]);
void new_generation(int matrix[][W], int temp[][W]);
int check_cell(int matrix[][W], int i, int j);

int main() {
    int matrix[H][W] = {0};
    int temp[H][W] = {0};
    read_position(matrix);
    game_of_life(matrix, temp);
    return 0;
}

void game_of_life(int matrix[][W], int temp[][W]) {
    int delay = 250000;
    char quit = '0';
    while (check_matrix(matrix) && quit == '0') {
        initscr();
        // cbreak();
        // noecho();
        new_generation(matrix, temp);
        print_matrix(matrix);
        FILE *f = freopen("/dev/tty", "r", stdin);
        nodelay(stdscr, 1);
        char input = getch();
        // while (getch() != -1) {
        // }

        if (input == 'a')
            if (delay > 50000) delay -= 50000;
        if (input == 'z')
            if (delay < 2e+6) delay += 50000;
        if (input == 'q') quit = '1';
        usleep(delay);
        // system("clear");
        endwin();
        fclose(f);
    }
}

void read_position(int matrix[][W]) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void print_matrix(int matrix[][W]) {
    system("clear");
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (matrix[i][j] == 0)
                printf(" ");
            else
                printf("O");
        }
        printf("\n");
    }
}

void new_generation(int matrix[][W], int temp[][W]) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            temp[i][j] = check_cell(matrix, i, j);
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
}

int check_matrix(int matrix[][W]) {
    int count = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (matrix[i][j]) count++;
        }
    }
    return count;
}

int check_cell(int matrix[][W], int i, int j) {
    int neighbors = 0, life;
    for (int k = -1; k < 2; k++) {
        for (int l = -1; l < 2; l++) {
            neighbors = neighbors + matrix[(H + i + k) % H][(W + j + l) % W];
        }
    }
    if (matrix[i][j]) {
        if (neighbors < 3 || neighbors > 4)
            life = 0;
        else
            life = 1;
    } else {
        if (neighbors == 3)
            life = 1;
        else
            life = 0;
    }
    return life;
}
