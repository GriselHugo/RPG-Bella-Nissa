/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-romain.oeil
** File description:
** functions relative to the config file
*/

#include "../include/rpg.h"

char **create_config_arr(void)
{
    int fd;
    char buf[600];
    char **arr;
    fd = open("include/config", O_RDONLY);
    if (fd == -1)
        return (NULL);
    read(fd, buf, 599);
    buf[599] = '\0';
    arr = str_to_word_array(buf, '\n');
    close(fd);
    return (arr);
}

void *get_conf_value(char *param, char **config, int index)
{
    list *help = new_list();
    if (config[index] == NULL)
        return (NULL);
    if (my_strcmp(param, "HELP_TEXT") == 0) {
        for (int i = index; my_strcmp(config[i], "END") != 0; i++) {
            help = add_end(help, config[i]);
        }
        return (help);
    }
    return (config[index]);
}

void *find_in_config(char *param, char **config)
{
    for (int i = 0; config[i] != NULL; i++) {
        if (my_strcmp(param, config[i]) == 0) {
            return (get_conf_value(param, config, i + 1));
        }
    }
    return (NULL);
}

void change_val(game_t *game, char *param, char *value)
{
    for (int i = 0; game->config[i] != NULL; i++) {
        if (my_strcmp(param, game->config[i]) == 0) {
            change_str(game->config[i + 1], value);
        }
    }
}

void change_config(game_t *game)
{
    int i;
    char mstr[4];
    char sstr[4];
    char istr[10];
    change_val(game, "MUSIC", my_itoa(game->musicvol, mstr));
    change_val(game, "SOUND", my_itoa(game->soundvol, sstr));
    if (game->state == PLAY || game->state == PAUSE)
        change_val(game,"INV",item_tab_to_str(game->play.inv.items, istr,','));
    FILE *fd = fopen("include/config", "w");
    fclose(fd);
    fd = fopen("include/config", "a+");
    for (i = 0; game->config[i + 1] != NULL; i++) {
        fwrite(game->config[i], sizeof(char), my_strlen(game->config[i]), fd);
        if (game->config[i + 1] != NULL)
            fwrite("\n", sizeof(char), 1, fd);
    }
    fwrite("}", sizeof(char), 1, fd);
    fclose(fd);
}
