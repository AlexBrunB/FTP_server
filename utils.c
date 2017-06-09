/*
** utils.c for utils in /home/abrun/delivery/Tek2/PSU_2016_myftp
** 
** Made by Alexandre Brun
** Login   <abrun@epitech.net>
** 
** Started on  Sun May 21 18:35:00 2017 Alexandre Brun
** Last update Sun May 21 18:45:27 2017 Alexandre Brun
*/

# include <stdio.h>
# include <stdlib.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <netdb.h>

int	check_socket(int my_socket)
{

  if (my_socket != -1)
    {
      printf("[OK] Socked created\n");
    }
  else
    {
      printf("[KO] Socket Error");
      return (0);
    }
  return (my_socket);
}

int	check_ret(int my_ret)
{
  if (my_ret != -1)
    {
      printf("[OK] Bind\n");
    }
  else
    {
      printf("[KO] Bind Error\n");
      return (1);
    }
  return (my_ret);
}

int	check_ret_listen(int my_ret)
{
  if (my_ret != -1)
    {
      printf("[OK] Listen\n");
    }
  else
    {
      printf("[KO] Error Listen\n");
      return (1);
    }
  return (my_ret);
}
