# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:   #
#                                                     +:+ +:+         +:+     #
#    By: 42Tokyo <42Tokyo@student.42tokyo.jp>       +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2024/01/01 00:00:00 by 42Tokyo          #+#    #+#             #
#    Updated: 2024/01/01 00:00:00 by 42Tokyo         ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

# プロジェクト名
NAME = get_next_line

# コンパイラとフラグ
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g -fsanitize=address

# ソースファイル
SRCS = get_next_line.c get_next_line_utils.c

# オブジェクトファイル
OBJS = $(SRCS:.c=.o)

# ヘッダーファイル
HEADER = get_next_line.h

# デフォルトターゲット
all: $(NAME)

# メインターゲット
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# オブジェクトファイルの作成
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# デバッグビルド
debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(NAME)

# クリーンアップ
clean:
	rm -f $(OBJS)

# 完全クリーンアップ
fclean: clean
	rm -f $(NAME)

# 再ビルド
re: fclean all

# テスト用ターゲット
test: $(NAME)
	./$(NAME)

# ヘルプ
help:
	@echo "利用可能なターゲット:"
	@echo "  all     - プロジェクトをビルド"
	@echo "  debug   - デバッグフラグ付きでビルド"
	@echo "  clean   - オブジェクトファイルを削除"
	@echo "  fclean  - すべての生成ファイルを削除"
	@echo "  re      - 完全に再ビルド"
	@echo "  test    - テストを実行"
	@echo "  help    - このヘルプを表示"

# .PHONYターゲット
.PHONY: all debug clean fclean re test help
