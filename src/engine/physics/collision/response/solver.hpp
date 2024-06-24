#ifndef genesis_solver
#define genesis_solver

#include <vector>

#include "physics/collision/detection/collision.hpp"

namespace Genesis {

/**
 * @brief Abstract base class for solvers.
 *
 * A solver is used to *solve* things about the physics world. That could be the
 * impulse from a collision or raw position correction, really anything you
 * choose to implement.
 *
 * Credits: https://winter.dev/articles/physics-engine#Collision, and ChatGPT.
 */

class Solver {
   public:
    /**
     * @brief Solves the collisions for the given objects over a time step.
     * @param collisions Vector of collisions to solve.
     * @param dt Time step for the simulation.
     */
    virtual void solve(std::vector<Collision>& collisions, float dt) = 0;

    /**
     * @brief Virtual destructor for polymorphic behavior.
     */
    virtual ~Solver() = default;
};

}  // namespace Genesis

#endif  // genesis_solver
