FROM gcc:latest AS builder

# Install dependencies
RUN apt-get update && apt-get install cmake libpcap-dev -y

WORKDIR /project
COPY . .

RUN mkdir build

RUN cd build && cmake .. && make

FROM debian:latest

RUN apt-get update && apt-get install libpcap0.8 -y

COPY --from=builder /project/build/sniffer /usr/bin

ENTRYPOINT ["sniffer"]
