##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	= 	gcc

SRC	= 	src/main.c	\
		src/window.c	\
		src/anim.c	\
		src/create_anim_from_file.c	\
		src/game_logic.c	\
		src/anim_game.c	\
		src/draw_game.c	\
		src/rain_particle_sys.c	\
		src/fire_particle_sys.c	\
		src/update_fire_particle_sys.c	\
		src/init_resources.c	\
		src/init_game_data.c	\
		src/save_game.c	\
		src/load_game.c	\
		src/collisions_logic.c	\
		src/character/move_character.c	\
		src/character/fight_logic.c	\
		src/character/character_event.c	\
		src/character/init_character.c	\
		src/character/init_boxes.c	\
		src/character/init_anims.c	\
		src/character/character_logic.c	\
		src/character/init_stats_bars.c	\
		src/character/stat_logic.c	\
		src/character/draw_character.c	\
		src/monsters/init_monster.c	\
		src/monsters/monsters_logic.c	\
		src/monsters/init_monster_health_bar.c	\
		src/monsters/fight_logic.c	\
		src/monsters/move_monsters.c	\
		src/monsters/flip_monster.c	\
		src/inventory/item/init_items.c	\
		src/inventory/item/item_bank.c	\
		src/inventory/init_inventory.c	\
		src/inventory/draw_inventory.c	\
		src/inventory/setting.c	\
		src/inventory/init_rectangle.c	\
		src/inventory/inventory_logic.c	\
		src/inventory/draw_inventory_boxes.c	\
		src/inventory/item/item_interaction.c	\
		src/inventory/item/item_logic.c	\
		src/inventory/check_for_item_in_inventory.c	\
		src/npc/init_npcs.c	\
		src/npc/draw_npc.c	\
		src/npc/dialogue/draw_dialogue_box.c	\
		src/npc/dialogue/init_dialogue.c	\
		src/npc/dialogue/get_dialogues.c	\
		src/npc/search_npc.c	\
		src/load_world/load_map.c	\
		src/load_world/create_texture.c	\
		src/load_world/load_monsters.c	\
		src/load_world/load_events.c	\
		src/find_char.c	\
		src/create_box.c	\
		src/push_button.c	\
		src/create_button.c	\
		src/display_button.c	\
		src/game_loop.c	\
		src/stat_point/init_ui.c	\
		src/stat_point/draw_ui.c	\
		src/stat_point/stat_point_logic.c	\
		src/quest/check_quests.c	\
		src/quest/init_quest.c	\
		src/quest/init_quest2.c	\
		src/scene_logic.c	\
		src/scene_redirection.c	\
		src/analyse_scene.c	\
		src/display_settings.c	\
		src/button_logic.c	\
		src/menus.c	\
		src/set_music.c	\
		src/manage_map_loading.c	\
		src/dungeon/dungeon_event.c	\
		src/info_box/init_info_box.c	\
		src/info_box/set_info_box.c	\
		src/info_box/draw_info_box.c	\
		src/houses_management.c	\
		src/manage_map_lock.c	\
		src/intro/game_intro.c	\
		src/intro/draw_intro.c	\
		src/intro/event.c	\
		src/intro/init_intro.c	\
		src/intro/intro_logic.c	\

OBJ	=	$(SRC:.c=.o)

NAME 	=	my_rpg

LDFLAGS	=	-L ./lib/my -lmy

CFLAGS	=	-Wall -Wextra -I ./include -g

TEST	=	./tests/

LIBMY   = lib/my/libmy.a

TEST_OBJ =	$(TEST:.c=.o)

RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

.SILENT:

all: $(NAME)

$(NAME): libmy msg $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS) -l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio -lm
	printf "\n$(GREEN)[✓]$(NC)\x1B[32mExecutable $(NAME) ready !\x1B[37m\n"

%.o : %.c
	printf "\e[38;5;27m▒▒\e[0m"
	gcc -o $@ -c -I ./include $(CFLAGS) $^

libmy:
	make --no-print-directory -C ./lib/my/

msg:
	@printf "\n\x1B[38;5;27mCompiling $(NAME)...\n\x1b[37m"


test_run: CFLAGS += --coverage
test_run: LDFLAGS += -lcriterion --coverage
test_run: clean $(TEST_OBJ)
	$(CC) -o unit_tests $(TEST_OBJ) $(LDFLAGS)
	./unit_tests

clean:
	make --no-print-directory -C ./lib/my/ clean
	rm -f $(OBJ)
	printf "$(RED)[-]$(NC).o files deleted\n"
	rm -f *.gcno
	rm -f *.gcda

fclean: clean
	make --no-print-directory -C ./lib/my/ fclean
	rm -f $(NAME)
	printf "$(RED)[-]$(NC)Executable $(NAME) deleted\n"
	rm -f *.gcno
	rm -f ./tests/*.gcno
	rm -f *.gcda
	rm -f ./tests/*.gcda
	rm -f ./tests/*.o
	rm -f unit_tests

re: fclean all
