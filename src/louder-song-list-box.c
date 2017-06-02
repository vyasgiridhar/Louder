/* louder-song-list-box.c
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

#include "louder-song-list-box.h"

struct _LouderSongListBox {

};

typedef struct
{

} LouderSongListBoxPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (LouderSongListBox, louder_song_list_box, GTK_TYPE_LIST_BOX)

enum {
	PROP_0,
	N_PROPS
};

static GParamSpec *properties [N_PROPS];

LouderSongListBox *
louder_song_list_box_new (void)
{
	return g_object_new (LOUDER_TYPE_SONG_LIST_BOX, NULL);
}

static void
louder_song_list_box_finalize (GObject *object)
{
	LouderSongListBox *self = (LouderSongListBox *)object;
	LouderSongListBoxPrivate *priv = louder_song_list_box_get_instance_private (self);

	G_OBJECT_CLASS (louder_song_list_box_parent_class)->finalize (object);
}

static void
louder_song_list_box_get_property (GObject    *object,
                                   guint       prop_id,
                                   GValue     *value,
                                   GParamSpec *pspec)
{
	LouderSongListBox *self = LOUDER_SONG_LIST_BOX (object);

	switch (prop_id)
	  {
	  default:
	    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	  }
}

static void
louder_song_list_box_set_property (GObject      *object,
                                   guint         prop_id,
                                   const GValue *value,
                                   GParamSpec   *pspec)
{
	LouderSongListBox *self = LOUDER_SONG_LIST_BOX (object);

	switch (prop_id)
	  {
	  default:
	    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	  }
}

static void
louder_song_list_add_place_holder ()
{
	GtkStack *place_holder = GTK_STACK (gtk_stack_new ());
	gtk_stack_set_transition_type (place_holder, GTK_STACK_TRANSITION_TYPE_CROSSFADE);
	GtkLabel *loading_label = GTK_LABEL (gtk_label_new ("Loading..."));
	gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (loading_label)), "dim-label");
	gtk_stack_add_named (place_holder, GTK_WIDGET (loading_label), "Spinner");
	GtkLabel *no_songs_label = GTK_LABEL (gtk_label_new ("No songs found..."));
	gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (no_songs_label)), "dim-label");
	gtk_label_set_line_wrap_mode (no_songs_label, PANGO_WRAP_WORD_CHAR);
	gtk_stack_add_named (place_holder, GTK_WIDGET (no_songs_label), "No-entries");
	
	GtkBox *error_box = GTK_BOX (gtk_box_new (GTK_ORIENTATION_VERTICAL, 12));
	GtkLabel *error_label = GTK_LABEL (gtk_label_new (""));
	gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (error_label)), "dim-label");
	gtk_label_set_selectable (error_label, TRUE);
	gtk_label_set_line_wrap (error_label, TRUE);
	GtkButton *retry_button = GTK_BUTTON (gtk_button_new_with_label ("Retry"));
	gtk_widget_set_halign (GTK_WIDGET (retry_button), GTK_ALIGN_START);
	
}

static void
louder_song_list_box_class_init (LouderSongListBoxClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);

	object_class->finalize = louder_song_list_box_finalize;
	object_class->get_property = louder_song_list_box_get_property;
	object_class->set_property = louder_song_list_box_set_property;
}

static void
louder_song_list_box_init (LouderSongListBox *self)
{
//	louder_song_list_add_place_holder();
}
