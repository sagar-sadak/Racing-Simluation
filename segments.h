/*
Description: This .h file declares the RoadSegment classes and its children,
            which will then be defined in the .cpp file.
*/

// libraries needed for this program
#pragma once
#ifndef SEGMENTS_H
#define SEGMENTS_H
#include <string>

// blueprint for the RoadSegment class
class RoadSegment
{
    // declare protected variables
    protected:
        int length;
        double modifier;
    
    // declare constructor & public methods
    // note the pure virtual methods
    public:
        RoadSegment();
        virtual RoadSegment* generateNeighbor() = 0;
        int getLength();
        double getModifier();
        virtual std::string toString() = 0;
        virtual char firstChar() = 0;
};

// declare AsphaltSegment and inherit from RoadSegment
class AsphaltSegment : public RoadSegment
{
    // declare the constructor and re-defined methods
    public:
        AsphaltSegment();
        RoadSegment* generateNeighbor();
        std::string toString();
        char firstChar();
};

// declare CrumbledSegment and inherit from RoadSegment
class CrumbledSegment : public RoadSegment
{
    // declare the constructor and re-defined methods
    public:
        CrumbledSegment();
        RoadSegment* generateNeighbor();
        std::string toString();
        char firstChar();
};

// declare GravelSegment and inherit from RoadSegment
class GravelSegment : public RoadSegment
{
    // declare the constructor and re-defined methods
    public:
        GravelSegment();
        RoadSegment* generateNeighbor();
        std::string toString();
        char firstChar();
};

// declare DirtSegment and inherit from RoadSegment
class DirtSegment : public RoadSegment
{
    // declare the constructor and re-defined methods
    public:
        DirtSegment();
        RoadSegment* generateNeighbor();
        std::string toString();
        char firstChar();
};

#endif