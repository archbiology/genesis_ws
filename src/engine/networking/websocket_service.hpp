#ifndef genesis_websocket_service
#define genesis_websocket_service

#include <memory>
#include "core/service.hpp"
#include "websocket_server.hpp"

namespace Genesis {

class App;  // Forward declaration

/**
 * @brief The WebSocketService.
 *
 * @details WebSocket is used for sending to the HTML page (rendering engine)
 * the position of the objects in the scene, for example.
 */
class WebSocketService : public Service {
   public:
    /**
     * Initializes the Service.
     *
     * @param genesis The engine address.
     */
    void initialize(App* genesis);

    /**
     * @brief Updates the WebSocketService.
     * @details Updates objects position in the application.
     */
    void update();

    /**
     * Terminates the Service.
     */
    void terminate();

   private:
    /**
     * @brief Flag to track pending objects.
     */
    bool objectsPending = false;

    /**
     * @brief WebSocket server
     */
    std::shared_ptr<WebSocketServer> wsServer= nullptr;
};

}  // namespace Genesis

#endif  // genesis_websocket_service
