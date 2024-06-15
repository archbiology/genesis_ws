#include "core/creation.hpp"

int main() {
    std::shared_ptr<Genesis::Creation> creation = std::make_shared<Genesis::Creation>();

    // Set a name for the creation
    // creation->name = "MyCreation";

    // Print the name of the creation
    // std::cout << "Creation Name: " << creation->name << std::endl;

    printf("Creation succeeded \n\n");
    return 0;
}