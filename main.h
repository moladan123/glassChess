#pragma once

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