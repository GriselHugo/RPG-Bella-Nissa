/*
** EPITECH PROJECT, 2022
** rpg.h
** File description:
** .h for my_rpg project
*/

#ifndef RPG_H
    #define RPG_H

    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <fcntl.h>
    #include <math.h>
    #include <time.h>

    #define BLUE "\033[0;34m"
    #define GREEN "\033[0;32m"
    #define RED "\033[0;31m"
    #define YELLOW "\033[0;33m"
    #define PURPLE "\033[0;35m"
    #define CYAN "\033[0;36m"
    #define WHITE "\033[0;37m"
    #define RESET "\033[0m"
    #define BOLD "\033[1m"
    #define UNBOLD "\033[0m"
    #define BASE (sfColor) {255, 255, 255, 255}
    #define TRANSPARENT (sfColor) {255, 255, 255, 100}

enum state {
    MENU,
    PLAY,
    OPTION,
    HELP,
    EXIT,
    PAUSE,
    SETTINGS,
    LOADING,
};

enum move {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
};

enum entitytype {
    DEAD,
    ENNEMY,
    NPC,
    BOSS,
};

enum quest {
    READY,
    PROGRESS,
    END
};

enum loadorder {
    L_NONE,
    L_NICE,
};

enum WEATHER {
    SUN,
    RAIN,
    FOG,
};

enum SCENE {
    S_NICE,
    S_MCDO,
    S_EPI,
    S_CREDITS,
};

typedef struct text_s {
    int nbr_stat;
    char *string;
    sfText *stat;
    sfFont *font;
    sfVector2f pos;
} text_t;

typedef struct weather_s {
    sfSprite *sprite;
    sfTexture *rain_tex;
    sfTexture *sun_tex;
    sfTexture *fog_tex;
    sfClock *change;
    sfClock *clock;
    sfIntRect rect;
    sfTime time;
    bool manual;
    float seconds;
    int timer;
    int speed_mod;
    int type;
} weather_t;

typedef struct listnode {
    void *value;
    struct listnode *next;
    struct listnode *prev;
} list;

typedef struct object_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
    bool obtained;
} object_t;

typedef struct sound_s {
    sfSound *click;
    sfSoundBuffer *click_b;
    sfSound *quest;
    sfSoundBuffer *quest_b;
    sfSound *heal;
    sfSoundBuffer *heal_b;
} sound_t;

typedef struct inv_s {
    object_t gun;
    object_t potion;
    object_t cycle;
    object_t card;
    object_t map;
    text_t dmg;
    text_t rst;
    text_t speed;
    sfSprite *sprite;
    sfTexture *texture;
    char **items;
    bool open;
    bool pizza;
} inv_t;

typedef struct button_s {
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    int status;
} button_t;

typedef struct option_s {
    sfSprite *sprite;
    sfTexture *texture;
    button_t back;
    button_t musicminus;
    button_t musicplus;
    button_t soundminus;
    button_t soundplus;
    sfText *music;
    sfText *sound;
    sfFont *font;
} option_t;

typedef struct help_s {
    sfSprite *sprite;
    sfTexture *texture;
    button_t back;
    list *text;
    sfFont *font;
} help_t;

typedef struct loading_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfSprite *planet_s;
    sfTexture *planet_t;
} loading_t;

typedef struct menu_s {
    sfMusic *music;
    sfSprite *sprite;
    sfTexture *texture;
    button_t select_r;
    button_t select_l;
    button_t play;
    button_t option;
    button_t help;
    button_t exit;
    button_t reset;
    sfSprite *preview_s;
    sfTexture *preview_t;
    sfIntRect pre;
    int status;
} menu_t;

typedef struct attack_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    sfTime time;
    float seconds;
    bool attckng;
} attack_t;

typedef struct charac_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    sfClock *ivcblt;
    sfClock *attck_cldwn;
    sfClock *potion_cldwn;
    sfClock *effect;
    sfTime time;
    sfIntRect rect_hp;
    object_t health_bar;
    object_t hp;
    attack_t atk;
    bool is_running;
    float seconds;
    float health;
    float damage;
    float resist;
    int move;
    int kill;
    int speed;
} charac_t;

typedef struct entity_s {
    int type;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    sfSprite *text_s;
    sfTexture *text_t;
    float seconds;
    float health;
    float damage;
    float resist;
    int speed;
    int range;
    int dir;
} entity_t;

typedef struct credits_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfIntRect rect;
    bool skip;
    sfText *text;
    sfFont *font;
} credits_t;

typedef struct cartext_s {
    sfTexture *red;
    sfTexture *blue;
    sfTexture *green;
    sfTexture *yellow;
    sfTexture *black;
    sfTexture *white;
} cartext_t;

typedef struct sprite {
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    int status;
} sprite_t;

typedef struct play_s {
    sfMusic *fight_m;
    sfImage *map_bw_img;
    sfImage *mcdo_bw;
    sfImage *nice_bw;
    sfImage *epitech_bw;
    sfSprite *details_s;
    sfSprite *sea_spr;
    sfTexture *sea_tex;
    sfTexture *details_t;
    sfTexture *palm_t;
    sfSprite *map_spr;
    sfTexture *nice_tex;
    sfTexture *map_tex;
    sfTexture *mcdo_t;
    sfTexture *epitech_tex;
    sfIntRect map_rct;
    sfIntRect nice_rct;
    sfIntRect mcdo_rct;
    sfIntRect epitech_rct;
    sfIntRect sea_rct;
    sfClock *sea_clk;
    list *ennemy;
    list *npc;
    list *boss;
    list *cars;
    list *old_npc;
    int quest;
    int scene;
    sfSprite *pizza_s;
    sfTexture *pizza_t;
    sfVector2f pos_pizza;
    charac_t perso;
    sfVector2f pos_nice;
    sfVector2f pos_mcdo;
    sfVector2f pos_epitech;
    sfVector2f pos_sea_cur;
    sfVector2f pos_sea_str;
    sfVector2f pos_sea_end;
    sfVector2f sea_spd;
    sfVector2f sea_spd_inv;
    inv_t inv;
    weather_t weather;
    int sea_tick;
    int map_x;
    int map_y;
    int nice_x;
    int nice_y;
    int mcdo_x;
    int mcdo_y;
    int epitech_x;
    int epitech_y;
    bool fight;
    bool change_scn;
    bool sea_up;
    credits_t credits;
    cartext_t cartext;
} play_t;

typedef struct pause_s {
    button_t menu;
    button_t resume;
    button_t quit;
    button_t settings;
} pause_t;

typedef struct game_s {
    sfMusic *explo_m;
    sfRenderWindow *window;
    sfTime time;
    sfEvent event;
    sfImage *icon;
    int black;
    int red;
    int blue;
    int white;
    int state;
    int seconds;
    int musicvol;
    int soundvol;
    char **config;
    menu_t menu;
    help_t help;
    option_t option;
    play_t play;
    pause_t pause;
    sound_t sound;
    loading_t loading;
    inv_t inv;
    int index;
    int nextload;
    bool play_loaded;
    sprite_t damien;
} game_t;

object_t create_item(char *path, sfVector2f pos);
button_t assign_button(char *path, sfVector2f pos, sfIntRect rect);
option_t assign_option_s(game_t *game);
help_t assign_help_s(game_t *game);
menu_t assign_menu_s(void);
game_t assign_game_s(void);
pause_t assign_pause_s(game_t *game);
charac_t assign_perso(game_t *game);
play_t assign_play_s(game_t *game);
inv_t assign_inventory(void);
entity_t *assign_entity_s(char *name, int type, game_t *game, sfVector2f pos);
sound_t assign_sounds(void);
loading_t assign_loading_s(void);
entity_t *assign_npc(char *name, int type, game_t *game, sfVector2f pos);
weather_t assign_weather_s(void);
credits_t assign_credits_s(void);
text_t create_text_stats(char *path, game_t *game, sfVector2f pos, char *stat);
list *boss_defeat(game_t *game, list *npc);
list *generate_npc(game_t *game);
list *add_end(list *li, void *value);
list *add_front(list *li, void *value);
list *rem_end(list *li);
list *rem_front(list *li);
list *rem_mid(list *lst);
list *new_list(void);
list *generate_boss(game_t *game, char *type);
list *generate_ennemies(game_t *game, char *type);
list *create_ennemis_garden(game_t *game, list *tlst);
list *create_ennemis_prom(game_t *game, list *tlst);
list *create_ennemis_place(game_t *game, list *tlst);
sfIntRect set_rect(int top, int left, int height, int width);
sfTexture *assign_texture(game_t *game);
sfText *create_text(char *str, int dist, sfFont *font);
void anim_old(game_t *game);
void draw_olds(game_t *game, list *oldNpc);
void create_old_list(play_t *play, game_t *game);
bool can_move(game_t *game);
bool can_move_hori(game_t *game, int pos_x, int pos_y, int black);
bool is_in_window(sfVector2f pos);
bool is_button_hovered(sfVector2f mouse_pos, sfFloatRect rect);
bool rect_collision(sfSprite *sprite, sfVector2f collider);
bool is_empty(list *li);
bool sprite_collision(sfSprite *sprite1, sfSprite *sprite2);
bool ennemy_can_move(entity_t *entity, game_t *game, int dir);
void set_color(entity_t *car, cartext_t *cartext);
void set_eric_mode(game_t *game);
void draw_boss(game_t *game, list *bossl);
void fight_management(game_t *game, entity_t *ennemy, float distance);
void boss_fight(game_t *game);
void destroy_musics(sound_t *sound);
void draw_ennemies(game_t *game, list *renderl);
void ciro_quest(game_t *game, list *render);
void draw_npc(game_t *game, list *renderNpc);
void heal_bar_change(game_t *game,float damage);
void assign_perso_misc(charac_t *perso);
void assign_play_s_2(play_t *play);
void *my_itoa(int n, char *s);
void assign_inv(inv_t *inv);
void move_directions(game_t *game);
void perso_selection_back(game_t *game, sfVector2i mouse_pos);
void perso_selection(game_t *game, sfVector2i mouse_pos);
void preview_create(menu_t *menu);
void select_buttons(option_t *option);
void assign_game_s_second(game_t *game);
void inventory_pop(game_t *game);
void check_display_inv(game_t *game);
void manage_keyboard_perso(game_t *game);
void move_character(game_t *game);
void music(game_t *game);
void perso_anim(game_t *game);
void listen_events(game_t *game);
void draw_sprites(game_t *game);
void draw_pause(game_t *game);
void manual(void);
void my_putchar(char c);
void set_button_rect(button_t *button, int top, int left);
void manage_mouse(game_t *game);
void draw_menu(game_t *game);
void draw_help(game_t *game);
void draw_option(game_t *game);
void draw_game(game_t *game);
void draw_load(game_t *game);
void destroy_button(button_t *button);
void destroy_option(option_t *option);
void destroy_help(help_t *help, int state);
void destroy_game(game_t *game);
void destroy_charac_t(charac_t *perso);
void destroy_list(list *li);
void destroy_play(play_t *play);
void destroy_inv(inv_t *inv);
void destroy_menu(menu_t *menu);
void destroy_pause(pause_t *pause);
void destroy_loading(loading_t *loading);
void manage_pause_menu_button(game_t *game, sfVector2i mouse_pos);
void manage_pause_resume_button(game_t *game, sfVector2i mouse_pos);
void manage_pause_quit_button(game_t *game, sfVector2i mouse_pos);
void manage_pause_settings_button(game_t *game, sfVector2i mouse_pos);
void manage_exit_button(game_t *game, sfVector2i mouse_pos);
void manage_option_button(game_t *game, sfVector2i mouse_pos);
void manage_help_button(game_t *game, sfVector2i mouse_pos);
void manage_play_button(game_t *game, sfVector2i mouse_pos);
void manage_reset_button(game_t *game, sfVector2i mouse_pos);
void mouse_help(game_t *game, sfVector2i mouse_pos);
void manage_back_button(game_t *game, sfVector2i mouse_pos);
void manage_sound_plus_button(game_t *game, sfVector2i mouse_pos);
void manage_sound_minus_button(game_t *game, sfVector2i mouse_pos);
void manage_music_plus_button(game_t *game, sfVector2i mouse_pos);
void manage_music_minus_button(game_t *game, sfVector2i mouse_pos);
void manage_game_music_plus_button(game_t *game, sfVector2i mouse_pos);
void manage_game_music_minus_button(game_t *game, sfVector2i mouse_pos);
void manage_back_to_game_button(game_t *game, sfVector2i mouse_pos);
void manage_loading(game_t *game);
void manage_weather(weather_t *weather);
void assigns_option_text(option_t *option, int musicvol, int soundvol);
void change_volume(game_t *game, char channel, int vol);
void change_config(game_t *game);
void change_value(game_t *game);
void change_val(game_t *game, char *param, char *value);
void change_str(char *dest, char *src);
void change_weather(weather_t *weather, int type);
void print_list(list *li);
void move_ennemies_wnd(game_t *game, sfVector2f direction);
void move_boss(list *bossl, sfVector2f direction);
void move_ennemies_to_player(game_t *game);
void move_vertical(entity_t *entity, charac_t *player, game_t *game);
void move_horizontal(entity_t *entity, charac_t *player, game_t *game);
void check_inventory(inv_t *inv, char **config);
void set_entity_s(entity_t *entity);
void perso_attack(game_t *game);
void attack_player(charac_t *player, entity_t *ennemy, game_t *game);
void is_alive(game_t *game);
void play_event(game_t *game);
void mouse_play(game_t *game, sfVector2i mouse_pos);
void use_potion(game_t *game);
void player_run(game_t *game);
void set_weather(weather_t *weather);
void move_rect(sfIntRect *rect, int offset, int max_value);
void move_rect_vert(sfIntRect *rect, int offset, int max_value);
void anim_ennemy(entity_t *ennemy);
void change_scene(game_t *game);
void set_foreground_transparenty(game_t *game, int color);
void set_play(play_t *play, game_t *game);
void render_nice(game_t *game);
void render_mcdo(game_t *game);
void render_epitech(game_t *game);
void render_credits(game_t *game);
void render_car(game_t *game, list *render);
void credits_loop(credits_t *credits, game_t *game);
void *find_in_config(char *param, char **config);
void create_cars_list(play_t *play, game_t *game);
char **str_to_word_array(char *str, char delim);
char **create_config_arr(void);
char *my_tab_to_str(char **tab, char *str, char delim);
char *item_tab_to_str(char **tab, char *str, char delim);
char *my_revstr(char *str);
char *my_strcat(char *, char const *);
int main_game(int mode);
int my_putstr(char const *str);
int main(int ac, char **av);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
int my_getnbr(char const *);
int list_len(list *li);
float get_distance(charac_t *player, entity_t *ennemy);

#endif
