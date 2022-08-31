/**
 * @file InputValidator.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-31
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "InputValidator.hpp"

InputValidator::InputValidator(const std::string& file_name)
    : file_name_(file_name), score_set_(std::vector<int>(21)) {}

void InputValidator::CheckFileName_(void) const {
  if (file_name_.size() <= 3 ||
      file_name_.compare(file_name_.size() - 3, 3, ".bs"))
    throw OpenFailureException_();
}

void InputValidator::CheckScoreSet_(std::ifstream& input_file) {
  if (!input_file.is_open()) throw OpenFailureException_();
  std::stringstream ss;
  input_file >> ss.rdbuf();
  std::string score_set_str(ss.str());
  if (score_set_str.compare(score_set_str.size() - 2, 2, "]}") ||
      (sscanf(
           score_set_str.c_str(),
           "{[%d,%d];[%d,%d];[%d,%d];[%d,%d];[%d,%d];[%d,%d];[%d,%d];[%d,%d];\
             [%d,%d];[%d,%d,%d]}",
           &score_set_[0], &score_set_[1], &score_set_[2], &score_set_[3],
           &score_set_[4], &score_set_[5], &score_set_[6], &score_set_[7],
           &score_set_[8], &score_set_[9], &score_set_[10], &score_set_[11],
           &score_set_[12], &score_set_[13], &score_set_[14], &score_set_[15],
           &score_set_[16], &score_set_[17], &score_set_[18], &score_set_[19],
           &score_set_[20]) != 21))
    throw InvalidInputException_();
  if (std::find_if(score_set_.begin(), score_set_.end(), CheckScoreRange_()) !=
      score_set_.end()) {
    throw InvalidInputException_();
  }
}

void InputValidator::Validate(void) {
  CheckFileName_();
  std::ifstream input_file(file_name_);
  if (!input_file.is_open()) throw OpenFailureException_();
  CheckScoreSet_(input_file);
  input_file.close();
}

const std::vector<int>& InputValidator::GetScoreSet(void) const {
  return score_set_;
}
