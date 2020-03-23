Assessment #2
=============
An Homemade packet sniffer
--------------------------

![](https://img.shields.io/docker/v/arthurknoep/sniffer)

This project was carried out as part of the CO892 Advanced Network Security module at the University of Kent.

#### Project information
Student ID: 19909342

#### Build instruction

##### With cmake

This project require the `lib_pcap` in order to compile and run. Install it before continuing.

```bash
## For Debian/Ubuntu
apt install libpcap-dev cmake build-essential

## For Fedora 
dnf install libpcap-devel cmake make automake gcc gcc-c++ kernel-devel
```

Building:
```bash
mkdir build
cd build/
cmake ..
make
```

##### With docker

Building from source
```bash
docker build -t sniffer .
```

Pulling pre-built image
```bash
docker pull arthurknoep/sniffer
```

Usage
```bash
docker run --net host --rm sniffer
# Alternatively, if you use my pre-built image
docker run --net host --rm arthurknoep/sniffer

# Example usage
docker run --net host --rm sniffer -l
docker run --net host --rm -v `pwd`/out:/out sniffer -s wlp2s0 -o /out/cap.pcap
```

#### Usage

```
Usage: ./sniffer (-l|-s) [OPTION]
Sniff 10 packets from the device specified in option and store them in a pcap file

 -l, --list-devices		list network interfaces
 -s, --sniff=DEVICE		sniff 10 packets from DEVICE

 -f, --filter=FILTER		apply specific filter
 -o, --out=OUTPUT		write captured packet to OUTPUT, default to out.pcap
```
