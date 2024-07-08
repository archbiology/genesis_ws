# ----------------
# Define variables
# ----------------
CURRENT_DIR := $(shell pwd)
BUILD_DIR = build
SRC_DIR = src
TARGET = Genesis
CMAKE = cmake
MAKE = make
RENDERING_DIR = $(SRC_DIR)/rendering

# ------------------------------------------------------------
# Default target.
# It does the following:
# 	1. It first builds the C++ executable using cmake and make
#	2. Then it installs the npm dependencies for the frontend
# ------------------------------------------------------------
all: $(BUILD_DIR)
	cd $(BUILD_DIR) && $(CMAKE) .. && $(MAKE)
	cd $(RENDERING_DIR) && npm install

# ----------------------------------------------
# Create the build directory if it doesn't exist
# ----------------------------------------------
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# ---------------------------------------------------------------------
# Create a soft link on /genesis_ws pointing to this directory
# so that VS Code can find included files through src/compile_flags.txt
# ---------------------------------------------------------------------
setup:
	sudo rm -f /genesis_ws || true && sudo ln -sfv $(CURRENT_DIR) /genesis_ws

# --------------------------------------------------------------------
# Run the 'genesis' executable and `npm run dev` to serve the frontend
# The genesis.sh is used to make sure both the executable
# and the npm app are terminated when CTRL+C is pressed.
# --------------------------------------------------------------------
run: $(BUILD_DIR)/genesis
	./genesis.sh

# ---------------------------------------------------------------
# Run the 'unitTests' executable
# Use '--gtest_filter=MySpecificTestCase.*' to run specific tests
# ---------------------------------------------------------------
test: $(BUILD_DIR)/unitTests
	./$(BUILD_DIR)/unitTests --gtest_brief=1  # --gtest_filter=MySpecificTestCase.*

# ------------------------
# Clean up build directory
# ------------------------
clean:
	rm -rf $(BUILD_DIR)

# Add phony targets
.PHONY: setup all run test clean
