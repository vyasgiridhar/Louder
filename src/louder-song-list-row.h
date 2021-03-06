/* louder-song-list-row.h
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

#ifndef LOUDER_SONG_LIST_ROW_H
#define LOUDER_SONG_LIST_ROW_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define LOUDER_TYPE_SONG_LIST_ROW (louder_song_list_row_get_type())

G_DECLARE_FINAL_TYPE (LouderSongListRow, louder_song_list_row, LOUDER, SONG_LIST_ROW, GtkListBoxRow)

LouderSongListRow *louder_song_list_row_new (void);

G_END_DECLS

#endif /* LOUDER_SONG_LIST_ROW_H */

