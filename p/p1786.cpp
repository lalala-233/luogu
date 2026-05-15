#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

void print(const auto& v) {
    cout << v;
}
void println(const auto& v) {
    cout << v << '\n';
}
const std::pair<std::string, int32_t> POSITIONS[7] = { {
                                                           "BangZhu",
                                                           1,
                                                       },
                                                       {
                                                           "FuBangZhu",
                                                           1 + 2,
                                                       },
                                                       {
                                                           "HuFa",
                                                           1 + 2 + 2,
                                                       },
                                                       {
                                                           "ZhangLao",
                                                           1 + 2 + 2 + 4,
                                                       },
                                                       {
                                                           "TangZhu",
                                                           1 + 2 + 2 + 4 + 7,
                                                       },
                                                       {
                                                           "JingYing",
                                                           1 + 2 + 2 + 4 + 7 + 25,
                                                       },
                                                       {
                                                           "BangZhong",
                                                           114514,
                                                       } };
struct Player {
    int32_t index;
    string position;
    string name;
    int32_t contribution;
    int32_t level;
};
int32_t find_position(string position) {
    for (int32_t i = 0;; i++) {
        if (position == POSITIONS[i].first) {
            return i;
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int64_t player_count;
    cin >> player_count;
    vector<Player> players;
    players.resize(player_count);
    for (int64_t i = 0; i < player_count; i++) {
        players[i].index = i;
        cin >> players[i].name;
        cin >> players[i].position;
        cin >> players[i].contribution;
        cin >> players[i].level;
    }

    std::sort(players.begin(), players.end(), [](Player& left, Player& right) {
        if (left.position == POSITIONS[0].first) {
            return true;
        } else if (right.position == POSITIONS[0].first) {
            return false;
        }

        if (left.position == POSITIONS[1].first && right.name == POSITIONS[1].first) {
            return left.index < right.index;
        }
        if (left.position == POSITIONS[1].first) {
            return true;
        } else if (right.position == POSITIONS[1].first) {
            return false;
        }

        if (left.contribution != right.contribution) {
            return left.contribution > right.contribution;
        } else {
            return left.index < right.index;
        }
    });

    for (int64_t i = 0, current_position = 0; i < player_count; i++) {
        if (i >= POSITIONS[current_position].second) {
            current_position += 1;
        }
        players[i].position = POSITIONS[current_position].first;
    }

    std::sort(players.begin(), players.end(), [](Player& left, Player& right) {
        int32_t left_position = find_position(left.position);
        int32_t right_position = find_position(right.position);
        if (left_position != right_position) {
            return left_position < right_position;
        }
        if (left.level != right.level) {
            return left.level > right.level;
        } else {
            return left.index < right.index;
        }
    });

    for (Player& player: players) {
        print(player.name);
        print(' ');
        print(player.position);
        print(' ');
        print(player.level);
        print('\n');
    }
}