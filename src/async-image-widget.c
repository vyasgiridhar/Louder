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

struct _AsyncImageWidget {
	GtkImage parent;
};

typedef struct
{
	gint padding;
	
	gchar *url;

	cairo_surface_t *surface;

	SoupSession *session;
	GSList *callbacks;

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

gboolean
async_image_widget_add_callback (AsyncImageWidget *self, void (*transform)(GtkWidget*,cairo_t*))
{
	g_return_val_if_fail (ASYNC_IS_IMAGE_WIDGET (self), FALSE);

	AsyncImageWidgetPrivate *priv = async_image_widget_get_instance_private (self);

	priv->callbacks = g_slist_prepend (priv->callbacks,transform);

	return TRUE;
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
			return;
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
	AsyncImageWidgetPrivate *priv = async_image_widget_get_instance_private (self);
	
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
async_image_widget_draw (GtkWidget *widget, cairo_t *cr)
{	
/*	AsyncImageWidgetPrivate *priv = async_image_widget_get_instance_private (ASYNC_IMAGE_WIDGET (widget));
	GSList *iter;
	g_debug ("%d",g_slist_length (priv->callbacks));
	for (iter = priv->callbacks; iter != NULL; iter = iter->next)
	{
		void (*callback)(GtkWidget*,cairo_t*) = iter->data;
		(*callback) (widget,cr);
	}
*/
	GdkPixbuf *default_image = gdk_pixbuf_new_from_resource ("/org/vyasg/louder/ui/avatar.png",NULL);
	cairo_surface_t *surface = gdk_cairo_surface_create_from_pixbuf (default_image, 1, NULL);
	cairo_set_source_surface(cr, surface, 1, 1);
	cairo_arc(cr, /*x*/ 100, /* y */ 100, /* radius */ 100, 0, 2*M_PI);
	g_debug ("%s","HASDASDASD");
	cairo_clip(cr);
	cairo_paint(cr);
	return FALSE;
}
static void
async_image_widget_class_init (AsyncImageWidgetClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);

	object_class->finalize = async_image_widget_finalize;
	object_class->get_property = async_image_widget_get_property;
	object_class->set_property = async_image_widget_set_property;

	GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);
	widget_class->draw = async_image_widget_draw;
}

static void
async_image_widget_init (AsyncImageWidget *self)
{
	AsyncImageWidgetPrivate *priv = async_image_widget_get_instance_private (self);

	priv->url = "";
	priv->session = soup_session_new ();
	priv->callbacks = NULL;
	gtk_widget_show_all (GTK_WIDGET (self));
}
