/*
** EPITECH PROJECT, 2020
** CO892_2019_assessment2
** File description:
** sniff.c
*/

#include <pcap/pcap.h>
#include "sniff.h"

static const int packet_count_limit = 10;

int apply_filter(char *bin_name, t_args *args, pcap_t *sniffer) {
    struct bpf_program filter;
    if (args->filter != NULL) {
        if (pcap_compile(sniffer, &filter, args->filter, 0, PCAP_NETMASK_UNKNOWN) == PCAP_ERROR) {
            pcap_close(sniffer);
            fprintf(stderr, "%s: %s\n", bin_name, pcap_geterr(sniffer));
            return (84);
        }
        if (pcap_setfilter(sniffer, &filter) == PCAP_ERROR) {
            pcap_close(sniffer);
            fprintf(stderr, "%s: %s\n", bin_name, pcap_geterr(sniffer));
            return (84);
        }
    }
    return (0);
}

int dump_pcap(char *bin_name, t_args *args, pcap_t *sniffer) {
    pcap_dumper_t *dumper;
    if ((dumper = pcap_dump_open(sniffer, args->out_filename)) == NULL) {
        pcap_close(sniffer);
        fprintf(stderr, "%s: %s\n", bin_name, pcap_geterr(sniffer));
        return (84);
    }
    pcap_dispatch(sniffer, packet_count_limit, &pcap_dump, (u_char *)dumper);
    pcap_dump_close(dumper);
    return (0);
}

int sniff_device(char *bin_name, t_args *args) {
    pcap_t *sniffer;
    int timeout_limit = 3 * 1000;
    char errbuf[PCAP_ERRBUF_SIZE];
    int code;

    if ((sniffer = pcap_open_live(args->sniff_device, BUFSIZ, 0, timeout_limit, errbuf)) == NULL) {
        fprintf(stderr, "%s: %s\n", bin_name, errbuf);
        return (84);
    }
    if ((code = apply_filter(bin_name, args, sniffer)) != 0) {
        return (code);
    }
    if ((code = dump_pcap(bin_name, args, sniffer)) != 0) {
        return (code);
    }
    pcap_close(sniffer);
    return (0);
}