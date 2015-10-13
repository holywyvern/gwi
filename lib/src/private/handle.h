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
#ifndef GWI_HANDLE_H
#define	GWI_HANDLE_H

#include "radixtree.h"
#include <gwi/event.h>
#include "private/handle.h"
#ifdef _WIN32
#include <windows.h>
#endif

#ifdef	__cplusplus
extern "C" {
#endif

struct gwi_handle
{
  rt_tree *events;
  rt_tree *properties;
#ifdef _WIN32
  HANDLE hwnd;
#endif
};

struct gwi_event_container
{
 void        *ctx;
 gwi_event_fn fn;
};

gwi_handle *
gwi_handle_base(void);

static int
gwi_fire(gwi_handle *handle, const char *name, gwi_event *evt)
{
  struct gwi_event_container *c;
  c = rt_tree_get(handle->events, (const unsigned char *)name, strlen(name));
  if (!c)
   return 1;
  return c->fn(c->ctx, handle, evt);
}

#ifdef	__cplusplus
}
#endif

#endif	/* GWI_HANDLE_H */

