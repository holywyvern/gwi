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
#include "private/handle.h"
#include "radixtree.h"

int 
gwi_set(gwi_handle *handle, const char *key, void *value)
{
 int result;
 gwi_event evt;
 evt.value.property_event.old_value = rt_tree_get(handle->properties, (const unsigned char *)key, strlen(key));
 result = rt_tree_set(handle->properties, (const unsigned char *)key, strlen(key), value);
 evt.value.property_event.name  = key;
 evt.value.property_event.new_value = value;
 if (result) gwi_fire(handle, "property.change", &evt);
 return result;
}

void * 
gwi_get(gwi_handle *handle, const char *key)
{
 return rt_tree_get(handle->properties, (const unsigned char *)key, strlen(key));
}

void
gwi_delete(gwi_handle *handle, const char *key)
{
  void *value;
  int r;
  gwi_event evt;
  value = gwi_get(handle, key);
  r = rt_tree_remove(handle->properties, (const unsigned char *)key, strlen(key));
  evt.value.property_event.name  = key;
  evt.value.property_event.new_value = value;  
  evt.value.property_event.old_value = value;  
  if (r) gwi_fire(handle, "property.delete", &evt);
}