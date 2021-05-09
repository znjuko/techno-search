#include <iostream>

extern "C" {
    #include "../../../../../src/map_service/map_graph/graph/graph.h"
}

const double *app[] = {
        {},
        {},
        {},
};

TEST(deviation, values_1) {
EXPECT_EQ(deviation(app, des), 22);
}

TEST(fridge, initialization) {
dish_list* fridge = NULL;
push(&fridge, des);
push(&fridge, des2);
push(&fridge, des3);
EXPECT_EQ(fridge->current.e_value, 22);
del(fridge);
}

TEST(fridge, initialization_2) {
dish_list* fridge = NULL;
push(&fridge, des);
push(&fridge, des2);
push(&fridge, des3);
EXPECT_EQ(fridge->next->current.e_value, 23);
del(fridge);
}

TEST(find, values_1) {
dish_list* fridge = NULL;
push(&fridge, des);
push(&fridge, des2);
push(&fridge, des3);
char *result = find(app, fridge);
EXPECT_EQ(result, rights);
}

TEST(find, values_2) {
dish_list* fridge = NULL;
push(&fridge, des);
char *result = find(app, fridge);
EXPECT_EQ(result, dess);
}

TEST(deviation, values_3) {
EXPECT_EQ(deviation(des2, app), 40);
}

TEST(find, values_3) {
dish_list* fridge = NULL;
push(&fridge, des);
push(&fridge, des3);
push(&fridge, des2);
char *result = find(app, fridge);
EXPECT_EQ(result, rights);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
