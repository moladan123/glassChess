#include <iostream>
#include <array>

#define coordinate std::array<char, 2>

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
};

class Move
{
private:
public:
    // 0 based index of where on the board it is
    coordinate from;
    coordinate to;

    Move() = delete;
    Move(std::string ean)
    {
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
