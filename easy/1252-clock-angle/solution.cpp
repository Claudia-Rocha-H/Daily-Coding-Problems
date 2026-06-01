#include <algorithm>
#include <cmath>
#include <string>

int clockAngle(const std::string& time) {
    const std::size_t colon = time.find(':');
    const int hours = std::stoi(time.substr(0, colon));
    const int minutes = std::stoi(time.substr(colon + 1));

    const double hourAngle = 30.0 * (hours % 12) + 0.5 * minutes;
    const double minuteAngle = 6.0 * minutes;
    const double difference = std::abs(hourAngle - minuteAngle);
    const double smallerAngle = std::min(difference, 360.0 - difference);

    return static_cast<int>(std::lround(smallerAngle));
}
