#include <iostream>
#include "gtest/gtest.h"
#include "C/main.h"

TEST(LayersCount, CyrclesOfHell) {
  EXPECT_EQ(ABYSS_LAYERS_COUNT, 6);
}

TEST(Depth, IsEqualInMeters) {
  EXPECT_EQ(DEPTH_FIRST_LAYER, 1100);
}

int main(int depth, char **layer) {
  ::testing::InitGoogleTest(&depth, layer);
  return RUN_ALL_TESTS();
}
