# Genesis Project

> In the beginning, God created the heavens and the earth.
> <p style="text-align: right">Genesis 1:1</p>

3D simulator (physics and rendering).

It also contains the Holy Bible - WEB (World English Bible) version.

## Features

- **Physics Simulator**: Simulates physical interactions.
- **Rendering Simulator**: Visualizes scenes and objects.
- **Event System**: Manages events and interactions within the simulation.
- **Scripting Interface**: Allows users to script behaviors.

## Setup Instructions

### Installation

Tested on Linux **Ubuntu 24.04**.

1. **Install requirements**

    ```bash

    sudo apt update
    sudo apt install git make cmake libwebsockets-dev -y
    ```

2. **Clone the Repository**

    ```bash

    cd
    git clone https://github.com/archbiology/genesis_ws
    cd genesis_ws

    make setup
    ```

4. **Build it**

    ```bash

    cd genesis_ws

    make
    ```

    The `make` command builds the C++ `genesis` executable, and it also runs
    `npm install` on the `rendering` folder to install `VueJs` dependencies.


4. **Run it**

    ```bash

    cd genesis_ws

    make run
    ```

    Once you run it, please open the following URL in your browser:

    http://localhost:3000


    The `make run` commands calls `genesis.sh`, which in turn runs
    both the C++ `genesis` executable, and `npm run dev` on the `rendering` folder.


    The `genesis.sh` script kills both the C++ executable and npm when
    `CTRL+C` is pressed.

    The "rendering" runs on port `3000`, and the WebSocket server on port `7000`.


5. **Test it**

    ```bash

    cd genesis_ws

    make test
    ```

## Troubleshooting

In case things don't work as expected:

1. Make sure ports `3000` and `7000` are not blocked by your firewall.
2. Make sure `WebSocket` is not blocked by your web browser or firewall.
3. Open the JavaScript Console (`CTRL + SHIFT + i`) and check the JavaScript log messages.
