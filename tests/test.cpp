/**
 * @file test.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief
 * @version 0.1
 * @date 2022-08-31
 */

#include <gtest/gtest.h>

#include "InputValidator.hpp"
#include "ScoreBoard.hpp"
#include "ScoreCalculator.hpp"

TEST(TestScoreBoard, OpenInvalidInput) {
  InputValidator validator;
  try {
    validator.Validate("../test_input/zero");
    ASSERT_NE(1, 1);
  } catch (const std::exception& e) {
    EXPECT_EQ(e.what(), "cannot open file");
  }
  try {
    validator.Validate(".bs");
    ASSERT_NE(2, 2);
  } catch (const std::exception& e) {
    EXPECT_EQ(e.what(), "cannot open file");
  }
  try {
    validator.Validate(
        "../test_input/non_existing");  // Opening non-exisiting file
    ASSERT_NE(3, 3);
  } catch (const std::exception& e) {
    EXPECT_EQ(e.what(), "cannot open file");
  }
}

TEST(TestScoreBoard, ParseInvalidInput) {
  InputValidator validator;
  try {
    validator.Validate("../test_input/invalid.bs");  // Invalid input
    ASSERT_NE(1, 1);
  } catch (const std::exception& e) {
    EXPECT_EQ(e.what(), "invalid input");
  }
  try {
    validator.Validate("../test_input/invalid_one.bs");  // Invalid input
    ASSERT_NE(2, 2);
  } catch (std::exception& e) {
    EXPECT_EQ(e.what(), "invalid input");
  }
  try {
    validator.Validate("../test_input/invalid_two.bs");  // Invalid input
    ASSERT_NE(3, 3);
  } catch (std::exception& e) {
    EXPECT_EQ(e.what(), "invalid input");
  }
  try {
    validator.Validate("../test_input/invalid_three.bs");  // Invalid input
    ASSERT_NE(4, 4);
  } catch (std::exception& e) {
    EXPECT_EQ(e.what(), "invalid input");
  }
  try {
    validator.Validate("../test_input/invalid_four.bs");  // Invalid input
    ASSERT_NE(5, 5);
  } catch (std::exception& e) {
    EXPECT_EQ(e.what(), "invalid input");
  }
  try {
    validator.Validate("../test_input/all_ten.bs");  // Invalid input
    ASSERT_NE(6, 6);
  } catch (std::exception& e) {
    EXPECT_EQ(e.what(), "invalid input");
  }
  try {
    validator.Validate("../test_input/last_three_ten.bs");  // Invalid input
    ASSERT_NE(7, 7);
  } catch (std::exception& e) {
    EXPECT_EQ(e.what(), "invalid input");
  }
  try {
    validator.Validate("../test_input/invalid_last_num.bs");  // Invalid input
    ASSERT_NE(7, 7);
  } catch (std::exception& e) {
    EXPECT_EQ(e.what(), "invalid input");
  }
}

// TEST(TestScoreBoard, CheckParseResult) {
//   InputValidator validator;
//   ScoreBoard score_board = validator.Validate("../test_input/zero.bs");
// ScoreBoard score_board("../test_input/zero.bs");
// try {
//   ScoreBoard score_board("../test_input/all_ten.bs");
//   ASSERT_NE(1, 1);
// } catch (std::exception& e) {
//   EXPECT_EQ(e.what(), "invalid input");
// }
// }

TEST(TestScoreCalculator, CalculateScore) {
  InputValidator validator;
  ScoreBoard score_board = validator.Validate("../test_input/zero.bs");
  ScoreCalculator score_cal(score_board);
  EXPECT_EQ(0, score_cal.Calculate());
}
