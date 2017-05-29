/* louder-window.c
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

#include "louder-application.h"
#include "louder-window.h"
#include "louder-sidebar-row.h"
#include "louder-song-list-row.h"
#include "async-image-widget.h"


#ifndef M_PI
	#define M_PI   3.14159265358979323846264338327950288
#endif

struct _LouderWindow
{
  GtkApplicationWindow parent;
};

typedef struct
{
	GtkWidget		 *search;
	GtkWidget		 *gears;
	AsyncImageWidget *avatar;
	GtkWidget		 *menu_panel;
	GtkWidget		 *sidebar_menu;
	GSettings		 *settings;
} LouderWindowPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (LouderWindow, louder_window, GTK_TYPE_APPLICATION_WINDOW)

enum {
	PROP_0,
	N_PROPS
};

static GParamSpec *properties [N_PROPS];

LouderWindow *
louder_window_new (LouderApplication *app)
{
	return g_object_new (LOUDER_TYPE_WINDOW, "application", app,NULL);
}

static void
louder_window_finalize (GObject *object)
{
	LouderWindow *self = (LouderWindow *)object;
	LouderWindowPrivate *priv = louder_window_get_instance_private (self);

	G_OBJECT_CLASS (louder_window_parent_class)->finalize (object);
}

void AddListItem (GtkWidget *listbox)
{
    LouderSidebarRow *item;
		item = louder_sidebar_row_new();
    gtk_container_add (GTK_CONTAINER (listbox), GTK_WIDGET (item));

    /* --- Make it visible --- */
    gtk_widget_show (GTK_WIDGET (item));
}

static void
louder_window_get_property (GObject    *object,
														guint       prop_id,
														GValue     *value,
														GParamSpec *pspec)
{
	LouderWindow *self = LOUDER_WINDOW (object);

	switch (prop_id)
	  {
	  default:
	    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	  }
}

static void
louder_window_set_property (GObject      *object,
                            guint         prop_id,
                            const GValue *value,
                            GParamSpec   *pspec)
{
	LouderWindow *self = LOUDER_WINDOW (object);

	switch (prop_id)
	  {
	  default:
	    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	  }
}

static void
louder_window_dispose (GObject *object)
{
LouderWindow *win;
  LouderWindowPrivate *priv;

  win = LOUDER_WINDOW (object);
  priv = louder_window_get_instance_private (win);

  g_clear_object (&priv->settings);

  G_OBJECT_CLASS (louder_window_parent_class)->dispose (object);
}

static void
louder_window_class_init (LouderWindowClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);
	
	g_type_ensure (ASYNC_TYPE_IMAGE_WIDGET);
	gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (object_class),
												 "/org/vyasg/louder/ui/louder-window.ui");
	object_class->finalize = louder_window_finalize;
	object_class->get_property = louder_window_get_property;
	object_class->set_property = louder_window_set_property;
	gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (object_class), LouderWindow, search);
	gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (object_class), LouderWindow, gears);
	gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (object_class), LouderWindow, menu_panel);
	gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (object_class), LouderWindow, sidebar_menu);
	gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (object_class), LouderWindow, avatar);
	//gtk_widget_class_bind_template_callback (GTK_WIDGET_CLASS (object_class), search_text_changed);
}

void
louder_round_avatar (GtkWidget *widget, cairo_t *cr)
{
	GdkPixbuf *default_image = gdk_pixbuf_new_from_resource ("/org/vyasg/louder/ui/avatar.png",NULL);
	cairo_surface_t *surface = gdk_cairo_surface_create_from_pixbuf (default_image, 1, NULL);
	cairo_set_source_surface(cr, surface, 1, 1);
//	cairo_arc(cr, /*x*/ 100, /* y */ 100, /* radius */ 100, 0, 2*M_PI);
	g_debug ("%s","HASDASDASD");
//	cairo_clip(cr);
//	cairo_paint(cr);
}

static void
louder_window_init (LouderWindow *self)
{
	LouderWindowPrivate *priv;

  priv = louder_window_get_instance_private (self);
	gtk_widget_init_template (GTK_WIDGET (self));
  //priv->settings = g_settings_new ("org.vyasg.louder");

	AddListItem (priv->sidebar_menu);
	AddListItem (priv->sidebar_menu);
	async_image_widget_add_callback (priv->avatar, &louder_round_avatar);
	gtk_window_maximize (GTK_WINDOW (self));
	gtk_paned_set_position (GTK_PANED (priv->menu_panel), 300);
	gtk_widget_show_all (GTK_WIDGET (self));
}
