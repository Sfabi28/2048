#include "header.h"

void	mirror(int *row, t_game *game)
{
	int	temp;

	temp = row[0];
	row[0] = row[game->size - 1];
	row[game->size - 1] = temp;
	if (game->size == 4)
	{
		temp = row[1];
		row[1] = row[2];
		row[2] = temp;
	}
	else if (game->size == 5)
	{
		temp = row[1];
		row[1] = row[3];
		row[3] = temp;
	}
}

void	transpose(t_game *game)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < game->size)
	{
		j = i + 1;
		while (j < game->size)
		{
			temp = game->board[i][j];
			game->board[i][j] = game->board[j][i];
			game->board[j][i] = temp;
			j++;
		}
		i++;
	}
}

int	align(int *row, t_game *game)
{
	int	moves;
	int	k;
	int	i;

	moves = 0;
	k = 0;
	i = 0;
	while (i < game->size)
	{
		if (row[i] != 0)
		{
			if (k != i)
			{
				row[k] = row[i];
				row[i] = 0;
				moves = 1;
			}
			k++;
		}
		i++;
	}
	return (moves);
}

void	save_score_to_file(char *filename, int score)
{
	int		fd;
	char	*str;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return ;
	str = ft_itoa(score);
	if (str)
	{
		write(fd, str, ft_strlen(str));
		free(str);
	}
	close(fd);
}

int	merge(int *row, t_game *game)
{
	int	moves;
	int	i;

	moves = 0;
	i = 0;
	while (i < game->size - 1)
	{
		if (row[i] != 0 && row[i + 1] == row[i])
		{
			row[i] *= 2;
			row[i + 1] = 0;
			moves++;
			game->score += row[i];
			if (game->size == 4 && game->score > game->best_score_4)
			{
				game->best_score_4 = game->score;
				save_score_to_file(".best_score_4", game->best_score_4);
			}
			else if (game->size == 5 && game->score > game->best_score_5)
			{
				game->best_score_5 = game->score;
				save_score_to_file(".best_score_5", game->best_score_5);
			}
		}
		i++;
	}
	return (moves);
}

int	get_score_from_file(char *filename)
{
	int		fd;
	char	buffer[20];
	int		bytes;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	bytes = read(fd, buffer, 19);
	close(fd);
	if (bytes > 0)
	{
		buffer[bytes] = '\0';
		return (ft_atoi(buffer));
	}
	return (0);
}

void	load_best_score(t_game *game)
{
	game->best_score_4 = get_score_from_file(".best_score_4");
	game->best_score_5 = get_score_from_file(".best_score_5");
}

void	update_best_score(t_game *game)
{
	save_score_to_file(".best_score_4", game->best_score_4);
	save_score_to_file(".best_score_5", game->best_score_5);
}