#ifndef genesis_websocket_server
#define genesis_websocket_server

#include <libwebsockets.h>

#include <csignal>
#include <memory>
#include <string>
#include <vector>

namespace Genesis {

/**
 * @class WebSocketServer
 * @brief A class to manage WebSocket server operations.
 *
 * @note This tiny yet powerful WebSocket server wouldn't be possible without
 * the help of:
 *
 *  1. God (for the Life and health)
 *  2. https://github.com/warmcat/libwebsockets
 *  3. ChatGPT
 *  4. https://apidog.com/blog/how-to-implement-websocket-in-c/
 *  5. https://iamsorush.com/posts/cpp-std-thread/
 *
 * Example of how to compile this:
 *  g++ websocket_server.cpp -lwebsockets
 *
 * Example of how to make instantiate this:

    int main() {
        Genesis::WebSocketServer server;

        // https://iamsorush.com/posts/cpp-std-thread/
        // std::thread t(Genesis::everySecond);

        server.start(8000);  // Replace with desired port number

        // Now go to https://piehost.com/websocket-tester and
        // type the following URL to test it: ws://localhost:8000
    }
 */
class WebSocketServer {
   public:
    /**
     * @brief Constructor for WebSocketServer.
     */
    WebSocketServer();

    /**
     * @brief Destructor for WebSocketServer.
     */
    ~WebSocketServer();

    /**
     * @brief Starts the WebSocket server on the given port.
     * @param port The port number on which the server should listen.
     */
    void start(int port);

    /**
     * @brief Stops the WebSocket server.
     */
    void stop();

    /**
     * @brief Callback when a new connection is established.
     * @param wsi Pointer to the WebSocket instance.
     */
    void onConnect(lws *wsi);

    /**
     * @brief Callback when a message is received.
     * @param wsi Pointer to the WebSocket instance.
     * @param msg The received message.
     */
    void onMsg(lws *wsi, std::string msg);

    /**
     * @brief Callback when a connection is closed.
     * @param wsi Pointer to the WebSocket instance.
     */
    void onDisconnect(lws *wsi);

    /**
     * @brief Sends a message to a specific client.
     * @param wsi Pointer to the WebSocket instance.
     * @param msg The message to be sent.
     */
    void sendMsg(lws *wsi, std::shared_ptr<std::string> msg);

    /**
     * @brief Sends a message to a specific client.
     * @param wsi Pointer to the WebSocket instance.
     * @param msg The message to be sent as an array of unsigned char.
     * @param msgSize The size of the message.
     *
     * @note Use this instead of the other sendMsg if you want to send the
     *  same message to many clients, so that we don't hvae to compute the
     *  msg size for every client.
     */
    void sendMsg(lws *wsi, unsigned char *msg, int msgSize);

    /**
     * @brief Gets a list of all connected clients.
     * @return A vector of pointers to WebSocket instances.
     */
    std::vector<lws *> getAllClients();

    /**
     * @brief Sends a message to all connected clients.
     * @param msg The message to be sent.
     */
    void sendMsgToAllClients(std::shared_ptr<std::string> msg);

    /**
     * @brief Static callback function for libwebsockets.
     * @param wsi Pointer to the WebSocket instance.
     * @param reason The reason for the callback.
     * @param user User data.
     * @param in Input data.
     * @param len Length of the input data.
     * @return An integer indicating the callback result.
     */
    static int callback(struct lws *wsi, enum lws_callback_reasons reason,
                        void *user, void *in, size_t len);

    /**
     * @brief A list of all connected clients.
     */
    std::vector<lws *> clients;

   private:
    /**
     * @brief Pointer to the WebSocket context.
     */
    struct lws_context *context;

    /**
     * @brief Non-static callback handler for libwebsockets.
     * @param wsi Pointer to the WebSocket instance.
     * @param reason The reason for the callback.
     * @param user User data.
     * @param in Input data.
     * @param len Length of the input data.
     * @return An integer indicating the callback result.
     */
    int callbackHandler(struct lws *wsi, enum lws_callback_reasons reason,
                        void *user, void *in, size_t len);

    /**
     * @brief Helper function to process received messages.
     * @param wsi Pointer to the WebSocket instance.
     * @param msg The received message.
     */
    void processMessage(struct lws *wsi, std::string msg);
};

// --------------------------------------------------------------------
// Static variable to hold a pointer to the instance of WebSocketServer
// --------------------------------------------------------------------
static WebSocketServer *wsServerInstance = nullptr;

}  // namespace Genesis

#endif  // genesis_websocket_server
