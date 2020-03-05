/*
** EPITECH PROJECT, 2020
** CO892_2019_assessment2
** File description:
** list_devices.c
*/

#include <pcap/pcap.h>
#include <string.h>

int max_device_name_length(pcap_if_t *devices) {
    unsigned long max_device_name_length = 0;
    unsigned long tmp_len;
    while (devices) {
        tmp_len = strlen(devices->name);
        if (tmp_len > max_device_name_length) {
            max_device_name_length = tmp_len;
        }
        devices = devices->next;
    }
    return (int)max_device_name_length;
}

void print_device(pcap_if_t *device, int device_name_length) {
#if defined(PCAP_IF_CONNECTION_STATUS_CONNECTED) && defined(PCAP_IF_CONNECTION_STATUS_CONNECTED)
    printf("%*s %5c %12c %11c\n",
           device_name_length, device->name,
           (device->flags & PCAP_IF_UP) ? 'Y' : 'N',
           (device->flags & PCAP_IF_CONNECTION_STATUS_CONNECTED) ? 'Y' : 'N',
           (device->flags & PCAP_IF_WIRELESS) ? 'Y' : 'N');
#else
    printf("%*s %5c %12c %11c\n",
           device_name_length, device->name,
           (device->flags & PCAP_IF_UP) ? 'Y' : 'N',
           'X',
           'X');
#endif
}

int list_devices() {
    int err;
    char errbuf[PCAP_ERRBUF_SIZE];
    int device_length;
    pcap_if_t *devices;

    if ((err = pcap_findalldevs(&devices, errbuf)) != 0 || devices == NULL) {
        printf("Cannot list device:\ncode %d\nmessage: %s", err, errbuf);
        return (84);
    }
    device_length = max_device_name_length(devices);
    if (device_length < 14) {
        device_length = 14;
    }
    printf("%*s %5s %12s %11s\n", device_length, "Device name", "Up", "Connected", "Wireless");
    while (devices) {
        print_device(devices, device_length);
        devices = devices->next;
    }
    pcap_freealldevs(devices);
    return (0);
}