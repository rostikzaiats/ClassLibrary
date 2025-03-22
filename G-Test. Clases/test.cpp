#include "pch.h"
#include"..\Program V-15\Wine.h"
#include"..\Program V-15\packagedWine.h"
#include"..\Program V-15\WineBox.h"

using namespace std;
// Test Wine.h
TEST(WineTest, DefaultConstructor) {
    Wine wine;
    ostringstream os;
    wine.printOn(os);
    EXPECT_FALSE(os.str().empty());
}






TEST(WineTest, CheckWineStrength) {
    Wine wine("Merlot", "Red", "Dry", 13.5);
    EXPECT_TRUE(wine.checkWine(13.5));
}

// Test packagedWine.h
   
TEST(PackagedWineTest, DefaultConstructor) {
    PackagedWine wine;
    ostringstream os;
    wine.printOn(os);
    EXPECT_FALSE(os.str().empty());
}

TEST(PackagedWineTest, ParameterizedConstructor) {
    PackagedWine wine("Merlot", "Red", "Dry", 13.5, 0.75);
    ostringstream os;
    wine.printOn(os);
    string output = os.str();
    EXPECT_NE(output.find("Merlot"), string::npos);
    EXPECT_NE(output.find("Red"), string::npos);
    EXPECT_NE(output.find("Dry"), string::npos);
    EXPECT_NE(output.find("13.5"), string::npos);
    EXPECT_NE(output.find("0.75"), string::npos);
}

TEST(PackagedWineTest, ChangePackage) {
    PackagedWine wine("Merlot", "Red", "Dry", 13.5, 0.75);
    wine.changePackage();
    ostringstream os;
    wine.printOn(os);
    EXPECT_NE(os.str().find(GLASS_CONTAINER), string::npos);
}

TEST(PackagedWineTest, DivisionOperator) {
    PackagedWine wine("Merlot", "Red", "Dry", 13.5, 1.5);
    PackagedWine result = wine / 2.0;
    EXPECT_DOUBLE_EQ(result.getVolume(), 0.75);
}

TEST(PackagedWineTest, GetVolume) {
    PackagedWine wine("Merlot", "Red", "Dry", 13.5, 0.75);
    EXPECT_DOUBLE_EQ(wine.getVolume(), 0.75);
}

