#ifndef H_AL_HELPER
#define H_AL_HELPER

#include <stdio.h>
#include <allegro5/allegro.h>
#include <stdio.h>
#include "vectors.h"

typedef struct _mouse_buttons {
  bool left_button;
  bool right_button;
  bool middle_button;
} mouse_buttons;

static mouse_buttons empty_buttons;

typedef struct _helper_data {
  ALLEGRO_DISPLAY *display;
  ALLEGRO_EVENT_QUEUE *event_queue;
  ALLEGRO_COLOR clear_color;
  ALLEGRO_MOUSE_STATE mouse_state;
  mouse_buttons last_mouse;
  ALLEGRO_KEYBOARD_STATE key_state;
  ALLEGRO_TIMER * fps_time;
  bool keys[ ALLEGRO_KEY_MAX ];
  bool last_keys[ ALLEGRO_KEY_MAX ];
  bool checked_keys[ALLEGRO_KEY_MAX];
} helper_data;

void combine_vector( vector * rec, vector in );

void change_fps( helper_data * in_data, float in_fps );

mouse_buttons get_mouse_buttons( helper_data * in_data );

mouse_buttons get_mouse_pressed( helper_data * in_data );

vector get_mouse_pos( helper_data * in_data );

//void add_vector( vector * rec, vector in );

void al_easy_init( helper_data * in_data, float display_x, float display_y, int display_flags, float fps, float r, float g, float b );
void al_easy_exit( helper_data * in_data );

int al_catch_events( helper_data * in_data );

bool is_key_down( helper_data * in_data, int keycode );

bool is_key_pressed( helper_data * in_data, int keycode );

void zero_bool( bool * in_bool, int size );

void change_fps( helper_data * in_data, float in_fps );
#endif