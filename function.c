/*****************************************************************************************************************
Cricket : Its fun												*
Copyright (C) 2016 Ashutosh Gajanan Gathe									*
License GPLv3+: GNU GPL version 3 of later <http://gnu.org/licenses/gpl.html>                                   *
This is free software , you are free to cahnge and redistribute it.						*
Thereis NO WARRANTY, to the extent permitted by the law.							*
Any changes will be helpful.											*
														*
													        * 															*                 															*
														* 														
******************************************************************************************************************/





#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "score.c"
#include "scoree.c"
#include "odistats.c"
static void team1_bat(GtkWidget *button, gpointer window) {
	int i, j;
	GtkWidget *window_m, *table, *team1l, *team2l, *card, *extras, *runnout;
	GtkWidget *player1, *player2, *player3, *player4, *player5, *player6, *player7, *player8, *player9, *player10, *player11;
	GtkWidget *bowler1, *bowler2, *bowler3, *bowler4, *bowler5;
	window_m = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window_m), GTK_WIN_POS_CENTER);
        //gtk_window_set_default_size(GTK_WINDOW(window_m),1920, 1080);
        gtk_window_set_title(GTK_WINDOW(window_m), "CRIC");
        gtk_container_set_border_width(GTK_CONTAINER(window_m), 10);
	typedef struct play {
		GtkWidget *player[11];
		GtkWidget *single[11];	
		GtkWidget *two[11];
		GtkWidget *three[11];
		GtkWidget *four[11];
		GtkWidget *six[11];
		GtkWidget *sum[11];
	}play;
	play pl[13];	
	
	player1 = gtk_label_new("player1");
	player2 = gtk_label_new("player2");
	player3 = gtk_label_new("player3");
	player4 = gtk_label_new("player4");
	player5 = gtk_label_new("player5");
	player6 = gtk_label_new("player6");
	player7 = gtk_label_new("player7");
	player8 = gtk_label_new("player8");
	player9 = gtk_label_new("player9");
	player10 = gtk_label_new("player10");
	player11 = gtk_label_new("player11");


	bowler1 = gtk_label_new("bowler1");
	bowler2 = gtk_label_new("bowler2");
	bowler3 = gtk_label_new("bowler3");
	bowler4 = gtk_label_new("bowler4");
	bowler5 = gtk_label_new("bowler5");
	
	extras = gtk_button_new_with_label("extras");
	team1l = gtk_label_new("TEAM 1 BAT");
	team2l = gtk_label_new("TEAM 2 BOWL");
	
	runnout = gtk_button_new_with_label("runout");
	card = gtk_button_new_with_label("Scorecard");


	GdkColor red = {0, 0xffff, 0x0000, 0x0000};
	GdkColor yellow = {0, 0xffff, 0xffff, 0x0000};

	table = gtk_table_new(25, 7, TRUE);
	i = 1;
	while(i <= 11) {
		pl[i].single[i] = gtk_button_new_with_label("one");
		pl[i].two[i] = gtk_button_new_with_label("two");
		pl[i].three[i] = gtk_button_new_with_label("three");
		pl[i].four[i] = gtk_button_new_with_label("four");
		pl[i].six[i] = gtk_button_new_with_label("six");
		pl[i].sum[i] = gtk_button_new_with_label("sum");
		i++;
	}

	i = 1;
	while(i <= 11) {
		gtk_widget_modify_bg((pl[i].sum[i]), GTK_STATE_NORMAL, &red);
		i++;
	}
	gtk_table_attach_defaults(GTK_TABLE(table), team1l, 0, 4, 0, 1);
	
	gtk_table_attach_defaults(GTK_TABLE(table), player1, 0, 1, 1, 2);
	gtk_table_attach_defaults(GTK_TABLE(table), player2, 0, 1, 2, 3);
	gtk_table_attach_defaults(GTK_TABLE(table), player3, 0, 1, 3, 4);
	gtk_table_attach_defaults(GTK_TABLE(table), player4, 0, 1, 4, 5);
	gtk_table_attach_defaults(GTK_TABLE(table), player5, 0, 1, 5, 6);
	gtk_table_attach_defaults(GTK_TABLE(table), player6, 0, 1, 6, 7);
	gtk_table_attach_defaults(GTK_TABLE(table), player7, 0, 1, 7 , 8);
	gtk_table_attach_defaults(GTK_TABLE(table), player8, 0, 1, 8, 9);
	gtk_table_attach_defaults(GTK_TABLE(table), player9, 0, 1, 9, 10);
	gtk_table_attach_defaults(GTK_TABLE(table), player10, 0, 1, 10, 11);
	gtk_table_attach_defaults(GTK_TABLE(table), player11, 0, 1, 11, 12);
	
	i = 1;
	while(i <= 11) {
		gtk_table_attach_defaults(GTK_TABLE(table), pl[i].single[i], 1 , 2,  i, i + 1);	
		gtk_table_attach_defaults(GTK_TABLE(table), pl[i].two[i], 2 , 3,  i, i + 1);
		gtk_table_attach_defaults(GTK_TABLE(table), pl[i].three[i], 3 , 4,  i, i + 1);
		gtk_table_attach_defaults(GTK_TABLE(table), pl[i].four[i], 4 , 5,  i, i + 1);
		gtk_table_attach_defaults(GTK_TABLE(table), pl[i].six[i], 5 , 6,  i, i + 1);
		gtk_table_attach_defaults(GTK_TABLE(table), pl[i].sum[i], 6 , 7,  i, i + 1);
		i++;
	}
	gtk_table_attach_defaults(GTK_TABLE(table), extras, 0, 1, 12, 13);
	gtk_table_attach_defaults(GTK_TABLE(table), team2l, 0, 4, 14, 15);
	gtk_table_attach_defaults(GTK_TABLE(table), runnout, 0, 1, 20, 21);
	gtk_table_attach_defaults(GTK_TABLE(table), card, 0, 1, 21, 22);


	g_signal_connect(card, "clicked", G_CALLBACK(card_as), window_m);
	gtk_widget_modify_bg(card, GTK_STATE_NORMAL, &yellow);

	g_signal_connect(pl[1].single[1], "clicked", G_CALLBACK(run_scored_so), window_m);
	g_signal_connect(pl[1].two[1], "clicked", G_CALLBACK(run_scored_st), window_m);
	g_signal_connect(pl[1].three[1], "clicked", G_CALLBACK(run_scored_sth), window_m);
	g_signal_connect(pl[1].four[1], "clicked", G_CALLBACK(run_scored_sf), window_m);
	g_signal_connect(pl[1].six[1], "clicked", G_CALLBACK(run_scored_ss), window_m);
	g_signal_connect(pl[1].sum[1], "clicked", G_CALLBACK(sum_scored_se), window_m);



	g_signal_connect(pl[2].single[2], "clicked", G_CALLBACK(run_scored_sao), window_m);
	g_signal_connect(pl[2].two[2], "clicked", G_CALLBACK(run_scored_sat), window_m);
	g_signal_connect(pl[2].three[2], "clicked", G_CALLBACK(run_scored_sath), window_m);
	g_signal_connect(pl[2].four[2], "clicked", G_CALLBACK(run_scored_saf), window_m);
	g_signal_connect(pl[2].six[2], "clicked", G_CALLBACK(run_scored_sas), window_m);
	g_signal_connect(pl[2].sum[2], "clicked", G_CALLBACK(sum_scored_sae), window_m);

	g_signal_connect(pl[3].single[3], "clicked", G_CALLBACK(run_scored_sbo), window_m);
	g_signal_connect(pl[3].two[3], "clicked", G_CALLBACK(run_scored_sbt), window_m);
	g_signal_connect(pl[3].three[3], "clicked", G_CALLBACK(run_scored_sbth), window_m);
	g_signal_connect(pl[3].four[3], "clicked", G_CALLBACK(run_scored_sbf), window_m);
	g_signal_connect(pl[3].six[3], "clicked", G_CALLBACK(run_scored_sbs), window_m);
	g_signal_connect(pl[3].sum[3], "clicked", G_CALLBACK(sum_scored_sbe), window_m);

	g_signal_connect(pl[4].single[4], "clicked", G_CALLBACK(run_scored_sco), window_m);
	g_signal_connect(pl[4].two[4], "clicked", G_CALLBACK(run_scored_sct), window_m);
	g_signal_connect(pl[4].three[4], "clicked", G_CALLBACK(run_scored_scth), window_m);
	g_signal_connect(pl[4].four[4], "clicked", G_CALLBACK(run_scored_scf), window_m);
	g_signal_connect(pl[4].six[4], "clicked", G_CALLBACK(run_scored_scs), window_m);
	g_signal_connect(pl[4].sum[4], "clicked", G_CALLBACK(sum_scored_sce), window_m);



	g_signal_connect(pl[5].single[5], "clicked", G_CALLBACK(run_scored_sdo), window_m);
	g_signal_connect(pl[5].two[5], "clicked", G_CALLBACK(run_scored_sdt), window_m);
	g_signal_connect(pl[5].three[5], "clicked", G_CALLBACK(run_scored_sdth), window_m);
	g_signal_connect(pl[5].four[5], "clicked", G_CALLBACK(run_scored_sdf), window_m);
	g_signal_connect(pl[5].six[5], "clicked", G_CALLBACK(run_scored_sds), window_m);
	g_signal_connect(pl[5].sum[5], "clicked", G_CALLBACK(sum_scored_sde), window_m);

	g_signal_connect(pl[6].single[6], "clicked", G_CALLBACK(run_scored_seo), window_m);
	g_signal_connect(pl[6].two[6], "clicked", G_CALLBACK(run_scored_set), window_m);
	g_signal_connect(pl[6].three[6], "clicked", G_CALLBACK(run_scored_seth), window_m);
	g_signal_connect(pl[6].four[6], "clicked", G_CALLBACK(run_scored_sef), window_m);
	g_signal_connect(pl[6].six[6], "clicked", G_CALLBACK(run_scored_ses), window_m);
	g_signal_connect(pl[6].sum[6], "clicked", G_CALLBACK(sum_scored_see), window_m);

	g_signal_connect(pl[7].single[7], "clicked", G_CALLBACK(run_scored_sfo), window_m);
	g_signal_connect(pl[7].two[7], "clicked", G_CALLBACK(run_scored_sft), window_m);
	g_signal_connect(pl[7].three[7], "clicked", G_CALLBACK(run_scored_sfth), window_m);
	g_signal_connect(pl[7].four[7], "clicked", G_CALLBACK(run_scored_sff), window_m);
	g_signal_connect(pl[7].six[7], "clicked", G_CALLBACK(run_scored_sfs), window_m);
	g_signal_connect(pl[7].sum[7], "clicked", G_CALLBACK(sum_scored_sfe), window_m);

	g_signal_connect(pl[8].single[8], "clicked", G_CALLBACK(run_scored_sgo), window_m);
	g_signal_connect(pl[8].two[8], "clicked", G_CALLBACK(run_scored_sgt), window_m);
	g_signal_connect(pl[8].three[8], "clicked", G_CALLBACK(run_scored_sgth), window_m);
	g_signal_connect(pl[8].four[8], "clicked", G_CALLBACK(run_scored_sgf), window_m);
	g_signal_connect(pl[8].six[8], "clicked", G_CALLBACK(run_scored_sgs), window_m);
	g_signal_connect(pl[8].sum[8], "clicked", G_CALLBACK(sum_scored_sge), window_m);

	g_signal_connect(pl[9].single[9], "clicked", G_CALLBACK(run_scored_sho), window_m);
	g_signal_connect(pl[9].two[9], "clicked", G_CALLBACK(run_scored_sht), window_m);
	g_signal_connect(pl[9].three[9], "clicked", G_CALLBACK(run_scored_shth), window_m);
	g_signal_connect(pl[9].four[9], "clicked", G_CALLBACK(run_scored_shf), window_m);
	g_signal_connect(pl[9].six[9], "clicked", G_CALLBACK(run_scored_shs), window_m);
	g_signal_connect(pl[9].sum[9], "clicked", G_CALLBACK(sum_scored_she), window_m);

	g_signal_connect(pl[10].single[10], "clicked", G_CALLBACK(run_scored_sio), window_m);
	g_signal_connect(pl[10].two[10], "clicked", G_CALLBACK(run_scored_sit), window_m);
	g_signal_connect(pl[10].three[10], "clicked", G_CALLBACK(run_scored_sith), window_m);
	g_signal_connect(pl[10].four[10], "clicked", G_CALLBACK(run_scored_sif), window_m);
	g_signal_connect(pl[10].six[10], "clicked", G_CALLBACK(run_scored_sis), window_m);
	g_signal_connect(pl[10].sum[10], "clicked", G_CALLBACK(sum_scored_sie), window_m);

	g_signal_connect(pl[11].single[11], "clicked", G_CALLBACK(run_scored_sjo), window_m);
	g_signal_connect(pl[11].two[11], "clicked", G_CALLBACK(run_scored_sjt), window_m);
	g_signal_connect(pl[11].three[11], "clicked", G_CALLBACK(run_scored_sjth), window_m);
	g_signal_connect(pl[11].four[11], "clicked", G_CALLBACK(run_scored_sjf), window_m);
	g_signal_connect(pl[11].six[11], "clicked", G_CALLBACK(run_scored_sjs), window_m);
	g_signal_connect(pl[11].sum[11], "clicked", G_CALLBACK(sum_scored_sje), window_m);

	
	
	
	
	GtkWidget  *extralabel, *label, *labela, *labelb, *labelc, *labeld, *rnout;
 	GtkWidget *wlabel, *wlabela, *wlabelb, *wlabelc, *wlabeld;
	
  	GtkWidget *overs[6];
  	GtkWidget *wickets[6];

	i = 1;
	while(i <= 5) {
		overs[i] = gtk_button_new_with_label("ov");
		wickets[i] = gtk_button_new_with_label("wic");
		i++;
	}
	
	extralabel = gtk_label_new("0");
	rnout = gtk_label_new("0");

	label = gtk_label_new("0");
	labela = gtk_label_new("0");
	labelb = gtk_label_new("0");
	labelc = gtk_label_new("0");
	labeld = gtk_label_new("0");

	wlabel = gtk_label_new("0");
	wlabela = gtk_label_new("0");
	wlabelb = gtk_label_new("0");
	wlabelc = gtk_label_new("0");
	wlabeld = gtk_label_new("0");

	
	
	i = 15;
	j = 1;
	while(i < 20 && j <= 5) {
		gtk_table_attach_defaults(GTK_TABLE(table), overs[j], 1, 2, i, i + 1);
		gtk_table_attach_defaults(GTK_TABLE(table), wickets[j], 3, 4, i, i + 1);
		i++;
		j++;
	}
	
	gtk_table_attach_defaults(GTK_TABLE(table), bowler1, 0, 1, 15, 16);
	gtk_table_attach_defaults(GTK_TABLE(table), bowler2, 0, 1, 16, 17);
	gtk_table_attach_defaults(GTK_TABLE(table), bowler3, 0, 1, 17, 18);
	gtk_table_attach_defaults(GTK_TABLE(table), bowler4, 0, 1, 18, 19);
	gtk_table_attach_defaults(GTK_TABLE(table), bowler5, 0, 1, 19, 20);

	gtk_table_attach_defaults(GTK_TABLE(table), extralabel, 1, 2, 12, 13);
	gtk_table_attach_defaults(GTK_TABLE(table), rnout, 1, 2, 20, 21);
	
	gtk_table_attach_defaults(GTK_TABLE(table), label, 2, 3, 15, 16);
	gtk_table_attach_defaults(GTK_TABLE(table), labela, 2, 3, 16, 17);
	gtk_table_attach_defaults(GTK_TABLE(table), labelb, 2, 3, 17, 18);
	gtk_table_attach_defaults(GTK_TABLE(table), labelc, 2, 3, 18, 19);
	gtk_table_attach_defaults(GTK_TABLE(table), labeld, 2, 3, 19, 20);

	gtk_table_attach_defaults(GTK_TABLE(table), wlabel, 4, 5, 15, 16);
	gtk_table_attach_defaults(GTK_TABLE(table), wlabela, 4, 5, 16, 17);
	gtk_table_attach_defaults(GTK_TABLE(table), wlabelb, 4, 5, 17, 18);
	gtk_table_attach_defaults(GTK_TABLE(table), wlabelc, 4, 5, 18, 19);
	gtk_table_attach_defaults(GTK_TABLE(table), wlabeld, 4, 5, 19, 20);

	g_signal_connect(overs[1], "clicked",G_CALLBACK(overs_clicked), label);
	g_signal_connect(overs[2], "clicked",G_CALLBACK(oversa_clicked), labela);
	g_signal_connect(overs[3], "clicked",G_CALLBACK(oversb_clicked), labelb);
	g_signal_connect(overs[4], "clicked",G_CALLBACK(oversc_clicked), labelc);
	g_signal_connect(overs[5], "clicked",G_CALLBACK(oversd_clicked), labeld);
	
	g_signal_connect(wickets[1], "clicked",G_CALLBACK(wickets_clicked), wlabel);
	g_signal_connect(wickets[2], "clicked",G_CALLBACK(wicketsa_clicked), wlabela);
	g_signal_connect(wickets[3], "clicked",G_CALLBACK(wicketsb_clicked), wlabelb);
	g_signal_connect(wickets[4], "clicked",G_CALLBACK(wicketsc_clicked), wlabelc);
	g_signal_connect(wickets[5], "clicked",G_CALLBACK(wicketsd_clicked), wlabeld);

	g_signal_connect(extras, "clicked", G_CALLBACK(extra_run), extralabel);
	g_signal_connect(runnout, "clicked", G_CALLBACK(run_out), rnout);
	

	gtk_container_add(GTK_CONTAINER(window_m), table);
	gtk_widget_show_all(window_m);
}


static void team2_bat(GtkWidget *button, gpointer window) {
	int i, j;
	GtkWidget *window_m, *table, *extrast, *team1l, *team2l, *cardt, *rnoutt;
	GtkWidget *player1, *player2, *player3, *player4, *player5, *player6, *player7, *player8, *player9, *player10, *player11;
	GtkWidget *bowler1, *bowler2, *bowler3, *bowler4, *bowler5;
	window_m = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window_m), GTK_WIN_POS_CENTER);
        //gtk_window_set_default_size(GTK_WINDOW(window_m),1920, 1080);
        gtk_window_set_title(GTK_WINDOW(window_m), "CRIC");
        gtk_container_set_border_width(GTK_CONTAINER(window_m), 10);
	typedef struct playt {
		GtkWidget *player[11];
		GtkWidget *single[11];	
		GtkWidget *two[11];
		GtkWidget *three[11];
		GtkWidget *four[11];
		GtkWidget *six[11];
		GtkWidget *sum[11];
	}playt;
	playt plt[13];	
	
	player1 = gtk_label_new("player1");
	player2 = gtk_label_new("player2");
	player3 = gtk_label_new("player3");
	player4 = gtk_label_new("player4");
	player5 = gtk_label_new("player5");
	player6 = gtk_label_new("player6");
	player7 = gtk_label_new("player7");
	player8 = gtk_label_new("player8");
	player9 = gtk_label_new("player9");
	player10 = gtk_label_new("player10");
	player11 = gtk_label_new("player11");

	bowler1 = gtk_label_new("bowler1");
	bowler2 = gtk_label_new("bowler2");
	bowler3 = gtk_label_new("bowler3");
	bowler4 = gtk_label_new("bowler4");
	bowler5 = gtk_label_new("bowler5");

	extrast = gtk_button_new_with_label("extras");
	team2l = gtk_label_new("TEAM 2 BAT");
	team1l = gtk_label_new("TEAM 1 BOWl");
	
	rnoutt= gtk_button_new_with_label("runout");
	cardt = gtk_button_new_with_label("Scorecard");
	
	GdkColor red = {0, 0xffff, 0x0000, 0x0000};
	GdkColor yellow = {0, 0xffff, 0xffff, 0x0000};
	
	
	
	
	table = gtk_table_new(25, 7, TRUE);
	 i = 1;
	while(i <= 11) {
		plt[i].single[i] = gtk_button_new_with_label("one");
		plt[i].two[i] = gtk_button_new_with_label("two");
		plt[i].three[i] = gtk_button_new_with_label("three");
		plt[i].four[i] = gtk_button_new_with_label("four");
		plt[i].six[i] = gtk_button_new_with_label("six");
		plt[i].sum[i] = gtk_button_new_with_label("sum");
		i++;
	}

	i = 1;
	while(i <= 11) {
		gtk_widget_modify_bg((plt[i].sum[i]), GTK_STATE_NORMAL, &red);
		i++;
	}
	gtk_table_attach_defaults(GTK_TABLE(table), team2l, 0, 4, 0, 1);

	gtk_table_attach_defaults(GTK_TABLE(table), player1, 0, 1, 1, 2);
	gtk_table_attach_defaults(GTK_TABLE(table), player2, 0, 1, 2, 3);
	gtk_table_attach_defaults(GTK_TABLE(table), player3, 0, 1, 3, 4);
	gtk_table_attach_defaults(GTK_TABLE(table), player4, 0, 1, 4, 5);
	gtk_table_attach_defaults(GTK_TABLE(table), player5, 0, 1, 5, 6);
	gtk_table_attach_defaults(GTK_TABLE(table), player6, 0, 1, 6, 7);
	gtk_table_attach_defaults(GTK_TABLE(table), player7, 0, 1, 7, 8);
	gtk_table_attach_defaults(GTK_TABLE(table), player8, 0, 1, 8, 9);
	gtk_table_attach_defaults(GTK_TABLE(table), player9, 0, 1, 9, 10);
	gtk_table_attach_defaults(GTK_TABLE(table), player10, 0, 1, 10, 11);
	gtk_table_attach_defaults(GTK_TABLE(table), player11, 0, 1, 11, 12);
	

	i = 1;
	while(i <= 11) {
		gtk_table_attach_defaults(GTK_TABLE(table), plt[i].single[i], 1 , 2,  i, i + 1);	
		gtk_table_attach_defaults(GTK_TABLE(table), plt[i].two[i], 2 , 3,  i, i + 1);
		gtk_table_attach_defaults(GTK_TABLE(table), plt[i].three[i], 3 , 4,  i, i + 1);
		gtk_table_attach_defaults(GTK_TABLE(table), plt[i].four[i], 4 , 5,  i, i + 1);
		gtk_table_attach_defaults(GTK_TABLE(table), plt[i].six[i], 5 , 6,  i, i + 1);
		gtk_table_attach_defaults(GTK_TABLE(table), plt[i].sum[i], 6 , 7,  i, i + 1);
		i++;
	}
	gtk_table_attach_defaults(GTK_TABLE(table), extrast, 0, 1, 12, 13 );
	gtk_table_attach_defaults(GTK_TABLE(table), team1l, 0, 4, 14, 15);
	gtk_table_attach_defaults(GTK_TABLE(table), rnoutt, 0, 1, 20, 21);
	gtk_table_attach_defaults(GTK_TABLE(table), cardt, 0, 1, 21, 22);

	g_signal_connect(cardt, "clicked", G_CALLBACK(cardt_as), window_m);
	gtk_widget_modify_bg(cardt, GTK_STATE_NORMAL, &yellow);

	g_signal_connect(plt[1].single[1], "clicked", G_CALLBACK(runt_scored_so), window_m);
	g_signal_connect(plt[1].two[1], "clicked", G_CALLBACK(runt_scored_st), window_m);
	g_signal_connect(plt[1].three[1], "clicked", G_CALLBACK(runt_scored_sth), window_m);
	g_signal_connect(plt[1].four[1], "clicked", G_CALLBACK(runt_scored_sf), window_m);
	g_signal_connect(plt[1].six[1], "clicked", G_CALLBACK(runt_scored_ss), window_m);
	g_signal_connect(plt[1].sum[1], "clicked", G_CALLBACK(sumt_scored_se), window_m);

	g_signal_connect(plt[2].single[2], "clicked", G_CALLBACK(runt_scored_sao), window_m);
	g_signal_connect(plt[2].two[2], "clicked", G_CALLBACK(runt_scored_sat), window_m);
	g_signal_connect(plt[2].three[2], "clicked", G_CALLBACK(runt_scored_sath), window_m);
	g_signal_connect(plt[2].four[2], "clicked", G_CALLBACK(runt_scored_saf), window_m);
	g_signal_connect(plt[2].six[2], "clicked", G_CALLBACK(runt_scored_sas), window_m);
	g_signal_connect(plt[2].sum[2], "clicked", G_CALLBACK(sumt_scored_sae), window_m);
	
	g_signal_connect(plt[3].single[3], "clicked", G_CALLBACK(runt_scored_sbo), window_m);
	g_signal_connect(plt[3].two[3], "clicked", G_CALLBACK(runt_scored_sbt), window_m);
	g_signal_connect(plt[3].three[3], "clicked", G_CALLBACK(runt_scored_sbth), window_m);
	g_signal_connect(plt[3].four[3], "clicked", G_CALLBACK(runt_scored_sbf), window_m);
	g_signal_connect(plt[3].six[3], "clicked", G_CALLBACK(runt_scored_sbs), window_m);
	g_signal_connect(plt[3].sum[3], "clicked", G_CALLBACK(sumt_scored_sbe), window_m);

	g_signal_connect(plt[4].single[4], "clicked", G_CALLBACK(runt_scored_sco), window_m);
	g_signal_connect(plt[4].two[4], "clicked", G_CALLBACK(runt_scored_sct), window_m);
	g_signal_connect(plt[4].three[4], "clicked", G_CALLBACK(runt_scored_scth), window_m);
	g_signal_connect(plt[4].four[4], "clicked", G_CALLBACK(runt_scored_scf), window_m);
	g_signal_connect(plt[4].six[4], "clicked", G_CALLBACK(runt_scored_scs), window_m);
	g_signal_connect(plt[4].sum[4], "clicked", G_CALLBACK(sumt_scored_sce), window_m);

	g_signal_connect(plt[5].single[5], "clicked", G_CALLBACK(runt_scored_sdo), window_m);
	g_signal_connect(plt[5].two[5], "clicked", G_CALLBACK(runt_scored_sdt), window_m);
	g_signal_connect(plt[5].three[5], "clicked", G_CALLBACK(runt_scored_sdth), window_m);
	g_signal_connect(plt[5].four[5], "clicked", G_CALLBACK(runt_scored_sdf), window_m);
	g_signal_connect(plt[5].six[5], "clicked", G_CALLBACK(runt_scored_sds), window_m);
	g_signal_connect(plt[5].sum[5], "clicked", G_CALLBACK(sumt_scored_sde), window_m);
	
	g_signal_connect(plt[6].single[6], "clicked", G_CALLBACK(runt_scored_seo), window_m);
	g_signal_connect(plt[6].two[6], "clicked", G_CALLBACK(runt_scored_set), window_m);
	g_signal_connect(plt[6].three[6], "clicked", G_CALLBACK(runt_scored_seth), window_m);
	g_signal_connect(plt[6].four[6], "clicked", G_CALLBACK(runt_scored_sef), window_m);
	g_signal_connect(plt[6].six[6], "clicked", G_CALLBACK(runt_scored_ses), window_m);
	g_signal_connect(plt[6].sum[6], "clicked", G_CALLBACK(sumt_scored_see), window_m);
	

	g_signal_connect(plt[7].single[7], "clicked", G_CALLBACK(runt_scored_sfo), window_m);
	g_signal_connect(plt[7].two[7], "clicked", G_CALLBACK(runt_scored_sft), window_m);
	g_signal_connect(plt[7].three[7], "clicked", G_CALLBACK(runt_scored_sfth), window_m);
	g_signal_connect(plt[7].four[7], "clicked", G_CALLBACK(runt_scored_sff), window_m);
	g_signal_connect(plt[7].six[7], "clicked", G_CALLBACK(runt_scored_sfs), window_m);
	g_signal_connect(plt[7].sum[7], "clicked", G_CALLBACK(sumt_scored_sfe), window_m);

	g_signal_connect(plt[8].single[8], "clicked", G_CALLBACK(runt_scored_sgo), window_m);
	g_signal_connect(plt[8].two[8], "clicked", G_CALLBACK(runt_scored_sgt), window_m);
	g_signal_connect(plt[8].three[8], "clicked", G_CALLBACK(runt_scored_sgth), window_m);
	g_signal_connect(plt[8].four[8], "clicked", G_CALLBACK(runt_scored_sgf), window_m);
	g_signal_connect(plt[8].six[8], "clicked", G_CALLBACK(runt_scored_sgs), window_m);
	g_signal_connect(plt[8].sum[8], "clicked", G_CALLBACK(sumt_scored_sge), window_m);

	g_signal_connect(plt[9].single[9], "clicked", G_CALLBACK(runt_scored_sho), window_m);
	g_signal_connect(plt[9].two[9], "clicked", G_CALLBACK(runt_scored_sht), window_m);
	g_signal_connect(plt[9].three[9], "clicked", G_CALLBACK(runt_scored_shth), window_m);
	g_signal_connect(plt[9].four[9], "clicked", G_CALLBACK(runt_scored_shf), window_m);
	g_signal_connect(plt[9].six[9], "clicked", G_CALLBACK(runt_scored_shs), window_m);
	g_signal_connect(plt[9].sum[9], "clicked", G_CALLBACK(sumt_scored_she), window_m);

	g_signal_connect(plt[10].single[10], "clicked", G_CALLBACK(runt_scored_sio), window_m);
	g_signal_connect(plt[10].two[10], "clicked", G_CALLBACK(runt_scored_sit), window_m);
	g_signal_connect(plt[10].three[10], "clicked", G_CALLBACK(runt_scored_sith), window_m);
	g_signal_connect(plt[10].four[10], "clicked", G_CALLBACK(runt_scored_sif), window_m);
	g_signal_connect(plt[10].six[10], "clicked", G_CALLBACK(runt_scored_sis), window_m);
	g_signal_connect(plt[10].sum[10], "clicked", G_CALLBACK(sumt_scored_sie), window_m);

	g_signal_connect(plt[11].single[11], "clicked", G_CALLBACK(runt_scored_sjo), window_m);
	g_signal_connect(plt[11].two[11], "clicked", G_CALLBACK(runt_scored_sjt), window_m);
	g_signal_connect(plt[11].three[11], "clicked", G_CALLBACK(runt_scored_sjth), window_m);
	g_signal_connect(plt[11].four[11], "clicked", G_CALLBACK(runt_scored_sjf), window_m);
	g_signal_connect(plt[11].six[11], "clicked", G_CALLBACK(runt_scored_sjs), window_m);
	g_signal_connect(plt[11].sum[11], "clicked", G_CALLBACK(sumt_scored_sje), window_m);
	
	GtkWidget  *extralabelt, *labelt, *labelat, *labelbt, *labelct, *labeldt, *runoutt;
 	GtkWidget *wlabelt, *wlabelat, *wlabelbt, *wlabelct, *wlabeldt;
	
  	GtkWidget *overst[6];
  	GtkWidget *wicketst[6];

	i = 1;
	while(i <= 5) {
		overst[i] = gtk_button_new_with_label("ov");
		wicketst[i] = gtk_button_new_with_label("wic");
		i++;
	}
	
	extralabelt = gtk_label_new("0");
	runoutt = gtk_label_new("0");

	labelt = gtk_label_new("0");
	labelat = gtk_label_new("0");
	labelbt = gtk_label_new("0");
	labelct = gtk_label_new("0");
	labeldt = gtk_label_new("0");

	wlabelt = gtk_label_new("0");
	wlabelat = gtk_label_new("0");
	wlabelbt = gtk_label_new("0");
	wlabelct = gtk_label_new("0");
	wlabeldt = gtk_label_new("0");

	
	
	i = 15;
	j = 1;
	while(i < 20 && j <= 5) {
		gtk_table_attach_defaults(GTK_TABLE(table), overst[j], 1, 2, i, i + 1);
		gtk_table_attach_defaults(GTK_TABLE(table), wicketst[j], 3, 4, i, i + 1);
		i++;
		j++;
	}
	
	gtk_table_attach_defaults(GTK_TABLE(table), bowler1, 0, 1, 15, 16);
	gtk_table_attach_defaults(GTK_TABLE(table), bowler2, 0, 1, 16, 17);
	gtk_table_attach_defaults(GTK_TABLE(table), bowler3, 0, 1, 17, 18);
	gtk_table_attach_defaults(GTK_TABLE(table), bowler4, 0, 1, 18, 19);
	gtk_table_attach_defaults(GTK_TABLE(table), bowler5, 0, 1, 19, 20);

	gtk_table_attach_defaults(GTK_TABLE(table), extralabelt, 1, 2, 12, 13);
	gtk_table_attach_defaults(GTK_TABLE(table), runoutt, 1, 2, 20, 21);
	
	gtk_table_attach_defaults(GTK_TABLE(table), labelt, 2, 3, 15, 16);
	gtk_table_attach_defaults(GTK_TABLE(table), labelat, 2, 3, 16, 17);
	gtk_table_attach_defaults(GTK_TABLE(table), labelbt, 2, 3, 17, 18);
	gtk_table_attach_defaults(GTK_TABLE(table), labelct, 2, 3, 18, 19);
	gtk_table_attach_defaults(GTK_TABLE(table), labeldt, 2, 3, 19, 20);

	gtk_table_attach_defaults(GTK_TABLE(table), wlabelt, 4, 5, 15, 16);
	gtk_table_attach_defaults(GTK_TABLE(table), wlabelat, 4, 5, 16, 17);
	gtk_table_attach_defaults(GTK_TABLE(table), wlabelbt, 4, 5, 17, 18);
	gtk_table_attach_defaults(GTK_TABLE(table), wlabelct, 4, 5, 18, 19);
	gtk_table_attach_defaults(GTK_TABLE(table), wlabeldt, 4, 5, 19, 20);

	g_signal_connect(overst[1], "clicked",G_CALLBACK(overst_clicked), labelt);
	g_signal_connect(overst[2], "clicked",G_CALLBACK(oversta_clicked), labelat);
	g_signal_connect(overst[3], "clicked",G_CALLBACK(overstb_clicked), labelbt);
	g_signal_connect(overst[4], "clicked",G_CALLBACK(overstc_clicked), labelct);
	g_signal_connect(overst[5], "clicked",G_CALLBACK(overstd_clicked), labeldt);
	
	g_signal_connect(wicketst[1], "clicked",G_CALLBACK(wicketst_clicked), wlabelt);
	g_signal_connect(wicketst[2], "clicked",G_CALLBACK(wicketsta_clicked), wlabelat);
	g_signal_connect(wicketst[3], "clicked",G_CALLBACK(wicketstb_clicked), wlabelbt);
	g_signal_connect(wicketst[4], "clicked",G_CALLBACK(wicketstc_clicked), wlabelct);
	g_signal_connect(wicketst[5], "clicked",G_CALLBACK(wicketstd_clicked), wlabeldt);

	g_signal_connect(extrast, "clicked", G_CALLBACK(extra_runt), extralabelt);
	g_signal_connect(rnoutt, "clicked", G_CALLBACK(runt_out), runoutt);
	
	gtk_container_add(GTK_CONTAINER(window_m), table);
	gtk_widget_show_all(window_m);
}
static void stats_nodi(GtkWidget *button, gpointer window) {
	GtkWidget *window_m, *bestbat, *bestbow, *boundaryhit, *table;
	window_m = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window_m), GTK_WIN_POS_CENTER);
        gtk_window_set_default_size(GTK_WINDOW(window_m),300, 300);
        gtk_window_set_title(GTK_WINDOW(window_m), "Statistics");
        gtk_container_set_border_width(GTK_CONTAINER(window_m), 10);

	bestbat = gtk_button_new_with_label("Bets Batsman");
	bestbow = gtk_button_new_with_label("Bets Bowler");
	boundaryhit = gtk_button_new_with_label("Max boundarie hit by");

	table = gtk_table_new(4, 4, TRUE);

	gtk_table_attach_defaults(GTK_TABLE(table), bestbat, 0, 1, 0, 1);
	gtk_table_attach_defaults(GTK_TABLE(table), bestbow, 0, 1, 1, 2);
	gtk_table_attach_defaults(GTK_TABLE(table), boundaryhit, 0, 1, 2, 3);

	g_signal_connect(bestbat, "clicked", G_CALLBACK(bestbat_nodi), window_m);
	g_signal_connect(bestbow, "clicked", G_CALLBACK(bestbow_nodi), window_m);
	g_signal_connect(boundaryhit, "clicked", G_CALLBACK(boundary_hit_nodi), window_m);
	
	gtk_container_add(GTK_CONTAINER(window_m), table);
	gtk_widget_show_all(window_m);
}

