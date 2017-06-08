/* louder-player-bar.c
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

#include "louder-player-bar.h"

struct _LouderPlayerBar
{
	GtkBox parent_instance;
};

typedef struct
{
	GtkWidget *album_art_button;
	GtkWidget *album_art_event_box;
	GtkWidget *previous_button;
	GtkWidget *previous_event_box;
	GtkWidget *play_pause_button;
	GtkWidget *play_pause_event_box;
	GtkWidget *next_button;
	GtkWidget *next_event_box;
	GtkWidget *repeat_button;
	GtkWidget *repeat_event_box;
	GtkWidget *scrobber;
	GtkWidget *album_art_popover;
	GtkWidget *album_art_big;

	gboolean playing;
} LouderPlayerBarPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (LouderPlayerBar, louder_player_bar, GTK_TYPE_BOX)

enum {
	PROP_0,
	N_PROPS
};

static GParamSpec *properties [N_PROPS];

LouderPlayerBar *
louder_player_bar_new (void)
{
	return g_object_new (LOUDER_TYPE_PLAYER_BAR, NULL);
}

static void
louder_player_bar_finalize (GObject *object)
{
	LouderPlayerBar *self = (LouderPlayerBar *)object;
	LouderPlayerBarPrivate *priv = louder_player_bar_get_instance_private (self);

	G_OBJECT_CLASS (louder_player_bar_parent_class)->finalize (object);
}

static void
louder_player_bar_get_property (GObject    *object,
                                guint       prop_id,
                                GValue     *value,
                                GParamSpec *pspec)
{
	LouderPlayerBar *self = LOUDER_PLAYER_BAR (object);

	switch (prop_id)
	{
		default:
			G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	}
}

static void
louder_player_bar_set_property (GObject      *object,
                                guint         prop_id,
                                const GValue *value,
                                GParamSpec   *pspec)
{
	LouderPlayerBar *self = LOUDER_PLAYER_BAR (object);

	switch (prop_id)
	{
		default:
			G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	}
}

static gboolean 
album_art_pressed_callback (GtkWidget			 *event_box,
														GdkEventButton *event,
														gpointer				data)
{
	LouderPlayerBar *self = data;
	LouderPlayerBarPrivate *priv = louder_player_bar_get_instance_private (self);

	gtk_image_set_from_resource (GTK_IMAGE (priv->album_art_big), "/org/vyasg/louder/ui/song_art.jpg");
	gtk_popover_popup (GTK_POPOVER (priv->album_art_popover));
	return TRUE;
}

static gboolean 
previous_pressed_callback (GtkWidget			*event_box,
													 GdkEventButton *event,
													 gpointer				 data)
{
	g_print ("Coordinates :%f , %f\n",event->x,event->y);
	return TRUE;
}

static gboolean 
play_pause_pressed_callback (GtkWidget			*event_box,
														 GdkEventButton *event,
														 gpointer				 data)
{
	LouderPlayerBar *self = data;
	LouderPlayerBarPrivate *priv = louder_player_bar_get_instance_private (self);
	
	if (priv->playing)
	{
		gtk_image_set_from_resource (GTK_IMAGE (priv->play_pause_button), "/org/vyasg/louder/ui/play.svg");
		priv->playing = FALSE;
	}
	else
	{
		gtk_image_set_from_resource (GTK_IMAGE (priv->play_pause_button), "/org/vyasg/louder/ui/pause.svg");
		priv->playing = TRUE;
	}
	return TRUE;
}

static gboolean 
next_pressed_callback (GtkWidget			*event_box,
											 GdkEventButton *event,
											 gpointer				 data)
{
	g_print ("Coordinates :%f , %f\n",event->x,event->y);
	return TRUE;
}

static gboolean 
repeat_pressed_callback (GtkWidget			*event_box,
											 GdkEventButton *event,
											 gpointer				 data)
{
	g_print ("Coordinates :%f , %f\n",event->x,event->y);
	return TRUE;
}

static void
louder_player_bar_class_init (LouderPlayerBarClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);

	GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

	gtk_widget_class_set_template_from_resource (widget_class, "/org/vyasg/louder/ui/louder-player-bar.ui");
	gtk_widget_class_bind_template_child_private (widget_class, LouderPlayerBar, album_art_button);
	gtk_widget_class_bind_template_child_private (widget_class, LouderPlayerBar, album_art_event_box);
	gtk_widget_class_bind_template_child_private (widget_class, LouderPlayerBar, previous_button);
	gtk_widget_class_bind_template_child_private (widget_class, LouderPlayerBar, previous_event_box);
	gtk_widget_class_bind_template_child_private (widget_class, LouderPlayerBar, play_pause_button);
	gtk_widget_class_bind_template_child_private (widget_class, LouderPlayerBar, play_pause_event_box);
	gtk_widget_class_bind_template_child_private (widget_class, LouderPlayerBar, next_button);
	gtk_widget_class_bind_template_child_private (widget_class, LouderPlayerBar, next_event_box);
	gtk_widget_class_bind_template_child_private (widget_class, LouderPlayerBar, repeat_button);
	gtk_widget_class_bind_template_child_private (widget_class, LouderPlayerBar, repeat_event_box);
	gtk_widget_class_bind_template_child_private (widget_class, LouderPlayerBar, scrobber);
	gtk_widget_class_bind_template_child_private (widget_class, LouderPlayerBar, album_art_popover);
	gtk_widget_class_bind_template_child_private (widget_class, LouderPlayerBar, album_art_big);

	object_class->finalize = louder_player_bar_finalize;
	object_class->get_property = louder_player_bar_get_property;
	object_class->set_property = louder_player_bar_set_property;
}

static void
louder_player_bar_init (LouderPlayerBar *self)
{
	LouderPlayerBarPrivate *priv = louder_player_bar_get_instance_private (self);
	GdkPixbuf *album_art;

	gtk_widget_init_template (GTK_WIDGET (self));
	gtk_widget_show_all (GTK_WIDGET (self));

	priv->playing = FALSE;

	album_art = gdk_pixbuf_new_from_resource ("/org/vyasg/louder/ui/song_art.jpg", NULL);
	album_art = gdk_pixbuf_scale_simple (album_art, 40, 40,	GDK_INTERP_BILINEAR);
	
	gtk_image_set_from_resource (GTK_IMAGE (priv->play_pause_button), "/org/vyasg/louder/ui/play.svg");
	gtk_image_set_from_resource (GTK_IMAGE (priv->previous_button), "/org/vyasg/louder/ui/previous.svg");
	gtk_image_set_from_resource (GTK_IMAGE (priv->next_button), "/org/vyasg/louder/ui/next.svg");
	gtk_image_set_from_resource (GTK_IMAGE (priv->repeat_button), "/org/vyasg/louder/ui/repeat-track-inactive.svg");
	gtk_image_set_from_pixbuf (GTK_IMAGE (priv->album_art_button), album_art);

	g_signal_connect (G_OBJECT (priv->album_art_event_box),
										"button_press_event",
										G_CALLBACK (album_art_pressed_callback),
										self);

	g_signal_connect (G_OBJECT (priv->previous_event_box),
										"button_press_event",
										G_CALLBACK (previous_pressed_callback),
										priv->previous_button);

	g_signal_connect (G_OBJECT (priv->play_pause_event_box),
										"button_press_event",
										G_CALLBACK (play_pause_pressed_callback),
										self);	

	g_signal_connect (G_OBJECT (priv->next_event_box),
										"button_press_event",
										G_CALLBACK (next_pressed_callback),
										priv->next_button);

	g_signal_connect (G_OBJECT (priv->repeat_event_box),
										"button_press_event",
										G_CALLBACK (previous_pressed_callback),
										priv->previous_button);
}
