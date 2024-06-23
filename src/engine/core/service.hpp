#ifndef genesis_service
#define genesis_service
#include <string>

namespace Genesis {

class App;  // Forward declaration

/**
 * Interface for a Service.
 *
 * Allows multiple different backends for the same type of service.
 */
class Service {
   protected:
    std::string name;
    App* genesis;

   public:
    /**
     * Initializes the Service - Abstract.
     *
     * @param param Optional parameters for initialization.
     */
    virtual void initialize(App* genesis) = 0;

    /**
     * Terminates the Service - Abstract.
     */
    virtual void terminate() = 0;

    /**
     * Updates the Service - Abstract.
     */
    virtual void update() = 0;
};

}  // namespace Genesis

#endif  // genesis_service