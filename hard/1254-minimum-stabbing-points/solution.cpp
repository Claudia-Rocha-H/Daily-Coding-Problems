#include <algorithm>
#include <vector>

struct Interval {
    double start;
    double end;
};

std::vector<double> chooseStabbingPoints(std::vector<Interval> intervals) {
    std::sort(intervals.begin(), intervals.end(), [](const Interval& left, const Interval& right) {
        if (left.end == right.end) {
            return left.start < right.start;
        }
        return left.end < right.end;
    });

    std::vector<double> points;
    if (intervals.empty()) {
        return points;
    }

    double currentPoint = intervals.front().end;
    points.push_back(currentPoint);

    for (const Interval& interval : intervals) {
        if (interval.start > currentPoint) {
            currentPoint = interval.end;
            points.push_back(currentPoint);
        }
    }

    return points;
}
