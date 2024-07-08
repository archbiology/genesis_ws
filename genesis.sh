#!/bin/bash

# --------------------------------------------------
# Run the `genesis` C++ executable in the background
# --------------------------------------------------
./build/genesis &
GENESIS_PID=$!

# ---------------------------------------------------------------
# Change directory to `rendering` and run `npm run dev` (frontend)
# ---------------------------------------------------------------
cd src/rendering
npm run dev &
NPM_PID=$!

# ----------------------------------------------------------------------
# Trap SIGINT to ensure both processes are killed when CTRL+C is pressed
# ----------------------------------------------------------------------
trap "kill $GENESIS_PID $NPM_PID" SIGINT

# -----------------------------------
# Wait for both processes to complete
# -----------------------------------
wait $GENESIS_PID
wait $NPM_PID
