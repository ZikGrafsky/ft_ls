NAME=ft_ls

CC=clang
FLG=-Wall -Wextra -Werror
SRC=	main.c ft_ls.c output_data.c duarrtsort.c\
		fncs/duarrbsort.c fncs/ft_atoi.c fncs/ft_itoa.c\
		fncs/duarrfree.c fncs/duarrlen.c fncs/ft_strchr.c\
		fncs/ft_strcmp_nc.c fncs/ft_strcpy.c fncs/stradd.c\
		fncs/ft_strdup.c fncs/ft_strjoin.c fncs/ft_strlen.c\
		fncs/strconcat.c fncs/to_lower.c gets/get_groupname.c\
		gets/get_list_format_data.c gets/get_output_options.c\
		gets/get_permissions.c gets/get_output_data.c\
		gets/get_username.c gets/get_output_args.c
OBJ=$(SRC:.c=.o)

all: $(SRC) $(NAME)
	@echo "\033[32;1m───[.o]-files => o_files-dir\033[0m"
	@mkdir o_files
	@mv fncs/*.o o_files
	@mv gets/*.o o_files
	@mv *.o o_files

$(NAME): $(OBJ)
	@echo "\033[32;1m└──Get object files\033[0m"
	@echo "\033[32;1m┌──Compile\033[0m"
	$(CC) $(FLG) $(OBJ) -o $@

.cpp.o:
	$(CC) $(FLG) $< -o $@

clean:
	@echo "\033[32;1m───Object files have been removed\033[0m"
	@rm -rf o_files

fclean: clean
	@rm ${NAME}
	@echo "\033[32;1m───The project has been cleared\033[0m"

re: fclean all
#____________________________TESTS________________________________

testcases:
	@echo "\033[33;1mTESTCASES(Please compile ft_ls before running test cases)\n\033[35;1m└─$$ make test_sc\033[0m - single cases\n\
\033[35;1m└─$$ make test_mc\033[0m - multiple cases\n\
\033[35;1m└─$$ make test_wf\033[0m - without flags\n\
\033[35;1m└─$$ make test_a\033[0m - flag 'a'\n\
\033[35;1m└─$$ make test_r\033[0m - flag 'r'\n\
\033[35;1m└─$$ make test_R\033[0m - flag 'R'\n\
\033[35;1m└─$$ make test_t\033[0m - flag 't'\n\
\033[35;1m└─$$ make test_l\033[0m - flag 'l'\033[0m\n\
\033[35;1m└─$$ make test\033[0m - all testcases\033[0m\n"

test_a:
	@echo "\033[32;1m||||||||WITH_FLAG_[[a]]: \033[0m\n"
	@echo "\033[35;1m____FT_LS____\033[0m"
	@./$(NAME) -a
	@echo "\033[35;1m\n-------------\n_____LS______\033[0m"
	@ls -a
	@echo "\033[35;1m-------------\n\n\033[0m"

test_r:
	@echo "\033[32;1m||||||||WITH_FLAG_[[r]]: \033[0m\n"
	@echo "\033[35;1m____FT_LS____\033[0m"
	@./$(NAME) -r
	@echo "\033[35;1m\n-------------\n_____LS______\033[0m"
	@ls -r
	@echo "\033[35;1m-------------\n\n\033[0m"

test_t:
	@echo "\033[32;1m||||||||WITH_FLAG_[[t]]: \033[0m\n"
	@echo "\033[35;1m____FT_LS____\033[0m"
	@./$(NAME) -t
	@echo "\033[35;1m\n-------------\n_____LS______\033[0m"
	@ls -t
	@echo "\033[35;1m-------------\n\n\033[0m"

test_R:
	@echo "\033[32;1m||||||||WITH_FLAG_[[R]]: \033[0m\n"
	@echo "\033[35;1m____FT_LS____\033[0m"
	@./$(NAME) -R
	@echo "\033[35;1m\n-------------\n_____LS______\033[0m"
	@ls -R
	@echo "\033[35;1m-------------\n\n\033[0m"

test_l:
	@echo "\033[32;1m||||||||WITH_FLAG_[[l]]: \033[0m\n"
	@echo "\033[35;1m____FT_LS____\033[0m"
	@./$(NAME) -l
	@echo "\033[35;1m\n-------------\n_____LS______\033[0m"
	@ls -l
	@echo "\033[35;1m-------------\n\n\033[0m"

test_wf:
	@echo "\033[32;1m||||||||WITHOUT_FLAGS: \033[0m\n"
	@echo "\033[35;1m____FT_LS____\033[0m"
	@./$(NAME)
	@echo "\033[35;1m\n-------------\n_____LS______\033[0m"
	@ls
	@echo "\033[35;1m-------------\n\n\033[0m"

test_sc: test_wf test_l test_a test_r test_R test_t

test_mc:
	@echo "\033[32;1m||||||||||||||||||||||MULTIPLE_CASES||||||||||||||||||||||||\033[0m\n"
	@echo "\033[32;1m||||||||WITH_FLAGS_[[al]]: \033[0m\n"
	@echo "\033[35;1m____FT_LS____\033[0m"
	@./$(NAME) -al
	@echo "\033[35;1m\n-------------\n_____LS______\033[0m"
	@ls -al
	@echo "\033[35;1m-------------\n\n\033[0m"
	@echo "\033[32;1m||||||||WITH_FLAGS_[[ar]]: \033[0m\n"
	@echo "\033[35;1m____FT_LS____\033[0m"
	@./$(NAME) -ar
	@echo "\033[35;1m\n-------------\n_____LS______\033[0m"
	@ls -ar
	@echo "\033[35;1m-------------\n\n\033[0m"
	@echo "\033[32;1m||||||||WITH_FLAGS_[[at]]: \033[0m\n"
	@echo "\033[35;1m____FT_LS____\033[0m"
	@./$(NAME) -at
	@echo "\033[35;1m\n-------------\n_____LS______\033[0m"
	@ls -at
	@echo "\033[35;1m-------------\n\n\033[0m"
	@echo "\033[32;1m||||||||WITH_FLAGS_[[aR]]: \033[0m\n"
	@echo "\033[35;1m____FT_LS____\033[0m"
	@./$(NAME) -aR
	@echo "\033[35;1m\n-------------\n_____LS______\033[0m"
	@ls -aR
	@echo "\033[35;1m-------------\n\n\033[0m"
	@echo "\033[32;1m||||||||WITH_FLAGS_[[lt]]: \033[0m\n"
	@echo "\033[35;1m____FT_LS____\033[0m"
	@./$(NAME) -lt
	@echo "\033[35;1m\n-------------\n_____LS______\033[0m"
	@ls -lt
	@echo "\033[35;1m-------------\n\n\033[0m"
	@echo "\033[32;1m||||||||WITH_FLAGS_[[lr]]: \033[0m\n"
	@echo "\033[35;1m____FT_LS____\033[0m"
	@./$(NAME) -lr
	@echo "\033[35;1m\n-------------\n_____LS______\033[0m"
	@ls -lr
	@echo "\033[35;1m-------------\n\n\033[0m"
	@echo "\033[32;1m||||||||WITH_FLAGS_[[lR]]: \033[0m\n"
	@echo "\033[35;1m____FT_LS____\033[0m"
	@./$(NAME) -lR
	@echo "\033[35;1m\n-------------\n_____LS______\033[0m"
	@ls -lR
	@echo "\033[35;1m-------------\n\n\033[0m"
	@echo "\033[32;1m||||||||WITH_FLAGS_[[tr]]: \033[0m\n"
	@echo "\033[35;1m____FT_LS____\033[0m"
	@./$(NAME) -tr
	@echo "\033[35;1m\n-------------\n_____LS______\033[0m"
	@ls -tr
	@echo "\033[35;1m-------------\n\n\033[0m"
	@echo "\033[32;1m||||||||WITH_FLAGS_[[tR]]: \033[0m\n"
	@echo "\033[35;1m____FT_LS____\033[0m"
	@./$(NAME) -tR
	@echo "\033[35;1m\n-------------\n_____LS______\033[0m"
	@ls -tR
	@echo "\033[35;1m-------------\n\n\033[0m"
	@echo "\033[32;1m||||||||WITH_FLAGS_[[rR]]: \033[0m\n"
	@echo "\033[35;1m____FT_LS____\033[0m"
	@./$(NAME) -rR
	@echo "\033[35;1m\n-------------\n_____LS______\033[0m"
	@ls -rR
	@echo "\033[35;1m-------------\n\n\033[0m"

test: test_sc test_mc

.PHONY:	all clean fclean re