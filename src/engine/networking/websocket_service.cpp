#include "websocket_service.hpp"

#include <functional>  // for std::bind
#include <memory>
#include <thread>

#include "core/app.hpp"
#include "websocket_server.hpp"

namespace Genesis {

/**
 * @brief Start the WebSocket server
 *
 * @param wsServer The WebSocket server instance to be started
 */
auto startWsServer(std::shared_ptr<WebSocketServer> wsServer) {
    // TODO: Get the port number as a argument, env var, config file, etc.
    int wsServerPort = 8000;

    // --------------------------
    // Start the WebSocket Server
    // --------------------------
    wsServer->start(wsServerPort);
}

void WebSocketService::initialize(App* genesis) {
    this->genesis = genesis;

    wsServer = std::make_shared<WebSocketServer>();
    {
        // -------------------------------------------------------
        // We start the WebSocket Server in a thread.
        // Threads have to be either 'joined' or 'detached' before
        //  going out of scope, to avoid the following error:
        //  "terminate called without an active exception"
        //
        // Credits:
        //  https://iamsorush.com/posts/cpp-std-thread/
        //  https://stackoverflow.com/a/21978054/6490637
        // -------------------------------------------------------
        std::thread wsThread(Genesis::startWsServer, wsServer);
        wsThread.detach();
    }
}

void WebSocketService::update() {
    float dt = 1;  // FIXME: this must be a parameters or set somewhere else.

    std::shared_ptr<std::string> msg = std::make_shared<std::string>("Alive");

    // TODO: send msg to clients at most 10 times a second.
    // wsServer->sendMsgToAllClients(msg);
}

void WebSocketService::terminate() {}

}  // namespace Genesis
