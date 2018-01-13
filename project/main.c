#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>


GtkBuilder *builder;
GtkWidget *window;
GtkWidget *radiobutton2;
GtkWidget *radiobutton3;
GtkWidget *radiobutton4;
GtkWidget *radiobutton5;
GtkWidget *radiobutton6;
GtkWidget *entry1,*entry2,*entry3,*entry4,*entry5,*entry6,*entry7,*entry8 ;
char *text;
double wynik;
gchar *wynik2;
int masa;
double wzrost;
static void toggled_func(GtkWidget* widget, gpointer data)
{

     masa=atoi(gtk_entry_get_text(GTK_ENTRY(entry3)));
     wzrost=atoi(gtk_entry_get_text(GTK_ENTRY(entry7)));
	if(strcmp((char*)data, "1") == 0){
		if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget))){
			text = "Tempo biegu";}}

	if(strcmp((char*)data, "2") == 0){
		if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget))){
			text= "Wskaznik BMI";
			wynik=masa/(wzrost*wzrost)*10000;
			if(wynik<16) wynik2="wyglodzenie";
			else if(wynik>=16&&wynik<17) wynik2="wychudzenie";
			else if(wynik>=17&&wynik<18.5) wynik2="niedowaga";
			else if(wynik>=18.5&&wynik<25) wynik2="wartosc prawidlowa";
			else if(wynik>=25&&wynik<30) wynik2="nadwaga";
			else if(wynik>=30&&wynik<35) wynik2="I stopien otylosci";
			else if(wynik>=35&&wynik<40) wynik2="II stopien otylosci";
			else if(wynik>=40) wynik2="III stopien otylosci(otylosc skrajna)";
	}}
	if(strcmp((char*)data, "3") == 0){
		if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget))){
			text = "Kalkulator kalorii";}}

	if(strcmp((char*)data, "4") == 0){
		if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget))){
			text = "Kalkulator idealnej wagi";}}

	if(strcmp((char*)data, "5") == 0){
		if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget))){
			text = "Wskaznik tkanki tluszczowej";}}
}
int main(int argc, char *argv[])
{

    gtk_init(&argc, &argv);


    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "Project.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window2"));
    gtk_builder_connect_signals(builder, NULL);
    entry1 = GTK_WIDGET(gtk_builder_get_object(builder, "entry1"));
    entry2 = GTK_WIDGET(gtk_builder_get_object(builder, "entry2"));
    entry3 = GTK_WIDGET(gtk_builder_get_object(builder, "entry3"));
    entry4 = GTK_WIDGET(gtk_builder_get_object(builder, "entry4"));
    entry5 = GTK_WIDGET(gtk_builder_get_object(builder, "entry5"));
    entry6 = GTK_WIDGET(gtk_builder_get_object(builder, "entry6"));
    entry7 = GTK_WIDGET(gtk_builder_get_object(builder, "entry7"));
    entry8 = GTK_WIDGET(gtk_builder_get_object(builder, "entry8"));

    radiobutton2 = GTK_WIDGET(gtk_builder_get_object(builder, "radiobutton2"));
    g_signal_connect(radiobutton2, "toggled", G_CALLBACK(toggled_func), (gpointer)"1");
    radiobutton3 = GTK_WIDGET(gtk_builder_get_object(builder, "radiobutton3"));
    g_signal_connect(radiobutton3, "toggled", G_CALLBACK(toggled_func), (gpointer)"2");
    radiobutton4 = GTK_WIDGET(gtk_builder_get_object(builder, "radiobutton4"));
    g_signal_connect(radiobutton4, "toggled", G_CALLBACK(toggled_func), (gpointer)"3");
    radiobutton5 = GTK_WIDGET(gtk_builder_get_object(builder, "radiobutton5"));
    g_signal_connect(radiobutton5, "toggled", G_CALLBACK(toggled_func), (gpointer)"4");
    radiobutton6 = GTK_WIDGET(gtk_builder_get_object(builder, "radiobutton6"));
    g_signal_connect(radiobutton6, "toggled", G_CALLBACK(toggled_func), (gpointer)"5");

    g_object_unref(builder);
    gtk_widget_show(window);
    gtk_main();

    return 0;
}
G_MODULE_EXPORT void on_btn_wybierz_clicked(){
    GtkWidget *grid;
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *label;
  GtkWidget *label2;

  /*Create the window and set a title*/
window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), text);

  /*Create a button with a label*/
  button = gtk_button_new_with_label ("Zapisz");
gchar *lbl1=g_strdup_printf("%s dla: %dkg i %.1fm",text,masa,wzrost/100);
  /*Create the progress bar*/
  label = gtk_label_new(lbl1);
  gchar *lbl2=g_strdup_printf("wynik %.1f : %s",(gdouble)wynik,wynik2);
  label2 = gtk_label_new(lbl2);
  gtk_widget_modify_font (label2,
  pango_font_description_from_string ("Monospace 25")
);

  /*Create a grid and attach the button and progress bar
  accordingly*/
  grid = gtk_grid_new ();
  gtk_grid_attach (GTK_GRID (grid), label, 1, 1, 1, 1);
    gtk_grid_attach (GTK_GRID (grid), label2, 1, 20, 20, 1);
    gtk_grid_attach_next_to (GTK_GRID (grid),
                           button,
                           label2,
                           GTK_POS_BOTTOM, 1, 1);


  /*Connecting the clicked signal to the callback function*/
  g_signal_connect (GTK_BUTTON (button), "clicked",
                    G_CALLBACK (on_btn_wybierz_clicked), label);

  gtk_container_add (GTK_CONTAINER (window), GTK_WIDGET (grid));



	gtk_widget_show_all(window);
	gtk_main();

}
G_MODULE_EXPORT void on_button1_clicked()
{
   GtkWidget *window;
  /* create a new window, and set its title */
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_container_set_border_width (GTK_CONTAINER (window), 200);

  //////////////////////////////

  /////////////////////////

  gtk_widget_show_all (window);
  gtk_main();

    printf("elo");

}
G_MODULE_EXPORT void on_entry1_icon_press(){
gtk_entry_set_text(GTK_ENTRY(entry1)," ");
}
G_MODULE_EXPORT void on_entry2_icon_press(){
gtk_entry_set_text(GTK_ENTRY(entry2)," ");
}
G_MODULE_EXPORT void on_entry3_icon_press(){
gtk_entry_set_text(GTK_ENTRY(entry3)," ");
}
G_MODULE_EXPORT void on_entry4_icon_press(){
gtk_entry_set_text(GTK_ENTRY(entry4)," ");
}
G_MODULE_EXPORT void on_entry5_icon_press(){
gtk_entry_set_text(GTK_ENTRY(entry5)," ");
}
G_MODULE_EXPORT void on_entry6_icon_press(){
gtk_entry_set_text(GTK_ENTRY(entry6)," ");
}
G_MODULE_EXPORT void on_entry7_icon_press(){
gtk_entry_set_text(GTK_ENTRY(entry7)," ");
}
G_MODULE_EXPORT void on_entry8_icon_press(){
gtk_entry_set_text(GTK_ENTRY(entry8)," ");
}
// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}
