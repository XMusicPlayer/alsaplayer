/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>


#include "gladesrc.h"
#include "support.h"

GtkWidget*
create_main_window (void)
{
  GtkWidget *main_window;
  GtkWidget *vbox25;
  GtkWidget *frame1;
  GtkWidget *main_box;
  GtkWidget *info_box;
  GtkWidget *pos_box;
  GtkWidget *pos_scale;
  GtkWidget *button_scale_box;
  GtkWidget *control_box;
  GtkWidget *button_box;
  GtkWidget *cd_button;
  GtkWidget *prev_button;
  GtkWidget *play_button;
  GtkWidget *stop_button;
  GtkWidget *next_button;
  GtkWidget *playlist_button;
  GtkWidget *audio_control_box;
  GtkWidget *hbox34;
  GtkWidget *hbox36;
  GtkWidget *reverse_button;
  GtkWidget *pause_button;
  GtkWidget *forward_button;
  GtkWidget *pitch_scale;
  GtkWidget *bal_vol_box;
  GtkWidget *hbox37;
  GtkWidget *balance_pic_frame;
  GtkWidget *bal_scale;
  GtkWidget *volume_box;
  GtkWidget *volume_frame;
  GtkWidget *volume_pix_frame;
  GtkWidget *vol_scale;

  main_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_object_set_data (G_OBJECT (main_window), "main_window", main_window);
// deprecated  gtk_widget_set_usize (main_window, 408, 98);
	gtk_widget_set_size_request(main_window, 408, -1); //set it bigger
  gtk_window_set_title (GTK_WINDOW (main_window), "AlsaPlayer");
//deprecated  gtk_window_set_policy (GTK_WINDOW (main_window), TRUE, TRUE, FALSE);
	gtk_window_set_resizable(GTK_WINDOW (main_window), FALSE);

  vbox25 = gtk_vbox_new (FALSE, 0);
  gtk_widget_ref (vbox25);
  g_object_set_data_full (G_OBJECT (main_window), "vbox25", vbox25,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (vbox25);
  gtk_container_add (GTK_CONTAINER (main_window), vbox25);

  frame1 = gtk_frame_new (NULL);
  gtk_widget_ref (frame1);
  g_object_set_data_full (G_OBJECT (main_window), "frame1", frame1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (frame1);
  gtk_box_pack_start (GTK_BOX (vbox25), frame1, TRUE, TRUE, 0);
  gtk_frame_set_shadow_type (GTK_FRAME (frame1), GTK_SHADOW_OUT);

  main_box = gtk_vbox_new (FALSE, 0);
  gtk_widget_ref (main_box);
  g_object_set_data_full (G_OBJECT (main_window), "main_box", main_box,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (main_box);
  gtk_container_add (GTK_CONTAINER (frame1), main_box);

  info_box = gtk_hbox_new (FALSE, 0);
  gtk_widget_ref (info_box);
  g_object_set_data_full (G_OBJECT (main_window), "info_box", info_box,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (info_box);
  gtk_box_pack_start (GTK_BOX (main_box), info_box, TRUE, TRUE, 0);

  pos_box = gtk_vbox_new (FALSE, 0);
  gtk_widget_ref (pos_box);
  g_object_set_data_full (G_OBJECT (main_window), "pos_box", pos_box,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (pos_box);
  gtk_box_pack_start (GTK_BOX (main_box), pos_box, FALSE, FALSE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (pos_box), 2);

  pos_scale = gtk_hscale_new (GTK_ADJUSTMENT (gtk_adjustment_new (0, 0, 0, 0, 0, 0)));
  gtk_widget_ref (pos_scale);
  g_object_set_data_full (G_OBJECT (main_window), "pos_scale", pos_scale,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (pos_scale);
  gtk_box_pack_start (GTK_BOX (pos_box), pos_scale, TRUE, TRUE, 0);
  gtk_scale_set_draw_value (GTK_SCALE (pos_scale), FALSE);

  button_scale_box = gtk_hbox_new (FALSE, 0);
  gtk_widget_ref (button_scale_box);
  g_object_set_data_full (G_OBJECT (main_window), "button_scale_box", button_scale_box,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (button_scale_box);
  gtk_box_pack_start (GTK_BOX (main_box), button_scale_box, FALSE, FALSE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (button_scale_box), 2);

  control_box = gtk_hbox_new (FALSE, 0);
  gtk_widget_ref (control_box);
  g_object_set_data_full (G_OBJECT (main_window), "control_box", control_box,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (control_box);
  gtk_box_pack_start (GTK_BOX (button_scale_box), control_box, FALSE, FALSE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (control_box), 2);

  button_box = gtk_hbox_new (FALSE, 0);
  gtk_widget_ref (button_box);
  g_object_set_data_full (G_OBJECT (main_window), "button_box", button_box,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (button_box);
  gtk_box_pack_start (GTK_BOX (control_box), button_box, FALSE, TRUE, 0);

  cd_button = gtk_button_new ();
  gtk_widget_ref (cd_button);
  g_object_set_data_full (G_OBJECT (main_window), "cd_button", cd_button,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (cd_button);
  gtk_box_pack_start (GTK_BOX (button_box), cd_button, FALSE, TRUE, 0);
gtk_widget_set_size_request (cd_button, 26, 24);

  prev_button = gtk_button_new ();
  gtk_widget_ref (prev_button);
  g_object_set_data_full (G_OBJECT (main_window), "prev_button", prev_button,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (prev_button);
  gtk_box_pack_start (GTK_BOX (button_box), prev_button, FALSE, TRUE, 0);
gtk_widget_set_size_request (prev_button, 26, 24);

  play_button = gtk_button_new ();
  gtk_widget_ref (play_button);
  g_object_set_data_full (G_OBJECT (main_window), "play_button", play_button,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (play_button);
  gtk_box_pack_start (GTK_BOX (button_box), play_button, FALSE, TRUE, 0);
gtk_widget_set_size_request (play_button, 26, 24);

  stop_button = gtk_button_new ();
  gtk_widget_ref (stop_button);
  g_object_set_data_full (G_OBJECT (main_window), "stop_button", stop_button,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (stop_button);
  gtk_box_pack_start (GTK_BOX (button_box), stop_button, FALSE, TRUE, 0);
gtk_widget_set_size_request (stop_button, 26, 24);

  next_button = gtk_button_new ();
  gtk_widget_ref (next_button);
  g_object_set_data_full (G_OBJECT (main_window), "next_button", next_button,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (next_button);
  gtk_box_pack_start (GTK_BOX (button_box), next_button, FALSE, TRUE, 0);
gtk_widget_set_size_request (next_button, 26, 24);

  playlist_button = gtk_button_new ();
  gtk_widget_ref (playlist_button);
  g_object_set_data_full (G_OBJECT (main_window), "playlist_button", playlist_button,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (playlist_button);
  gtk_box_pack_start (GTK_BOX (button_box), playlist_button, FALSE, TRUE, 0);
gtk_widget_set_size_request (playlist_button, 26, 24);

  audio_control_box = gtk_vbox_new (FALSE, 0);
  gtk_widget_ref (audio_control_box);
  g_object_set_data_full (G_OBJECT (main_window), "audio_control_box", audio_control_box,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (audio_control_box);
  gtk_box_pack_start (GTK_BOX (button_scale_box), audio_control_box, TRUE, TRUE, 0);

  hbox34 = gtk_hbox_new (FALSE, 0);
  gtk_widget_ref (hbox34);
  g_object_set_data_full (G_OBJECT (main_window), "hbox34", hbox34,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (hbox34);
  gtk_box_pack_start (GTK_BOX (audio_control_box), hbox34, FALSE, FALSE, 0);

  hbox36 = gtk_hbox_new (FALSE, 0);
  gtk_widget_ref (hbox36);
  g_object_set_data_full (G_OBJECT (main_window), "hbox36", hbox36,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (hbox36);
  gtk_box_pack_start (GTK_BOX (hbox34), hbox36, FALSE, FALSE, 0);

  reverse_button = gtk_button_new ();
  gtk_widget_ref (reverse_button);
  g_object_set_data_full (G_OBJECT (main_window), "reverse_button", reverse_button,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (reverse_button);
  gtk_box_pack_start (GTK_BOX (hbox36), reverse_button, TRUE, TRUE, 0);
gtk_widget_set_size_request (reverse_button, 22, 20);

  pause_button = gtk_button_new ();
  gtk_widget_ref (pause_button);
  g_object_set_data_full (G_OBJECT (main_window), "pause_button", pause_button,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (pause_button);
  gtk_box_pack_start (GTK_BOX (hbox36), pause_button, TRUE, TRUE, 0);
gtk_widget_set_size_request (pause_button, 22, 20);

  forward_button = gtk_button_new ();
  gtk_widget_ref (forward_button);
  g_object_set_data_full (G_OBJECT (main_window), "forward_button", forward_button,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (forward_button);
  gtk_box_pack_start (GTK_BOX (hbox36), forward_button, TRUE, TRUE, 0);
gtk_widget_set_size_request (forward_button, 22, 20);

  pitch_scale = gtk_hscale_new (GTK_ADJUSTMENT (gtk_adjustment_new (100, -400, 401, 1, 1, 1)));
  gtk_widget_ref (pitch_scale);
  g_object_set_data_full (G_OBJECT (main_window), "pitch_scale", pitch_scale,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (pitch_scale);
  gtk_box_pack_start (GTK_BOX (hbox34), pitch_scale, TRUE, TRUE, 0);
  gtk_scale_set_draw_value (GTK_SCALE (pitch_scale), FALSE);

  bal_vol_box = gtk_hbox_new (FALSE, 0);
  gtk_widget_ref (bal_vol_box);
  g_object_set_data_full (G_OBJECT (main_window), "bal_vol_box", bal_vol_box,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (bal_vol_box);
  gtk_box_pack_start (GTK_BOX (audio_control_box), bal_vol_box, TRUE, FALSE, 0);

  hbox37 = gtk_hbox_new (FALSE, 0);
  gtk_widget_ref (hbox37);
  g_object_set_data_full (G_OBJECT (main_window), "hbox37", hbox37,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (hbox37);
  gtk_box_pack_start (GTK_BOX (bal_vol_box), hbox37, TRUE, TRUE, 0);

  balance_pic_frame = gtk_vbox_new (FALSE, 0);
  gtk_widget_ref (balance_pic_frame);
  g_object_set_data_full (G_OBJECT (main_window), "balance_pic_frame", balance_pic_frame,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (balance_pic_frame);
  gtk_box_pack_start (GTK_BOX (hbox37), balance_pic_frame, FALSE, TRUE, 0);
gtk_widget_set_size_request (balance_pic_frame, 30, -1);

  bal_scale = gtk_hscale_new (GTK_ADJUSTMENT (gtk_adjustment_new (100, 0, 201, 1, 1, 1)));
  gtk_widget_ref (bal_scale);
  g_object_set_data_full (G_OBJECT (main_window), "bal_scale", bal_scale,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (bal_scale);
  gtk_box_pack_start (GTK_BOX (hbox37), bal_scale, TRUE, TRUE, 0);
  gtk_scale_set_draw_value (GTK_SCALE (bal_scale), FALSE);

  volume_box = gtk_hbox_new (FALSE, 0);
  gtk_widget_ref (volume_box);
  g_object_set_data_full (G_OBJECT (main_window), "volume_box", volume_box,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (volume_box);
  gtk_box_pack_start (GTK_BOX (bal_vol_box), volume_box, TRUE, TRUE, 0);

  volume_frame = gtk_hbox_new (FALSE, 0);
  gtk_widget_ref (volume_frame);
  g_object_set_data_full (G_OBJECT (main_window), "volume_frame", volume_frame,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (volume_frame);
  gtk_box_pack_start (GTK_BOX (volume_box), volume_frame, TRUE, TRUE, 0);

  volume_pix_frame = gtk_vbox_new (FALSE, 0);
  gtk_widget_ref (volume_pix_frame);
  g_object_set_data_full (G_OBJECT (main_window), "volume_pix_frame", volume_pix_frame,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (volume_pix_frame);
  gtk_box_pack_start (GTK_BOX (volume_frame), volume_pix_frame, FALSE, TRUE, 0);
gtk_widget_set_size_request (volume_pix_frame, 18, -1);

  vol_scale = gtk_hscale_new (GTK_ADJUSTMENT (gtk_adjustment_new (14, 0, 14, 1, 1, 1)));
  gtk_widget_ref (vol_scale);
  g_object_set_data_full (G_OBJECT (main_window), "vol_scale", vol_scale,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (vol_scale);
  gtk_box_pack_start (GTK_BOX (volume_frame), vol_scale, TRUE, TRUE, 0);
  gtk_scale_set_draw_value (GTK_SCALE (vol_scale), FALSE);

  return main_window;
}

GtkWidget*
create_playlist_window (void)
{
  GtkWidget *playlist_window;
  GtkWidget *vbox5;
  GtkWidget *hbox16;
  GtkWidget *scrolledwindow1;
  GtkListStore *playlist_model;
  GtkWidget *playlist;
  GtkWidget *vbox6;
  GtkWidget *add_button;
  GtkWidget *del_button;
  GtkWidget *close_button;
  GtkWidget *shuffle_button;
  GtkWidget *vbox24;
  GtkWidget *label101;
  GtkWidget *load_button;
  GtkWidget *save_button;
  GtkWidget *clear_button;
  GtkWidget *loop_button;
  GtkWidget *playlist_status;

  playlist_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_object_set_data (G_OBJECT (playlist_window), "playlist_window", playlist_window);
  gtk_window_set_default_size (GTK_WINDOW(playlist_window), 480, 390);
  gtk_window_set_title (GTK_WINDOW (playlist_window), "Queue");

  vbox5 = gtk_vbox_new (FALSE, 0);
  gtk_widget_ref (vbox5);
  g_object_set_data_full (G_OBJECT (playlist_window), "vbox5", vbox5,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (vbox5);
  gtk_container_add (GTK_CONTAINER (playlist_window), vbox5);

  hbox16 = gtk_hbox_new (FALSE, 0);
  gtk_widget_ref (hbox16);
  g_object_set_data_full (G_OBJECT (playlist_window), "hbox16", hbox16,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (hbox16);
  gtk_box_pack_start (GTK_BOX (vbox5), hbox16, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (hbox16), 8);

  scrolledwindow1 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_ref (scrolledwindow1);
  g_object_set_data_full (G_OBJECT (playlist_window), "scrolledwindow1", scrolledwindow1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (scrolledwindow1);
  gtk_box_pack_start (GTK_BOX (hbox16), scrolledwindow1, TRUE, TRUE, 0);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow1), GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);

	playlist_model = gtk_list_store_new(3, GDK_TYPE_PIXBUF, G_TYPE_STRING, G_TYPE_STRING);
 
  playlist = gtk_tree_view_new_with_model(GTK_TREE_MODEL(playlist_model));
  gtk_widget_ref (playlist);
  g_object_set_data_full (G_OBJECT (playlist_window), "playlist", playlist,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (playlist);
  gtk_container_add (GTK_CONTAINER (scrolledwindow1), playlist);

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	
	renderer = gtk_cell_renderer_pixbuf_new();
	column = gtk_tree_view_column_new_with_attributes("playing", renderer, "pixbuf", 0, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (playlist), column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("title", renderer, "text", 1, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (playlist), column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("time", renderer, "text", 2, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (playlist), column);
	
	gtk_tree_selection_set_mode(gtk_tree_view_get_selection(GTK_TREE_VIEW(playlist)), GTK_SELECTION_MULTIPLE);
	gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(playlist), FALSE);

  vbox6 = gtk_vbox_new (FALSE, 6);
  gtk_widget_ref (vbox6);
  g_object_set_data_full (G_OBJECT (playlist_window), "vbox6", vbox6,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (vbox6);
  gtk_box_pack_start (GTK_BOX (hbox16), vbox6, FALSE, TRUE, 6);

  add_button = gtk_button_new_from_stock (GTK_STOCK_ADD);
  gtk_widget_ref (add_button);
  g_object_set_data_full (G_OBJECT (playlist_window), "add_button", add_button,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (add_button);
  gtk_box_pack_start (GTK_BOX (vbox6), add_button, FALSE, TRUE, 0);
//my try  gtk_widget_set_usize (add_button, 70, 22);

  del_button = gtk_button_new_from_stock (GTK_STOCK_REMOVE);
  gtk_widget_ref (del_button);
  g_object_set_data_full (G_OBJECT (playlist_window), "del_button", del_button,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (del_button);
  gtk_box_pack_start (GTK_BOX (vbox6), del_button, FALSE, TRUE, 0);
//my try  gtk_widget_set_usize (del_button, 70, -2);

  close_button = gtk_button_new_from_stock(GTK_STOCK_CLOSE);
  gtk_widget_ref (close_button);
  g_object_set_data_full (G_OBJECT (playlist_window), "close_button", close_button,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (close_button);
  gtk_box_pack_end (GTK_BOX (vbox6), close_button, FALSE, TRUE, 0);

  shuffle_button = gtk_button_new_with_label ("Shuffle");
  gtk_widget_ref (shuffle_button);
  g_object_set_data_full (G_OBJECT (playlist_window), "shuffle_button", shuffle_button,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (shuffle_button);
  gtk_box_pack_start (GTK_BOX (vbox6), shuffle_button, FALSE, FALSE, 0);

  vbox24 = gtk_vbox_new (FALSE, 0);
  gtk_widget_ref (vbox24);
  g_object_set_data_full (G_OBJECT (playlist_window), "vbox24", vbox24,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (vbox24);
  gtk_box_pack_start (GTK_BOX (vbox6), vbox24, FALSE, TRUE, 18);

  label101 = gtk_label_new ("PLAYLIST");
  gtk_widget_ref (label101);
  g_object_set_data_full (G_OBJECT (playlist_window), "label101", label101,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (label101);
  gtk_box_pack_start (GTK_BOX (vbox24), label101, FALSE, FALSE, 4);

  load_button = gtk_button_new_from_stock (GTK_STOCK_OPEN);
  gtk_widget_ref (load_button);
  g_object_set_data_full (G_OBJECT (playlist_window), "load_button", load_button,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (load_button);
  gtk_box_pack_start (GTK_BOX (vbox24), load_button, FALSE, FALSE, 0);

  save_button = gtk_button_new_from_stock (GTK_STOCK_SAVE);
  gtk_widget_ref (save_button);
  g_object_set_data_full (G_OBJECT (playlist_window), "save_button", save_button,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (save_button);
  gtk_box_pack_start (GTK_BOX (vbox24), save_button, FALSE, FALSE, 6);

  clear_button = gtk_button_new_from_stock (GTK_STOCK_CLEAR);
  gtk_widget_ref (clear_button);
  g_object_set_data_full (G_OBJECT (playlist_window), "clear_button", clear_button,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (clear_button);
  gtk_box_pack_start (GTK_BOX (vbox24), clear_button, FALSE, FALSE, 0);
//my try  gtk_widget_set_usize (clear_button, 70, -2);

  loop_button = gtk_button_new_with_label ("Loop");
  gtk_widget_ref (loop_button);
  gtk_object_set_data_full (GTK_OBJECT (playlist_window), "loop_button", loop_button,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (loop_button);
  gtk_box_pack_start (GTK_BOX (vbox6), loop_button, FALSE, FALSE, 0);

  playlist_status = gtk_vbox_new (FALSE, 0);
  gtk_widget_ref (playlist_status);
  g_object_set_data_full (G_OBJECT (playlist_window), "playlist_status", playlist_status,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (playlist_status);
  gtk_box_pack_start (GTK_BOX (vbox5), playlist_status, FALSE, TRUE, 4);

  return playlist_window;
}

GtkWidget*
create_playlist_load (void)
{
  GtkWidget *playlist_load;
  GtkWidget *ok_button1;
  GtkWidget *cancel_button1;

  playlist_load = gtk_file_selection_new ("Load Playlist");
  g_object_set_data (G_OBJECT (playlist_load), "playlist_load", playlist_load);
  gtk_container_set_border_width (GTK_CONTAINER (playlist_load), 10);

  ok_button1 = GTK_FILE_SELECTION (playlist_load)->ok_button;
  g_object_set_data (G_OBJECT (playlist_load), "ok_button1", ok_button1);
  gtk_widget_show (ok_button1);
  GTK_WIDGET_SET_FLAGS (ok_button1, GTK_CAN_DEFAULT);

  cancel_button1 = GTK_FILE_SELECTION (playlist_load)->cancel_button;
  g_object_set_data (G_OBJECT (playlist_load), "cancel_button1", cancel_button1);
  gtk_widget_show (cancel_button1);
  GTK_WIDGET_SET_FLAGS (cancel_button1, GTK_CAN_DEFAULT);

  return playlist_load;
}

GtkWidget*
create_playlist_save (void)
{
  GtkWidget *playlist_save;
  GtkWidget *ok_button2;
  GtkWidget *cancel_button2;

  playlist_save = gtk_file_selection_new ("Save Playlist");
  g_object_set_data (G_OBJECT (playlist_save), "playlist_save", playlist_save);
  gtk_container_set_border_width (GTK_CONTAINER (playlist_save), 10);

  ok_button2 = GTK_FILE_SELECTION (playlist_save)->ok_button;
  g_object_set_data (G_OBJECT (playlist_save), "ok_button2", ok_button2);
  gtk_widget_show (ok_button2);
  GTK_WIDGET_SET_FLAGS (ok_button2, GTK_CAN_DEFAULT);

  cancel_button2 = GTK_FILE_SELECTION (playlist_save)->cancel_button;
  g_object_set_data (G_OBJECT (playlist_save), "cancel_button2", cancel_button2);
  gtk_widget_show (cancel_button2);
  GTK_WIDGET_SET_FLAGS (cancel_button2, GTK_CAN_DEFAULT);

  return playlist_save;
}

GtkWidget*
create_effects_window (void)
{
  GtkWidget *effects_window;
  GtkWidget *vbox23;
  GtkWidget *hbox31;
  GtkWidget *plugin_list_box;
  GtkWidget *effects_list;
  GtkWidget *label16;
  GtkWidget *label17;
  GtkWidget *parameter_box;
  GtkWidget *button_box;
  GtkWidget *ok_button;

  effects_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_object_set_data (G_OBJECT (effects_window), "effects_window", effects_window);
  gtk_window_set_default_size (GTK_WINDOW(effects_window), 500, 300);
  gtk_window_set_title (GTK_WINDOW (effects_window), "Effects");

  vbox23 = gtk_vbox_new (FALSE, 0);
  gtk_widget_ref (vbox23);
  g_object_set_data_full (G_OBJECT (effects_window), "vbox23", vbox23,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (vbox23);
  gtk_container_add (GTK_CONTAINER (effects_window), vbox23);

  hbox31 = gtk_hbox_new (FALSE, 0);
  gtk_widget_ref (hbox31);
  g_object_set_data_full (G_OBJECT (effects_window), "hbox31", hbox31,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (hbox31);
  gtk_box_pack_start (GTK_BOX (vbox23), hbox31, TRUE, TRUE, 0);

  plugin_list_box = gtk_vbox_new (FALSE, 0);
  gtk_widget_ref (plugin_list_box);
  g_object_set_data_full (G_OBJECT (effects_window), "plugin_list_box", plugin_list_box,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (plugin_list_box);
  gtk_box_pack_start (GTK_BOX (hbox31), plugin_list_box, FALSE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (plugin_list_box), 8);

  effects_list = gtk_ctree_new (2, 0);
  gtk_widget_ref (effects_list);
  g_object_set_data_full (G_OBJECT (effects_window), "effects_list", effects_list,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (effects_list);
  gtk_box_pack_start (GTK_BOX (plugin_list_box), effects_list, TRUE, TRUE, 0);
  gtk_clist_set_column_width (GTK_CLIST (effects_list), 0, 80);
  gtk_clist_set_column_width (GTK_CLIST (effects_list), 1, 80);
  gtk_clist_column_titles_hide (GTK_CLIST (effects_list));

  label16 = gtk_label_new ("label16");
  gtk_widget_ref (label16);
  g_object_set_data_full (G_OBJECT (effects_window), "label16", label16,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (label16);
  gtk_clist_set_column_widget (GTK_CLIST (effects_list), 0, label16);

  label17 = gtk_label_new ("label17");
  gtk_widget_ref (label17);
  g_object_set_data_full (G_OBJECT (effects_window), "label17", label17,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (label17);
  gtk_clist_set_column_widget (GTK_CLIST (effects_list), 1, label17);

  parameter_box = gtk_vbox_new (FALSE, 0);
  gtk_widget_ref (parameter_box);
  g_object_set_data_full (G_OBJECT (effects_window), "parameter_box", parameter_box,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (parameter_box);
  gtk_box_pack_start (GTK_BOX (hbox31), parameter_box, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (parameter_box), 8);

  button_box = gtk_hbox_new (FALSE, 0);
  gtk_widget_ref (button_box);
  g_object_set_data_full (G_OBJECT (effects_window), "button_box", button_box,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (button_box);
  gtk_box_pack_start (GTK_BOX (vbox23), button_box, FALSE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (button_box), 8);

  ok_button = gtk_button_new_with_label ("OK");
  gtk_widget_ref (ok_button);
  g_object_set_data_full (G_OBJECT (effects_window), "ok_button", ok_button,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (ok_button);
  gtk_box_pack_end (GTK_BOX (button_box), ok_button, FALSE, TRUE, 0);
//my try  gtk_widget_set_usize (ok_button, 80, -2);

  return effects_window;
}

GtkWidget*
create_scopes_window (void)
{
  GtkWidget *scopes_window;
  GtkWidget *vbox22;
  GtkWidget *hbox38;
  GtkWidget *label18;
  GtkWidget *scopes_list_box;
  GtkWidget *scrolledwindow2;
  GtkWidget *scopes_list;
  GtkWidget *label14;
  GtkWidget *label15;
  GtkWidget *hbox32;
  GtkWidget *ok_button;

  scopes_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_object_set_data (G_OBJECT (scopes_window), "scopes_window", scopes_window);
  gtk_window_set_default_size (GTK_WINDOW(scopes_window), 200, 300);
  gtk_window_set_title (GTK_WINDOW (scopes_window), "Scopes");

  vbox22 = gtk_vbox_new (FALSE, 0);
  gtk_widget_ref (vbox22);
  g_object_set_data_full (G_OBJECT (scopes_window), "vbox22", vbox22,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (vbox22);
  gtk_container_add (GTK_CONTAINER (scopes_window), vbox22);

  hbox38 = gtk_hbox_new (FALSE, 0);
  gtk_widget_ref (hbox38);
  g_object_set_data_full (G_OBJECT (scopes_window), "hbox38", hbox38,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (hbox38);
  gtk_box_pack_start (GTK_BOX (vbox22), hbox38, FALSE, TRUE, 5);

  label18 = gtk_label_new ("Double click to activate");
  gtk_widget_ref (label18);
  g_object_set_data_full (G_OBJECT (scopes_window), "label18", label18,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (label18);
  gtk_box_pack_start (GTK_BOX (hbox38), label18, FALSE, FALSE, 10);

  scopes_list_box = gtk_hbox_new (FALSE, 0);
  gtk_widget_ref (scopes_list_box);
  g_object_set_data_full (G_OBJECT (scopes_window), "scopes_list_box", scopes_list_box,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (scopes_list_box);
  gtk_box_pack_start (GTK_BOX (vbox22), scopes_list_box, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (scopes_list_box), 8);

  scrolledwindow2 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_ref (scrolledwindow2);
  g_object_set_data_full (G_OBJECT (scopes_window), "scrolledwindow2", scrolledwindow2,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (scrolledwindow2);
  gtk_box_pack_start (GTK_BOX (scopes_list_box), scrolledwindow2, TRUE, TRUE, 0);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow2), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

  scopes_list = gtk_clist_new (2);
  gtk_widget_ref (scopes_list);
  g_object_set_data_full (G_OBJECT (scopes_window), "scopes_list", scopes_list,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (scopes_list);
  gtk_container_add (GTK_CONTAINER (scrolledwindow2), scopes_list);
//my try  gtk_widget_set_usize (scopes_list, 150, 220);
  gtk_clist_set_column_width (GTK_CLIST (scopes_list), 0, 49);
  gtk_clist_set_column_width (GTK_CLIST (scopes_list), 1, 80);
  gtk_clist_column_titles_hide (GTK_CLIST (scopes_list));

  label14 = gtk_label_new ("label14");
  gtk_widget_ref (label14);
  g_object_set_data_full (G_OBJECT (scopes_window), "label14", label14,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (label14);
  gtk_clist_set_column_widget (GTK_CLIST (scopes_list), 0, label14);

  label15 = gtk_label_new ("label15");
  gtk_widget_ref (label15);
  g_object_set_data_full (G_OBJECT (scopes_window), "label15", label15,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (label15);
  gtk_clist_set_column_widget (GTK_CLIST (scopes_list), 1, label15);

  hbox32 = gtk_hbox_new (FALSE, 0);
  gtk_widget_ref (hbox32);
  g_object_set_data_full (G_OBJECT (scopes_window), "hbox32", hbox32,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (hbox32);
  gtk_box_pack_start (GTK_BOX (vbox22), hbox32, FALSE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (hbox32), 8);

  ok_button = gtk_button_new_with_label ("Close");
  gtk_widget_ref (ok_button);
  g_object_set_data_full (G_OBJECT (scopes_window), "ok_button", ok_button,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (ok_button);
  gtk_box_pack_end (GTK_BOX (hbox32), ok_button, FALSE, TRUE, 0);
//my try  gtk_widget_set_usize (ok_button, 80, -2);

  return scopes_window;
}

GtkWidget*
create_fileselection1 (void)
{
  GtkWidget *fileselection1;
  GtkWidget *ok_button3;
  GtkWidget *cancel_button3;

  fileselection1 = gtk_file_selection_new ("Select File");
  g_object_set_data (G_OBJECT (fileselection1), "fileselection1", fileselection1);
  gtk_container_set_border_width (GTK_CONTAINER (fileselection1), 10);

  ok_button3 = GTK_FILE_SELECTION (fileselection1)->ok_button;
  g_object_set_data (G_OBJECT (fileselection1), "ok_button3", ok_button3);
  gtk_widget_show (ok_button3);
  GTK_WIDGET_SET_FLAGS (ok_button3, GTK_CAN_DEFAULT);

  cancel_button3 = GTK_FILE_SELECTION (fileselection1)->cancel_button;
  g_object_set_data (G_OBJECT (fileselection1), "cancel_button3", cancel_button3);
  gtk_widget_show (cancel_button3);
  GTK_WIDGET_SET_FLAGS (cancel_button3, GTK_CAN_DEFAULT);

  return fileselection1;
}

