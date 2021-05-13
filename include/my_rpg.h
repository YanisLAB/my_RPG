/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-yanis.labchiri
** File description:
** my_rpg.h
*/

#ifndef __RPG__
#define __RPG__

#define WIDTH 1920
#define HEIGHT 1080
#define INDEX_SPELL 4
#define INDEX_MAP 2
#define INDEX_MINIMAP 3
#define INDEX_BUTTON 5
#define INDEX_PARA 4
#define INDEX_BOSS 3
#define INDEX_OPTION 8
#define INDEX_PNJ 2
#define INDEX_PAUSE 6
#define INDEX_CINE 2
#define INDEX_INVEN 6
#define INDEX_WIN 5
#define INDEX_LOSE 6
#define INDEX_USE 9
#define INDEX_HELP 6
#define NB_QUEST 1
#define MENU 0
#define GAME 1
#define OPTION 2
#define HELP 3
#define PAUSE 4
#define CIN 6
#define DEAD 7
#define WIN 8
#define TOUCH 5
#define UP 520
#define DOWN 650
#define RIGHT 715
#define LEFT 582
#define pp all->p.player.position

#define PARICULE_ANGLE_MIN (0)
#define PARICULE_ANGLE_MAX (M_PI * 2)
#define GRAVITY_X (1.0f * 0)
#define GRAVITY_Y (1.0f * 0)
#define ALPHA (255)

#define PARICULE_MAX (5000)
#define SPEED (0.1f)

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <SFML/Config.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Window.h>
#include <unistd.h>
#include <SFML/Audio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct clock_s {
    float sec;
    sfClock* clock;
    sfTime time;
}clocks_t;

typedef struct sprite_s {
    sfIntRect rect;
    sfVector2f scale;
    sfSprite *sprite;
    sfCircleShape *circle;
    sfVector2u size;
    sfTexture* texture;
    sfVector2f position;
    sfVector2f acceleration;
    clock_t clock;
}sprite_t;

typedef struct text_s {
    char str[500];
    int nbr;
    sfText *text;
    sfFont *my_font;
    sfVector2f position;
}text_t;

typedef struct sound_s {
    sfSound *sound;
    sfSoundBuffer *sbuffer;
}sound_t;

typedef struct particle_s
{
    sfVector2f pos;
    sfVector2f vel;
    sfColor color;
    size_t radius;
    bool living;
}particle_t;

typedef struct particle_environment_s
{
    float angle_min;
    float angle_max;
    float speed;
    sfVector2f gravity;
    sfUint8 alpha;
    sfClock *clock;
    sfTime time;
    float sec;
    sfCircleShape *circle_shape;
    sfRectangleShape *rectangle_shape;
    sfConvexShape *convex_shape;
}particle_environment_t;

typedef struct player_s {
    clocks_t attack_c;
    sprite_t attack_s;
    sprite_t player;
    int finish;
    float life;
    float max_hp;
    float mana;
    float max_mana;
    float xp;
    float max_xp;
    int attack;
    text_t lvl;
    int point;
    int offset1;
    int offset2;
}player_t;

typedef struct mob_s {
    sprite_t mob;
    int offset1;
    int offset2;
}mob_t;

typedef struct mob_z_s {
    mob_t mobs;
    int life;
    struct mob_z_s *next;
}mob_z_t;

typedef struct keys_s {
    text_t pup;
    text_t pdown;
    text_t pleft;
    text_t pright;
    text_t pinv;
    int change;
    int up;
    int down;
    int left;
    int right;
    int inv;
}keys_t;

typedef struct map_s {
    int fd;
    int lvl;
    sfBool read_map;
    size_t len;
    char *buffer;
    char **map;
}map_t;

typedef struct inv_s {
    sprite_t stuff;
    int type;
    sfBool item;
    int stat[3];
    sfVector2f coord;
}inv_t;

typedef struct inventory_s {
    inv_t inv;
    struct inventory_s *next;
}inventory_t;

typedef struct boss_s {
    sprite_t boss;
    text_t id;
    int life;
    sfBool dead;
    int offset1;
    int offset2;
    clocks_t clock;
} boss_t;

typedef struct spell_s {
    int id;
    int damage;
    int range;
    text_t cooldown;
}spell_t;

typedef struct boss_f_s {
    int regen;
    int life;
    int life_max;
    int offset1;
    int offset2;
    sprite_t bg_bar;
    sprite_t bar_life;
    sprite_t boss;
    text_t name;
    sfBool fight;
} boss_f_t;

typedef struct pos_mob_s {
    int x;
    int y;
} pos_mob_t;


// General Struct
typedef struct all_struct_s {
    int s;
    int colspell1;
    int colspell2;
    int colspell3;
    int colspell4;
    int collattack;
    int colpart[4];
    int scene;
    int last_scene;
    int quest;
    bool invent;
    bool dial;
    sfBool use[INDEX_USE];
    pos_mob_t pos_mob;
    text_t time_play;
    text_t touch[TOUCH];
    text_t quest_t;
    sfRenderWindow* window;
    clocks_t clocks;
    sfEvent event;
    sfVector2i mouse;
    sprite_t quest_bg;
    sprite_t spelloverlay[INDEX_SPELL];
    sprite_t map[INDEX_MAP];
    sprite_t minimap[INDEX_MINIMAP];
    sprite_t button[INDEX_BUTTON];
    sprite_t parrallax[INDEX_PARA];
    sprite_t option[INDEX_OPTION];
    sprite_t pnj[INDEX_PNJ];
    sprite_t pause[INDEX_PAUSE];
    sprite_t cine[INDEX_CINE];
    sprite_t inventory_s[INDEX_INVEN];
    sprite_t lose[INDEX_LOSE];
    sprite_t win[INDEX_WIN];
    sprite_t help[INDEX_HELP];
    sprite_t logo;
    int help_page;
    spell_t spell[INDEX_SPELL];
    boss_t boss[INDEX_BOSS];
    text_t spell_lvl[INDEX_SPELL];
    boss_f_t boss_f;
    sprite_t load[2];
    text_t p_enter;
    map_t world;
    player_t p;
    keys_t keys;
    sprite_t overlay_items;
    inventory_t *inventory;
    inventory_t *equiped;
    mob_z_t *mob_z1;
    sfJoystickMoveEvent manette;
    clocks_t controller;
    clocks_t time_joy;
    clocks_t coll;
    int volume_music;
    int volume_sound;
    sfMusic *music_game;
    sound_t click;
    particle_t particle_rain[PARICULE_MAX];
    particle_t particle[PARICULE_MAX];
    particle_t particle_bis[PARICULE_MAX];
    particle_environment_t rain;
    particle_environment_t particle_environment;
    particle_environment_t particle_environment_bis;
} all_t;

typedef struct array_t {
    void(*ptr)(all_t *all);
}array_t;

//--------------------[all]--------------------
// ~~~{init.c}~~~
void init_all(all_t *all);
void init_bis(all_t *all);

// ~~~{destroy.c}~~~
void destroy_all(all_t *all);
void destroy_boss(all_t *all);

// ~~~{display.c}~~~
void display(all_t *all);
void act_coll(all_t *all);
//-------------------------------------------

//--------------------[lib]--------------------
// ~~~{init_sprite.c}~~~
void event_all(all_t *all);
sprite_t init_sprite(sfIntRect rect, char *path);
void move_rect(sfIntRect *rect, float offset, float offset2);
void destroy_sprite(sprite_t *sprite);
void display_sprite(sfRenderWindow *window, sprite_t *sprite,
                    float offset, float offset2);
void set_pos(sprite_t *sprite, int x, int y);
float get_distance(int cx, int cy, int x, int y);
char *my_strcpy(char *dest, char *src);
char *my_strcat(char *dest, char const *src);
void my_int_str(char *str, int nb);
bool free_at(mob_z_t **list, int index);
void display_coll(all_t *all);
char *open_file(char *file);

// ~~~{overlay_check.c}~~~
sfBool overlay_check(sprite_t *sprite, all_t *all);
sfBool release_check(all_t *all, sprite_t *sprite);
sfBool click_check(all_t *all);
void change_scene(all_t *all, int scene);

// ~~~{my_init_tab.c}~~~
char **my_init_char_tab(char **tab, int size, int size2);
void my_free_char_tab(char **tab, int size);
// char **my_str_to_word_array(char *str, char *separator);
char **my_str_to_word_array(char *str);
int my_strlen(char *str);
char **my_str_to_word_array2(char *str, char sep);
int my_atoi(char const *str);

// ~~~{swap_elem.c}~~~
void init_item_push_back(inventory_t **list, sfVector2f coord);

char *get_line(char *filepath, int line);
void time_str(char *str, int nb);
int my_put_nbr(int nb, int fd);
//-------------------------------------------

//--------------------[map]--------------------
// ~~~{map.c}~~~
void init_map(all_t *all);
void display_map(all_t * all);
void destroy_map(all_t *all);

// ~~~{open_map.c}~~~
int get_world(map_t *map, char *filepath);
int destroy_world(all_t *all);
void init_minimap(all_t *all);
void display_minimap(all_t *all);
void destroy_minimap(all_t *all);

//-------------------------------------------

//--------------------[player]--------------------
// ~~~{player.c}~~~
sfBool check_pos_player(all_t *all, int x, int y);
void init_player(all_t *all);
void destroy_player(all_t *all);
void move_player(all_t *all, int top, int mtop);
void init_pnj(all_t *all);
void update_life(all_t *all);
void move_player(all_t *all, int top, int mtop);
void display_attack(all_t *all);
int choose_rect(all_t *all);
void display_a(all_t *all, int rect);
//-------------------------------------------

//--------------------[menu_main]--------------------
// ~~~{event.c}~~~
void event_main_menu(all_t *all);
void overlay_main_menu(all_t *all);
// ~~~{init_main_menu.c}~~~~
void init_main_menu(all_t *all);
// ~~~{display_main_menu.c}~~~
void display_main_menu(all_t *all);
// ~~~{destroy.c}~~~
void destroy_main(all_t *all);
//-------------------------------------------

//--------------------[menu_option]--------------------
//~~~{init.c}~~~
void init_option(all_t *all);
//~~~{destroy.c}~~~
void destroy_option(all_t *all);
//~~~{display.c}~~~
void display_option(all_t *all);
//~~~{event.c}~~~
void event_option(all_t *all);
void overlay_option(all_t *all);
//~~~{sound.c}~~~
void init_music(all_t *all);
void destroy_sound(all_t *all);
void music_volume(all_t *all, int button);
void sound_volume(all_t *all, int button);
//-------------------------------------------

//--------------------[game]--------------------
void move_map_rect(all_t *all, int left, int top);
void event_spell(all_t *all);
void attack(all_t *all);
void attack_up(mob_z_t *mobs, int dommage, all_t *all);
void attack_down(mob_z_t *mobs, int dommage, all_t *all);
void attack_left(mob_z_t *mobs, int dommage, all_t *all);
void attack_right(mob_z_t *mobs, int dommage, all_t *all);
// ~~~{game.c}~~~
void event_game(all_t *all);
void event_pnj(all_t *all);
void pnj1(all_t *all);
void pnj2(all_t *all);
//-------------------------------------------

//--------------------[help]--------------------
//~~~{init.c}~~~
void init_help(all_t *all);
void destroy_help(all_t *all);
void pos_key(all_t *all, int type);
void display_help(all_t *all);
//~~~{event.c}~~~
void event_help(all_t *all);
void overlay_help(all_t *all);
//-------------------------------------------

//------------------[pause]-----------------
void init_pause(all_t *all);
void display_pause(all_t *all);
void event_pause(all_t *all);
void destroy_pause(all_t *all);

//--------------------[inventory]--------------------
//~~~{init.c}~~~
void init_inv(all_t *all);
//~~~{display.c}~~~
void display_inventory(all_t *all);
//~~~{destroys.c}~~~
void destroy_inventory(all_t *all);
void event_inventory(all_t *all);
void reset(all_t *all);
void delet_badge(inventory_t **inv);
void remove_item(all_t *all);
void item_switch(inv_t *tmp, inv_t *tmp2);
int randomizer_item(void);
void give_item(all_t *all, int type);
void overlay_inv(all_t *all);
void update_stat(all_t *all, int *stat, int type);
void unequipe_item(all_t *all);
void switch_items(all_t *all);
void check_switch(inventory_t *tmp, all_t *all);
//-------------------------------------------


//--------------------[joystick]--------------------
void joystick_movement(all_t *all);
//-------------------------------------------

//---------------------[cinématique]-----------------
void event_cine(all_t *all);
void cine(all_t *all);
//----------------------------------------------

//---------------------[load]-----------------
void init_loading(all_t *all);
void display_load(all_t *all);
//----------------------------------------------

//---------------------[spell]-----------------
void display_attack(all_t *all);
int init_spell(all_t *all);
void spell_one(all_t *all);
void spell_two(all_t *all);
void spell_tree(all_t *all);
void spell_four(all_t *all);
void init_spell_lvl(all_t *all);
void destroy_cooldown(all_t *all);
void even_spellb(all_t *all);
//----------------------------------------------

//---------------------[mob]-----------------
void mobs_push_back(mob_z_t **mobs, sprite_t img, int life, pos_mob_t pos);
void moov_all_mobs(all_t *all);
void check_dead(all_t *all);
void display_boss(all_t *all);
void init_boss_final(all_t *all);
void event_fboss(all_t *all);
void destroy_boss_final(all_t *all);
void init_boss(all_t *all);
void moov_mobs(mob_z_t **mobs, all_t *all);
void init_mobs(mob_z_t **mobs, int nb_mob, int x, int y);
void init_all_mobs(all_t *all);
void destroy_mob(all_t *all);
void display_all_mobs(all_t *all);
void dammage_all_mobs(all_t *all);
//----------------------------------------------

//---------------------[pnj]-----------------
text_t set_text_quest(int x, int y);
void pnj2_bis(all_t *all);
void blabla2(all_t *all);
void pnj2_if(all_t *all);
void pnj2_condition(all_t *all);
//----------------------------------------------

//---------------------[particule]-----------------
void init_particule(const particle_environment_t *particle_environment,
particle_t *particule, const sfVector2f pos);
void init_particle_environment(particle_environment_t *particle_environment,
const sfVector2f angle, const sfVector2f gravity, const sfUint8 alpha);
void display_particle(sfRenderWindow *window, const particle_t *particule,
sfCircleShape *circle_shape);
void add_particle(const particle_environment_t *particle_environment,
particle_t *particule, const size_t particle_num, const sfVector2f pos);
void update_particle(const particle_environment_t *particle_environment,
particle_t *particule);

void init_particule_bis(const particle_environment_t *particle_environment,
particle_t *particule, const sfVector2f pos);
void init_particle_environment_bis(particle_environment_t *particle_environmen,
const sfUint8 alpha);
void display_particle_bis(sfRenderWindow *window, const particle_t *particule,
sfConvexShape *convex_shape);
void add_particle_bis(const particle_environment_t *particle_environment,
particle_t *particule, const size_t particle_num, const sfVector2f pos);
void update_particle_bis(const particle_environment_t *particle_environment,
particle_t *particule);

void add_rain(const particle_environment_t *particle_environment,
particle_t *particule, const size_t particle_num, const sfVector2f pos);
void update_rain(const particle_environment_t *particle_environment,
particle_t *particule);
void display_rain(sfRenderWindow *window, const particle_t *particule,
sfRectangleShape *rectangle_shape);
void init_rain(const particle_environment_t *particle_environment,
particle_t *particule, const sfVector2f pos);
void init_rain_env(particle_environment_t *particle_environment,
const sfVector2f angle, const sfVector2f gravity, const sfUint8 alpha);
//----------------------------------------------

//---------------------[lose]-----------------
void init_lose(all_t *all);
void display_lose(all_t *all);
void destroy_lose(all_t *all);
void event_lose(all_t *all);
void restart(all_t *all);
//---------------------------------------------------

//---------------------[win]-----------------
void init_win(all_t *all);
void display_win(all_t *all);
void destroy_win(all_t *all);
void event_win(all_t *all);
//---------------------------------------------------

//---------------------[save]-----------------
void init_player_bis(all_t *all);
void open_save(all_t *all);
void write_save(all_t *all);
void save_player(all_t *all);
void save_inv(all_t *all, char *str);
void save_equipe_bis(all_t *all, inventory_t *tmp, int nbr, int a);
void save_pos_mobs(all_t *all, int x, int y);
//---------------------------------------------------

#endif