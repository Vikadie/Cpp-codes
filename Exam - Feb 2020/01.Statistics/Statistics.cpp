#include "Statistics.h"

Statistics& operator<<(Statistics& s, PersonInfo& person)
{
    if (person.age <= 18)
        s.minors.push_back(person);
    else if (person.age > 18 && person.age <= 62)
        s.adults.push_back(person);
    else if (person.age > 62)
        s.elder.push_back(person);

    return s;
}
