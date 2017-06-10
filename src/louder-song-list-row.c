/* louder-song-list-row.c
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

#include "louder-song-list-row.h"
#include "louder-avatar-widget.h"

struct _LouderSongListRow
{
	GtkListBoxRow parent;
};

typedef struct
{
	GtkWidget          *song_art;
	GtkWidget          *play_button;
	GtkWidget          *song_artist;
	GtkWidget          *song_name;
	GtkWidget          *song_event;
	GtkWidget          *actions_revealer;
	
//SCSong             *song;
} LouderSongListRowPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (LouderSongListRow, louder_song_list_row, GTK_TYPE_LIST_BOX_ROW)

enum {
	PROP_0,
	N_PROPS
};

static GParamSpec *properties [N_PROPS];

LouderSongListRow *
louder_song_list_row_new (void)
{
	return g_object_new (LOUDER_TYPE_SONG_LIST_ROW, NULL);
}

static void
louder_song_list_row_finalize (GObject *object)
{
	LouderSongListRow *self = (LouderSongListRow *)object;
	LouderSongListRowPrivate *priv = louder_song_list_row_get_instance_private (self);

	G_OBJECT_CLASS (louder_song_list_row_parent_class)->finalize (object);
}

static void
louder_song_list_row_get_property (GObject    *object,
                                   guint       prop_id,
                                   GValue     *value,
                                   GParamSpec *pspec)
{
	LouderSongListRow *self = LOUDER_SONG_LIST_ROW (object);

	switch (prop_id)
	  {
	  default:
	    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	  }
}

static void
louder_song_list_row_set_property (GObject      *object,
                                   guint         prop_id,
                                   const GValue *value,
                                   GParamSpec   *pspec)
{
	LouderSongListRow *self = LOUDER_SONG_LIST_ROW (object);

	switch (prop_id)
	  {
	  default:
	    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	  }
}

static void
louder_song_list_row_class_init (LouderSongListRowClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);

	object_class->finalize = louder_song_list_row_finalize;
	object_class->get_property = louder_song_list_row_get_property;
	object_class->set_property = louder_song_list_row_set_property;

	GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

	gtk_widget_class_set_template_from_resource (widget_class, "org/vyasg/louder/ui/louder-song-list-row.ui");
	
}

static void
louder_song_list_row_init (LouderSongListRow *self)
{
	gtk_widget_init_template (GTK_WIDGET (self));
	gtk_widget_show_all (GTK_WIDGET (self));
}
