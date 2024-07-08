import { reactive } from "vue";

class WebSocketClient {
  constructor() {
    this.state = reactive({
      isConnected: false,
      messages: [],
    });
    this.ws = null;
    this.onConnectCallback = null;
    this.onMessageCallback = null;
    this.onCloseCallback = null;
  }

  connect(webSocketUrl) {
    this.ws = new WebSocket(webSocketUrl);

    this.ws.onopen = () => {
      this.state.isConnected = true;
      console.log("WebSocket connected");
      if (this.onConnectCallback) {
        this.onConnectCallback();
      }
    };

    this.ws.onmessage = (message) => {
      this.state.messages.push(message.data);
      console.log("Received:", message.data);
      if (this.onMessageCallback) {
        this.onMessageCallback(message.data);
      }
    };

    this.ws.onclose = () => {
      this.state.isConnected = false;
      console.log("WebSocket disconnected");
      if (this.onCloseCallback) {
        this.onCloseCallback();
      }
    };

    this.ws.onerror = (error) => {
      console.error("WebSocket error:", error);
    };
  }

  sendMsg(message) {
    if (this.ws && this.state.isConnected) {
      this.ws.send(message);
      console.log("Sent:", message);
    } else {
      console.warn("WebSocket is not connected.");
    }
  }

  onConnect(callback) {
    this.onConnectCallback = callback;
  }

  onMessage(callback) {
    this.onMessageCallback = callback;
  }

  onClose(callback) {
    this.onCloseCallback = callback;
  }

  getState() {
    return this.state;
  }
}

export default WebSocketClient;
