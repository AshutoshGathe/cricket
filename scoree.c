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

int xt=1, yt = 2, zt = 3, at = 4, bt = 6;
float ballcountt = 0.0, blcountt = 0.0;
int sixcount_t[13], fourcount_t[13]; 
int inscore_t[13], overs_t[7], wickets_t[7];
float strikerate_t[13] , indball_t[13];
int totalscore_t = 0, fallwicket_t = 0;


/*-----------------------------------------------------stack of players for storing runs------------------------*/

typedef struct stackt {
	int a[100];
	int i;
}stackt;
stackt st[13];


void pusht(stackt st[0], int n) {
	st[0].a[st[0].i]= n;
	(st[0].i)++;
}
int popt(stackt st[0]) {
	int t = st[0].a[st[0].i - 1];
	(st[0].i)--;
	return t;
}
int emptyt(stackt st[0]) {
	if(st[0].i == -1) 
		return 0;
	else
		return 1;
	
}

void push1t(stackt st[1], int m) {
	st[1].a[st[1].i]= m;
	(st[1].i)++;
}
int pop1t(stackt st[1]) {
	int t = st[1].a[st[1].i - 1];
	(st[1].i)--;
	return t;
}
int empty1t(stackt st[1]) {
	if(st[1].i == -1) 
		return 0;
	else 
		return 1;
	
}	

void push2t(stackt st[2], int o) {
	st[2].a[st[2].i]= o;
	(st[2].i)++;
}
int pop2t(stackt st[2]) {
	int t = st[2].a[st[2].i - 1];
	(st[2].i)--;
	return t;
}
int empty2t(stackt st[2]) {
	if(st[2].i == -1) 
		return 0;
	else 
		return 1;
	
}

void push3t(stackt st[3], int o) {
	st[3].a[st[3].i]= o;
	(st[3].i)++;
}
int pop3t(stackt st[3]) {
	int t = st[3].a[st[3].i - 1];
	(st[3].i)--;
	return t;
}
int empty3t(stackt st[3]) {
	if(st[3].i == -1) 
		return 0;
	else 
		return 1;
	
}

void push4t(stackt st[4], int t) {
	st[4].a[st[4].i]= t;
	(st[4].i)++;
}
int pop4t(stackt st[4]) {
	int t = st[4].a[st[4].i - 1];
	(st[4].i)--;
	return t;
}
int empty4t(stackt st[4]) {
	if(st[4].i == -1) 
		return 0;
	else 
		return 1;
	
}

void push5t(stackt st[5], int f) {
	st[5].a[st[5].i]= f;
	(st[5].i)++;
}
int pop5t(stackt st[5]) {
	int t = st[5].a[st[5].i - 1];
	(st[5].i)--;
	return t;
}
int empty5t(stackt st[5]) {
	if(st[5].i == -1) 
		return 0;
	else 
		return 1;
	
}

void push6t(stackt st[6], int n) {
	st[6].a[st[6].i]= n;
	(st[6].i)++;
}
int pop6t(stackt st[6]) {
	int t = st[6].a[st[6].i - 1];
	(st[6].i)--;
	return t;
}
int empty6t(stackt st[6]) {
	if(st[6].i == -1) 
		return 0;
	else 
		return 1;
	
}

void push7t(stackt st[7], int n) {
	st[7].a[st[7].i]= n;
	(st[7].i)++;
}
int pop7t(stackt st[7]) {
	int t = st[7].a[st[7].i - 1];
	(st[7].i)--;
	return t;
}
int empty7t(stackt st[7]) {
	if(st[7].i == -1) 
		return 0;
	else 
		return 1;
	
}

void push8t(stackt st[8], int n) {
	st[8].a[st[8].i]= n;
	(st[8].i)++;
}
int pop8t(stackt st[8]) {
	int t = st[8].a[st[8].i - 1];
	(st[8].i)--;
	return t;
}
int empty8t(stackt st[8]) {
	if(st[8].i == -1) 
		return 0;
	else 
		return 1;	
}

void push9t(stackt st[9], int n) {
	st[9].a[st[9].i]= n;
	(st[9].i)++;
}
int pop9t(stackt st[9]) {
	int t = st[9].a[st[9].i - 1];
	(st[9].i)--;
	return t;
}
int empty9t(stackt st[9]) {
	if(st[9].i == -1) 
		return 0;
	else 
		return 1;	
}

void push10t(stackt st[10], int n) {
	st[10].a[st[10].i]= n;
	(st[10].i)++;
}
int pop10t(stackt st[10]) {
	int t = st[10].a[st[10].i - 1];
	(st[10].i)--;
	return t;
}
int empty10t(stackt st[10]) {
	if(st[10].i == -1) 
		return 0;
	else 
		return 1;	
}

void push11t(stackt st[11], int n) {
	st[11].a[st[11].i]= n;
	(st[11].i)++;
}
int pop11t(stackt st[11]) {
	int t = st[11].a[st[11].i - 1];
	(st[11].i)--;
	return t;
}
int empty11t(stackt st[11]) {
	if(st[11].i == -1) 
		return 0;
	else 
		return 1;	
}
/*-----------------------------------------------------------------------------------------------------------------*/



/*----------------------------------storing in stack runs scored-----------*/	
	
static void runt_scored_so(GtkWidget *button, gpointer window) {
	pusht(&st[0], xt);
	indball_t[1] = indball_t[1] + 1;		
}
static void runt_scored_st(GtkWidget *button, gpointer window) {
	pusht(&st[0], yt);
	
	indball_t[1] = indball_t[1] + 1;	
}
static void runt_scored_sth(GtkWidget *button, gpointer window) {
	pusht(&st[0],zt );
	indball_t[1] = indball_t[1] + 1;		
}
static void runt_scored_sf(GtkWidget *button, gpointer window) {
	pusht(&st[0], at);
	fourcount_t[1] = fourcount_t[1] + 1;
	indball_t[1] = indball_t[1] + 1;		
}
static void runt_scored_ss(GtkWidget *button, gpointer window) {
	pusht(&st[0], bt);
	sixcount_t[1] = sixcount_t[1] + 1;
	indball_t[1] = indball_t[1] + 1;		
}
static void sumt_scored_se(GtkWidget *button, gpointer window, int a) {
	while(emptyt(&st[0])) {
		 a = popt(&st[0]);
		 inscore_t[1] = a + inscore_t[1] ;
	}
	strikerate_t[1] = (inscore_t[1] / indball_t[1]) * 100;
}
static void runt_scored_sao(GtkWidget *button, gpointer window) {
	push1t(&st[1], xt);
	indball_t[2] = indball_t[2] + 1;		
}
static void runt_scored_sat(GtkWidget *button, gpointer window) {
	push1t(&st[1], yt);
	indball_t[2] = indball_t[2] + 1;
			
}
static void runt_scored_sath(GtkWidget *button, gpointer window) {
	push1t(&st[1], zt);
	indball_t[2] = indball_t[2] + 1;
		
}
static void runt_scored_saf(GtkWidget *button, gpointer window) {
	push1t(&st[1], at);
	fourcount_t[2] = fourcount_t[2] + 1;
	indball_t[2] = indball_t[2] + 1;		
}
static void runt_scored_sas(GtkWidget *button, gpointer window) {
	push1t(&st[1], bt);
	sixcount_t[2] = sixcount_t[2] + 1;
	indball_t[2] = indball_t[2] + 1;		
}
static void sumt_scored_sae(GtkWidget *button, gpointer window, int a) {
	while(empty1t(&st[1])) {
               	a = pop1t(&st[1]);
               inscore_t[2] = a + inscore_t[2];
        }
	strikerate_t[2] = (inscore_t[2] / indball_t[2]) * 100;
}
static void runt_scored_sbo(GtkWidget *button, gpointer window) {
	push2t(&st[2], xt);
	
	indball_t[3] = indball_t[3] + 1;	
}
static void runt_scored_sbt(GtkWidget *button, gpointer window) {
	push2t(&st[2], yt);
	indball_t[3] = indball_t[3] + 1;
	
}
static void runt_scored_sbth(GtkWidget *button, gpointer window) {
	push2t(&st[2], zt);
	indball_t[3] = indball_t[3] + 1;
			
}
static void runt_scored_sbf(GtkWidget *button, gpointer window) {
	push2t(&st[2], at);
	fourcount_t[3] = fourcount_t[3] + 1;
	indball_t[3] = indball_t[3] + 1;	
}
static void runt_scored_sbs(GtkWidget *button, gpointer window) {
	push2t(&st[2], bt);
	sixcount_t[3] = sixcount_t[3] + 1;
	indball_t[3] = indball_t[3] + 1;
}
static void sumt_scored_sbe(GtkWidget *button, gpointer window, int a) {
	while(empty2t(&st[2])) {
                a = pop2t(&st[2]);
                inscore_t[3] = a + inscore_t[3];
        }
	strikerate_t[3] = (inscore_t[3] / indball_t[3]) * 100;
}
static void runt_scored_sco(GtkWidget *button, gpointer window) {
	push3t(&st[3], xt);
	indball_t[4] = indball_t[4] + 1;	
}
static void runt_scored_sct(GtkWidget *button, gpointer window) {
	push3t(&st[3], yt);
	indball_t[4] = indball_t[4] + 1;
	
}
static void runt_scored_scth(GtkWidget *button, gpointer window) {
	push3t(&st[3], zt);
	indball_t[4] = indball_t[4] + 1;			
}
static void runt_scored_scf(GtkWidget *button, gpointer window) {
	push3t(&st[3], a);
	fourcount_t[4] = fourcount_t[4] + 1;
	indball_t[4] = indball_t[4] + 1;	
}
static void runt_scored_scs(GtkWidget *button, gpointer window) {
	push3t(&st[3], bt);
	sixcount_t[4] = sixcount_t[4] + 1;
	
	indball_t[4] = indball_t[4] + 1;
}
static void sumt_scored_sce(GtkWidget *button, gpointer window, int a) {
	
	while(empty3t(&st[3])) {
                a = pop3t(&st[3]);
               inscore_t[4] = a + inscore_t[4];
        }
	strikerate_t[4] = (inscore_t[4] / indball_t[4]) * 100;
	
}

static void runt_scored_sdo(GtkWidget *button, gpointer window) {
	push4t(&st[4], xt);
	indball_t[5] = indball_t[5] + 1;	
}
static void runt_scored_sdt(GtkWidget *button, gpointer window) {
	push4t(&st[4], yt);
	indball_t[5] = indball_t[5] + 1;
	
}
static void runt_scored_sdth(GtkWidget *button, gpointer window) {
	push4t(&st[4], zt);
	indball_t[5] = indball_t[5] + 1;
			
}
static void runt_scored_sdf(GtkWidget *button, gpointer window) {
	push4t(&st[4], at);
	fourcount_t[5] = fourcount_t[5] + 1;
	indball_t[5] = indball_t[5] + 1;	
}
static void runt_scored_sds(GtkWidget *button, gpointer window) {
	push4t(&st[4], bt);
	sixcount_t[5] = sixcount_t[5] + 1;
	indball_t[5] = indball_t[5] + 1;
}
static void sumt_scored_sde(GtkWidget *button, gpointer window, int a) {
	while(empty4t(&st[4])) {
                a = pop4t(&st[4]);
                inscore_t[5] = a + inscore_t[5];
        }
	strikerate_t[2] = (inscore_t[5] / indball_t[5]) * 100;
	
}
static void runt_scored_seo(GtkWidget *button, gpointer window) {
	push5t(&st[5], xt);
	
	indball_t[6] = indball_t[6] + 1;	
}
static void runt_scored_set(GtkWidget *button, gpointer window) {
	push5t(&st[5], yt);
	
	indball_t[6] = indball_t[6] + 1;
	
}
static void runt_scored_seth(GtkWidget *button, gpointer window) {
	push5t(&st[5], zt);
	indball_t[6] = indball_t[6] + 1;
			
}
static void runt_scored_sef(GtkWidget *button, gpointer window) {
	push5t(&st[5], at);
	fourcount_t[6] = fourcount_t[6] + 1;
	
	indball_t[6] = indball_t[6] + 1;	
}
static void runt_scored_ses(GtkWidget *button, gpointer window) {
	push5t(&st[5], bt);
	sixcount_t[6] = sixcount_t[6] + 1;
	indball_t[6] = indball_t[6] + 1;
}
static void sumt_scored_see(GtkWidget *button, gpointer window, int a) {
	while(empty5t(&st[5])) {
                a = pop5t(&st[5]);
                inscore_t[6] = a + inscore_t[6];
        }
	strikerate_t[6] = (inscore_t[6] / indball_t[6]) * 100;
	
}
static void runt_scored_sfo(GtkWidget *button, gpointer window) {
	push6t(&st[6], xt);
	
	indball_t[7] = indball_t[7] + 1;	
}
static void runt_scored_sft(GtkWidget *button, gpointer window) {
	push6t(&st[6], yt);
	indball_t[7] = indball_t[7] + 1;
	
}
static void runt_scored_sfth(GtkWidget *button, gpointer window) {
	push6t(&st[6], zt);
	
	indball_t[7] = indball_t[7] + 1;
			
}
static void runt_scored_sff(GtkWidget *button, gpointer window) {
	push6t(&st[6], at);
	fourcount_t[7] = fourcount_t[7] + 1;
	
	indball_t[7] = indball_t[7] + 1;	
}
static void runt_scored_sfs(GtkWidget *button, gpointer window) {
	push6t(&st[6], bt);
	sixcount_t[7] = sixcount_t[7] + 1;
	
	indball_t[7] = indball_t[7] + 1;
}
static void sumt_scored_sfe(GtkWidget *button, gpointer window, int a) {
	while(empty6t(&st[6])) {
                a = pop6t(&st[6]);
                inscore_t[7] = a + inscore_t[7];
        }
	strikerate_t[7] = (inscore_t[7] / indball_t[7]) * 100;
	
}

static void runt_scored_sgo(GtkWidget *button, gpointer window) {
	push7t(&st[7], xt);
	indball_t[8] = indball_t[8] + 1;	
}
static void runt_scored_sgt(GtkWidget *button, gpointer window) {
	push7t(&st[7], yt);
	indball_t[8] = indball_t[8] + 1;
	
}
static void runt_scored_sgth(GtkWidget *button, gpointer window) {
	push7t(&st[7], zt);
	indball_t[8] = indball_t[8] + 1;
			
}
static void runt_scored_sgf(GtkWidget *button, gpointer window) {
	push7t(&st[7], at);
	fourcount_t[8] = fourcount_t[8] + 1;
	indball_t[8] = indball_t[8] + 1;	
}
static void runt_scored_sgs(GtkWidget *button, gpointer window) {
	push7t(&st[7], bt);
	sixcount_t[8] = sixcount_t[8] + 1;
	indball_t[8] = indball_t[8] + 1;
}
static void sumt_scored_sge(GtkWidget *button, gpointer window, int a) {
	while(empty7t(&st[7])) {
                a = pop7t(&st[7]);
                inscore_t[8] = a + inscore_t[8];
        }
	strikerate_t[8] = (inscore_t[8] / indball_t[8]) * 100;
}

static void runt_scored_sho(GtkWidget *button, gpointer window) {
	push8t(&st[8], xt);
	
	indball_t[9] = indball_t[9] + 1;	
}
static void runt_scored_sht(GtkWidget *button, gpointer window) {
	push8t(&st[8], yt);
	indball_t[9] = indball_t[9] + 1;
	
}
static void runt_scored_shth(GtkWidget *button, gpointer window) {
	push8t(&st[8], zt);
	
	indball_t[9] = indball_t[9] + 1;
			
}
static void runt_scored_shf(GtkWidget *button, gpointer window) {
	push8t(&st[8], at);
	fourcount_t[9] = fourcount_t[9] + 1;
	indball_t[9] = indball_t[9] + 1;	
}
static void runt_scored_shs(GtkWidget *button, gpointer window) {
	push8t(&st[8], bt);
	sixcount_t[9] = sixcount_t[9] + 1;
	indball_t[9] = indball_t[9] + 1;
}
static void sumt_scored_she(GtkWidget *button, gpointer window, int a) {
	while(empty8t(&st[8])) {
                a = pop8t(&st[8]);
                inscore_t[9] = a + inscore_t[9];
        }
	strikerate_t[9] = (inscore_t[9] / indball_t[9]) * 100;
}

static void runt_scored_sio(GtkWidget *button, gpointer window) {
	push9t(&st[9], xt);
	
	indball_t[10] = indball_t[10] + 1;	
}
static void runt_scored_sit(GtkWidget *button, gpointer window) {
	push9t(&st[9], yt);
	indball_t[10] = indball_t[10] + 1;
	
}
static void runt_scored_sith(GtkWidget *button, gpointer window) {
	push9t(&st[9], zt);
	
	indball_t[10] = indball_t[10] + 1;
			
}
static void runt_scored_sif(GtkWidget *button, gpointer window) {
	push9t(&st[9], at);
	fourcount_t[10] = fourcount_t[10] + 1;
	
	indball_t[10] = indball_t[10] + 1;	
}
static void runt_scored_sis(GtkWidget *button, gpointer window) {
	push9t(&st[9], bt);
	sixcount_t[10] = sixcount_t[10] + 1;
	indball_t[10] = indball_t[10] + 1;
}
static void sumt_scored_sie(GtkWidget *button, gpointer window, int a) {
	while(empty9t(&st[9])) {
                a = pop9t(&st[9]);
                inscore_t[10] = a + inscore_t[10];
        }
	strikerate_t[10] = (inscore_t[10] / indball_t[10]) * 100;
	g_print("%d\n",inscore_t[10]);
	
}
static void runt_scored_sjo(GtkWidget *button, gpointer window) {
	push10t(&st[10], xt);
	indball_t[11] = indball_t[11] + 1;	
}
static void runt_scored_sjt(GtkWidget *button, gpointer window) {
	push10t(&st[10], yt);
	indball_t[11] = indball_t[11] + 1;
	
}
static void runt_scored_sjth(GtkWidget *button, gpointer window) {
	push10t(&st[10], zt);
	indball_t[11] = indball_t[11] + 1;
			
}
static void runt_scored_sjf(GtkWidget *button, gpointer window) {
	push10t(&st[10], a);
	fourcount_t[11] = fourcount_t[11] + 1;
	indball_t[11] = indball_t[11] + 1;	
}
static void runt_scored_sjs(GtkWidget *button, gpointer window) {
	push10t(&st[10], b);
	sixcount_t[11] = sixcount_t[11] + 1;
	indball_t[11] = indball_t[11] + 1;
}
static void sumt_scored_sje(GtkWidget *button, gpointer window, int a) {
	while(empty10t(&st[10])) {
                a = pop10t(&st[10]);
                inscore_t[11] = a + inscore_t[11];
        }
	strikerate_t[11] = (inscore_t[11] / indball_t[11]) * 100;
	
}

			

/*-------------------bowlers data-------------------------------------*/
	gint extracountt = 0;
	gint runtoutt = 0;	
	gint countt = 0;
	gint countta = 0;
	gint counttb = 0;
	gint counttc = 0;
	gint counttd = 0;

	gint countte = 0;
	gint counttf = 0;
	gint counttg = 0;
	gint countth = 0;
	gint countti= 0;




char buft[10];
void extra_runt(GtkWidget *widget, gpointer extralabelt) {
	extracountt++;
	totalscore_t = extracountt;
	sprintf(buft, "%d", extracountt);
  	gtk_label_set_text(extralabelt, buft);
}
void runt_out(GtkWidget *widget, gpointer runoutt) {
	runtoutt++;
	fallwicket_t = runtoutt;
	sprintf(buft, "%d", runtoutt);
  	gtk_label_set_text(runoutt, buft);
}
void overst_clicked(GtkWidget *widget, gpointer labelt) {
	if(countt > 9) {
		countt = countt - 1;
	}
	countt++;
	overs_t[1] = countt;
  	sprintf(buft, "%d", countt);
  	gtk_label_set_text(labelt, buft);
}
void oversta_clicked(GtkWidget *widget, gpointer labelat) {
	if(countta > 9) {
		countta = countta - 1;
	} 
	countta++;
	overs_t[2] = countta;
  	sprintf(buft, "%d", countta);
  	gtk_label_set_text(labelat, buft);
}
void overstb_clicked(GtkWidget *widget, gpointer labelbt) {
	if(counttb > 9) {
		counttb = counttb - 1;
	} 
	counttb++;
	overs_t[3] = counttb;
  	sprintf(buft, "%d", counttb);
  	gtk_label_set_text(labelbt, buft);
}
void overstc_clicked(GtkWidget *widget, gpointer labelct) {
	if(counttc > 9) {
		counttc = counttc - 1;
	} 
	counttc++;
	overs_t[4] = counttc;
  	sprintf(buft, "%d", counttc);
  	gtk_label_set_text(labelct, buft);
}
void overstd_clicked(GtkWidget *widget, gpointer labeldt) {
	if(counttd > 9) {
		counttd = counttd - 1;
	} 
	counttd++;
	overs_t[5] = counttd;
  	sprintf(buft, "%d", counttd);
  	gtk_label_set_text(labeldt, buft);
}

void wicketst_clicked(GtkWidget *widget, gpointer wlabelt) {
	if(countte > 7) {
		countte = countte - 1;
	}
	countte++;
	wickets_t[1] = countte;
	sprintf(buft, "%d", countte);
  	gtk_label_set_text(wlabelt, buft);
}
void wicketsta_clicked(GtkWidget *widget, gpointer wlabelat) {
	if(counttf > 7) {
		counttf = counttf - 1;
	}
	counttf++;
	wickets_t[2] = counttf;
	sprintf(buft, "%d", counttf);
  	gtk_label_set_text(wlabelat, buft);
}
void wicketstb_clicked(GtkWidget *widget, gpointer wlabelbt) {
	if(counttg > 7) {
		counttg = counttg - 1;
	}
	counttg++;
	wickets_t[3] = counttg;
	sprintf(buft, "%d", counttg);
  	gtk_label_set_text(wlabelbt, buft);
}
void wicketstc_clicked(GtkWidget *widget, gpointer wlabelct) {
	if(countth > 7) {
		countth = countth - 1;
	}
	countth++;
	wickets_t[4] = countth;
	sprintf(buft, "%d", countth);
  	gtk_label_set_text(wlabelct, buft);
}
void wicketstd_clicked(GtkWidget *widget, gpointer wlabeldt) {
	if(countti > 7) {
		countti = countti - 1;
	}
	countti++;
	wickets_t[5] = countti;
	sprintf(buft, "%d", countti);
  	gtk_label_set_text(wlabeldt, buft);
}		




/* ---------------------------------- for dispaly of scorecard---------------------------------------------*/	
static void cardt_as(GtkWidget *button, gpointer window) {
	GtkWidget *window_m, *label, *label1, *label2, *vbox, *totalwickets,*teamscore, *teamwickets, *totscore;
	int i = 1;
	char tscore[5], twickets[5];
	FILE *fp;
	fp = fopen ("pscore1.txt", "w");
	window_m = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window_m), GTK_WIN_POS_CENTER);
        gtk_window_set_default_size(GTK_WINDOW(window_m),1000, 1000);
        gtk_window_set_title(GTK_WINDOW(window_m), "Scorecard");
        gtk_container_set_border_width(GTK_CONTAINER(window_m), 10);

	vbox = gtk_vbox_new(0, 0);
	label1 = gtk_label_new("TEAM 2\nName\t\tScore\t\tSix\t\tStrikerate");
	gtk_box_pack_start(GTK_BOX(vbox), label1, 0,0,0);

	fprintf(fp, "%s\t%d\t%d\t%d\t%.2f\n", "playt1",  fourcount_t[1], sixcount_t[1], inscore_t[1], strikerate_t[1]);
	fprintf(fp, "%s\t%d\t%d\t%d\t%.2f\n", "playt2", fourcount_t[2], sixcount_t[2], inscore_t[2], strikerate_t[2]);
	fprintf(fp, "%s\t%d\t%d\t%d\t%.2f\n", "playt3",  fourcount_t[3], sixcount_t[3], inscore_t[3], strikerate_t[3]);
	fprintf(fp, "%s\t%d\t%d\t%d\t%.2f\n", "playt4",  fourcount_t[4], sixcount_t[4], inscore_t[4], strikerate_t[4]);
	fprintf(fp, "%s\t%d\t%d\t%d\t%.2f\n", "playt5",  fourcount_t[5], sixcount_t[5], inscore_t[5], strikerate_t[5]);
	fprintf(fp, "%s\t%d\t%d\t%d\t%.2f\n", "playt6",  fourcount_t[6], sixcount_t[6], inscore_t[6], strikerate_t[6]);
	fprintf(fp, "%s\t%d\t%d\t%d\t%.2f\n", "playt7",  fourcount[7], sixcount_t[i], inscore_t[7], strikerate_t[7]);
	fprintf(fp, "%s\t%d\t%d\t%d\t%.2f\n", "playt8",  fourcount_t[8], sixcount_t[8], inscore_t[8], strikerate_t[8]);
	fprintf(fp, "%s\t%d\t%d\t%d\t%.2f\n", "playt9",  fourcount_t[8], sixcount_t[i], inscore_t[8], strikerate_t[8]);
	fprintf(fp, "%s\t%d\t%d\t%d\t%.2f\n", "playt10",  fourcount_t[9], sixcount_t[9], inscore_t[9], strikerate_t[9]);
	fprintf(fp, "%s\t%d\t%d\t%d\t%.2f\n", "playt10",  fourcount_t[10], sixcount_t[10], inscore_t[10], strikerate_t[10]);
	fprintf(fp, "%s\t%d\t%d\t%d\t%.2f\n", "playt11",fourcount_t[11], sixcount_t[11], inscore_t[11], strikerate_t[11]);

	
 
	fprintf(fp, "%s\t%d\t%d\n", "bowlt1", overs_t[1], wickets_t[1]);
	fprintf(fp, "%s\t%d\t%d\n", "bowlt2", overs_t[2], wickets_t[2]);
	fprintf(fp, "%s\t%d\t%d\n", "bowlt3",  overs_t[3], wickets_t[3]);
	fprintf(fp, "%s\t%d\t%d\n", "bowlt4", overs_t[4], wickets_t[4]);
	fprintf(fp, "%s\t%d\t%d\n", "bowlt5", overs_t[5], wickets_t[5]);
	
	fclose(fp);	
	char line [100];
	vbox = gtk_vbox_new(0, 0);
	FILE *file;
	file = fopen("pscore1.txt", "r");
	label1 = gtk_label_new("TEAM 2\n\nName\t\tScore\tSix\tStrikeRate\n");
	gtk_box_pack_start(GTK_BOX(vbox), label1, 0, 0, 0);
	for(i = 1; i <= 12; i++) {		
		fgets(line, sizeof(line), file);
		label = gtk_label_new(line);
		gtk_box_pack_start(GTK_BOX(vbox), label, 0,0,0);
		totalscore_t = inscore_t[i] + totalscore_t; 
	}

	totscore = gtk_label_new("TotalScore = ");
	gtk_box_pack_start(GTK_BOX(vbox), totscore, 0, 0, 0);
	sprintf(tscore, "%d", totalscore_t);
	teamscore = gtk_label_new(tscore);
	gtk_box_pack_start(GTK_BOX(vbox), teamscore, 0, 0, 0);

	label2 = gtk_label_new("Name\tOvers\tWickets\tEconomy");	
	gtk_box_pack_start(GTK_BOX(vbox), label2, 0, 0, 0);
	for(i = 1; i <= 5; i++) {
		fgets(line, sizeof line, fp);
		label = gtk_label_new(line);
		gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);
		fallwicket_t = wickets_t[i] + fallwicket_t;
	}
	totalwickets = gtk_label_new("Wickets = ");
	sprintf(twickets, "%d", fallwicket_t);
	teamwickets = gtk_label_new(twickets);
	gtk_box_pack_start(GTK_BOX(vbox), totalwickets, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(vbox), teamwickets, 0, 0, 0);

	
	
	

	gtk_container_add(GTK_CONTAINER(window_m),vbox);

	gtk_widget_show_all(window_m);
	
}
		


