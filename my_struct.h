/*
** my_struct.h for my_struct in /home/abrun/delivery/Tek2/PSU_2016_myftp
** 
** Made by Alexandre Brun
** Login   <abrun@epitech.net>
** 
** Started on  Sun May 21 18:49:36 2017 Alexandre Brun
** Last update Sun May 21 18:49:44 2017 Alexandre Brun
*/

#ifndef MY_STRUCT_H_H
# define MY_STRUCT_H_H
# include "server.h"

typedef struct  s_psf
{
  char          *command;
  void          (*func)(t_ftp *ftp);

}               t_psf;

t_psf   my_array[] =
  {
    {"QUIT", &my_quit},
    {"USER", &my_user},
    {"PASS", &my_pass},
    {"HELP", &my_help}
  };


#endif
