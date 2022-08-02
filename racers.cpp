/*
Description: This .cpp file defines the Racer class from the .h file.
            It defines the resetProgress, makeProgress, and the toString methods
*/

// libraries needed for this program
#include "racers.h"

// define getters and return appropriate variables
double Racer::getCurrentProgress()
{
    return this->currentProgress;
}
double Racer::getSpeed()
{
    return this->speed;
}
int Racer::getCarNumber()
{
    return this->carNumber;
}
//define setter and update appropriate variable
void Racer::setCarNumber(int num)
{
    this->carNumber = num;
}
// method to reset Progress back to 0
void Racer::resetProgress()
{
    this->currentProgress = 0;
}

// StreetRacer method to make progress on track
void StreetRacer::makeProgress(double mod)
{
    this->currentProgress += (this->speed * mod) + 0.5;
}
// StreetRacer toString method
std::string StreetRacer::toString()
{
    // create and update string
    std::string str = "Racer #" + std::to_string(this->carNumber) + " Street Car - " + std::to_string(int(this->currentProgress)) + " units";
    return str;
}
// SteadyRacer method to make progress on track
void SteadyRacer::makeProgress(double modifier)
{
    this->currentProgress += this->speed;
}
// SteadyRacer toString method
std::string SteadyRacer::toString()
{
    // create and update string
    std::string str = "Racer #" + std::to_string(this->carNumber) + " Steady Car - " + std::to_string(int(this->currentProgress)) + " units";
    return str;
}
// ToughRacer method to make progress on track
void ToughRacer::makeProgress(double mod)
{
    double bonusSpeed = 5 * (1.0 - mod);
    this->currentProgress += this->speed + bonusSpeed;
}
// ToughRacer toString method
std::string ToughRacer::toString()
{
    // create and update string
    std::string str = "Racer #" + std::to_string(this->carNumber) + " Tough Car - " + std::to_string(int(this->currentProgress)) + " units";
    return str;
}