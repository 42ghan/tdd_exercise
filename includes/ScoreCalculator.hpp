/**
 * @file ScoreCalculator.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-31
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SCORE_CALCULATOR_HPP
#define SCORE_CALCULATOR_HPP

#include "ScoreBoard.hpp"

class ScoreCalculator {
 public:
  ScoreCalculator(const ScoreBoard& score_board);
  unsigned int Calculate(void);
};

#endif  // SCORE_CALCULATOR_HPP