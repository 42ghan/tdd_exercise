/**
 * @file InputValidator.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @version 0.1
 * @date 2022-08-31
 */

#include "InputValidator.hpp"

InputValidator::InputValidator(void) : score_set_(std::vector<int>(21)) {}

void InputValidator::CheckFileName_(const std::string& file_name) const {
  if (file_name.size() <= 3 ||
      file_name.compare(file_name.size() - 3, 3, ".bs"))
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

ScoreBoard InputValidator::FormatScoreSetIntoScoreBoard_() const {
  ScoreBoard score_board;
  for (int i = 1; i < 18; i += 2) {
    if (score_set_[i - 1] + score_set_[i] > 10) throw InvalidInputException_();
    score_board.frames.push_back(
        std::pair<int, int>(score_set_[i - 1], score_set_[i]));
  }
  if (score_set_[20] &&
      !(score_set_[18] == 10 || score_set_[18] + score_set_[19] == 10))
    throw InvalidInputException_();
  score_board.last.SetTriplet(score_set_[18], score_set_[19], score_set_[20]);
  return score_board;
}

ScoreBoard InputValidator::Validate(const std::string& file_name) {
  CheckFileName_(file_name);
  std::ifstream input_file(file_name);
  if (!input_file.is_open()) throw OpenFailureException_();
  CheckScoreSet_(input_file);
  input_file.close();
  return FormatScoreSetIntoScoreBoard_();
}

const std::vector<int>& InputValidator::GetScoreSet(void) const {
  return score_set_;
}
