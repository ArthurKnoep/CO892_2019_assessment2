Assessment #2
=============
An Homemade packet sniffer
--------------------------
This project was carried out as part of the CO892 Advanced Network Security module at the University of Kent.

#### Project information
Student ID: 19909342

#### Build instruction

This project require the `lib_pcap` in order to compile and run. Install it before continuing.

```bash
## For Debian/Ubuntu
apt install libpcap-dev cmake build-essential

## For Fedora 
dnf install libpcap-devel
```

Building:
```bash
mkdir build
cd build/
cmake ..
make
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
