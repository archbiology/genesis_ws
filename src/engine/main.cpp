#include "core/app.hpp"
#include "core/heart.hpp"

namespace AlphaOmega {

int speak() {
    printf("Instantiating Genesis engine...\n");
    LetThereBe(Genesis::App) genesis = ItCameToPass(Genesis::App);

    printf("Initializing...\n");
    genesis->initialize();

    printf("Running...\n");
    genesis->run();

    printf("Finished \n\n");
    return 0;
}
}

int main() { return AlphaOmega::speak(); }