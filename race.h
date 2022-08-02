/*
Description: This .h file declares the Race class,
            which will then be defined in the .cpp file.
*/
#pragma once
#include "segments.h"
#include "racers.h"

// blueprint for Race class
class Race
{
    // declare constructor & public methods
    public:
        Race();
        void outputTrack(RoadSegment** roadArray, int len);
        void outputRacers(Racer** racerArray, int* tracker, RoadSegment** roadArray);
        void outputDivider(int counter);
};