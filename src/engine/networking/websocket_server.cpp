#include "websocket_server.hpp"

#include <libwebsockets.h>

#include <algorithm>
#include <chrono>
#include <csignal>
#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>

namespace Genesis {

WebSocketServer::WebSocketServer() {
    context = nullptr;

    if (wsServerInstance) {
        throw std::runtime_error(
            "🧨 Error: Only one instance of WebSocketServer is allowed.");
    }

    // -----------------------------------------------------
    // Assigning the current instance to the static variable
    // -----------------------------------------------------
    wsServerInstance = this;
}

WebSocketServer::~WebSocketServer() { stop(); }

#define EXAMPLE_RX_BUFFER_BYTES (10)

static struct lws_protocols protocols[] = {
    /* The first protocol must always be the HTTP handler */
    {
        "http-only",               /* name */
        WebSocketServer::callback, /* callback */
        0,                         /* No per session data. */
        0,                         /* max frame size / rx buffer */
    },
    {
        "example-protocol",
        WebSocketServer::callback,
        0,
        EXAMPLE_RX_BUFFER_BYTES,
    },
    {NULL, NULL, 0, 0} /* terminator */
};

void WebSocketServer::start(int port) {
    struct lws_context_creation_info info;
    memset(&info, 0, sizeof(info));

    info.port = port;
    info.iface = nullptr;
    info.protocols = protocols;
    info.extensions = nullptr;
    info.gid = -1;
    info.uid = -1;
    // info.options = 0;

    context = lws_create_context(&info);
    if (!context) {
        std::cerr << "🔴️ WebSocket server creation failed.\n";
        return;
    }

    std::cout << "🟢️ WebSocket server started on port " << port << std::endl;

    int count = 0;
    while (1) {
        printf("while.lws_service... %d \n", count++);
        lws_service(context, /* timeout_ms = */ 1000000);
    }
}

void WebSocketServer::stop() {
    if (context) {
        lws_context_destroy(context);
        context = nullptr;
    }
}

void WebSocketServer::onConnect(lws *wsi) {
    clients.push_back(wsi);

    std::cout << "\n🟢️ wsi.onConnect(" << wsi << ")\n";

    // ------------------------------------------------------------
    // Call lws_callback_on_writable to make the websocket writable.
    // ❤️‍🔥❤️‍🔥❤️‍🔥 Add a timer to send a msg every
    // second https://apidog.com/blog/how-to-implement-websocket-in-c/
    // ------------------------------------------------------------
    // lws_callback_on_writable(wsi);
}

void WebSocketServer::onMsg(lws *wsi, std::string msg) {
    std::cout << "⬇️  onMsg(" << wsi << "): " << msg << std::endl;

    std::string newMsg = "I received, brother: " + msg;
    lws_callback_on_writable_all_protocol(lws_get_context(wsi),
                                          lws_get_protocol(wsi));
    printf("Depois do lws_callback_on_writable_all_protocol \n");
    // sendMsg(wsi, newMsg);
    // Process the message as needed
}

void WebSocketServer::onDisconnect(lws *wsi) {
    auto it = std::find_if(clients.begin(), clients.end(),
                           [wsi](lws *client) { return client == wsi; });

    if (it != clients.end()) {
        clients.erase(it);
        std::cout << "🔴 onDisconnect(" << *it << ")" << std::endl;
    }
}

void WebSocketServer::sendMsg(lws *wsi, std::shared_ptr<std::string> msg) {
    lws_write(wsi, (unsigned char *)msg->c_str(), msg->size(), LWS_WRITE_TEXT);
}

void WebSocketServer::sendMsg(lws *wsi, unsigned char *msg, int msgSize) {
    lws_write(wsi, msg, msgSize, LWS_WRITE_TEXT);
}

std::vector<lws *> WebSocketServer::getAllClients() { return clients; }

void WebSocketServer::sendMsgToAllClients(std::shared_ptr<std::string> msg) {
    printf("Clients %ld\n", clients.size());

    unsigned char *theMsg = (unsigned char *)msg->c_str();
    unsigned msgSize = msg->size();

    for (auto &client : clients) {
        sendMsg(client, theMsg, msgSize);
    }
}

int WebSocketServer::callback(struct lws *wsi, enum lws_callback_reasons reason,
                              void *user, void *in, size_t len) {
    // printf("callback.reason: %d \n", reason);
    // std::cout<<"callback.reason.wsServerInstance:
    // "<<wsServerInstance<<std::endl;

    if (wsServerInstance) {
        return wsServerInstance->callbackHandler(wsi, reason, user, in, len);
    }
    return 0;
}

int WebSocketServer::callbackHandler(struct lws *wsi,
                                     enum lws_callback_reasons reason,
                                     void *user, void *in, size_t len) {
    std::shared_ptr<std::string> msg =
        std::make_shared<std::string>("Jesus loves you");

    switch (reason) {
        case LWS_CALLBACK_ESTABLISHED:  // 0
            onConnect(wsi);
            break;

        case LWS_CALLBACK_RECEIVE:
            onMsg(wsi, std::string((char *)in));
            break;

        case LWS_CALLBACK_SERVER_WRITEABLE:  // 11

            // -----------------------------------------------------------
            // Just sending a default msg in response to the msg received.
            // -----------------------------------------------------------
            std::cout << "\n🔹 wsi.WRITABLE.before " << wsi << "\n";
            sendMsg(wsi, msg);
            std::cout << "🔹 wsi.WRITABLE.after " << wsi << "\n";

            break;

        case LWS_CALLBACK_CLOSED:
            onDisconnect(wsi);
            break;

        default:
            break;
    }
    return 0;
}

void WebSocketServer::processMessage(struct lws *wsi, std::string msg) {
    // Handle incoming messages here

    onMsg(wsi, msg);  // Example implementation
}

using std::chrono::seconds;
using std::this_thread::sleep_for;

auto everySecond() {
    int count = 0;
    const int heartbeatInterval = 1;
    std::shared_ptr<std::string> novMsg =
        std::make_shared<std::string>("🫀 server.heartbeat");

    try {
        while (1) {
            std::cout << "🩺 everySecond.outer-loop " << std::endl;

            while (1) {
                std::cout << "\n everySecond.again ..." << count++ << "\n";

                if (wsServerInstance) {
                    wsServerInstance->sendMsgToAllClients(novMsg);
                } else {
                    printf(" No server instance...");
                }

                // ------------------
                // Sleep for 1 second
                // ------------------
                sleep_for(seconds(heartbeatInterval));
            }
        }

    } catch (std::exception e) {
        std::cout << "🤕🤕🤕 everySecond.error:" << e.what() << std::endl;
    }
}
}  // namespace Genesis

// int main() {
//     Genesis::WebSocketServer server;

//     // https://iamsorush.com/posts/cpp-std-thread/
//     // std::thread t(Genesis::everySecond);

//     server.start(8000);  // Replace with desired port number
//     // Optionally, handle other logic or keep the server running
//     printf("❤️‍🔥❤️‍🔥 Running on port 8000 \n");

//     while (true) {
//         printf(">>>>>>>> Sending msgs to clients...\n");
//         // Handle other server logic or keep alive tasks here
//         // For example, periodically send a message to all clients
//         // server.sendMsgToAllClients("Periodic message to all clients");

//         // Sleep or do other processing
//         std::this_thread::sleep_for(std::chrono::seconds(1));
//     }

//     return 0;
// }
