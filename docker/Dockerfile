FROM dcv:latest
SHELL ["/bin/bash", "-c"]

WORKDIR /tmp
RUN echo "Installing darknet" && \
  git clone https://github.com/AlexeyAB/darknet.git
WORKDIR /tmp/darknet
RUN mkdir build
WORKDIR /tmp/darknet/build
RUN cmake .. && make -j$(nproc) install

WORKDIR /
RUN rm -rf /tmp/*