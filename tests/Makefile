NAME = tests

#CC = gcc
CC = gcc -Wall -Wextra -Werror
#CC = gcc -Wall -Wextra -Werror -g -fsanitize=address

C_DIR = srcs
C_FILES = $(addprefix $(C_DIR)/, \
		  main.c)

O_DIR = objs
O_FILES = $(C_FILES:$(C_DIR)/%.c=$(O_DIR)/%.o)

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a
H_DIR = includes

PROJ_LIB = libfiller.a
PROJ_DIR = ..
H_DIR_PROJ = ../includes

LIB = -L$(LIBFT_DIR) -lft -L. -lfiller
INCL = -I$(H_DIR) -I$(LIBFT_DIR)/includes -I$(H_DIR_PROJ)

################################################################################
#################################### RULES #####################################
################################################################################

all : $(NAME)

$(LIBFT) :
	@echo "\033[1;31m-- LIBFT ----------------------\033[0m"
	@make -C $(LIBFT_DIR)
	@printf  "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"

libfiller :
	@echo "\033[1;31m-- FILLER ---------------------\033[0m"
	@make -C $(PROJ_DIR) $(PROJ_LIB)
	@echo "\033[1;31m-- TEST OBJ --------------------\033[0m"

$(NAME) : $(LIBFT) libfiller $(O_FILES)
	@echo "\033[1;31m-- EXEC ------------------------\033[0m"
	@$(CC) $(O_FILES) -o $@ $(LIB)
	@printf "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"

$(O_DIR)/%.o: $(C_DIR)/%.c $(H_DIR)
	@mkdir -p $(O_DIR)
	@$(CC) -o $@ -c $< $(INCL)
	@printf "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"

clean :
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PROJ_DIR)
	@rm -rf $(O_DIR)

fclean : clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PROJ_DIR)
	@rm -rf $(NAME)
	@rm -rf $(PROJ_LIB)

re : fclean all

.PHONY : clean all fclean re
