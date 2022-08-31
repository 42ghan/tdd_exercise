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
    validator.Validate("../test_input/invalid_last_num.bs");  // Invalid input
    ASSERT_NE(7, 7);
  } catch (std::exception& e) {
    EXPECT_EQ(e.what(), "invalid input");
  }
}

TEST(TestScoreCalculator, CalculateScore) {
  InputValidator validator;
  ScoreCalculator score_cal;
  EXPECT_EQ(0,
            score_cal.Calculate(validator.Validate("../test_input/zero.bs")));
  EXPECT_EQ(61,
            score_cal.Calculate(validator.Validate("../test_input/no_ten.bs")));
  EXPECT_EQ(58,
            score_cal.Calculate(validator.Validate("../test_input/strike.bs")));
  EXPECT_EQ(24,
            score_cal.Calculate(validator.Validate("../test_input/spare.bs")));
  EXPECT_EQ(300, score_cal.Calculate(
                     validator.Validate("../test_input/last_three_ten.bs")));
  EXPECT_EQ(20, score_cal.Calculate(
                    validator.Validate("../test_input/second_last_spare.bs")));
}
