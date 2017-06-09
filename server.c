/*
** server.c for server in /home/abrun/delivery/Tek2/PSU/sandbox
** 
** Made by Alexandre Brun
** Login   <abrun@epitech.net>
** 
** Started on  Tue May  9 10:28:11 2017 Alexandre Brun
** Last update Sun May 21 18:46:02 2017 Alexandre Brun
*/

# include "server.h"

int			my_operations(t_ftp ftp)
{
  struct sockaddr	client_struct;
  pid_t			pid;

  while (1)
    {
      ftp.socket_client =  accept(ftp.my_socket,
				  (struct sockaddr *)&client_struct,
				  &ftp.len);

      pid = fork();
      if (pid == 0)
	{
	  close(ftp.my_socket);
	  if (ftp.socket_client != -1)
	    {
	      if (ftp.my_cmd != 3)
		dprintf(ftp.socket_client, "220 \r\n");
	      my_command(ftp);
	      close(ftp.socket_client);
	    }
	}
      else
	close(ftp.socket_client);
    }
  close(ftp.my_socket);
}

int	main(int ac, char **av)
{
  struct sockaddr_in	my_struct;
  int			my_ret;
  int			op;
  t_ftp			ftp;

  if (ac != 3)
    {
      fprintf(stderr, "Usage : /server port path\n");
      exit (0);
    }
  op = 1;
  ftp.my_socket = socket(AF_INET, SOCK_STREAM, 0);
  my_struct.sin_family = AF_INET;
  my_struct.sin_addr.s_addr = htonl(INADDR_ANY);
  my_struct.sin_port = htons(atoi(av[1]));
  check_socket(ftp.my_socket);
  my_ret = bind(ftp.my_socket,
		(struct sockaddr *)&my_struct, sizeof(struct sockaddr_in));
  if (setsockopt(ftp.my_socket,
		 SOL_SOCKET, SO_REUSEADDR, &op, sizeof(int)) == -1)
    check_ret(my_ret);
  my_ret = listen(ftp.my_socket, 5);
  check_ret_listen(my_ret);
  my_operations(ftp);
  return (0);
}
