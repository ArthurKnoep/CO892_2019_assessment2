/*
** EPITECH PROJECT, 2020
** CO892_2019_assessment2
** File description:
** parse_args.h
*/

#ifndef CO892_2019_ASSESSMENT2_PARSE_ARGS_H
#define CO892_2019_ASSESSMENT2_PARSE_ARGS_H

typedef struct {
  int help_mode;
  int list_mode;
  int sniff_mode;
  char *sniff_device;
  char *filter;
  char *out_filename;
} t_args;

void initialize_args(t_args *args);
int parse_args(int ac, char **av, t_args *args);

#endif //CO892_2019_ASSESSMENT2_PARSE_ARGS_H
