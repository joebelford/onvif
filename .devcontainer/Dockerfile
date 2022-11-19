# Build stage
ARG VARIANT="buster"
# "mcr.microsoft.com/devcontainers/base:${templateOption:imageVariant}"
FROM mcr.microsoft.com/devcontainers/base:${VARIANT}


RUN echo ========== Install dependencies ========== \
  && apt-get update && \
    export DEBIAN_FRONTEND=noninteractive && \
    apt-get install -y --no-install-recommends \
    clang \
    gdb \
    git \
    libssl-dev \
    make \
    perl \
    unzip \
    wget \
    autoconf \
    zlib1g-dev \
    bison \
    flex \
  && apt-get clean \
  && rm -rf /var/lib/apt/lists/*
WORKDIR /opt
RUN wget -q https://sourceforge.net/projects/gsoap2/files/latest/download && unzip -q download
WORKDIR gsoap-2.8
RUN ./configure
WORKDIR /opt
RUN rm -rf download
