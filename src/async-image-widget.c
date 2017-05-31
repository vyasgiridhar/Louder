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

#ifndef M_PI
	#define M_PI   3.14159265358979323846264338327950288
#endif

struct _LouderAvatarWidget {
	GtkImage parent;
};

typedef struct
{
	gchar *url;
	int width;
	int height;

	cairo_surface_t *surface;

	SoupSession *session;
	GSList *callbacks;

} LouderAvatarWidgetPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (LouderAvatarWidget, louder_avatar_widget, GTK_TYPE_IMAGE)

enum {
	PROP_0,
	PROP_URL,
	N_PROPS
};

static GParamSpec *properties [N_PROPS];

LouderAvatarWidget*
louder_avatar_widget_new (gchar *url)
{
	return g_object_new (LOUDER_TYPE_AVATAR_WIDGET,
						 "url",
						 url,
						 NULL);
}

static void
louder_avatar_widget_finalize (GObject *object)
{
	LouderAvatarWidget *self = (LouderAvatarWidget *)object;
	LouderAvatarWidgetPrivate *priv = louder_avatar_widget_get_instance_private (self);
	cairo_surface_destroy (priv->surface);
	G_OBJECT_CLASS (louder_avatar_widget_parent_class)->finalize (object);
}

static void
louder_avatar_widget_get_property (GObject    *object,
                                 guint       prop_id,
                                 GValue     *value,
                                 GParamSpec *pspec)
{
	LouderAvatarWidget *self = LOUDER_AVATAR_WIDGET (object);
	LouderAvatarWidgetPrivate *priv = louder_avatar_widget_get_instance_private (self);

	switch (prop_id)
	  {
		case PROP_URL:
			g_value_set_string (value, priv->url);
			return;
		default:
			G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	  }
}

static void
louder_avatar_widget_set_property (GObject      *object,
                                 guint         prop_id,
                                 const GValue *value,
                                 GParamSpec   *pspec)
{
	LouderAvatarWidget *self = LOUDER_AVATAR_WIDGET (object);
	LouderAvatarWidgetPrivate *priv = louder_avatar_widget_get_instance_private (self);

	switch (prop_id)
	  {
		  case PROP_URL:
			  priv->url = g_strdup (g_value_get_string (value));
			  break;
		  default:
			  G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	  }
}

static gboolean
louder_avatar_widget_draw (GtkWidget *widget, cairo_t *cr)
{	
	LouderAvatarWidgetPrivate *priv = louder_avatar_widget_get_instance_private (LOUDER_AVATAR_WIDGET (widget));

	GdkPixbuf *default_image;
	cairo_surface_t *surface;
	default_image = gdk_pixbuf_new_from_resource ("/org/vyasg/louder/ui/andrew.png",NULL);
	surface = gdk_cairo_surface_create_from_pixbuf (default_image, 1, NULL);
	cairo_set_source_surface (cr, surface, 1, 1);
	cairo_arc(cr, /*x*/ 100, /* y */ 100, /* radius */ 100, 0, 2*M_PI);
	cairo_clip(cr);
	cairo_paint(cr);
	cairo_surface_destroy (surface);
	return FALSE;
}

static void
louder_avatar_widget_class_init (LouderAvatarWidgetClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);

	object_class->finalize = louder_avatar_widget_finalize;
	object_class->get_property = louder_avatar_widget_get_property;
	object_class->set_property = louder_avatar_widget_set_property;

	GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);
	widget_class->draw = louder_avatar_widget_draw;
}

static void
louder_avatar_widget_init (LouderAvatarWidget *self)
{
	LouderAvatarWidgetPrivate *priv = louder_avatar_widget_get_instance_private (self);
	priv->url = "";
	priv->height = priv->width = 200;
	priv->surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, priv->width, priv->height);
	gtk_image_set_from_surface (GTK_IMAGE (self), priv->surface);
	/*This sets the template size TODO: I need to change this to the proper way*/
//	gtk_image_set_from_resource (GTK_IMAGE (self), "/org/vyasg/louder/ui/avatar.png");
	priv->session = soup_session_new ();
	priv->callbacks = NULL;
}
