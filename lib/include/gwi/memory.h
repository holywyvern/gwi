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
#ifndef GWI_MEMORY_H
#define	GWI_MEMORY_H

#ifdef	__cplusplus
extern "C" {
#endif

void *
gwi_malloc(size_t size);

void *
gwi_realloc(void *ptr, size_t size);

void
gwi_free(void *ptr);

void
gwi_set_alloc_hook(void *ctx, gwi_alloc_fn fn);

#ifdef	__cplusplus
}
#endif

#endif	/* GWI_MEMORY_H */
