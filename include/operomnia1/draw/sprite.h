#ifndef H_SPRITE
#define H_SPRITE

#include <allegro5/allegro.h>
#include <operomnia1/timers.h>

typedef ALLEGRO_BITMAP op_bitmap;

typedef struct frame {
  op_bitmap * frame_data;
  int frame_numb;
  bool is_head_frame;
  char * frame_name;
  struct frame * next_frame;
} frame;

typedef struct sprite {
  op_timer * anim_timer;
  int current_frame;
  int amount_frames;
  float fps;
  frame * frames;
} sprite;

void read_frames( frame * head_frame );

sprite * sort_frames( sprite * to_sort );

void free_frames( frame * in_frame );

void destroy_sprite( sprite * in_sprite );

// You just need a number before the .png
sprite * load_sprite( const char * sprite_dir, float in_fps );

void append_frame( frame * head_frame, char * in_frame_path );

void add_sorted_frame( sprite * data, frame * head_frame, char * in_frame_path );

#endif
