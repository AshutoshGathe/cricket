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
#define MAXSIZE 100

int x=1, y = 2, z = 3, a = 4, b = 6;
float ballcount = 0.0, blcount = 0.0;
int sixcount[13], fourcount[13]; 
int inscore[13], overs[7], wickets[7];
float strikerate[13] , indball[13];
int totalscore = 0, fallwicket = 0;
/*-------------------------------------palyers stack for storing runs------------------------------*/
typedef struct stack {
	int a[100];
	int i;
}stack;
stack s[13];


void push(stack s[0], int n) {
	s[0].a[s[0].i]= n;
	(s[0].i)++;
}
int pop(stack s[0]) {
	int t = s[0].a[s[0].i - 1];
	(s[0].i)--;
	return t;
}
int empty(stack s[0]) {
	if(s[0].i == -1) 
		return 0;
	else
		return 1;
	
}

void push1(stack s[1], int m) {
	s[1].a[s[1].i]= m;
	(s[1].i)++;
}
int pop1(stack s[1]) {
	int t = s[1].a[s[1].i - 1];
	(s[1].i)--;
	return t;
}
int empty1(stack s[1]) {
	if(s[1].i == -1) 
		return 0;
	else 
		return 1;
	
}	

void push2(stack s[2], int o) {
	s[2].a[s[2].i]= o;
	(s[2].i)++;
}
int pop2(stack s[2]) {
	int t = s[2].a[s[2].i - 1];
	(s[2].i)--;
	return t;
}
int empty2(stack s[2]) {
	if(s[2].i == -1) 
		return 0;
	else 
		return 1;
	
}

void push3(stack s[3], int m) {
	s[3].a[s[3].i]= m;
	(s[3].i)++;
}
int pop3(stack s[3]) {
	int t = s[3].a[s[3].i - 1];
	(s[3].i)--;
	return t;
}
int empty3(stack s[3]) {
	if(s[3].i == -1) 
		return 0;
	else 
		return 1;
	
}

void push4(stack s[4], int t) {
	s[4].a[s[4].i]= t;
	(s[4].i)++;
}
int pop4(stack s[4]) {
	int t = s[4].a[s[4].i - 1];
	(s[4].i)--;
	return t;
}
int empty4(stack s[4]) {
	if(s[4].i == -1) 
		return 0;
	else 
		return 1;
	
}

void push5(stack s[5], int f) {
	s[5].a[s[5].i]= f;
	(s[5].i)++;
}
int pop5(stack s[5]) {
	int t = s[5].a[s[5].i - 1];
	(s[5].i)--;
	return t;
}
int empty5(stack s[5]) {
	if(s[5].i == -1) 
		return 0;
	else 
		return 1;
	
}

void push6(stack s[6], int n) {
	s[6].a[s[6].i]= n;
	(s[6].i)++;
}
int pop6(stack s[6]) {
	int t = s[6].a[s[6].i - 1];
	(s[6].i)--;
	return t;
}
int empty6(stack s[6]) {
	if(s[6].i == -1) 
		return 0;
	else 
		return 1;
	
}

void push7(stack s[7], int n) {
	s[7].a[s[7].i]= n;
	(s[7].i)++;
}
int pop7(stack s[7]) {
	int t = s[7].a[s[7].i - 1];
	(s[7].i)--;
	return t;
}
int empty7(stack s[7]) {
	if(s[7].i == -1) 
		return 0;
	else 
		return 1;
	
}

void push8(stack s[8], int n) {
	s[8].a[s[8].i]= n;
	(s[8].i)++;
}
int pop8(stack s[8]) {
	int t = s[8].a[s[8].i - 1];
	(s[8].i)--;
	return t;
}
int empty8(stack s[8]) {
	if(s[8].i == -1) 
		return 0;
	else 
		return 1;	
}

void push9(stack s[9], int n) {
	s[9].a[s[9].i]= n;
	(s[9].i)++;
}
int pop9(stack s[9]) {
	int t = s[9].a[s[9].i - 1];
	(s[9].i)--;
	return t;
}
int empty9(stack s[9]) {
	if(s[9].i == -1) 
		return 0;
	else 
		return 1;	
}

void push10(stack s[10], int n) {
	s[10].a[s[10].i]= n;
	(s[10].i)++;
}
int pop10(stack s[10]) {
	int t = s[10].a[s[10].i - 1];
	(s[10].i)--;
	return t;
}
int empty10(stack s[10]) {
	if(s[10].i == -1) 
		return 0;
	else 
		return 1;	
}

void push11(stack s[11], int n) {
	s[11].a[s[11].i]= n;
	(s[11].i)++;
}
int pop11(stack s[11]) {
	int t = s[11].a[s[11].i - 1];
	(s[11].i)--;
	return t;
}
int empty11(stack s[11]) {
	if(s[11].i == -1) 
		return 0;
	else 
		return 1;	
}
/*-----------------------------------------------------------------------------------------------------------------*/
	
	
static void run_scored_so(GtkWidget *button, gpointer window) {
	push(&s[0], x);
	
	indball[1] = indball[1] + 1;		
}
static void run_scored_st(GtkWidget *button, gpointer window) {
	push(&s[0], y);
	indball[1] = indball[1] + 1;	
}
static void run_scored_sth(GtkWidget *button, gpointer window) {
	push(&s[0], z);
	indball[1] = indball[1] + 1;		
}
static void run_scored_sf(GtkWidget *button, gpointer window) {
	push(&s[0], a);
	fourcount[1] = fourcount[1] + 1;
	indball[1] = indball[1] + 1;
			
}
static void run_scored_ss(GtkWidget *button, gpointer window) {
	push(&s[0], b);
	sixcount[1] = sixcount[1] + 1;
	indball[1] = indball[1] + 1;
			
}
static void sum_scored_se(GtkWidget *button, gpointer window, int a) {
	while(empty(&s[0])) {
		 a = pop(&s[0]);
		 inscore[1] = a + inscore[1] ;
	}
	strikerate[1] = (inscore[1] / indball[1]) * 100;
	g_print("%d\n", inscore[1]);
}
static void run_scored_sao(GtkWidget *button, gpointer window) {
	push1(&s[1], x);
	
	indball[2] = indball[2] + 1;		
}
static void run_scored_sat(GtkWidget *button, gpointer window) {
	push1(&s[1], y);
	
	indball[2] = indball[2] + 1;
			
}
static void run_scored_sath(GtkWidget *button, gpointer window) {
	push1(&s[1], z);
	
	indball[2] = indball[2] + 1;
		
}
static void run_scored_saf(GtkWidget *button, gpointer window) {
	push1(&s[1], a);
	fourcount[2] = fourcount[2] + 1;
	
	indball[2] = indball[2] + 1;		
}
static void run_scored_sas(GtkWidget *button, gpointer window) {
	push1(&s[1], b);
	sixcount[2] = sixcount[2] + 1;
	indball[2] = indball[2] + 1;
			
}
static void sum_scored_sae(GtkWidget *button, gpointer window, int a) {
	while(empty1(&s[1])) {
               	a = pop1(&s[1]);
               inscore[2] = a + inscore[2];
        }
	strikerate[2] = (inscore[2] / indball[2]) * 100;
	g_print("%d\n", inscore[2]);
}
static void run_scored_sbo(GtkWidget *button, gpointer window) {
	push2(&s[2], x);
	indball[3] = indball[3] + 1;	
}
static void run_scored_sbt(GtkWidget *button, gpointer window) {
	push2(&s[2], y);
	indball[3] = indball[3] + 1;
	
}
static void run_scored_sbth(GtkWidget *button, gpointer window) {
	push2(&s[2], z);
	
	indball[3] = indball[3] + 1;
			
}
static void run_scored_sbf(GtkWidget *button, gpointer window) {
	push2(&s[2], a);
	fourcount[3] = fourcount[3] + 1;
	indball[3] = indball[3] + 1;	
}
static void run_scored_sbs(GtkWidget *button, gpointer window) {
	push2(&s[2], b);
	sixcount[3] = sixcount[3] + 1;
	indball[3] = indball[3] + 1;
}
static void sum_scored_sbe(GtkWidget *button, gpointer window, int a) {
	while(empty2(&s[2])) {
                a = pop2(&s[2]);
                inscore[3] = a + inscore[3];
        }
	strikerate[3] = (inscore[3] / indball[3]) * 100;
	g_print("%d\n",inscore[3]);
}
static void run_scored_sco(GtkWidget *button, gpointer window) {
	push3(&s[3], x);
	indball[4] = indball[4] + 1;	
}
static void run_scored_sct(GtkWidget *button, gpointer window) {
	push3(&s[3], y);
	
	indball[4] = indball[4] + 1;
	
}
static void run_scored_scth(GtkWidget *button, gpointer window) {
	push3(&s[3], z);
	indball[4] = indball[4] + 1;
			
}
static void run_scored_scf(GtkWidget *button, gpointer window) {
	push3(&s[3], a);
	fourcount[4] = fourcount[4] + 1;
	indball[4] = indball[4] + 1;	
}
static void run_scored_scs(GtkWidget *button, gpointer window) {
	push3(&s[3], b);
	sixcount[4] = sixcount[4] + 1;
	
}
static void sum_scored_sce(GtkWidget *button, gpointer window, int a) {
	
	while(empty3(&s[3])) {
                a = pop3(&s[3]);
               inscore[4] = a + inscore[4];
        }
	strikerate[4] = (inscore[4] / indball[4]) * 100;
	g_print("%d\n", inscore[4]);
}

static void run_scored_sdo(GtkWidget *button, gpointer window) {
	push4(&s[4], x);
	indball[5] = indball[5] + 1;	
}
static void run_scored_sdt(GtkWidget *button, gpointer window) {
	push4(&s[4], y);
	indball[5] = indball[5] + 1;
	
}
static void run_scored_sdth(GtkWidget *button, gpointer window) {
	push4(&s[4], z);
	indball[5] = indball[5] + 1;
			
}
static void run_scored_sdf(GtkWidget *button, gpointer window) {
	push4(&s[4], a);
	fourcount[5] = fourcount[5] + 1;
	indball[5] = indball[5] + 1;	
}
static void run_scored_sds(GtkWidget *button, gpointer window) {
	push4(&s[4], b);
	sixcount[5] = sixcount[5] + 1;
	indball[5] = indball[5] + 1;
}
static void sum_scored_sde(GtkWidget *button, gpointer window, int a) {
	while(empty4(&s[4])) {
                a = pop4(&s[4]);
                inscore[5] = a + inscore[5];
        }
	strikerate[5] = (inscore[5] / indball[5]) * 100;
	g_print("%d\n",inscore[5]);
}
static void run_scored_seo(GtkWidget *button, gpointer window) {
	push5(&s[5], x);
	
	indball[6] = indball[6] + 1;	
}
static void run_scored_set(GtkWidget *button, gpointer window) {
	push5(&s[5], y);
	indball[6] = indball[6] + 1;
	
}
static void run_scored_seth(GtkWidget *button, gpointer window) {
	push5(&s[5], z);
	indball[6] = indball[6] + 1;
			
}
static void run_scored_sef(GtkWidget *button, gpointer window) {
	push5(&s[5], a);
	fourcount[6] = fourcount[6] + 1;
	indball[6] = indball[6] + 1;	
}
static void run_scored_ses(GtkWidget *button, gpointer window) {
	push5(&s[5], b);
	sixcount[6] = sixcount[6] + 1;
	
}
static void sum_scored_see(GtkWidget *button, gpointer window, int a) {
	while(empty5(&s[5])) {
                a = pop5(&s[5]);
                inscore[6] = a + inscore[6];
        }
	strikerate[6] = (inscore[6] / indball[6]) * 100;
	g_print("%d\n",inscore[6]);
}
static void run_scored_sfo(GtkWidget *button, gpointer window) {
	push6(&s[6], x);
	
	indball[7] = indball[7] + 1;	
}
static void run_scored_sft(GtkWidget *button, gpointer window) {
	push6(&s[6], y);
	indball[7] = indball[7] + 1;
	
}
static void run_scored_sfth(GtkWidget *button, gpointer window) {
	push6(&s[6], z);
	indball[7] = indball[7] + 1;
			
}
static void run_scored_sff(GtkWidget *button, gpointer window) {
	push6(&s[6], a);
	fourcount[7] = fourcount[7] + 1;
	
	indball[7] = indball[7] + 1;	
}
static void run_scored_sfs(GtkWidget *button, gpointer window) {
	push6(&s[6], b);
	sixcount[7] = sixcount[7] + 1;
	indball[7] = indball[7] + 1;
}
static void sum_scored_sfe(GtkWidget *button, gpointer window, int a) {
	while(empty6(&s[6])) {
                a = pop6(&s[6]);
                inscore[7] = a + inscore[7];
        }
	strikerate[7] = (inscore[7] / indball[7]) * 100;
	g_print("%d\n",inscore[7]);
}

static void run_scored_sgo(GtkWidget *button, gpointer window) {
	push7(&s[7], x);
	indball[8] = indball[8] + 1;	
}
static void run_scored_sgt(GtkWidget *button, gpointer window) {
	push7(&s[7], y);
	
	indball[8] = indball[8] + 1;
	
}
static void run_scored_sgth(GtkWidget *button, gpointer window) {
	push7(&s[7], z);
	indball[8] = indball[8] + 1;
			
}
static void run_scored_sgf(GtkWidget *button, gpointer window) {
	push7(&s[7], a);
	fourcount[8] = fourcount[8] + 1;
	
	indball[8] = indball[8] + 1;	
}
static void run_scored_sgs(GtkWidget *button, gpointer window) {
	push7(&s[7], b);
	sixcount[8] = sixcount[8] + 1;
	
	indball[8] = indball[8] + 1;
}
static void sum_scored_sge(GtkWidget *button, gpointer window, int a) {
	while(empty7(&s[7])) {
                a = pop7(&s[7]);
                inscore[8] = a + inscore[8];
        }
	strikerate[8] = (inscore[8] / indball[8]) * 100;
	g_print("%d\n",inscore[8]);
}

static void run_scored_sho(GtkWidget *button, gpointer window) {
	push8(&s[8], x);
	
	indball[9] = indball[9] + 1;	
}
static void run_scored_sht(GtkWidget *button, gpointer window) {
	push8(&s[8], y);
	indball[9] = indball[9] + 1;
	
}
static void run_scored_shth(GtkWidget *button, gpointer window) {
	push8(&s[8], z);
	indball[9] = indball[9] + 1;
			
}
static void run_scored_shf(GtkWidget *button, gpointer window) {
	push8(&s[8], a);
	fourcount[9] = fourcount[9] + 1;
	
	indball[9] = indball[9] + 1;	
}
static void run_scored_shs(GtkWidget *button, gpointer window) {
	push8(&s[8], b);
	sixcount[9] = sixcount[9] + 1;
	indball[9] = indball[9] + 1;
}
static void sum_scored_she(GtkWidget *button, gpointer window, int a) {
	while(empty8(&s[8])) {
                a = pop8(&s[8]);
                inscore[9] = a + inscore[9];
        }
	strikerate[9] = (inscore[9] / indball[9]) * 100;
	g_print("%d\n",inscore[9]);
}

static void run_scored_sio(GtkWidget *button, gpointer window) {
	push9(&s[9], x);
	
	indball[10] = indball[10] + 1;	
}
static void run_scored_sit(GtkWidget *button, gpointer window) {
	push9(&s[9], y);
	indball[10] = indball[10] + 1;	
	
}
static void run_scored_sith(GtkWidget *button, gpointer window) {
	push9(&s[9], z);
	indball[10] = indball[10] + 1;	
			
}
static void run_scored_sif(GtkWidget *button, gpointer window) {
	push9(&s[9], a);
	fourcount[10] = fourcount[10] + 1;
	
	indball[10] = indball[10] + 1;		
}
static void run_scored_sis(GtkWidget *button, gpointer window) {
	push9(&s[9], b);
	sixcount[10] = sixcount[10] + 1;
	indball[10] = indball[10] + 1;	
}
static void sum_scored_sie(GtkWidget *button, gpointer window, int a) {
	while(empty9(&s[9])) {
                a = pop9(&s[9]);
                inscore[10] = a + inscore[10];
        }
	strikerate[10] = (inscore[10] / indball[10]) * 100;
	g_print("%d\n",inscore[10]);
	
}
static void run_scored_sjo(GtkWidget *button, gpointer window) {
	push10(&s[10], x);
	
	indball[11] = indball[11] + 1;		
}
static void run_scored_sjt(GtkWidget *button, gpointer window) {
	push10(&s[10], y);
	indball[11] = indball[11] + 1;
	
}
static void run_scored_sjth(GtkWidget *button, gpointer window) {
	push10(&s[10], z);
	indball[11] = indball[11] + 1;
			
}
static void run_scored_sjf(GtkWidget *button, gpointer window) {
	push10(&s[10], a);
	fourcount[11] = fourcount[11] + 1;
		
}
static void run_scored_sjs(GtkWidget *button, gpointer window) {
	push10(&s[10], b);
	sixcount[11] = sixcount[11] + 1;
	indball[11] = indball[11] + 1;
}
static void sum_scored_sje(GtkWidget *button, gpointer window, int a) {
	while(empty10(&s[10])) {
                a = pop10(&s[10]);
                inscore[11] = a + inscore[11];
        }
	strikerate[11] = (inscore[11] / indball[11]) * 100;
	g_print("%d\n",inscore[11]);
}

			

/*---------------bowlers data-----------------------------------------*/
	gint extracount = 0;
	gint runout = 0;	
	gint count = 0;
	gint counta = 0;
	gint countb = 0;
	gint countc = 0;
	gint countd = 0;

	gint counte = 0;
	gint countf = 0;
	gint countg = 0;
	gint counth = 0;
	gint counti= 0;




char buf[10];
void extra_run(GtkWidget *widget, gpointer extralabel) {
	extracount++;
	totalscore = extracount;
	sprintf(buf, "%d", extracount);
  	gtk_label_set_text(extralabel, buf);
}
void run_out(GtkWidget *widget, gpointer rnout) {
	runout++;
	fallwicket = runout;
	sprintf(buf, "%d", runout);
  	gtk_label_set_text(rnout, buf);
}
void overs_clicked(GtkWidget *widget, gpointer label) {
	if(count > 9) {
		count = count - 1;
	}
	count++;
	overs[1] = count;
  	sprintf(buf, "%d", count);
  	gtk_label_set_text(label, buf);
}
void oversa_clicked(GtkWidget *widget, gpointer labela) {
	if(counta > 9) {
		counta = counta - 1;
	} 
	counta++;
	overs[2] = counta;
  	sprintf(buf, "%d", counta);
  	gtk_label_set_text(labela, buf);
}
void oversb_clicked(GtkWidget *widget, gpointer labelb) {
	if(countb > 9) {
		countb = countb - 1;
	} 
	countb++;
	overs[3] = countb;
  	sprintf(buf, "%d", countb);
  	gtk_label_set_text(labelb, buf);
}
void oversc_clicked(GtkWidget *widget, gpointer labelc) {
	if(countc > 9) {
		countc = countc - 1;
	} 
	countc++;
	overs[4] = countc;
  	sprintf(buf, "%d", countc);
  	gtk_label_set_text(labelc, buf);
}
void oversd_clicked(GtkWidget *widget, gpointer labeld) {
	if(countd > 9) {
		countd = countd - 1;
	} 
	countd++;
	overs[5] = countd;
  	sprintf(buf, "%d", countd);
  	gtk_label_set_text(labeld, buf);
}
void wickets_clicked(GtkWidget *widget, gpointer wlabel) {
	if(counte > 7) {
		counte = counte - 1;
	}
	counte++;
	wickets[1] = counte;
	sprintf(buf, "%d", counte);
  	gtk_label_set_text(wlabel, buf);
}
void wicketsa_clicked(GtkWidget *widget, gpointer wlabela) {
	if(countf > 7) {
		countf = countf - 1;
	}
	countf++;
	wickets[2] = countf;
	sprintf(buf, "%d", countf);
  	gtk_label_set_text(wlabela, buf);
}
void wicketsb_clicked(GtkWidget *widget, gpointer wlabelb) {
	if(countg > 7) {
		countg = countg - 1;
	}
	countg++;
	wickets[3] = countg;
	sprintf(buf, "%d", countg);
  	gtk_label_set_text(wlabelb, buf);
}
void wicketsc_clicked(GtkWidget *widget, gpointer wlabelc) {
	if(counth > 7) {
		counth = counth - 1;
	}
	counth++;
	wickets[4] = counth;
	sprintf(buf, "%d", counth);
  	gtk_label_set_text(wlabelc, buf);
}
void wicketsd_clicked(GtkWidget *widget, gpointer wlabeld) {
	if(counti > 7) {
		counti = counti - 1;
	}
	counti++;
	wickets[5] = counti;
	sprintf(buf, "%d", counti);
  	gtk_label_set_text(wlabeld, buf);
}		
/*---------------------------------------------------------------------------------------------------------------------*/

	
/*---------------------for display scorecard ---------------------------------------------------*/
		
static void card_as(GtkWidget *button, gpointer window) {
	GtkWidget *window_m, *label, *label1, *label2, *vbox, *totalwickets,*teamscore, *teamwickets, *totscore ;
	int i = 1, j = 1;
	char tscore[5], twickets[5];
	FILE *fp;
	fp = fopen ("pscore.txt", "w");
	window_m = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(window_m), GTK_WIN_POS_CENTER);
        gtk_window_set_title(GTK_WINDOW(window), "TEAM 1");
	gtk_window_set_default_size(GTK_WINDOW(window_m),1000, 500);
        gtk_container_set_border_width(GTK_CONTAINER(window_m), 30);
	vbox = gtk_vbox_new(0, 0);
	label1 = gtk_label_new("TEAM 2\nName\t\tScore\t\tSix\t\tStrikerate");
	gtk_box_pack_start(GTK_BOX(vbox), label1, 0,0,0);


	while(i <= 11) {
		fprintf(fp, "%s%d\t%d\t%d\t%d\t%.2f\n", "play", i, fourcount[i], sixcount[i], inscore[i], strikerate[i]);
		i++;
		
	}
	fprintf(fp, "%s", "\n");
 
	while(j <= 5) {
		fprintf(fp, "%s%d\t%d\t%d\n", "bowl", j, overs[j],wickets[j]);
		j++;
	}
	
	fclose(fp);	
	
	char line [100];
	vbox = gtk_vbox_new(0, 0);
	FILE *file;
	file = fopen("pscore.txt", "r");
	label1 = gtk_label_new("TEAM\n\nName\t\tScore\tSix\tStrikeRate\n");
	gtk_box_pack_start(GTK_BOX(vbox), label1, 0, 0, 0);
	i = 1;
	for(i = 1; i <= 11; i++) {		
		fgets(line, sizeof(line), file);
		label = gtk_label_new(line);
		gtk_box_pack_start(GTK_BOX(vbox), label, 0,0,0);
	}
	
	totscore = gtk_label_new("TotalScore = ");
	gtk_box_pack_start(GTK_BOX(vbox), totscore, 0, 0, 0);
	sprintf(tscore, "%d", totalscore);
	teamscore = gtk_label_new(tscore);
	gtk_box_pack_start(GTK_BOX(vbox), teamscore, 0, 0, 0);

	label2 = gtk_label_new("Name\tOvers\tWickets\tEconomy");	
	gtk_box_pack_start(GTK_BOX(vbox), label2, 0, 0, 0);
	for(i = 1; i <= 5; i++) {
		fgets(line, sizeof line, fp);
		label = gtk_label_new(line);
		gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);

	}
	totalwickets = gtk_label_new("Wickets = ");
	sprintf(twickets, "%d", fallwicket);
	teamwickets = gtk_label_new(twickets);
	gtk_box_pack_start(GTK_BOX(vbox), totalwickets, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(vbox), teamwickets, 0, 0, 0);

	
	
	

	gtk_container_add(GTK_CONTAINER(window_m),vbox);

	gtk_widget_show_all(window_m);
	
}

		


