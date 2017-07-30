/* sc-song.h
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

#ifndef SC_SONG_H
#define SC_SONG_H

#include <glib-object.h>

G_BEGIN_DECLS

#define SC_TYPE_SONG (sc_song_get_type())

G_DECLARE_FINAL_TYPE (ScSong, sc_song, SC, SONG, GObject)

ScSong *sc_song_new (void);

G_END_DECLS

#endif /* SC_SONG_H */

