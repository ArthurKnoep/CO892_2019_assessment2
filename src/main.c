/*
** EPITECH PROJECT, 2020
** CO892_2019_assessment2
** File description:
** main.c
*/

#include "./list_devices.h"
#include "./usage.h"
#include "./parse_args.h"
#include "sniff.h"

int main(int ac, char **av) {
    t_args args;

    initialize_args(&args);
    if (parse_args(ac, av, &args)) {
        return (84);
    }
    if (args.help_mode || (!args.list_mode && !args.sniff_mode)) {
        return print_usage(av[0]);
    } else if (args.list_mode) {
        return list_devices();
    } else {
        return sniff_device(av[0], &args);
    }
}