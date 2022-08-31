/**
 * @file ScoreCalculator.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-31
 */

#include "ScoreCalculator.hpp"

ScoreCalculator::ScoreCalculator(void) {}

unsigned int ScoreCalculator::Calculate(ScoreBoard score_board) {
  unsigned int total_score = 0;
  for (std::vector<std::pair<int, int>>::iterator it =
           score_board.frames.begin();
       it != score_board.frames.end(); ++it) {
    total_score += (*it).first + (*it).second;
  }
  total_score +=
      score_board.last.first + score_board.last.second + score_board.last.third;
  return total_score;
}
