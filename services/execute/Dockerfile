FROM ubuntu:22.04

# Install essential tools for C++ development
RUN apt update && apt install -y \
    build-essential \
    cmake \
    clang \
    g++ \
    gcc \
    ninja-build \
    git \
    && apt clean

# Set the working directory inside the container
WORKDIR /workspace

# Set the default command to keep the container alive
CMD ["/bin/bash"]

