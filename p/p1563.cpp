#include <cstdint>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::pair;
using std::string;
using std::vector;

void print(const auto& v) {
    cout << v;
}
void println(const auto& v) {
    cout << v << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int64_t LEFT = 0;
    const int64_t RIGHT = 1;
    const int64_t FACE_IN = 0;
    const int64_t FACE_OUT = 1;
    int64_t player_count, command_count;
    cin >> player_count >> command_count;
    vector<pair<int64_t, string>> players(player_count);
    for (auto& player: players) {
        cin >> player.first;
        cin >> player.second;
    }

    int64_t current_person = 0;
    for (int64_t i = 0; i < command_count; i++) {
        int64_t direction, person;
        cin >> direction >> person;
        if (players[current_person].first == FACE_IN) {
            if (direction == RIGHT) {
                current_person += person;
            } else {
                current_person += player_count - person;
            }
        } else {
            if (direction == LEFT) {
                current_person += person;
            } else {
                current_person += player_count - person;
            }
        }
        current_person %= player_count;
    }
    println(players[current_person].second);
}