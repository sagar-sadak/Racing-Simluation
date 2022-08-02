/*
Description: This .h file declares the Racer class and all of its children,
            which will then be defined in the .cpp file.
*/

// libraries needed for this program
#pragma once
#ifndef RACERS_H
#define RACERS_H
#include <string>

// blueprint for the Racer class
class Racer
{
    // declare protected variables
    protected:
        int carNumber;
        double speed;
        double currentProgress;
    
    // declare public methods, as well as pure virtual methods
    public:
        int getCarNumber();
        void setCarNumber(int num);
        double getSpeed();
        double getCurrentProgress();
        void resetProgress();
        virtual void makeProgress(double modifier) = 0;
        virtual std::string toString() = 0;
};

// declare StreetRacer class and inherit from Racer class
class StreetRacer : public Racer
{
    // declare their respective protected and public variables and methods
    protected:
        double speed = (float)rand()/RAND_MAX * 1.5 + 5.5;
    public:
        void makeProgress(double modifier);
        std::string toString();
};

// declare SteadyRacer class and inherit from Racer class
class SteadyRacer : public Racer
{
    // declare their respective protected and public variables and methods
    protected:
        double speed = (float)rand()/RAND_MAX + 3;
    public:
        void makeProgress(double modifier);
        std::string toString();
};

// declare ToughRacer class and inherit from Racer class
class ToughRacer : public Racer
{
    // declare their respective protected and public variables and methods
    protected:
        double speed = (float)rand()/RAND_MAX + 2;
    public:
        void makeProgress(double modifier);
        std::string toString();
};

#endif