CC=clang
FLG=-Wall -Wextra -Werror
SRC=main.c
OBJ=$(SRC:.c=.o)
NAME=ft_ls

all: $(SRC) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLG) $(OBJ) -o $@

.cpp.o:
	$(CC) $(FLG) $< -o $@

clean:
	rm *.o

fclean: clean
	rm ${NAME}

re: fclean all
#____________________________TESTS________________________________
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

testcases:
	@echo "\033[35;1mtest_sc - single cases, \n\
test_mc - multiple cases\n\
test_wf - without flags\n\
test_a - flag \'a\'\n\
test_r - flag \'r\'\n\
test_R - flag \'R\'\n\
test_t - flag \'t\'\n\
test_l - flag \'l\'\033[0m\n"

.PHONY:	all clean fclean re