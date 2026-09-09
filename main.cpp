#include <cstdint>
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

int main() {
    Board board;
    board.white_pawns   = (1ULL << a2) | (1ULL << b2) | (1ULL << c2) | (1ULL << d2) |
                          (1ULL << e2) | (1ULL << f2) | (1ULL << g2) | (1ULL << h2);
    board.white_knights = (1ULL << b1) | (1ULL << g1);
    board.white_bishops = (1ULL << c1) | (1ULL << f1);
    board.white_rooks   = (1ULL << a1) | (1ULL << h1);
    board.white_queens  = (1ULL << d1);
    board.white_king    = (1ULL << e1);
    board.black_pawns   = (1ULL << a7) | (1ULL << b7) | (1ULL << c7) | (1ULL << d7) |
                          (1ULL << e7) | (1ULL << f7) | (1ULL << g7) | (1ULL << h7);
    board.black_knights = (1ULL << b8) | (1ULL << g8);
    board.black_bishops = (1ULL << c8) | (1ULL << f8);
    board.black_rooks   = (1ULL << a8) | (1ULL << h8);
    board.black_queens  = (1ULL << d8);
    board.black_king    = (1ULL << e8);

    print_board(board);
    return 0;
}