/*
Description: This .cpp file defines the RoadSegment class from the .h file.
            It defines the constructors, generateNeighbor, and the toString methods
*/

// libraries needed for this program
#include "segments.h"
#include <string>

// define constructor for RoadSegment
RoadSegment::RoadSegment()
{
    // only initialize length, because modifier will be updated by the child classes
    this->length = rand() % 41 + 10;
}

// length getter
int RoadSegment::getLength()
{
    return this->length;
}
// modifier getter
double RoadSegment::getModifier()
{
    return this->modifier;
}
// define AsphaltSegment constructor
AsphaltSegment::AsphaltSegment() : RoadSegment()
{
    // length already changed by parent constructor, only change modifier here
    this->modifier = 1.0;
}
// define CrumbledSegment constructor
CrumbledSegment::CrumbledSegment() : RoadSegment()
{
    // length already changed by parent constructor, only change modifier here
    this->modifier = 0.6 + (float)rand()/RAND_MAX * 0.2;
}
// define GravelSegment constructor
GravelSegment::GravelSegment() : RoadSegment()
{
    // length already changed by parent constructor, only change modifier here
    this->modifier = 0.3 + (float)rand()/RAND_MAX * 0.3;
}
// define DirtSegment constructor
DirtSegment::DirtSegment() : RoadSegment()
{
    // length already changed by parent constructor, only change modifier here
    this->modifier = (float)rand()/RAND_MAX * 0.3;
}
// define AsphaltSegment generateNeighbor method
RoadSegment* AsphaltSegment::generateNeighbor()
{
    // generate random int from 0 to 99
    // based on the int, choose appropriate neighbor segment
    // according to the respective probabilities
    int num = rand() % 100;
    RoadSegment* ptr;
    if (num < 65)
        ptr = new AsphaltSegment();
    else if (num < 85)
        ptr = new CrumbledSegment();
    else if (num < 95)
        ptr = new GravelSegment();
    else
        ptr = new DirtSegment();
    return ptr;
}
// define AsphaltSegment toString method
std::string AsphaltSegment::toString()
{
    // create and return the string
    std::string str = "Asphalt - " + std::to_string(this->length) + " units";
    return str;
}

// define helper method for each child class that returns char that represents the child class
char AsphaltSegment::firstChar()
{
    return 'A';
}
char CrumbledSegment::firstChar()
{
    return 'C';
}
char GravelSegment::firstChar()
{
    return 'G';
}
char DirtSegment::firstChar()
{
    return 'D';
}

// define AsphaltSegment generateNeighbor method
RoadSegment* CrumbledSegment::generateNeighbor()
{
    // generate random int from 0 to 99
    // based on the int, choose appropriate neighbor segment
    // according to the respective probabilities
    int num = rand() % 100;
    RoadSegment* ptr;
    if (num < 45)
        ptr = new CrumbledSegment();
    else if (num < 65)
        ptr = new AsphaltSegment();
    else if (num < 90)
        ptr = new GravelSegment();
    else
        ptr = new DirtSegment();
    return ptr;
}
// define CrumbledSegment toString method
std::string CrumbledSegment::toString()
{
    // create and return the string
    std::string str = "Crumbled - " + std::to_string(this->length) + " units";
    return str;
}
// define AsphaltSegment generateNeighbor method
RoadSegment* GravelSegment::generateNeighbor()
{
    // generate random int from 0 to 99
    // based on the int, choose appropriate neighbor segment
    // according to the respective probabilities
    int num = rand() % 100;
    RoadSegment* ptr;
    if (num < 55)
        ptr = new GravelSegment();
    else if (num < 85)
        ptr = new DirtSegment();
    else if (num < 95)
        ptr = new CrumbledSegment();
    else
        ptr = new AsphaltSegment();
    return ptr;
}
// define GravelSegment toString method
std::string GravelSegment::toString()
{
    // create and return the string
    std::string str = "Gravel - " + std::to_string(this->length) + " units";
    return str;
}
// define AsphaltSegment generateNeighbor method
RoadSegment* DirtSegment::generateNeighbor()
{
    // generate random int from 0 to 99
    // based on the int, choose appropriate neighbor segment
    // according to the respective probabilities
    int num = rand() % 100;
    RoadSegment* ptr;
    if (num < 60)
        ptr = new DirtSegment();
    else if (num < 95)
        ptr = new GravelSegment();
    else
        ptr = new CrumbledSegment();
    return ptr;
}
// define DirtSegment toString method
std::string DirtSegment::toString()
{
    // create and return the string
    std::string str = "Dirt - " + std::to_string(this->length) + " units";
    return str;
}