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
#ifndef GWI_MESSAGES_H
#define	GWI_MESSAGES_H

#ifdef	__cplusplus
extern "C" {
#endif

void
gwi_msg(gwi_handle *parent, const char *title, const char *caption);

int
gwi_ask(gwi_handle *parent, const char *title, const char *caption);

int
gwi_retry(gwi_handle *parent, const char *title, const char *caption);

void
gwi_error(gwi_handle *parent, const char *title, const char *caption);

void
gwi_info(gwi_handle *parent, const char *title, const char *caption);

void
gwi_warning(gwi_handle *parent, const char *title, const char *caption);

#ifdef	__cplusplus
}
#endif

#endif	/* GWI_MESSAGES_H */

