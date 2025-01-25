/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 07:58:00 by drubio-s          #+#    #+#             */
/*   Updated: 2025/01/04 10:55:06 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main (int argc, char **argv)
{
    int fd;
    char    *line;

    if (argc == 1)
    {
        printf ("Leyendo desde entrada estandar. Ctrl + D para terminar.\n");
        fd = 0;
    }
    else if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
            printf ("Error al abrir el archivo.\n");
            return (1);
        }
    }
    else
    {
        printf ("Has excedido el numero de argumentos.\n");
        return (2);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        if (!line)
        {
            printf ("Error al leer el archivo.\n");
            break;
        }
        printf ("Linea leida: %s", line);
        free (line);
    }
    if (argc == 1)
        printf ("Fin de lectura de entrada estandar.\n");
    if (argc == 2)
    {
        close (fd);
        printf ("Fin de lectura del archivo.\n");
    }
    return (0);

}