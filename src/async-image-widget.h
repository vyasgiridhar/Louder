/* async-image-widget.h
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

#ifndef LOUDER_AVATAR_WIDGET_H
#define LOUDER_AVATAR_WIDGET_H

#include <gtk/gtk.h>
#include <cairo.h>
#include <libsoup/soup.h>

G_BEGIN_DECLS

#define LOUDER_TYPE_AVATAR_WIDGET (louder_avatar_widget_get_type())

G_DECLARE_FINAL_TYPE (LouderAvatarWidget, louder_avatar_widget, LOUDER, AVATAR_WIDGET, GtkImage)

LouderAvatarWidget *louder_avatar_widget_new (gchar *url);

G_END_DECLS

#endif /* LOUDER_AVATAR_WIDGET_H */

