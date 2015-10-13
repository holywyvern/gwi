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
#include <gwi.h>
#include <gwi/event.h>
#include <string.h>
#include "radixtree.h"
#include "private/handle.h"

#define rt_qset(t, name, val) \
  rt_tree_set(t, (const unsigned char *)name, strlen(name), val)

#define rt_qget(t, name) \
  rt_tree_get(t, (const unsigned char *)name, strlen(name))

int
gwi_on(gwi_handle *handle, const char *name, void *ctx, gwi_event_fn fn)
{
 struct gwi_event_container *container;
 int result;
 container = gwi_malloc(sizeof *container);
 if (!container) return 0;
 container->ctx = ctx;
 container->fn = fn;
 result = rt_qset(handle->events, name, container);
 if (!result) 
  gwi_free(container);
 return result;
}

void
gwi_off(gwi_handle *handle, const char *name)
{
  rt_tree_remove(handle->events, name, strlen(name));
}

