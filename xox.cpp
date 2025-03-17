#include <stdio.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

// Oyun tahtasýný baþlat
void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Oyun tahtasýný ekrana yazdýr
void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j]);
            if (j < BOARD_SIZE - 1) {
                printf(" | ");
            }
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) {
            printf("---------\n");
        }
    }
}

// Hamleyi iþle ve tahtayý güncelle
int makeMove(int row, int col, char player) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ') {
        // Geçersiz hamle
        return 0;
    }

    board[row][col] = player;
    return 1;
}

// Oyunun galibi var mý kontrol et
char checkWinner() {
   
    // Satýrlarý kontrol et
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }

    // Sütunlarý kontrol et
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i];
        }
    }

    // Çaprazlarý kontrol et
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }

    // Beraberlik durumu
    int draw = 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                draw = 0;
                break;
            }
        }
        if (!draw) {
            break;
        }
    }
    if (draw) {
        return 'D'; // Beraberlik durumu
    }

    return ' '; // Devam eden oyun durumu
}

int main() {
    int row, col;
    char currentPlayer = 'X';
    char winner = ' ';

    initializeBoard();

    do {
        printBoard();

        // Sýradaki oyuncunun hamlesini al
        printf("Sira %c oyuncusunda. Satir ve sutun numaralarini sirasiyla girin (0-2 arasi): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Hamleyi yap ve tahtayý güncelle
        if (makeMove(row, col, currentPlayer)) {
            // Oyun tahtasýný kontrol et
            winner = checkWinner();
            if (winner == ' ') {
                // Sýradaki oyuncuyu deðiþtir
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            printf("Gecersiz hamle. Lutfen tekrar deneyin.\n");
        }

    } while (winner == ' ');

    printBoard();

    // Oyunun sonucunu bildir
    if (winner == 'D') {
        printf("Oyun berabere bitti.\n");
    } else {
        printf("Oyunu kazanan: %c oyuncusu!\n", winner);
    }

    return 0;
}

