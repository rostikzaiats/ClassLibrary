#include "pch.h"
#include"..\Program V-15\Wine.h"
#include"..\Program V-15\packagedWine.h"
#include"..\Program V-15\WineBox.h"

using namespace std;
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

// Test Wine.h
TEST(WineTest, DefaultConstructor) {
    Wine wine;
    ostringstream os;
    wine.printOn(os);
    EXPECT_FALSE(os.str().empty())
}


TEST(WineTest, ParameterizedConstructor) {
    Wine wine("Merlot", "Red", "Dry", 13.5);
    ostringstream os;
    wine.printOn(os);
    string output = os.str();
}
EXPECT_NE(output.find("Merlot"), string::npos);
EXPECT_NE(output.find("Red"), string::npos);
EXPECT_NE(output.find("Dry"), string::npos);
EXPECT_NE(output.find("13.5"), string::npos);
}


TEST(WineTest, comprasionOperator) {
    Wine wine1("Merlot", "Red", "Dry", 13.5);
    Wine wine2("Chardonnay", "White", "Dry", 12.0);
    EXPECT_TRUE(wine2 < wine1)
}

TEST(WineTest, CheckWineSwetness) {
    Wine wine("Merlot", "Red", "Dry", 13.5);
    EXPECT_TRUE(wine.checkWine("Merlot"))
}

TEST(WineTest, CheckWineStrength) {
    Wine wine("Merlot", "Red", "Dry", 13.5);
    EXPECT_TRUE(wine.checkWine(13.5))
}
