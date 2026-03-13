// Copyright 2025 UNN-CS Team

#include "circle.h"
#include "tasks.h"
#include <cstdint>
#include <gtest/gtest.h>

TEST(CircleTest, RadiusUpdate) {
  Circle c(10);

  EXPECT_NEAR(c.getFerence(), 62.8318, 0.001);
}

TEST(CircleTest, FerenceUpdate) {
  Circle c(0);

  c.setFerence(62.8318);

  EXPECT_NEAR(c.getRadius(), 10.0, 0.001);
}

TEST(Tasks, EarthTask) {
  double gap = taskEarth(6378.1, 1.0);

  EXPECT_NEAR(gap, 0.159, 0.001);
}

TEST(TaskPool, ConcreteOnly) {
  double total = taskPool(3, 1, 1000, 0);

  EXPECT_NEAR(total, 21991.1, 0.1);
}

TEST(CircleCore, ConstructorInit) {
  Circle c(5.0);

  EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
}

TEST(CircleCore, UnitCircleArea) {
  Circle c(1.0);

  EXPECT_NEAR(c.getArea(), PI, 1e-9);
}

TEST(CircleUpdate, RadiusToFerence) {
  Circle c(1.0);

  c.setRadius(2.0);

  EXPECT_NEAR(c.getFerence(), 12.56637, 1e-5);
}

TEST(CircleUpdate, RadiusToArea) {
  Circle c(1.0);

  c.setRadius(3.0);

  EXPECT_NEAR(c.getArea(), 28.27433, 1e-5);
}

TEST(CircleUpdate, FerenceToRadius) {
  Circle c(1.0);

  c.setFerence(31.4159);

  EXPECT_NEAR(c.getRadius(), 5.0, 1e-4);
}

TEST(CircleUpdate, FerenceToArea) {
  Circle c(1.0);

  c.setFerence(6.28318);

  EXPECT_NEAR(c.getArea(), 3.14159, 1e-5);
}

TEST(CircleUpdate, AreaToRadius) {
  Circle c(1.0);

  c.setArea(78.5398);

  EXPECT_NEAR(c.getRadius(), 5.0, 1e-4);
}

TEST(CircleUpdate, AreaToFerence) {
  Circle c(1.0);

  c.setArea(12.56637);

  EXPECT_NEAR(c.getFerence(), 12.56637, 1e-5);
}

TEST(CircleEdge, ZeroRadius) {
  Circle c(0.0);

  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}

TEST(CircleEdge, LargeValues) {
  Circle c(1e6);

  EXPECT_NEAR(c.getFerence(), 6283185.3, 0.1);
}

TEST(TaskEarth, StandardGap) {
  double gap = taskEarth(6378.1, 1.0);

  EXPECT_NEAR(gap, 0.159, 0.001);
}

TEST(TaskEarth, TenMeterGap) {
  double gap = taskEarth(6378.1, 10.0);

  EXPECT_NEAR(gap, 1.591, 0.001);
}

TEST(TaskEarth, SmallObjectGap) {
  double gapEarth = taskEarth(6378.1, 1.0);
  double gapTennisBall = taskEarth(0.000067, 1.0);

  EXPECT_NEAR(gapEarth, gapTennisBall, 1e-7);
}

TEST(TaskPool, StandardCalculation) {
  double total = taskPool(3, 1, 1000, 2000);

  EXPECT_NEAR(total, 72256.6, 0.1);
}

TEST(TaskPool, ZeroWidthPath) {
  Circle pool(3);

  double total = taskPool(3, 0, 1000, 2000);

  EXPECT_NEAR(total, pool.getFerence() * 2000, 0.1);
}

TEST(TaskPool, FreeMaterials) {
  double total = taskPool(5, 2, 0, 0);

  EXPECT_DOUBLE_EQ(total, 0.0);
}

TEST(TaskPool, TinyPool) {
  double total = taskPool(1, 0.5, 1000, 2000);

  EXPECT_NEAR(total, 22776.5, 0.1);
}

TEST(CircleConsistency, FerenceToAreaDirect) {
  Circle c(0);

  c.setFerence(100.0);
  double r = 100.0 / (2.0 * PI);
  double expectedArea = PI * r * r;

  EXPECT_NEAR(c.getArea(), expectedArea, 1e-7);
}

TEST(TaskPool, HighPrices) {
  double total = taskPool(10, 2, 1000000, 1000000);

  EXPECT_NEAR(total, 213628300.4, 1.0);
}

TEST(TaskEarth, NegativeExtraLength) {
  double gap = taskEarth(6378.1, -1.0);

  EXPECT_NEAR(gap, -0.159, 0.001);
}

TEST(CircleEdge, TinyArea) {
  Circle c(10.0);

  c.setArea(1e-10);

  EXPECT_NEAR(c.getRadius(), 0.00000564, 1e-8);
  EXPECT_NEAR(c.getFerence(), 0.00003544, 1e-8);
}
