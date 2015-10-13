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
#include "radixtree.h"
#include "private/handle.h"

static void
gwi_free_event(void *ptr)
{
 gwi_event *evt = ptr;
 gwi_free(evt);
};

#define gwi_fevt gwi_free_event
#define gwi_ma   gwi_malloc
#define gwi_rea  gwi_realloc
#define gwi_fr   gwi_free

#define rt_qget(t, name) \
  rt_tree_get(t, (const unsigned char *)name, strlen(name))

gwi_handle *
gwi_handle_base(void)
{
  gwi_handle *handle = gwi_malloc(sizeof *handle);
  handle->events = rt_tree_malloc(255, gwi_fevt, gwi_ma, gwi_rea, gwi_fr);
  if (!handle->events) {
    gwi_free(handle);
    return NULL;
  } 
  handle->properties = rt_tree_malloc(255, gwi_fevt, gwi_ma, gwi_rea, gwi_fr);
  if (!handle->properties) {
    gwi_free(handle->properties);
    gwi_free(handle);
    return NULL;
  } 
  return handle;
}

void
gwi_close(gwi_handle *handle)
{
 if (!handle) return;
 rt_tree_free(handle->events);
 rt_tree_free(handle->properties);
 gwi_free(handle);
}