#include <gtest/gtest.h>

#include "core/app.hpp"
#include "physics/dynamics/dynamics_service.hpp"
using namespace Genesis;

class DynamicsServiceTestCase : public ::testing::Test {
   protected:
    void SetUp() override {
        genesis = new App();
        dynamicsService = std::make_shared<DynamicsService>();
        dynamicsService->initialize(genesis);

        creation = std::make_shared<Creation>();
        creation->mass = 1.0f;
        creation->velocity = Vec3(0.0f, 0.0f, 0.0f);
        creation->transform.position = Vec3(0.0f, 100.0f, 0.0f);

        genesis->objects.push_back(creation);
    }

    App* genesis;
    std::shared_ptr<DynamicsService> dynamicsService;
    std::shared_ptr<Creation> creation;
};

TEST_F(DynamicsServiceTestCase, testPositionAfter1Sec) {
    dynamicsService->update();

    // Check that the force is correctly applied
    EXPECT_EQ(creation->force, creation->mass * dynamicsService->gravity);

    // Check that the velocity is correctly updated
    Vec3 expectedVelocity = creation->force / creation->mass;
    EXPECT_EQ(creation->velocity, expectedVelocity);

    // Check that the position is correctly updated
    Vec3 expectedPosition = Vec3(0, 90.19, 0);
    EXPECT_EQ(creation->transform.position, expectedPosition);
}
