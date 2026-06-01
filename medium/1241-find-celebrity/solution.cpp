#include <functional>

int findCelebrity(int people, const std::function<bool(int, int)>& knows) {
    int candidate = 0;

    for (int person = 1; person < people; ++person) {
        if (knows(candidate, person)) {
            candidate = person;
        }
    }

    for (int person = 0; person < people; ++person) {
        if (person == candidate) {
            continue;
        }
        if (knows(candidate, person) || !knows(person, candidate)) {
            return -1;
        }
    }

    return candidate;
}
