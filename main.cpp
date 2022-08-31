#include <iostream>

#include "InputValidator.hpp"
#include "ScoreCalculator.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Usage: ./bowling_score <file_name>" << std::endl;
    return EXIT_FAILURE;
  }
  try {
    InputValidator validator;
    ScoreCalculator calculator;
    unsigned int score = calculator.Calculate(validator.Validate(argv[1]));
    std::cout << "TOTAL SCORE : " << score << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}