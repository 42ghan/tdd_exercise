/**
 * @file ScoreBoard.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @version 0.1
 * @date 2022-08-31
 */

#ifndef SCORE_BOARD_HPP
#define SCORE_BOARD_HPP

#include <utility>
#include <vector>

struct triplet {
  int first;
  int second;
  int third;

  void SetTriplet(int x, int y, int z) {
    first = x;
    second = y;
    third = z;
  }

  int Sum(void) const { return first + second + third; }
};

struct ScoreBoard {
  std::vector<std::pair<int, int>> frames;
  triplet last;
};

#endif  // SCORE_BOARD_HPP