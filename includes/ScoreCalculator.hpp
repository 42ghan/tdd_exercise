/**
 * @file ScoreCalculator.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @version 0.1
 * @date 2022-08-31
 */

#ifndef SCORE_CALCULATOR_HPP
#define SCORE_CALCULATOR_HPP

#include "ScoreBoard.hpp"

#define NORMAL 0
#define STRIKE 1
#define SPARE 2

class ScoreCalculator {
  typedef std::vector<std::pair<int, int>>::iterator iterator;

 private:
  int flag_;

  void SetFrameFlag_(iterator& it);

 public:
  ScoreCalculator(void);
  unsigned int Calculate(ScoreBoard score_board);
};

#endif  // SCORE_CALCULATOR_HPP