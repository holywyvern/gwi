/*
 * Copyright 2015 Ramiro Rojo
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef GWI_GRAPHICS_H
#define	GWI_GRAPHICS_H

#ifdef	__cplusplus
extern "C" {
#endif

#define GWI_REPEAT_BOTH 0
#define GWI_REPEAT_X    1
#define GWI_REPEAT_Y    2
#define GWI_NO_REPEAT   3    

#define GWI_BUTT   0   
#define GWI_BEVEL 0   
#define GWI_ROUND  1   
#define GWI_SQUARE 2   
#define GWI_MITER 2 
    
#define GWI_LEFT   0
#define GWI_CENTER 1    
#define GWI_RIGHT  2    
    
gwi_graphics *
gwi_get_graphics(gwi_handle *window);

void
gwi_graphics_set_fill_style(gwi_graphics *g, gwi_style *style);

gwi_style *
gwi_graphics_get_fill_style(gwi_graphics *g);

void
gwi_graphics_set_stroke_style(gwi_graphics *g, gwi_style *style);

gwi_style *
gwi_graphics_get_stroke_style(gwi_graphics *g);

void
gwi_graphics_set_shadow(gwi_graphics *g, gwi_shadow *shadow);

gwi_shadow *
gwi_graphics_get_shadow(gwi_graphics *g);

void
gwi_graphics_set_line(gwi_graphics *g, gwi_line *shadow);

gwi_line *
gwi_graphics_get_line(gwi_graphics *g);

void
gwi_graphics_set_font(gwi_graphics *g, gwi_font *font);

gwi_font *
gwi_graphics_get_font(gwi_graphics *g);

gwi_image *
gwi_graphics_to_image(gwi_graphics *src);

gwi_image *
gwi_graphics_area_to_image(gwi_graphics *src, gwi_rect *rect);

void
gwi_graphics_rect(gwi_graphics *g, gwi_rect *rect);

void
gwi_graphics_clear(gwi_graphics *g, gwi_rect *rect);

void
gwi_graphics_stroke(gwi_graphics *g);

void
gwi_graphics_fill(gwi_graphics *g);

void
gwi_graphics_begin_path(gwi_graphics *g);

void
gwi_graphics_close_path(gwi_graphics *g);

void
gwi_graphics_move(gwi_graphics *g, int x, int y);

void
gwi_graphics_line(gwi_graphics *g, int x, int y);

void
gwi_graphics_clip(gwi_graphics *g, int x, int y, int w, int h);

void
gwi_graphics_quadratic(gwi_graphics *g, int cpx, int cpy, int x, int y);

void
gwi_graphics_bezier(gwi_graphics *g, int cpx1, int cpy1, int cpx2, int cpy2, int x, int y);

void
gwi_graphics_arc(gwi_graphics *g, int x, int y, int r, int start_angle, int end_angle, int counter_clockwise);

void
gwi_graphics_arc_to(gwi_graphics *g, int x1, int y1, int x2, int y2, int r);

void
gwi_graphics_scale(gwi_graphics *g, float x, float y);

void
gwi_graphics_rotate(gwi_graphics *g, float angle);

void
gwi_graphics_translate(gwi_graphics *g, int x, int y);

void
gwi_graphics_set_align(gwi_graphics *g, int align);

int
gwi_graphics_get_align(gwi_graphics *g);

void
gwi_graphics_set_baseline(gwi_graphics *g, int baseline);

int
gwi_graphics_get_baseline(gwi_graphics *g);

void
gwi_graphics_text(gwi_graphics *g, const char *txt, int x, int y, int max_width);

void
gwi_graphics_img(gwi_graphics *g, gwi_image *img, gwi_rect *src, gwi_rect *dst);

void
gwi_graphics_get_pixel(gwi_graphics *g, int x, int y, gwi_color *result);

void
gwi_graphics_set_pixel(gwi_graphics *g, int x, int y, gwi_color *color);

void
gwi_graphics_set_width(gwi_graphics *g, int w);

int
gwi_graphics_get_width(gwi_graphics *g);

void
gwi_graphics_set_height(gwi_graphics *g, int h);

int
gwi_graphics_get_height(gwi_graphics *g);

void
gwi_graphics_save(gwi_graphics *g);

void
gwi_graphics_load(gwi_graphics *g);

#ifdef	__cplusplus
}
#endif

#endif	/* GWI_GRAPHICS_H */

