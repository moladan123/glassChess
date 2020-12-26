#include "main.h"

class State
{
    std::vector<State> allPossibleMoves() const
    {
        // Get all moves, including illegal ones
        std::vector<State> allMoves{};
        for (int x = 0; x < 8; x++)
        {
            for (int y = 0; y < 8; y++)
            {
            }
        }

        // TODO filter out illegal moves (IE ones that leave the player in check)

        return allMoves;
    }
};

class Piece
{
public:
    virtual std::vector<State> legalMoves(State &state, coordinate position) const = 0;
};

class StandardPiece : Piece
{
protected:
    virtual bool onlyOneMove() const = 0; // King and knight
    virtual bool isDiagonal() const = 0;  // King, Queen, Bishop
    virtual bool isVertical() const = 0;  // King, Queen, Rook

public:
    std::vector<State> legalMoves(State &state, coordinate position) const
    {
    }
};

class Bishop : StandardPiece
{
protected:
    bool onlyOneMove()
    {
        return false;
    }

    bool isDiagonal()
    {
        return true;
    }

    bool isVertical()
    {
        return false;
    }
};

class Rook : StandardPiece
{
    bool onlyOneMove()
    {
        return false;
    }

    bool isDiagonal()
    {
        return false;
    }

    bool isVertical()
    {
        return true;
    }
};

class Queen : StandardPiece
{
    bool onlyOneMove()
    {
        return false;
    }

    bool isDiagonal()
    {
        return true;
    }

    bool isVertical()
    {
        return true;
    }
};

class King : StandardPiece
{
    bool onlyOneMove()
    {
        return true;
    }

    bool isDiagonal()
    {
        return true;
    }

    bool isVertical()
    {
        return true;
    }
};

class Knight : Piece
{
public:
    std::vector<State> legalMoves(State &state, coordinate position) const
    {
    }
};

class Pawn : Piece
{
public:
    std::vector<State> legalMoves(State &state, coordinate position) const
    {
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
