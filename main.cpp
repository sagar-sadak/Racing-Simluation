/* 
Description: This is the main driver file, which instantiates the Race object,
            thereby calling the constructor and setting off the entire program.
            Afterwards, it deletes the object and ends.
Usage: There are no nuances to run this program in the command line.
        Simply run the Makefile, and then the executable, as such:
        1) make
        2) ./exe
*/

// libraries needed for this program
#include <time.h>
#include "race.h"
#include "racers.h"
#include "segments.h"

// declare main function, where code will start executing
int main(int argc, char** argv)
{
    // seed the rand function
    srand(time(NULL));
    // create race object
    // the entire logic for this program occurs in the constructor of the Race class
    // therefore no other method needs to be called
    Race* race = new Race();
    // After executing the code, delete the race object and exit!
    delete race;
    return 1;
}