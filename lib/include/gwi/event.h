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
#ifndef GWI_EVENT_H
#define	GWI_EVENT_H

#include <gwi.h>

#ifdef	__cplusplus
extern "C" {
#endif

struct gwi_property_event
{
    const char *name;
    void       *old_value;
    void       *new_value;
};
    
union gwi_event_value
{
    struct gwi_property_event property_event;
};
    
struct gwi_event
{
  union gwi_event_value value;
  const char *name;
};

int
gwi_on(gwi_handle *handle, const char *name, void *ctx, gwi_event_fn fn);

void
gwi_off(gwi_handle *handle, const char *name);

#ifdef	__cplusplus
}
#endif

#endif	/* GWI_EVENT_H */

