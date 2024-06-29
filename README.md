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


4. **Run it**

    ```bash

    cd genesis_ws

    make run
    ```

5. **Test it**

    ```bash

    cd genesis_ws

    make test
    ```
