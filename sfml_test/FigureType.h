#pragma once
enum FigureType {
	CIRCLE,
	RECTANGLE,
	SQUARE,
	TRIANGLE,
	COMPOSITE
 };

inline const char* ToString(FigureType type)
{
    switch (type)
    {
    case CIRCLE:  return "circle"; 
    case RECTANGLE:   return "rectangle";
    case SQUARE: return "square";
    case TRIANGLE:   return "triangle";
    case COMPOSITE: return "composite";
    default:      return "Unknown";
    }
}