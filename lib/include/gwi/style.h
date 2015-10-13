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
#ifndef GWI_STYLE_H
#define	GWI_STYLE_H

#ifdef	__cplusplus
extern "C" {
#endif

gwi_style *
gwi_color_fill(gwi_color *color);

gwi_style *
gwi_linear_gradient(int x, int y, int width, int height);

gwi_style *
gwi_radial_gradient(int sx, int sy, int sr, int ex, int ey, int er);

gwi_style *
gwi_pattern(gwi_image *img, int style);

void
gwi_gradient_add_color(gwi_style *style, float point, gwi_color *color);

#ifdef	__cplusplus
}
#endif

#endif	/* GWI_STYLE_H */

