/* async-image-widget.c
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

#include "async-image-widget.h"

struct _AsyncImageWidget {
	GtkImage parent;
};

typedef struct
{
	gchar *url;
	
	cairo_surface_t *surface;

	SoupSession *session;
	
} AsyncImageWidgetPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (AsyncImageWidget, async_image_widget, GTK_TYPE_IMAGE)

enum {
	PROP_URL,
	N_PROPS
};

static GParamSpec *properties [N_PROPS];

AsyncImageWidget*
async_image_widget_new (gchar *url)
{
	return g_object_new (ASYNC_TYPE_IMAGE_WIDGET,
						 "url",
						 url,
						 NULL);
}

static void
async_image_widget_finalize (GObject *object)
{
	AsyncImageWidget *self = (AsyncImageWidget *)object;
	AsyncImageWidgetPrivate *priv = async_image_widget_get_instance_private (self);

	G_OBJECT_CLASS (async_image_widget_parent_class)->finalize (object);
}

static void
async_image_widget_get_property (GObject    *object,
                                 guint       prop_id,
                                 GValue     *value,
                                 GParamSpec *pspec)
{
	AsyncImageWidget *self = ASYNC_IMAGE_WIDGET (object);
	AsyncImageWidgetPrivate *priv = async_image_widget_get_instance_private (self);

	switch (prop_id)
	  {
		case PROP_URL:
			g_value_set_string (value, priv->url);
	  default:
	    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	  }
}

static void
async_image_widget_set_property (GObject      *object,
                                 guint         prop_id,
                                 const GValue *value,
                                 GParamSpec   *pspec)
{
	AsyncImageWidget *self = ASYNC_IMAGE_WIDGET (object);

	switch (prop_id)
	  {
	  default:
	    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	  }
}

static void
async_image_widget_class_init (AsyncImageWidgetClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);

	object_class->finalize = async_image_widget_finalize;
	object_class->get_property = async_image_widget_get_property;
	object_class->set_property = async_image_widget_set_property;
}

static void
async_image_widget_init (AsyncImageWidget *self)
{
}
