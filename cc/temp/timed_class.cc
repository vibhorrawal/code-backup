#include <stdio.h>
#include <iostream>
#include <ctime>

class TimedSection {
    char const *d_name;
    timespec d_start;
    public:
        TimedSection(char const *name) :
            d_name(name)
        {
            clock_gettime(CLOCK_REALTIME, &d_start);
        }
        ~TimedSection() {
            timespec end;
            clock_gettime(CLOCK_REALTIME, &end);
            double duration = 1e3 * (end.tv_sec - d_start.tv_sec) +
                              1e-6 * (end.tv_nsec - d_start.tv_nsec);
            std::cerr << d_name << '\t' << std::fixed << duration << " ms\n"; 
        }
};