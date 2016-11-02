
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

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int totalscorett3 = 0;
int totalscorett4 = 0;
typedef struct batt2 {
	char *name [11];
	int score[11];
	int six[11];
	float sr[11];
}batt2;
batt2 tt2[2];
typedef struct bowlt2 {
	char *name[11];
	int ov[11];
	int run[11];
	int wic[11];
	float eco[11];
}bowlt2;
bowlt2 blt2[2];

void startt2() {
	FILE *fp;
	fp = fopen("t20_2.txt", "r");
	int i, j;
	for(i = 1; i <= 4; i++) {
		tt2[0].name[i] = (char *) malloc((i + 1) *sizeof(int));	
		fscanf(fp, "%s %d %d %f", tt2[0].name[i], &tt2[0].score[i], &tt2[0].six[i], &tt2[0].sr[i]);		
	}
	for(j = 1; j <= 5; j++) {
		blt2[0].name[j] = (char *) malloc((i + 1) *sizeof(int));
		fscanf(fp, "%s %d %d %d %f", blt2[0].name[j], &blt2[0].ov[j], &blt2[0].run[j], &blt2[0].wic[j], &blt2[0].eco[j]);
	}
	for(j = 1; j <= 5; j++) {
		tt2[1].name[j] = (char *) malloc((i + 1) *sizeof(int));
		fscanf(fp, "%s %d %d %f", tt2[1].name[j], &tt2[1].score[j], &tt2[1].six[j], &tt2[1].sr[j]);
	}
	for(j = 1; j <= 6; j++) {
		blt2[1].name[j] = (char *) malloc((i + 1) *sizeof(int));
		fscanf(fp, "%s %d %d %d %f", blt2[1].name[j], &blt2[1].ov[j], &blt2[1].run[j], &blt2[1].wic[j], &blt2[1].eco[j]);
	}	
	fclose(fp);
}	

static void best_batsmantt2(GtkWidget *button, gpointer window) {
        int i, j, maxt1 =0, x, y;
        char str[10];
        startt2();
        for(i = 1, j = 2; i <= 4 && j <= 4; i++, j++) {
                if(tt2[0].score[i] > maxt1) {
                        maxt1 = tt2[0].score[i];
                        x = i;
                }
                if( maxt1 == tt2[0].score[j]) {
                                if(tt2[0].sr[j] > tt2[0].sr[i]) {
                                        x = j;
                                }

                                else {
                                      x = i;
                                }
                }


        }
        maxt1 = 0;
        for(i = 1, j = 2; i <= 5 && j <= 5; i++, j++) {
                if(tt2[1].score[i] > maxt1) {
                        maxt1 = tt2[1].score[i];
                        y = i;
                }
                if( maxt1 == tt2[1].score[j]) {
                                if(tt2[1].sr[j] > tt2[1].sr[i]) {
                                        y = j;
                                }

                                else {
                                        y = i;
                                }
                }
             }
        if(tt2[0].score[x] > tt2[1].score[y]) {
                strcpy(str, tt2[0].name[x]);
        }
        else {
                strcpy(str, tt2[1].name[y]);
        }
	GtkWidget *dialog;
  
	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", str);
	gtk_window_set_title(GTK_WINDOW(dialog), "Best batsman");
    	gtk_dialog_run(GTK_DIALOG(dialog));
    	gtk_widget_destroy(dialog);
}
 
static void best_bowlertt2(GtkWidget *button, gpointer window) {
	int i, j, maxt1 =0, x, y;
	char str[10];
	startt2();
	maxt1 = 0;
	for(i = 1, j = 2; i <= 5 && j <= 5; i++, j++) {
		if(blt2[0].wic[i] > maxt1) {
			maxt1 = blt2[0].wic[i];
			x = i;
		}
		if( maxt1 == blt2[0].wic[j]) {
				if(blt2[0].run[j] > blt2[0].run[i]) { 
					x = i;
				}	
				
				else {
					x = j;
				}
		}
		
	
	}
	maxt1 = 0;
	for(i = 1, j = 2; i <= 6 && j <= 6; i++, j++) {
		if(blt2[1].wic[i] > maxt1) {
			maxt1 = blt2[1].wic[i];
			y = i;
		}
		if( maxt1 == blt2[1].wic[j]) {
				if(blt2[1].run[j] > blt2[1].run[i]) { 
					y = i;
				}	
				
				else {
					y = j;
				}
		}
	}
	if(blt2[0].wic[x] > blt2[1].wic[y]) {
		strcpy(str, blt2[0].name[x]);
	}
	if(blt2[0].wic[x] == blt2[1].wic[y]) {
			if(blt2[0].run[x] > blt2[1].run[y]) {
				strcpy(str, blt2[1].name[y]);
			}
			else {
				strcpy(str, blt2[0].name[x]);
			}
				
	}
	if(blt2[0].wic[x] < blt2[1].wic[y]) {
		strcpy(str, blt2[1].name[y]);
	}			
	GtkWidget *dialog;
  
	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", str);
	gtk_window_set_title(GTK_WINDOW(dialog), "Best Bowler");
    	gtk_dialog_run(GTK_DIALOG(dialog));
    	gtk_widget_destroy(dialog);
}
 
static void boundary_hit_tt2(GtkWidget *button, gpointer window) {
	int i, j, maxt1 = 0, x, y;
	char bhit[10], bhit1[10];
	GtkWidget *window_m, *label, *label1, *vbox;
	window_m = gtk_window_new(GTK_WINDOW_TOPLEVEL);		        
	gtk_window_set_position(GTK_WINDOW(window_m), GTK_WIN_POS_CENTER);
        //gtk_window_set_default_size(GTK_WINDOW(window_m), 500, 500);
        gtk_window_set_title(GTK_WINDOW(window_m), "Boundaries hit");
        gtk_container_set_border_width(GTK_CONTAINER(window_m), 30);
	startt2();
	maxt1 = 0;
	for(i = 1, j = 2; i <= 4 && j <= 4; i++, j++) {
		if(tt2[0].six[i] > maxt1) {
			maxt1 = tt2[0].six[i];
			x = i;
		}
		if( maxt1 == tt2[0].six[j]) {
				if(tt2[0].score[i] > tt2[0].score[j]) {
					x = i;
				}
				else {
					x = j;
				}
						
		}		
	
	}

	maxt1 = 0;
	for(i = 1, j = 2; i <= 5 && j <= 5; i++, j++) {
		if(tt2[1].six[i] > maxt1) {
			maxt1 = tt2[1].six[i];
			y = i;
		}
		if( maxt1 == tt2[1].six[j]) {
				if(tt2[1].score[j] > tt2[1].score[i]) { 
					y = j;
				}	
				
				else {
					y = i;
				}
		}
	}	
	if(tt2[0].six[x] > tt2[1].six[y]) {
		strcpy(bhit, tt2[0].name[x]);
	} 
	if(tt2[0].six[x] < tt2[1].six[y]) {
		strcpy(bhit, tt2[1].name[y]);
	}
	if(tt2[0].six[x] == tt2[1].six[y]) {
		strcpy(bhit, tt2[0].name[x]);
		strcpy(bhit1, tt2[1].name[y]);
	}
	vbox = gtk_vbox_new(0, 0);
	label = gtk_label_new(bhit);
	label1 = gtk_label_new(bhit1);
	gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(vbox), label1, 0, 0, 0);
	gtk_container_add(GTK_CONTAINER(window_m), vbox);
	gtk_widget_show_all(window_m);	
} 

static void eco_bowlertt2(GtkWidget *button, gpointer window) {
	int i, j, x, y;
	char ecobowl[20];
	startt2();
	for(i = 1, j = 2; i <= 5 && j <= 5; i++, j++) {
		if(blt2[0].eco[i] < blt2[0].eco[j]) {
			x = i;
		}
		if( blt2[0].eco[i] == blt2[0].eco[j]) {
				if(bl[0].ov[i] > blt2[0].ov[j]) {
					x = i;
				}
				else {
					x = j;
				}			
		}		
	
	}
	for(i = 1, j = 2; i <= 6 && j <= 6; i++, j++) {
		if(blt2[1].eco[i] < blt2[1].eco[j]) {
			y = i;
		}
		if( blt2[1].eco[i] == blt2[1].eco[j]) {
				if(blt2[1].ov[i] > blt2[1].ov[j]) {
					y = i;
				}
				else {
					y = j;
				}
						
		}		
	}

	if(blt2[0].eco[x] > blt2[1].eco[y]) {
		strcpy(ecobowl, blt2[1].name[y]);
	}
	if(blt2[0].eco[x] == blt2[0].eco[y]) {
		if(blt2[0].ov[x] > blt2[0].ov[y]) {
			strcpy(ecobowl, blt2[0].name[x]);
		}
		else {
			strcpy(ecobowl, blt2[1].name[y]);
		}
	}
	if(blt2[0].eco[x] < blt2[1].eco[y]) {
		strcpy(ecobowl, blt2[0].name[x]);
	}
	GtkWidget *dialog;
  
	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", ecobowl);
	gtk_window_set_title(GTK_WINDOW(dialog), "Economic bowler");
    	gtk_dialog_run(GTK_DIALOG(dialog));
    	gtk_widget_destroy(dialog);
}

static void tt2_team1_score(GtkWidget *button, gpointer window) {
	GtkWidget *window_m, *label, *label1, *label2, *vbox, *totalscore, *totalwickets,*teamscore, *teamwickets;
	int wicketst1 = 0;
        char tscore[5], twickets[5];
        window_m = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(window_m), GTK_WIN_POS_CENTER);
        gtk_window_set_default_size(GTK_WINDOW(window_m),1000, 500);
        gtk_window_set_title(GTK_WINDOW(window), "TEAM 1");
        gtk_container_set_border_width(GTK_CONTAINER(window_m), 30);
        vbox = gtk_vbox_new(0, 0);
	startt2();

	char line [100];
	int i;
	FILE *fp;
	fp = fopen("t20_2.txt", "r");
	label1 = gtk_label_new("TEAM\n\nName\t\tScore\tSix\tStrikeRate\n");	
	gtk_box_pack_start(GTK_BOX(vbox), label1, 0, 0, 0);
	
	for(i = 1; i <= 4; i++) {
		fgets(line, sizeof line, fp);
		label = gtk_label_new(line);
		gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);
		totalscorett3= tt2[0].score[i] + totalscorett3;
	}
	totalscore = gtk_label_new("TotalScore = ");
	gtk_box_pack_start(GTK_BOX(vbox), totalscore, 0, 0, 0);
	sprintf(tscore, "%d", totalscorett3);
	teamscore = gtk_label_new(tscore);
	gtk_box_pack_start(GTK_BOX(vbox), teamscore, 0, 0, 0);

	label2 = gtk_label_new("Name\tOvers\tWickets\tEconomy");	
	gtk_box_pack_start(GTK_BOX(vbox), label2, 0, 0, 0);
	for(i = 1; i <= 5; i++) {
		fgets(line, sizeof line, fp);
		label = gtk_label_new(line);
		gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);
		wicketst1 = blt2[0].wic[i] + wicketst1;
	}
	totalwickets = gtk_label_new("Wickets = ");
	sprintf(twickets, "%d", wicketst1);
	teamwickets = gtk_label_new(twickets);
	gtk_box_pack_start(GTK_BOX(vbox), totalwickets, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(vbox), teamwickets, 0, 0, 0);

	fclose(fp);
	gtk_container_add(GTK_CONTAINER(window_m),vbox);
	gtk_widget_show_all(window_m);

}
static void tt2_team2_score(GtkWidget *button, gpointer window) {
	int i;
	int wicketst1 = 0;
	char tscore[5], twickets[5];
	GtkWidget *window_m, *label,*label1, *label2, *vbox, *totalscore, *totalwickets,*teamscore, *teamwickets;/*disply score on window*/
	window_m = gtk_window_new(GTK_WINDOW_TOPLEVEL);		        
	gtk_window_set_position(GTK_WINDOW(window_m), GTK_WIN_POS_CENTER);
        gtk_window_set_default_size(GTK_WINDOW(window_m),1000, 500);
        gtk_window_set_title(GTK_WINDOW(window), "TEAM 2");
        gtk_container_set_border_width(GTK_CONTAINER(window_m), 30);
	startt2();

	char line [100];
	FILE *fp;
	fp = fopen("t20_2.txt", "r");

	vbox = gtk_vbox_new(0, 0);
	label1 = gtk_label_new("TEAM 2\nName\t\tScore\t\tSix\t\tStrikerate");
	gtk_box_pack_start(GTK_BOX(vbox), label1, 0,0,0);
	
	for(i = 1; i <= 11; i++) {
		fgets(line, sizeof line, fp); 
	}
	for(i = 1; i <= 5; i++) {
		fgets(line, sizeof line, fp); 
 		label = gtk_label_new(line);
		gtk_box_pack_start(GTK_BOX(vbox), label, 0,0,0);
	       	totalscorett4 = tt2[1].score[i] +  totalscorett4;
        }
        totalscore = gtk_label_new("TotalScore = ");
        gtk_box_pack_start(GTK_BOX(vbox), totalscore, 0, 0, 0);
        sprintf(tscore, "%d", totalscorett4);
        teamscore = gtk_label_new(tscore);
        gtk_box_pack_start(GTK_BOX(vbox), teamscore, 0, 0, 0);

        label2 = gtk_label_new("Name\tOvers\tWickets\tEconomy");
        gtk_box_pack_start(GTK_BOX(vbox), label2, 0, 0, 0);

        for(i = 1; i <= 7; i++) {
                fgets(line, sizeof line, fp);
                label = gtk_label_new(line);
                gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);
                wicketst1 = blt2[1].wic[i] + wicketst1;
        }
        totalwickets = gtk_label_new("Wickets = ");
        sprintf(twickets, "%d", wicketst1);
        teamwickets = gtk_label_new(twickets);
	gtk_box_pack_start(GTK_BOX(vbox), totalwickets, 0, 0, 0);
        gtk_box_pack_start(GTK_BOX(vbox), teamwickets, 0, 0, 0);

                                                    
	fclose(fp);
	gtk_container_add(GTK_CONTAINER(window_m),vbox);
	gtk_widget_show_all(window_m);
}


static void tt2_stats_match2(GtkWidget *button, gpointer window) {
	GtkWidget  *window_m,*batsman, *bowler, *boundary, *econo, *table;

	window_m = gtk_window_new(GTK_WINDOW_TOPLEVEL);		        
	gtk_window_set_position(GTK_WINDOW(window_m), GTK_WIN_POS_CENTER);
        gtk_window_set_default_size(GTK_WINDOW(window_m),500, 500);
        gtk_window_set_title(GTK_WINDOW(window), "MATCH 1");
        gtk_container_set_border_width(GTK_CONTAINER(window_m), 30);

	batsman	= gtk_button_new_with_label("Best Batsman");
	bowler = gtk_button_new_with_label("Best Bowler");
	boundary = gtk_button_new_with_label("maximum Boundaries hit by");	
	econo = gtk_button_new_with_label("Economic bowler");

	table = gtk_table_new(5, 5, TRUE);

	gtk_table_attach_defaults(GTK_TABLE(table), batsman, 0 ,1, 0, 1);
	gtk_table_attach_defaults(GTK_TABLE(table), bowler, 0 ,1, 1, 2);
	gtk_table_attach_defaults(GTK_TABLE(table), boundary, 0 ,1, 2, 3);
	gtk_table_attach_defaults(GTK_TABLE(table), econo, 0 ,1, 3, 4);
	gtk_container_add(GTK_CONTAINER(window_m), table);

	g_signal_connect(batsman, "clicked", G_CALLBACK(best_batsmantt2), window_m);
	g_signal_connect(bowler, "clicked", G_CALLBACK(best_bowlertt2), window_m);
	g_signal_connect(boundary, "clicked", G_CALLBACK(boundary_hit_tt2), window_m);
	g_signal_connect(econo, "clicked", G_CALLBACK(eco_bowlertt2), window_m);
	
	gtk_widget_show_all(window_m);
}

static void match2_pret20(GtkWidget *button, gpointer window) {
	GtkWidget *window_m, *team1, *team2, *stats, *table ;
	window_m = gtk_window_new(GTK_WINDOW_TOPLEVEL);		        
	gtk_window_set_position(GTK_WINDOW(window_m), GTK_WIN_POS_CENTER);
        gtk_window_set_default_size(GTK_WINDOW(window_m),1000, 500);
        gtk_window_set_title(GTK_WINDOW(window), "MATCH 2");
        gtk_container_set_border_width(GTK_CONTAINER(window_m), 30);
	
	team1 = gtk_button_new_with_label("TEAM 1");
	team2 = gtk_button_new_with_label("TEAM 2");
	stats = gtk_button_new_with_label("STATS");

	table = gtk_table_new(13, 7, TRUE);

	gtk_table_attach_defaults(GTK_TABLE(table), team1, 0 ,1, 0, 1);
	gtk_table_attach_defaults(GTK_TABLE(table), team2, 1 ,2, 0, 1);
	gtk_table_attach_defaults(GTK_TABLE(table), stats, 2 ,3, 0, 1);
	
	g_signal_connect(team1, "clicked", G_CALLBACK(tt2_team1_score), window_m);
	g_signal_connect(team2, "clicked", G_CALLBACK(tt2_team2_score), window_m);
	g_signal_connect(stats, "clicked", G_CALLBACK(tt2_stats_match2), window_m);

	gtk_container_add(GTK_CONTAINER(window_m), table);
	
	gtk_widget_show_all(window_m);
}
                                                                                                   
