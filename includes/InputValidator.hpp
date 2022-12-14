/**
 * @file InputValidator.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @version 0.1
 * @date 2022-08-31
 */

#ifndef INPUT_VALIDATOR_HPP
#define INPUT_VALIDATOR_HPP

#include <algorithm>
#include <cstdio>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "ScoreBoard.hpp"

class InputValidator {
  class OpenFailureException_ : public std::exception {
    virtual const char* what() const throw() { return "cannot open file"; }
  };

  class InvalidInputException_ : public std::exception {
    virtual const char* what() const throw() { return "invalid input"; }
  };

  struct CheckScoreRange_ {
    bool operator()(int score) { return score < 0 || score > 10; }
  };

 private:
  std::vector<int> score_set_;

  void CheckFileName_(const std::string& file_name) const;
  void CheckScoreSet_(std::ifstream& input_file);
  ScoreBoard FormatScoreSetIntoScoreBoard_(void) const;

 public:
  InputValidator(void);
  ScoreBoard Validate(const std::string& file_name);
  const std::vector<int>& GetScoreSet(void) const;
};

#endif  // INPUT_VALIDATOR_HPP