/* sc-song.c
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

#include "sc-song.h"

struct _ScSong
{
    GObject parent_instance;
};

G_DEFINE_TYPE (ScSong, sc_song, G_TYPE_OBJECT)

enum {
    PROP_0,
    N_PROPS
};

static GParamSpec *properties [N_PROPS];

ScSong *
sc_song_new (void)
{
    return g_object_new (SC_TYPE_SONG, NULL);
}

static void
sc_song_finalize (GObject *object)
{
    ScSong *self = (ScSong *)object;

    G_OBJECT_CLASS (sc_song_parent_class)->finalize (object);
}

static void
sc_song_get_property (GObject    *object,
                      guint       prop_id,
                      GValue     *value,
                      GParamSpec *pspec)
{
    ScSong *self = SC_SONG (object);

    switch (prop_id)
      {
      default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      }
}

static void
sc_song_set_property (GObject      *object,
                      guint         prop_id,
                      const GValue *value,
                      GParamSpec   *pspec)
{
    ScSong *self = SC_SONG (object);

    switch (prop_id)
      {
      default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      }
}

static void
sc_song_class_init (ScSongClass *klass)
{
    GObjectClass *object_class = G_OBJECT_CLASS (klass);

    object_class->finalize = sc_song_finalize;
    object_class->get_property = sc_song_get_property;
    object_class->set_property = sc_song_set_property;
}

static void
sc_song_init (ScSong *self)
{
}
