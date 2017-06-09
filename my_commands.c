/*
** my_commands.c for my_commands in /home/abrun/delivery/Tek2/PSU_2016_myftp
** 
** Made by Alexandre Brun
** Login   <abrun@epitech.net>
** 
** Started on  Sun May 21 18:30:06 2017 Alexandre Brun
** Last update Sun May 21 18:47:20 2017 Alexandre Brun
*/

# include "server.h"
# include "my_struct.h"

int		my_command(t_ftp ftp)
{

  int           i;

  ftp.my_cmd = 0;
  while (1)
    {
      memset(ftp.buffer, 0, 100);
      read(ftp.socket_client, ftp.buffer, 100);
      i = 0;
      while (i < 4)
        {
          if (strncmp(my_array[i].command,
		      ftp.buffer, strlen(my_array[i].command)) == 0)
            my_array[i].func(&ftp);
          i++;
        }
    }
  return (0);
}

void		my_quit(t_ftp *ftp)
{
  dprintf(ftp->socket_client, "221 Ciao \r\n");
  close(ftp->socket_client);
  close(ftp->my_socket);
  exit(1);
}

void		my_user(t_ftp *ftp)
{
  ftp->my_cmd = 0;
  if ((strncmp(ftp->buffer, "USER ", 5) == 0 && strlen(ftp->buffer) == 7) ||
      (strncmp(ftp->buffer, "USER", 4) == 0 && strlen(ftp->buffer) == 6))
    dprintf(ftp->socket_client, "530 Permission denied \r\n");
  else
    {
      dprintf(ftp->socket_client, "331 Please specify the password \r\n");
      if (strncmp(ftp->buffer, "USER Anonymous", 14) == 0
	  && strlen(ftp->buffer) == 16)
        ftp->my_cmd = 1;
      else
        ftp->my_cmd = 2;
    }
}

void		my_pass(t_ftp *ftp)
{
  if (ftp->my_cmd == 1 && strncmp(ftp->buffer, "PASS", 4) == 0)
    {
      ftp->my_cmd = 3;
      dprintf(ftp->socket_client, "230 Login successful.\r\n");
    }
  if (ftp->my_cmd == 2)
    dprintf(ftp->socket_client, "530 Login incorrect.\r\n");
  if (ftp->my_cmd == 0)
    dprintf(ftp->socket_client, "530 Login with USER and PASS.\r\n");
}

void		my_help(t_ftp *ftp)
{
  if (ftp->my_cmd != 3)
    dprintf(ftp->socket_client, "530 Login with USER and PASS.\r\n");
  else
    {
      dprintf(ftp->socket_client,"214 HELP =\r\n");
      dprintf(ftp->socket_client,"USER PASS CWD CDUP QUIT DELE\r\n");
      dprintf(ftp->socket_client,"PWD PASV PORT HELP NOOP RETR\r\n");
      dprintf(ftp->socket_client,"STOR LIST\r\n");
      dprintf(ftp->socket_client,"214 Help OK\r\n");
    }
}
