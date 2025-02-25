#include "chronoTest.h"
#include <chrono>
#include <ctime>
#include <iostream>
#include <thread>
#include <ratio>
void printAllChrono()
{
    // normal system clock
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::cout << "Time since epoch: " << t << " seconds\n";
    // Cast the time point to ms, then get its duration, then get the duration's count.
    auto ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now).time_since_epoch().count();

    // Get the time point's duration, then cast to ms, then get its count.
    auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);

    // high resolution clock
    const auto startTime = std::chrono::high_resolution_clock::now();
    // pause for 5 seconds
    std::chrono::seconds dura(3);
    std::this_thread::sleep_for(dura);
    const auto secsLater = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double, std::milli> result = (secsLater - startTime);
    // const std::chrono::duration<double, std::milli> fp_ms
    // integral duration then require duration_cast
    const auto intResult = std::chrono::duration_cast<std::chrono::milliseconds>(secsLater - startTime);
    // converting integral duration to integral duration of shorter divisible time unit: no duration_cast needed
    const std::chrono::duration<long, std::micro> int_usec = intResult;
    std::cout << result.count() << ", or "
              << intResult.count() << " (whole milliseconds), or "
              << int_usec.count() << " (whole microseconds)\n";
    std::cout << std::ctime(&t) << std::endl; //this one has to be used on time_t format, 
    //ctime format: WWW MMM DD HH:mm:ss YYYY (for example: "Sun Dec 17 21:34:26 2023").
};

// The .count() member function is used to obtain the numerical value of the duration.
// The output will vary depending on the duration's underlying representation (e.g., seconds, milliseconds).
// For more control over formatting, consider using the fmt library.
