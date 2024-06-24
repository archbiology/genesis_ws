#ifndef genesis_impulse_solver
#define genesis_impulse_solver

#include <vector>

#include "solver.hpp"

namespace Genesis {

/**
 * @brief Solver that resolves collisions using impulse-based resolution.
 *
 * Credits: https://winter.dev/articles/physics-engine#Collision, and ChatGPT.
 */
class ImpulseSolver : public Solver {
   public:
    /**
     * @brief Solves the collisions using impulse-based resolution.
     * @param collisions Vector of collisions to solve.
     * @param dt Time step for the simulation.
     */
    void solve(std::vector<Collision>& collisions, float dt);

    void terminate();
};

}  // namespace Genesis

#endif  // genesis_impulse_solver
