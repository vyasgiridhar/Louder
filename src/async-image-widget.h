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

#ifndef ASYNC_IMAGE_WIDGET_H
#define ASYNC_IMAGE_WIDGET_H

#include <gtk/gtk.h>
#include <cairo.h>
#include <libsoup/soup.h>

G_BEGIN_DECLS

#define ASYNC_TYPE_IMAGE_WIDGET (async_image_widget_get_type())

G_DECLARE_FINAL_TYPE (AsyncImageWidget, async_image_widget, ASYNC, IMAGE_WIDGET, GtkImage)

AsyncImageWidget *async_image_widget_new (gchar *url);

G_END_DECLS

#endif /* ASYNC_IMAGE_WIDGET_H */

