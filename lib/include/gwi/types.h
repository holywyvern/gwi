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
#ifndef GWI_TYPES_H
#define	GWI_TYPES_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct gwi_handle   gwi_handle;
typedef struct gwi_event    gwi_event;
typedef struct gwi_color    gwi_color;    
typedef struct gwi_graphics gwi_graphics;
typedef struct gwi_style    gwi_style;
typedef struct gwi_image    gwi_image;
typedef struct gwi_shadow   gwi_shadow;
typedef struct gwi_line     gwi_line;
typedef struct gwi_font     gwi_font;
typedef struct gwi_rect     gwi_rect;

typedef void * (*gwi_alloc_fn)(void *, void *, size_t);
typedef int (*gwi_event_fn)(void *, gwi_handle *, gwi_event *);

struct gwi_color
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
};

struct gwi_shadow
{
    gwi_color color;
    int       blur;
    int       offset_x;
    int       offset_y;
};

struct gwi_line
{
    char cap;
    char join;
    int width;
    int miter;
};

struct gwi_rect
{
    int x;
    int y;
    int width;
    int height;
};

#ifdef	__cplusplus
}
#endif

#endif	/* GWI_TYPES_H */

