#include "websocket_service.hpp"

#include <functional>  // for std::bind
#include <memory>
#include <thread>

#include "core/app.hpp"

namespace Genesis {

auto startWsServer(WebSocketServer wsServer) {
    int wsServerPort = 8000;
    wsServer.start(wsServerPort);
}

void WebSocketService::initialize(App* genesis) {
    this->genesis = genesis;

    // ---------------------------------------------------------------------
    // std::bind is necessary if we want to pass an argument to the function
    // If we don't need an argument, we could just follow
    // https://iamsorush.com/posts/cpp-std-thread/, which would be simply:
    //  std::thread t(theFunctionToRunOnThread);
    // ---------------------------------------------------------------------
    std::thread t(std::bind(Genesis::startWsServer, wsServer));
}

void WebSocketService::update() {
    float dt = 1;  // FIXME: this must be a parameters or set somewhere else.

    std::shared_ptr<std::string> msg = std::make_shared<std::string>("Alive");
    wsServer.sendMsgToAllClients(msg);
}

void WebSocketService::terminate() {}

}  // namespace Genesis
