/*
** EPITECH PROJECT, 2017
** PSU_my_sokoban_2017
** File description:
** recup_map.c
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "runner.h"

char *my_strcat(char *dest, char *src)
{
	int i = 0;
	int x = 0;
	char *new = malloc(my_strlen(dest) + my_strlen(src) + 1);

	if (dest != NULL) {
		while (dest[i] != '\0') {
			new[i] = dest[i];
			i = i + 1;
		}
		free(dest);
	}
	if (src != NULL) {
		while (src[x] != '\0') {
			new[i] = src[x];
			i = i + 1;
			x = x + 1;
		}
	}
	new[i] = '\0';
	return (new);
}

char *load_file_in_mem(char *filepath)
{
	int fd;
	int reader;
	char *buffer = NULL;
	char *file = malloc(1);

	file[0] = '\0';
	if ((fd = open(filepath, O_RDONLY)) == -1)
		return (NULL);
	if ((buffer = malloc(sizeof(char) * 4097)) == NULL)
		return (NULL);
	while ((reader = read(fd, buffer, 4096)) != 0) {
		if (reader == -1)
			return (NULL);
		buffer[reader] = '\0';
		file = my_strcat(file, buffer);
	}
	free(buffer);
	return (file);
}

char **mem_alloc_2d_array(int nb_rows, char *file)
{
	char **tab = malloc(sizeof(char *) * (nb_rows + 1));
	int u = 0;
	int i = 0;
	int x = 0;

	tab[nb_rows] = NULL;
	while (file[i] != '\0') {
		while (file[i] != '\n' && file[i] != '\0') {
			i = i + 1;
			x = x + 1;
		}
		if (file[i] == '\0')
			return (NULL);
		tab[u] = malloc(sizeof(char) * (x + 1));
		tab[u][x] = '\0';
		u = u + 1;
		i = i + 1;
		x = 0;
	}
	return (tab);
}

int recup_dimension(char *file)
{
	int i = 0;
	int height = 0;

	while (file[i] != '\0') {
		if (file[i] == '\n')
			height = height + 1;
		i = i + 1;
	}
	return (height);
}

char **load_2d_arr_from_file(char *filepath, int height, int i, int u)
{
	char *file = load_file_in_mem(filepath);
	char **tab;

	if (file == NULL)
		return (NULL);
	height = recup_dimension(file);
	if ((tab = mem_alloc_2d_array(height, file)) == NULL)
		return (NULL);
	for (int x = 0; file[x] != '\0'; x++) {
		if (file[x] != '\n') {
			tab[u][i] = file[x];
			i = i + 1;
		} else {
			i = 0;
			u = u + 1;
		}
	}
	free(file);
	return (tab);
}
