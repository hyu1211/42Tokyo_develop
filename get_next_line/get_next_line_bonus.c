#include "get_next_line.h"

char	get_next_line(int fd)
{
	static t_fdlist	*first_fdlist = NULL;
	t_fdlist		*new_fdlist;
	t_fdlist		*current_fdlist;
	char			*save;

	//fdが初出かチェック、情報を取り出す。
	if (!first_fdlist)
	{
		first_fdlist = (t_fdlist *)malloc(sizeof(t_fdlist));
		if (!first_fdlist)
			return (NULL);
		init_fdlist(first_fdlist);//fdlistのポインタ要素をNULLにする初期化関数
		current_fdlist = first_fdlist;
	}
	else 
	{
		current_fdlist = fd_check(first_fdlist, fd);
		if (current_fdlist == NULL)
		{
			new_fdlist = (t_fdlist *)malloc(sizeof(t_fdlist));
			if (new_fdlist)
				return (NULL);
			init_fdlist(new_fdlist);
			while (current_fdlist != NULL)
			{

			}
		}
	}
	save = current_fdlist->remaining_data
	if (!(save) || ft_strchr(save, '\n' == NULL))//!(前回の残りに改行がある)
	{
		while ()//\nない限りreadしてbuflistに格納
		{
			read(fd, )
		if ()//エラーでreturn(NULL)
		if ()//読み切った（buflistに改行がない）とき連結してreturn
		//前回のbuflistのis_nを0にする
		}
		//buflistに改行があるとき、
		{
			//改行のあるbuflistの改行前を残し、後ろをfdlistに格納。
			//buflist連結しreturn
		}
	}
	else//前回の残りに改行がある
	{
		//前と後ろに分け、前をreturn、後ろをfdlistに格納
	}
}

//freeしっかり、fdlistはeofまではfreeできない

// typedef struct	s_buflist
// {
// 	int					read_len;
//	int					is_n; <- 初期値は1
// 	char				*buffer;
// 	struct s_buflist	*next_buf;
// }				t_buflist;

// typedef struct s_fdlist
// {
// 	int				fd;
// 	char			*remaining_data;
// 	struct s_fdlist	*next_fd;
// }				t_fdlist;
