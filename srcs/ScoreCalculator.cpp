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
  int flag = NORMAL;
  for (std::vector<std::pair<int, int>>::iterator it =
           score_board.frames.begin();
       it != score_board.frames.end(); ++it) {
    total_score += (*it).first + (*it).second;
    if (flag == STRIKE) {
      total_score += (*it).first + (*it).second;
      if ((*it).first == 10)
        total_score += (it + 1) != score_board.frames.end()
                           ? (*(it + 1)).first
                           : score_board.last.first;
    } else if (flag == SPARE)
      total_score += (*it).first;
    flag = NORMAL;
    if ((*it).first == 10)
      flag = STRIKE;
    else if ((*it).first + (*it).second == 10)
      flag = SPARE;
  }
  if (flag == STRIKE)
    total_score += score_board.last.first + score_board.last.second;
  else if (flag == SPARE)
    total_score += score_board.last.first;
  total_score += score_board.last.Sum();
  return total_score;
}
