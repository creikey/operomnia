#include <stdio.h>

#include <operomnia1/operomnia.h>
#include <operomnia1/error.h>
#include <operomnia1/draw/draw.h>
#include <operomnia1/draw/svg.h>

#define default_clear_color new_color(100,100,100)

void game_loop( operomnia_data * in_data );

void init_game( operomnia_data * in_data );

int main( void ) {
  operomnia_data * data = malloc( sizeof *data );
  init_op( data, 900,900, true, ALLEGRO_WINDOWED, 60, 255,255,0 );
  bool quit = false;
  init_game(data);
  while( true ) {
    int events = catch_events( data );
    switch(events) {
      case -1:
        quit = true;
        break;
      case 1:
        //eg_cs("game loop running\n");
        game_loop(data);
        break;
    }
    if( quit ) {
      //printf( "quitting\n" );
      break;
    }
  }
  exit_op( data );
}

svg * main_svg;
vector svg_pos;

void init_game( operomnia_data * in_data ) {
  svg_pos = v(0,0);
  main_svg = load_svg( "World_V2.0.svg", STANDARD_SVG_RES );
  printf( "Svg dimensions: %f, %f\n", get_svg_dimensions(main_svg).x, get_svg_dimensions(main_svg).y );
}

void game_loop( operomnia_data * in_data ) {
  clear_color( default_clear_color );
  //combine_vector(&svg_pos,v(1,1));
  scale_svg( main_svg, add_vectors(get_svg_scale(main_svg), v(0.005,0.01) ) );
  draw_svg( main_svg, new_color(255,255,255), svg_pos, 1 );
  draw_all();
}
