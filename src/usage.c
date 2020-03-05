/*
** EPITECH PROJECT, 2020
** CO892_2019_assessment2
** File description:
** usage.c
*/

#include <stdio.h>

int print_usage(char *bin_name) {
    printf("Usage: %s (-l|-s) [OPTION]\n", bin_name);
    printf("Sniff 10 packets from the device specified in option and store them in a pcap file\n\n");
    printf(" -l, --list-devices\t\tlist network interfaces\n");
    printf(" -s, --sniff=DEVICE\t\tsniff 10 packets from DEVICE\n\n");
    printf(" -f, --filter=FILTER\t\tapply specific filter\n");
    printf(" -o, --out=OUTPUT\t\twrite captured packet to OUTPUT, default to out.pcap\n");
    return (0);
}