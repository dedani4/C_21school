#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 25

void game_of_life(int matrix[][WIDTH], int temp[][WIDTH]);
void read_position(int matrix[][WIDTH]);
void print_matrix(int matrix[][WIDTH]);
int check_matrix(int matrix[][WIDTH]);
void cell_cycle(int matrix[][WIDTH], int temp[][WIDTH]);
int check_cell(int matrix[][WIDTH], int i, int j);

int main() {
    int matrix[HEIGHT][WIDTH] = {0};
    int temp[HEIGHT][WIDTH] = {0};
    read_position(matrix);
    game_of_life(matrix, temp);
    return 0;
}

void game_of_life(int matrix[][WIDTH], int temp[][WIDTH]) {
    int delay = 250000;
    char quit = '0';
    while (check_matrix(matrix) && quit == '0') {
        initscr();
        cell_cycle(matrix, temp);
        print_matrix(matrix);
        FILE *f = freopen("/dev/tty", "r", stdin);
        nodelay(stdscr, 1);
        char input = getch();
        while (getch() != -1) {
        }
        if (input == 'a')
            if (delay > 50000) delay -= 50000;
        if (input == 'z')
            if (delay < 2e+6) delay += 50000;
        if (input == 'q') quit = '1';
        usleep(delay);
        endwin();
        fclose(f);
    }
}

void read_position(int matrix[][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void print_matrix(int matrix[][WIDTH]) {
    system("clear");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (matrix[i][j] == 0)
                printf(" ");
            else
                printf("O");
        }
        printf("\n");
    }
}

void cell_cycle(int matrix[][WIDTH], int temp[][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            temp[i][j] = check_cell(matrix, i, j);
        }
    }
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
}

int check_matrix(int matrix[][WIDTH]) {
    int count = 0;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (matrix[i][j]) count++;
        }
    }
    return count;
}

int check_cell(int matrix[][WIDTH], int i, int j) {
    int neighbors = 0, life;
    for (int k = -1; k < 2; k++) {
        for (int l = -1; l < 2; l++) {
            neighbors = neighbors + matrix[(HEIGHT + i + k) % HEIGHT][(WIDTH + j + l) % WIDTH];
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
