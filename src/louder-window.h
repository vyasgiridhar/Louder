/* louder-window.h
 *
 * Copyright (C) 2017 Vyas Giridharan <vyasgiridhar27@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LOUDER_WINDOW_H
#define LOUDER_WINDOW_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define LOUDER_TYPE_WINDOW (louder_window_get_type())

G_DECLARE_FINAL_TYPE (LouderWindow, louder_window, LOUDER, WINDOW, GtkApplicationWindow)

LouderWindow *louder_window_new (LouderApplication *app);

G_END_DECLS

#endif /* LOUDER_WINDOW_H */

