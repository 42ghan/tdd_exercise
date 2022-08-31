/**
 * @file test.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief
 * @version 0.1
 * @date 2022-08-31
 */

#include <gtest/gtest.h>

#include "ScoreBoard.hpp"
#include "ScoreCalculator.hpp"

TEST(TestScoreBoard, OpenInvalidInput) {
  try {
    ScoreBoard no_extension("../test_input/zero");  // Invalid file name
    ASSERT_NE(1, 1);
  } catch (const std::exception& e) {
    EXPECT_EQ(e.what(), "cannot open file");
  }
  try {
    ScoreBoard only_bs(".bs");  // Invalid file name
    ASSERT_NE(2, 2);
  } catch (const std::exception& e) {
    EXPECT_EQ(e.what(), "cannot open file");
  }
  try {
    ScoreBoard non_existing(
        "../test_input/non_existing");  // Opening non-exisiting file
    ASSERT_NE(3, 3);
  } catch (const std::exception& e) {
    EXPECT_EQ(e.what(), "cannot open file");
  }
}

TEST(TestScoreBoard, ParseInvalidInput) {
  try {
    ScoreBoard invalid("../test_input/invalid.bs");  // Invalid input
    ASSERT_NE(1, 1);
  } catch (const std::exception& e) {
    EXPECT_EQ(e.what(), "invalid input");
  }
  try {
    ScoreBoard invalid1("../test_input/invalid_one.bs");  // Invalid input
    ASSERT_NE(2, 2);
  } catch (std::exception& e) {
    EXPECT_EQ(e.what(), "invalid input");
  }
  try {
    ScoreBoard invalid2("../test_input/invalid_two.bs");  // Invalid input
    ASSERT_NE(3, 3);
  } catch (std::exception& e) {
    EXPECT_EQ(e.what(), "invalid input");
  }
  try {
    ScoreBoard invalid3("../test_input/invalid_three.bs");  // Invalid input
    ASSERT_NE(4, 4);
  } catch (std::exception& e) {
    EXPECT_EQ(e.what(), "invalid input");
  }
  try {
    ScoreBoard invalid4("../test_input/invalid_four.bs");  // Invalid input
    ASSERT_NE(5, 5);
  } catch (std::exception& e) {
    EXPECT_EQ(e.what(), "invalid input");
  }
}

TEST(TestScoreBoard, HandleValidInput) {
  ScoreBoard score_board("../test_input/zero.bs");
}

TEST(TestScoreCalculator, CalculateScore) {
  ScoreBoard score_board("../test_input/zero.bs");
  ScoreCalculator score_cal(score_board);
  EXPECT_EQ(0, score_cal.Calculate());
}
