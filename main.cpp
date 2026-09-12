#include <cstdint>
#include <string>
#include <iostream>
using namespace std;

enum Square {
    a1, b1, c1, d1, e1, f1, g1, h1,
    a2, b2, c2, d2, e2, f2, g2, h2,
    a3, b3, c3, d3, e3, f3, g3, h3,
    a4, b4, c4, d4, e4, f4, g4, h4,
    a5, b5, c5, d5, e5, f5, g5, h5,
    a6, b6, c6, d6, e6, f6, g6, h6,
    a7, b7, c7, d7, e7, f7, g7, h7,
    a8, b8, c8, d8, e8, f8, g8, h8
};

struct Board {
    uint64_t white_pawns;
    uint64_t white_knights;
    uint64_t white_bishops;
    uint64_t white_rooks;
    uint64_t white_queens;
    uint64_t white_king;
    uint64_t black_pawns;
    uint64_t black_knights;
    uint64_t black_bishops;
    uint64_t black_rooks;
    uint64_t black_queens;
    uint64_t black_king;
};

void print_board(Board pos) {
    for (int rank = 7; rank >= 0; --rank) {
        for (int file = 0; file < 8; ++file) {
            int square = rank * 8 + file;
            uint64_t probe = 1ULL << square;
            if (pos.white_pawns & probe) cout << "P ";
            else if (pos.white_knights & probe) cout << "N ";
            else if (pos.white_bishops & probe) cout << "B ";
            else if (pos.white_rooks & probe) cout << "R ";
            else if (pos.white_queens & probe) cout << "Q ";
            else if (pos.white_king & probe) cout << "K ";
            else if (pos.black_pawns & probe) cout << "p ";
            else if (pos.black_knights & probe) cout << "n ";
            else if (pos.black_bishops & probe) cout << "b ";
            else if (pos.black_rooks & probe) cout << "r ";
            else if (pos.black_queens & probe) cout << "q ";
            else if (pos.black_king & probe) cout << "k ";
            else cout << ". ";
        }
        cout << "\n";
    }
}

Board parse_fen(string fen) {
    Board pos = {};
    int rank = 7;
    int file = 0;

    for (char c : fen) {
        if (c == ' ') break;

        if (c == '/') {
            rank--;
            file = 0;
        }
        else if (c >= '1' && c <= '8') {
            file += c - '0';
        }
        else {
            int square = rank * 8 + file;
            uint64_t bit = 1ULL << square;

            if      (c == 'P') pos.white_pawns   |= bit;
            else if (c == 'N') pos.white_knights |= bit;
            else if (c == 'B') pos.white_bishops |= bit;
            else if (c == 'R') pos.white_rooks   |= bit;
            else if (c == 'Q') pos.white_queens  |= bit;
            else if (c == 'K') pos.white_king    |= bit;
            else if (c == 'p') pos.black_pawns   |= bit;
            else if (c == 'n') pos.black_knights |= bit;
            else if (c == 'b') pos.black_bishops |= bit;
            else if (c == 'r') pos.black_rooks   |= bit;
            else if (c == 'q') pos.black_queens  |= bit;
            else if (c == 'k') pos.black_king    |= bit;

            file++;
        }
    }

    return pos;
}

int main() {
    Board board = parse_fen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    print_board(board);
    return 0;
}