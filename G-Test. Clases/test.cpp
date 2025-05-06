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

TEST(WineTest, ParameterizedConstructor) {
    Wine wine("Merlot", "Red", "Dry", 13.5);
    ostringstream os;
    wine.printOn(os);
    string output = os.str();
    EXPECT_NE(output.find("Red"), string::npos);
    EXPECT_NE(output.find("Dry"), string::npos);
    EXPECT_NE(output.find("13.5"), string::npos);
}

TEST(WineTest, comprasionOperator) {
    Wine wine1("Merlot", "Red", "Dry", 13.5);
    Wine wine2("Chardonnay", "White", "Dry", 12.0);
    EXPECT_TRUE(wine2 < wine1);
}

TEST(WineTest, CheckWineSwetness) {
    Wine wine("Merlot", "Red", "Dry", 13.5);
    EXPECT_TRUE(wine.checkWine("Dry"));
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
    EXPECT_NE(os.str().find(getContainerName(ContainerType::TetraPack)), string::npos);
}

TEST(PackagedWineTest, DivisionOperator) {  
    PackagedWine wine("Merlot", "Red", "Dry", 13.5, 1.5);
    EXPECT_ANY_THROW(PackagedWine result = wine / 0.0;);
}
TEST(PackagedWineTest, GetVolume) {
    PackagedWine wine("Merlot", "Red", "Dry", 13.5, 0.75);
    EXPECT_DOUBLE_EQ(wine.getVolume(), 0.75);
}

// Test WineBox.h

TEST(WineBoxTest, DefaultConstructor) {
    WineBox box;
    EXPECT_EQ(box.totalVolume("Dry"), 0);
}

TEST(WineBoxTest, ParameterizedConstructor) {
    WineBox box(5);
    EXPECT_EQ(box.totalVolume("Dry"), 0);
}

TEST(WineBoxTest, AddWine) {
    WineBox box;
    box.addW("Merlot", "Red", "Dry", 13.5, 0.75);
    EXPECT_NE(box.totalVolume("Dry"), 0);
}

TEST(WineBoxTest, LoadFromFile) {
    WineBox box;
    box.loadFromFile("test.txt");
    cout << "Total Dry Volume: " << box.totalVolume("Dry") << endl;
    EXPECT_TRUE(box.totalVolume("Dry"));
}

TEST(WineBoxTest, SortByStrength) {
    WineBox box;
    box.addW("Merlot", "Red", "Dry", 13.5, 1.0);
    box.addW("Chardonnay", "White", "Semi-dry", 12.0, 0.75);
    box.sortByStrenght();
    EXPECT_GT(box.totalVolume(13.5), box.totalVolume(12.0));
}

TEST(WineBoxTest, TotalVolumeByStrength) {
    WineBox box;
    box.addW("Merlot", "Red", "Dry", 13.5, 0.75);
    box.addW("Chardonnay", "White", "Semi-dry", 12.0, 1.0);
    EXPECT_DOUBLE_EQ(box.totalVolume(13.5), 0.75);
}