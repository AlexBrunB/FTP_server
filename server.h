/*
** server.h for server in /home/abrun/delivery/Tek2/PSU_2016_myftp
** 
** Made by Alexandre Brun
** Login   <abrun@epitech.net>
** 
** Started on  Sun May 21 18:48:57 2017 Alexandre Brun
** Last update Sun May 21 18:49:00 2017 Alexandre Brun
*/

#ifndef SERVER_H_H
# define SERVER_H_H

# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct  s_ftp
{
  int		my_socket;
  unsigned int  len;
  int		socket_client;
  pid_t		pid;
  char		buffer[100];
  int		my_cmd;
}               t_ftp;


void	my_write(int socket_client);
int	check_socket(int my_socket);
int	check_ret(int my_ret);
int	check_ret_listen(int my_ret);
int	my_command(t_ftp ftp);
void    my_quit(t_ftp *ftp);
void    my_user(t_ftp *ftp);
void    my_pass(t_ftp *ftp);
void    my_help(t_ftp *ftp);
void	my_connect(t_ftp *ftp);

#endif 
