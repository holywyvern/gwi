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
#include "private/handle.h"
#include "platform/win32/common.h"

#ifdef _WIN32
int
msg_base(gwi_handle *parent, const char *title, const char *caption, UINT type)
{
#ifdef _UNICODE
 LPTSTR t, c;
 int result;
#endif
 HANDLE hwnd = NULL;
 if (parent) hwnd = parent->hwnd;
#ifdef _UNICODE
 t = gwi_utf8_to_utf16(title);
 c = gwi_utf8_to_utf16(caption);
 result = MessageBox(hwnd, t, c, type);
 if (t)
  gwi_free(t);
 if (c)
  gwi_free(c);
 return result;
#else
 return MessageBox(hwnd, title, caption, type);
#endif  
}
#endif

void
gwi_msg(gwi_handle *parent, const char *title, const char *caption)
{
#ifdef _WIN32
 msg_base(parent, title, caption, MB_OK|MB_TASKMODAL);
#endif 
}

int
gwi_ask(gwi_handle *parent, const char *title, const char *caption)
{
 int result = 0;
#ifdef _WIN32
 result = msg_base(parent, title, caption, MB_YESNO|MB_ICONQUESTION|MB_TASKMODAL) == IDYES;
#endif  
 return result;
}

int
gwi_retry(gwi_handle *parent, const char *title, const char *caption)
{
 int result = 0;
#ifdef _WIN32
 result = msg_base(parent, title, caption, MB_RETRYCANCEL|MB_ICONQUESTION|MB_TASKMODAL) == IDRETRY;
#endif  
 return result;
}

void
gwi_error(gwi_handle *parent, const char *title, const char *caption)
{
#ifdef _WIN32
  msg_base(parent, title, caption, MB_OK|MB_ICONERROR|MB_TASKMODAL);
#endif  
}

void
gwi_info(gwi_handle *parent, const char *title, const char *caption)
{
#ifdef _WIN32
  msg_base(parent, title, caption, MB_OK|MB_ICONWARNING|MB_TASKMODAL);
#endif  
}

void
gwi_warning(gwi_handle *parent, const char *title, const char *caption)
{
#ifdef _WIN32
  msg_base(parent, title, caption, MB_OK|MB_ICONWARNING|MB_TASKMODAL);
#endif  
}

