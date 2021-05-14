#include "demogData.h"
#include <sstream>
#include <iomanip>

/* print county demographic data */
std::ostream& operator<<(std::ostream &out, const demogData &DD) {
    //out << "County Demographics Info: " << DD.getRegionName() << ", " << DD.getState();
    out << std::setprecision(2) << std::fixed;
    
    int popOver65Count = DD.getpopOver65Count();
    int popUnder18Count = DD.getpopUnder18Count();
    int popUnder5Count = DD.getpopUnder5Count();
    int BAupCount = DD.getBAupCount();
    int HSupCount = DD.getHSupCount();

    out << "County Demographics Info: " << DD.getRegionName() << ", " << DD.getState() << " total population: " << DD.totalPopulation2014;
    out << "\nPopulation info: \n(\% over 65): " << DD.popOver65 << " Count: " << popOver65Count;
    out << "\n(\% under 18): " << DD.popUnder18 << " Count: " << popUnder18Count;
    out << "\n(\% under 5): " << DD.popUnder5 << " Count: " << popUnder5Count;
    out << "\nEducation info: ";
    out << "\n(Bachelor degree or more): " << DD.popBachelorEduPlus << " Count: " << BAupCount;
    out << "\n(high school or more): " << DD.popHighSchoolEduPlus << " Count: " << HSupCount;
    out << "\npersons below poverty: " << DD.popInPoverty << " Count: " << DD.getPovertyCount();

    return out;
}
