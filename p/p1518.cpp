#include <cstdint>
#include <iostream>
#include <utility>

using std::cin;
using std::cout;
using std::pair;

void print(const auto& v) {
    cout << v;
}
void println(const auto& v) {
    cout << v << '\n';
}
enum class Direction { North, South, West, East };
Direction turn_right(Direction current) {
    switch (current) {
        case Direction::North: {
            return Direction::East;
        }
        case Direction::South: {
            return Direction::West;
        }
        case Direction::West: {
            return Direction::North;
        }
        case Direction::East: {
            return Direction::South;
        }
    }
}
pair<int32_t, int32_t> next(pair<int32_t, int32_t> coord, Direction direction) {
    switch (direction) {
        case Direction::North: {
            return { coord.first, coord.second - 1 };
        }
        case Direction::South: {
            return { coord.first, coord.second + 1 };
        }
        case Direction::West: {
            return { coord.first - 1, coord.second };
        }
        case Direction::East: {
            return { coord.first + 1, coord.second };
        }
    }
}
bool valid(pair<int32_t, int32_t> coord, char map[100]) {
    if (coord.first < 0 || coord.first >= 10 || coord.second < 0 || coord.second >= 10) {
        return false;
    }
    return map[coord.second * 10 + coord.first] != '*';
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    char map[100];
    pair<int32_t, int32_t> john;
    pair<int32_t, int32_t> cow;
    for (int32_t i = 0; i < 100; i++) {
        cin >> map[i];
        if (map[i] == 'F') {
            john = { i % 10, i / 10 };
        } else if (map[i] == 'C') {
            cow = { i % 10, i / 10 };
        }
    }
    Direction cow_direction = Direction::North;
    Direction john_direction = Direction::North;
    int32_t time = 0;
    for (int32_t i = 0; i < 100000; i++) {
        if (cow == john) {
            time = i;
            break;
        }
        if (valid(next(cow, cow_direction), map)) {
            cow = next(cow, cow_direction);
        } else {
            cow_direction = turn_right(cow_direction);
        }
        if (valid(next(john, john_direction), map)) {
            john = next(john, john_direction);
        } else {
            john_direction = turn_right(john_direction);
        }
    }
    println(time);
}