#include "core/creation.hpp"
#include "core/application.hpp"
#include "events/event_service.hpp"

int main() {
    printf("Instantiating Genesis engine...");
    // std::shared_ptr<Genesis::Creation> creation = std::make_shared<Genesis::Creation>();
    std::shared_ptr<Genesis::Application> engine = std::make_shared<Genesis::Application>();

    // Set a name for the creation
    // creation->name = "MyCreation";

    // Print the name of the creation
    // std::cout << "Creation Name: " << creation->name << std::endl;

    printf("Running...");
    engine->run();

    printf("Finished \n\n");
    return 0;
}