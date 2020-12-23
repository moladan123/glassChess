#include <iostream>
#include <array>
#include <vector>

#define coordinate std::array<char, 2>
#define piece unsigned char

// Utility functions to deal with the colors of pieces
#define WHITE_BITMASK 0b10000000
inline bool isWhite(piece p)
{
    return (p & WHITE_BITMASK) > 0;
}
inline void setWhite(piece &p)
{
    p |= WHITE_BITMASK;
}
inline void setBlack(piece &p)
{
    p &= ~WHITE_BITMASK;
}

piece PAWN = 'p';
piece BISHOP = 'b';
piece KNIGHT = 'n';
piece ROOK = 'r';
piece QUEEN = 'q';
piece KING = 'k';

// Some constants for accessing information from State and Move classes
const int KINGSIDE = 0;
const int QUEENSIDE = 1;

const int WHITE = 0;
const int BLACK = 1;

class State
{
public:
    unsigned char board[8][8];
    bool whiteToMove;

    bool movesMade;         // Full move number (for algebraic notation)
    bool halfMovesMade;     // Number of turns taken by players (for 50 move repitition)
    bool castleAvail[2][2]; // Whether castling is available
                            // Accessed by castleAvail[color][side]

    bool enPassantAvailable;      // If a length 2 pawn move was made last turn
    coordinate enPassantLocation; // Which square can be taken via en passant

    std::vector<State> allPossibleMoves() const
    {
        std::vector<State> allMoves{};

        return allMoves;
    }
};

class Move
{
private:
public:
    // 0 based index of where on the board it is
    coordinate from;
    coordinate to;

    bool castleKingside = false;
    bool castleQueenside = false;

    Move() = delete;
    Move(std::string ean)
    {
        if (ean.find("O-O") == 0)
        {
            if (ean.find("O-O-O"))
            {
                castleQueenside = true;
                return;
            }
            else
            {
                castleKingside = true;
                return;
            }
        }

        from = {(char)(ean[0] - 'a'), (char)(ean[1] - '1')};
        to = {(char)(ean[2] - 'a'), (char)(ean[3] - '1')};
    }

    std::string asEan() const
    {
        return {
            (char)(from[0] + 'a'),
            (char)(from[1] + '1'),
            (char)(to[0] + 'a'),
            (char)(to[1] + '1')};
    }
};

main()
{
    Move a("e2e4");

    std::cout << a.asEan() << std::endl;

    return 0;
}
