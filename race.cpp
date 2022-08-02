/*
Description: This .cpp file defines the Race class from the .h file.
            It defines the constructor (which does most of the heavy lifiting),
            and several miscellaneous methods
*/

// libraries needed for this program
#include <iostream>
#include "race.h"
#include "segments.h"
#include "racers.h"
#include "termcolor.hpp"
using std::cout;
using std::endl;
using std::cin;

// define Race constructor
Race::Race()
{
    // dynamically allocate arrays to store road segments, racers, and trackers
    RoadSegment** roadArray;
    Racer** racerArray = new Racer*[8];
    int* tracker = new int[8];
    int x;
    // get user input
    cout << termcolor::bright_blue << "Welcome to Sagar's Racer Derby!\nWould you like to:\n1 - Determine the length of the race\n2 - Run a random race\n-1 - Exit" << endl;
    cout << "Enter choice: " << termcolor::reset;
    cin >> x;
    if (x != 1 && x != 2)
    {
        cout << termcolor::bright_grey << "You are exiting the game. Play again later!" << termcolor::reset << endl;
        return;
    }
    else if (x == 1)
    {
        cout << termcolor::bright_blue << "Enter length of race: " << termcolor::reset;
        cin >> x;
    }
    else if (x == 2)
        x = rand() % 41 + 10;

    // fill road segments into the array
    roadArray = new RoadSegment*[x];
    int temp = rand() % 4;
    // randomly select starting segment
    if (temp == 0)
        roadArray[0] = new AsphaltSegment();
    else if (temp == 1)
        roadArray[0] = new CrumbledSegment();
    else if (temp == 2)
        roadArray[0] = new GravelSegment();
    else
        roadArray[0] = new DirtSegment();

    // generate neighboring segment for each segment
    for (int i = 1; i < x; i++)
        roadArray[i] = roadArray[i-1]->generateNeighbor();
    
    // randomly select 8 racers
    for (int i = 0; i < 8; i++)
    {
        int j = rand() % 3;
        if (j == 0)
            racerArray[i] = new StreetRacer();
        else if (j == 1)
            racerArray[i] = new SteadyRacer();
        else if (j == 2)
            racerArray[i] = new ToughRacer();
        racerArray[i]->setCarNumber(i + 1);
    }

    // initialize tracker array to zeros
    for (int i = 0; i < 8; i++)
        tracker[i] = 0;

    int loopCounter = 0;
    int winnerIndex = 0;
    bool noWinner = true;
    // this while loop actually runs the race
    while (noWinner)
    {
        loopCounter += 1;
        // for each racer, check if they have completed their segment, or the entire race
        for (int i = 0; i < 8; i++)
        {
            // check if racer's progress is greater than length of segment
            if (racerArray[i]->getCurrentProgress() >= roadArray[tracker[i]]->getLength())
            {
                // if so, reset progress and increase tracker
                racerArray[i]->resetProgress();
                tracker[i] += 1;
            }

            // check if the racer has won the race
            if (tracker[i] >= x)
            {
                // if so, save winner index and enter loop exit condition
                winnerIndex = i;
                noWinner = false;
            }

        }
        // if winner found, break out of while loop
        if (!noWinner)
            break;

        // for each racer, call their makeProgress method
        for (int i = 0; i < 8; i++)
            racerArray[i]->makeProgress(roadArray[tracker[i]]->getModifier());
        // output a divider and a summary of race at this point
        outputDivider(loopCounter);
        outputRacers(racerArray, tracker, roadArray);
    }
    // output the track segments
    outputTrack(roadArray, x);

    // Output number of iterations and winner
    cout << termcolor::bright_grey << "Number of loop iterations: " << loopCounter << endl;
    cout << termcolor::bright_green << "Hooray! The winner is Racer #" << winnerIndex + 1 << termcolor::reset << endl;
    
    // delete road array
    for (int i = 0; i < x; i++)
        delete[] roadArray[i];
    delete[] roadArray;

    // delete racer and tracker array
    for (int i = 0; i < 8; i++)
        delete[] racerArray[i];
    delete[] racerArray;
    delete[] tracker;
}

// define method to output a divider
void Race::outputDivider(int counter)
{
    cout << termcolor::bright_red << "####################" << endl;
    cout << "Update " << counter << "!\n----------" << termcolor::reset << endl;
}

// method that outputs the track
void Race::outputTrack(RoadSegment** roadArray, int len)
{
    cout << termcolor::bright_magenta << "Track:" << endl;
    for (int i = 0; i < len; i++)
    {
        if (i != len - 1)
            cout << roadArray[i]->firstChar() << ":" << roadArray[i]->getLength() << " - ";
        else
            cout << roadArray[i]->firstChar() << ":" << roadArray[i]->getLength() << termcolor::reset << endl;
    }
}

// output the current state of racers in the race
void Race::outputRacers(Racer** racerArray, int* tracker, RoadSegment** roadArray)
{
    for (int i = 0; i < 8; i++)
        cout << termcolor::bright_cyan << racerArray[i]->toString() << " into Segment #" << tracker[i] << " " << roadArray[tracker[i]]->toString() << " long" << termcolor::reset << endl;
}