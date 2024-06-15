# ----------------
# Define variables
# ----------------
BUILD_DIR = build
SRC_DIR = src
TARGET = Genesis
CMAKE = cmake
MAKE = make

# --------------
# Default target
# --------------
all: $(BUILD_DIR)
	cd $(BUILD_DIR) && $(CMAKE) .. && $(MAKE)

# ----------------------------------------------
# Create the build directory if it doesn't exist
# ----------------------------------------------
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# ----------------------------
# Run the 'genesis' executable
# ----------------------------
run: $(BUILD_DIR)/genesis
	./$(BUILD_DIR)/genesis

# ------------------------
# Clean up build directory
# ------------------------
clean:
	rm -rf $(BUILD_DIR)

# Add phony targets
.PHONY: all run clean
