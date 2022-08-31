/**
 * @file ScoreCalculator.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @version 0.1
 * @date 2022-08-31
 */

#include "ScoreCalculator.hpp"

ScoreCalculator::ScoreCalculator(void) : flag_(NORMAL) {}

void ScoreCalculator::SetFrameFlag_(iterator& it) {
  if (it->first == 10)
    flag_ = STRIKE;
  else if (it->first + it->second == 10)
    flag_ = SPARE;
  else
    flag_ = NORMAL;
}

unsigned int ScoreCalculator::Calculate(ScoreBoard score_board) {
  unsigned int total_score = 0;
  iterator ite = score_board.frames.end();
  for (iterator it = score_board.frames.begin(); it != ite; ++it) {
    total_score += it->first + it->second;
    if (flag_ == STRIKE) {
      total_score += it->first + it->second;
      if (it->first == 10)
        total_score +=
            (it + 1) != ite ? (it + 1)->first : score_board.last.first;
    } else if (flag_ == SPARE)
      total_score += it->first;
    SetFrameFlag_(it);
  }
  if (flag_ == STRIKE)
    total_score += score_board.last.first + score_board.last.second;
  else if (flag_ == SPARE)
    total_score += score_board.last.first;
  total_score += score_board.last.Sum();
  return total_score;
}
