#!/bin/bash

# Description: Build the project using CMake

# Exit immediately if a command exits with a non-zero status
set -e

# Change to the directory of the script and build the project
(
  cd "$(dirname "$0")" # Ensure compile steps are run within the repository directory
  cmake -B build -S .
  cmake --build ./build
)