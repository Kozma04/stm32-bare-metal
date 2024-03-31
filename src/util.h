#pragma once


#define BIT(pos) (1UL << (pos))
#define SET_BIT(lhs, pos, val) ((lhs) = ((lhs) & (~(1 << (pos)))) | ((val) << (pos)))
#define GET_BIT(lhs, pos) (lhs >> (pos) & 1)
#define SET_BITS(lhs, size, pos, val) ((lhs) = (((lhs) & (~(((1 << (size)) - 1) << pos)))) | ((val) << (pos)))
#define GET_BITS(lhs, size, pos) ((lhs) >> (pos) & ((1 << (size)) - 1))