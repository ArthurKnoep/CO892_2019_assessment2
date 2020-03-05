/*
** EPITECH PROJECT, 2020
** CO892_2019_assessment2
** File description:
** parse_args.c
*/

#include <getopt.h>
#include <stdio.h>
#include "parse_args.h"

void initialize_args(t_args *args) {
    args->help_mode = 0;
    args->sniff_mode = 0;
    args->list_mode = 0;
    args->sniff_device = NULL;
    args->filter = NULL;
    args->out_filename = "out.pcap";
}

int set_list_mode(t_args *args) {
    if (args->sniff_mode) {
        fprintf(stderr, "Cannot use at the same time sniff mode and list mode\n");
        return (1);
    }
    args->list_mode = 1;
    return (0);
}

int set_sniff_mode(t_args *args) {
    if (args->list_mode) {
        fprintf(stderr, "Cannot use at the same time sniff mode and list mode\n");
        return (1);
    }
    args->sniff_mode = 1;
    args->sniff_device = optarg;
    return (0);
}

int parse_args(int ac, char **av, t_args *args) {
    struct option opts[] = {
        {.name =  "help", .has_arg = no_argument, .flag = NULL, .val = 'h'},
        {.name =  "list-devices", .has_arg = no_argument, .flag = NULL, .val = 'l'},
        {.name =  "sniff", .has_arg = required_argument, .flag = NULL, .val = 's'},
        {.name =  "filter", .has_arg = required_argument, .flag = NULL, .val = 'f'},
        {.name =  "out", .has_arg = required_argument, .flag = NULL, .val = 'o'}
    };
    int c;
    while ((c = getopt_long(ac, av, "f:hlo:s:", opts, NULL)) != -1) {
        switch (c) {
            case 'h':args->help_mode = 1;
                return (0);
            case 'l':
                if (set_list_mode(args))
                    return (1);
                break;
            case 's':
                if (set_sniff_mode(args))
                    return (1);
                break;
            case 'f':args->filter = optarg;
                break;
            case 'o':args->out_filename = optarg;
                break;
            default:return 1;
        }
    }
    return (0);
}