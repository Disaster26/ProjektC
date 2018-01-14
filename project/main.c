#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>


GtkBuilder *builder;
GtkWidget *window,*window2;
GtkWidget *radiobutton2;
GtkWidget *radiobutton3;
GtkWidget *radiobutton4;
GtkWidget *radiobutton5;
GtkWidget *radiobutton6;
GtkWidget *combo,*vbox2,*vbox3,*combo2;
GtkWidget *entry1,*entry2,*entry3,*entry4,*entry5,*entry6,*entry7,*entry8 ;
GtkListStore *liststore;
GtkCellRenderer *column;
GtkListStore *liststore2;
GtkCellRenderer *column2;
char *text;
double wynik;
gchar *wynik2;
int wiek;
int waga;
gint aktywnosc;
gint plec;
double wzrost;
double talia;

void SaveFile()
{
    GtkWidget *dialog;
    dialog=gtk_file_chooser_dialog_new("Choose File",GTK_WINDOW(window),
                                       GTK_FILE_CHOOSER_ACTION_SAVE,GTK_STOCK_OK,GTK_RESPONSE_OK,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,NULL);
    gtk_widget_show_all(dialog);





}

int main(int argc, char *argv[])
{

    gtk_init(&argc, &argv);


    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "Project.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window2"));
    gtk_window_set_resizable (GTK_WINDOW(window), FALSE);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    gtk_builder_connect_signals(builder, NULL);
    entry1 = GTK_WIDGET(gtk_builder_get_object(builder, "entry1"));
    entry2 = GTK_WIDGET(gtk_builder_get_object(builder, "entry2"));
    entry3 = GTK_WIDGET(gtk_builder_get_object(builder, "entry3"));
    entry4 = GTK_WIDGET(gtk_builder_get_object(builder, "entry4"));
    entry5 = GTK_WIDGET(gtk_builder_get_object(builder, "entry5"));
    entry6 = GTK_WIDGET(gtk_builder_get_object(builder, "entry6"));
    entry7 = GTK_WIDGET(gtk_builder_get_object(builder, "entry7"));
    entry8 = GTK_WIDGET(gtk_builder_get_object(builder, "entry8"));
    vbox2 = GTK_WIDGET(gtk_builder_get_object(builder, "vbox2"));
    vbox3 = GTK_WIDGET(gtk_builder_get_object(builder, "vbox3"));
    radiobutton2 = GTK_WIDGET(gtk_builder_get_object(builder, "radiobutton2"));
    radiobutton3 = GTK_WIDGET(gtk_builder_get_object(builder, "radiobutton3"));
    radiobutton4 = GTK_WIDGET(gtk_builder_get_object(builder, "radiobutton4"));
    radiobutton5 = GTK_WIDGET(gtk_builder_get_object(builder, "radiobutton5"));
    radiobutton6 = GTK_WIDGET(gtk_builder_get_object(builder, "radiobutton6"));


    liststore = gtk_list_store_new(2, G_TYPE_STRING, G_TYPE_STRING);
    gtk_list_store_insert_with_values(liststore, NULL, -1,
                                      0, NULL,
                                      1, "mężczyzna",
                                      -1);
    gtk_list_store_insert_with_values(liststore, NULL, -1,
                                      0, NULL,
                                      1, "kobieta",
                                      -1);

    combo = gtk_combo_box_new_with_model(GTK_TREE_MODEL(liststore));

    /* liststore is now owned by combo, so the initial reference can
     * be dropped */
    g_object_unref(liststore);

    column = gtk_cell_renderer_text_new();
    gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(combo), column, TRUE);

    /* column does not need to be g_object_unref()ed because it
     * is GInitiallyUnowned and the floating reference has been
     * passed to combo by the gtk_cell_layout_pack_start() call. */

    gtk_cell_layout_set_attributes(GTK_CELL_LAYOUT(combo), column,
                                   "cell-background", 0,
                                   "text", 1,
                                   NULL);

    gtk_combo_box_set_active(GTK_COMBO_BOX(combo), 0);

    gtk_container_add(GTK_CONTAINER(vbox2), combo);





    liststore2 = gtk_list_store_new(2, G_TYPE_STRING, G_TYPE_STRING);
    gtk_list_store_insert_with_values(liststore2, NULL, -1,
                                      0, NULL,
                                      1, "brak aktywności fizycznej",
                                      -1);
    gtk_list_store_insert_with_values(liststore2, NULL, -1,
                                      0, NULL,
                                      1, "trening raz w tygodniu",
                                      -1);
    gtk_list_store_insert_with_values(liststore2, NULL, -1,
                                      0, NULL,
                                      1, "trening 2 razy w tygodniu",
                                      -1);
    gtk_list_store_insert_with_values(liststore2, NULL, -1,
                                      0, NULL,
                                      1, "trening 3-4 razy w tygodniu",
                                      -1);
    gtk_list_store_insert_with_values(liststore2, NULL, -1,
                                      0, NULL,
                                      1, "trening 5 razy w tygodniu",
                                      -1);
    gtk_list_store_insert_with_values(liststore2, NULL, -1,
                                      0, NULL,
                                      1, "codzienny trening",
                                      -1);

    combo2 = gtk_combo_box_new_with_model(GTK_TREE_MODEL(liststore2));

    /* liststore is now owned by combo, so the initial reference can
     * be dropped */
    g_object_unref(liststore2);

    column2 = gtk_cell_renderer_text_new();
    gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(combo2), column2, TRUE);

    /* column does not need to be g_object_unref()ed because it
     * is GInitiallyUnowned and the floating reference has been
     * passed to combo by the gtk_cell_layout_pack_start() call. */

    gtk_cell_layout_set_attributes(GTK_CELL_LAYOUT(combo2), column2,
                                   "cell-background", 0,
                                   "text", 1,
                                   NULL);

    gtk_combo_box_set_active(GTK_COMBO_BOX(combo2), 0);

    gtk_container_add(GTK_CONTAINER(vbox3), combo2);


    /* Also combo is GInitiallyUnowned and it is now owned
       by window after the gtk_container_add() call. */

    //g_signal_connect(radiobutton6, "toggled", G_CALLBACK(toggled_func), (gpointer)"5");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_object_unref(builder);
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
void close_window()
{
    gtk_widget_destroy(GTK_WIDGET(window2));
}
G_MODULE_EXPORT void on_btn_wybierz_clicked()
{

    GtkWidget *grid;
    GtkWidget *button;
    GtkWidget *button2;
    GtkWidget *label;
    GtkWidget *label2;
    GtkWidget *label3;
    GtkWidget *obraz;

    /*Create the window and set a title*/
    window2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window2), text);
    gtk_window_set_resizable (GTK_WINDOW(window2), FALSE);
    gtk_window_set_position(GTK_WINDOW(window2), GTK_WIN_POS_CENTER);
    /*Create a button with a label*/
    button = gtk_button_new_with_label ("Zapisz");
    button2 = gtk_button_new_with_label ("Anuluj");
    GError *error = NULL;
    GdkPixbuf *pix = gdk_pixbuf_new_from_file ("poziom.jpg", &error);
    pix=gdk_pixbuf_scale_simple(pix,900,400,GDK_INTERP_BILINEAR);
    if (pix == NULL)
    {
        g_printerr ("Error loading file: #%d %s\n", error->code, error->message);
        g_error_free (error);
        exit (1);
    }
    obraz= gtk_image_new_from_pixbuf (pix);
    grid = gtk_grid_new ();
    waga=atoi(gtk_entry_get_text(GTK_ENTRY(entry6)));
    wzrost=atoi(gtk_entry_get_text(GTK_ENTRY(entry7)));
    wiek=atoi(gtk_entry_get_text(GTK_ENTRY(entry3)));
    aktywnosc = gtk_combo_box_get_active(GTK_COMBO_BOX(combo2));
    plec= gtk_combo_box_get_active(GTK_COMBO_BOX(combo2));  /// 0 mężczyzna , 1 kobieta
    talia=atoi(gtk_entry_get_text(GTK_ENTRY(entry5)));
    label = gtk_label_new("");
    label2 = gtk_label_new("");
    label3 = gtk_label_new("");
    gchar *lbl1=NULL;
    gchar *lbl2=NULL;
    gchar *lbl3=NULL;
    char *markup=NULL;
    int blokada=0;
    const char *format = "<b>%s</b>";
    char *markup2=NULL;
    const char *format2 = "<i>%s</i>";
    gtk_widget_modify_font (label2,
                            pango_font_description_from_string ("Monospace 25")
                           );
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton3)))
    {
        if(waga==0)
        {
            blokada=0;

            gtk_entry_set_text(GTK_ENTRY(entry6),"BŁĄD(wprowadź np. 80)");
        }
        if(wzrost==0)
        {
            blokada=0;
            gtk_entry_set_text(GTK_ENTRY(entry7),"BŁĄD(wprowadź np. 180.5)");
        }
        if(wzrost!=0&&waga!=0) blokada=1;
        text = "Wskaznik BMI"; /// https://portal.abczdrowie.pl/jak-obliczyc-bmi
        wynik=waga/(wzrost*wzrost)*10000;
        lbl1=g_strdup_printf("%s dla: %dkg masy ciała i %.1fm wzrostu:",text,waga,wzrost/100);

        if(wynik<16) lbl2=g_strdup_printf("wynik %.1f : wygłodzenie",(gdouble)wynik);
        else if(wynik>=16&&wynik<17) lbl2=g_strdup_printf("wynik %.1f : wychudzenie",(gdouble)wynik);
        else if(wynik>=17&&wynik<18.5) lbl2=g_strdup_printf("wynik %.1f : niedowaga",(gdouble)wynik);
        else if(wynik>=18.5&&wynik<25) lbl2=g_strdup_printf("wynik %.1f : wartość prawidłowa",(gdouble)wynik);
        else if(wynik>=25&&wynik<30) lbl2=g_strdup_printf("wynik %.1f : nadwaga",(gdouble)wynik);
        else if(wynik>=30&&wynik<35) lbl2=g_strdup_printf("wynik %.1f : I stopień otyłości",(gdouble)wynik);
        else if(wynik>=35&&wynik<40) lbl2=g_strdup_printf("wynik %.1f : II stopień otyłości",(gdouble)wynik);
        else if(wynik>=40) lbl2=g_strdup_printf("wynik %.1f : III stopień otyłości(otylość skrajna)",(gdouble)wynik);
        gtk_label_set_text(GTK_LABEL(label2),lbl2);
        lbl3=g_strdup_printf("BMI (Body Mass Index), zwany też wskaźnikiem Queteleta, służy oszacowaniu, czy waga ciała jest prawidłowa. To narzędzie, które pozwala zorientować się, czy nasza dieta oraz styl życia są właściwe, a także czy powinniśmy udać się do specjalisty z prośbą o pomoc. To także najkrótsza droga do pierwszej diagnozy lekarskiej ­- kontrola indeksu BMI służy monitorowaniu stanu zdrowia naszego organizmu.");

    }
    else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton4)))
    {
        if(waga==0)
        {
            blokada=0;
            gtk_entry_set_text(GTK_ENTRY(entry6),"BŁĄD(wprowadź np. 80)");
        }
        else blokada=1;
        text = "Dzienne zapotrzebowanie na kalorie"; /// http://www.fabrykasily.pl/porady-trenerow/zapotrzebowanie-kaloryczne-wyliczenie  metoda 1
        wynik=waga*24;
        if(aktywnosc==0) lbl1=g_strdup_printf("%s dla: %dkg i leżącego lub siedzącego trybu życia oraz braku aktywności fizycznej",text,waga);
        else if(aktywnosc==1)
        {
            lbl1=g_strdup_printf("%s dla: %dkg i pracy siedzącej oraz aktywności fizycznej na niskim poziomie",text,waga);
            wynik=wynik*1.2;
        }
        else if(aktywnosc==2)
        {
            lbl1=g_strdup_printf("%s dla: %dkg i pracy niefizycznej oraz treningu 2 razy w tygodniu",text,waga);
            wynik=wynik*1.4;
        }
        else if(aktywnosc==3)
        {
            lbl1=g_strdup_printf("%s dla: %dkg i lekkiej pracy fizycznej oraz treningu 3-4 razy w tygodniu",text,waga);
            wynik=wynik*1.6;
        }
        else if(aktywnosc==4)
        {
            lbl1=g_strdup_printf("%s dla: %dkg i pracy fizycznej oraz treningu 5 razy w tygodniu",text,waga);
            wynik=wynik*1.8;
        }
        else if(aktywnosc==5)
        {
            lbl1=g_strdup_printf("%s dla: %dkg i ciężkiej pracy fizycznej oraz codziennego treningu",text,waga);
            wynik=wynik*2;
        }
        gtk_label_set_text(GTK_LABEL(label),lbl1);
        lbl2=g_strdup_printf("wynik: %.2fkcal",wynik);
        gtk_label_set_text(GTK_LABEL(label2),lbl2);
        lbl3=g_strdup_printf("Podstawowa przemiana materii (PPM znana również jak BMR) to ilość kalorii, jaką potrzebujemy do podtrzymania podstawowych funkcji życiowych i prawidłowego funkcjonowania organizmu. Możemy do nich zaliczyć m.in. procesy fizjologiczne, oddychanie, sen, trawienie, utrzymanie prawidłowej temperatury ciała, ale też naszą aktywność fizyczną. Im wyższa jest wartość PPM, tym większe jest zapotrzebowanie kaloryczne, lecz jednocześnie lepsze spalanie kalorii, co ma duże znaczenie choćby w okresie redukcji tkanki tłuszczowej czy też po prostu w utrzymaniu prawidłowej wagi ciała.");
    }
    else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton5)))
    {
        if(wzrost==0)
        {
            blokada=0;
            gtk_entry_set_text(GTK_ENTRY(entry7),"BŁĄD(wprowadź np. 180.5)");
        }
        else blokada=1;
        text = "Kalkulator idealnej wagi"; ///http://www.dieta-forum.pl/kalkulator-kalorii/waga-idealna
        if(plec==0)
        {
            lbl1=g_strdup_printf("%s dla: mężczyzny %dcm wzrostu",text,(int)wzrost);
            wynik=wzrost-100-((wzrost-150)/4);
        }
        else
        {
            lbl1=g_strdup_printf("%s dla: kobiety %dcm",text,(int)wzrost);
            wynik=wzrost-100-((wzrost-150)/2.5);
        }
        gtk_label_set_text(GTK_LABEL(label),lbl1);
        lbl2=g_strdup_printf("wynik: %.2fkg",wynik);
        gtk_label_set_text(GTK_LABEL(label2),lbl2);
        lbl3=g_strdup_printf("Wskaźnik określający idealny stosunek masy ciała do wzrostu osobnika ma za zadanie ukazać, ile powinniśmy ważyć, gdy zależy nam na zdrowej, szczupłej sylwetce. Zagadnieniem tym, zajmowali się m.in. tacy autorzy jak Broca, Lorentz, czy Potton. Przedmiotem ich rachunków, było uzyskanie wyliczenia, które ma za zadanie wskazać, jedynie za pomocą jednej wartości, czyli wzrostu, idealną masę ciała. Jak się okazuje, tego typu algorytmy się sprawdzają, jednak głównie wśród osób nietrenujących kulturystyki lub dążących do uzyskania szczupłej sylwetki.");
    }
    else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton6)))
    {
        if(talia==0)
        {
            blokada=0;
            gtk_entry_set_text(GTK_ENTRY(entry5),"BŁĄD(wprowadź np. 100.5)");
        }
        if(waga==0)
        {
            blokada=0;
            gtk_entry_set_text(GTK_ENTRY(entry6),"BŁĄD(wprowadź np. 80)");
        }
        if(talia!=0&&waga!=0) blokada=1;
        text = "Wskaznik tkanki tluszczowej"; ///https://www.trener.pl/trener-odpowiada/jak-obliczyc-zawartosc-tkanki-tluszczowej-w-organizmie/   ||| https://www.trener.pl/trening/atrakcyjnosc-fizyczna-a-poziom-tkanki-tluszczowej/
        if(plec==0)
        {
            lbl1=g_strdup_printf("%s dla: mężczyzny %.1f obwodu pasa(talii) %dkg masy ciała",text,talia,waga);
            wynik=((((4.15*talia)/2.54)-(0.082*waga*2.2)-98.42)/(waga*2.2))*100;
        }
        else
        {
            lbl1=g_strdup_printf("%s dla: kobiety %dcm obwodu pasa(talii)",text,(int)talia);
            wynik=((((4.15*talia)/2.54)-(0.082*waga*2.2)-76.76)/(waga*2.2))*100;
        }
        gtk_label_set_text(GTK_LABEL(label),lbl1);
        lbl2=g_strdup_printf("Twój wynik: %.2f%%",wynik);
        gtk_label_set_text(GTK_LABEL(label2),lbl2);
        gtk_grid_attach (GTK_GRID (grid), label, 1, 1, 1, 1);
        gtk_grid_attach (GTK_GRID (grid), label2, 1, 42, 76, 1);
        gtk_grid_attach (GTK_GRID (grid), obraz, 1, 1, 80, 80);
        gtk_grid_attach (GTK_GRID (grid), button, 40, 90, 41, 35);
        gtk_grid_attach_next_to (GTK_GRID (grid),
                                 button2,
                                 button,
                                 GTK_POS_LEFT, 35, 35);

//lbl3=g_strdup_printf("Zawartość tkanki tłuszczowej w organizmie (BF %%) można obliczyć za pomocą wielu metod. Niektóre z nich dla wielu nie będą nigdy dostępne, ponieważ wymagają albo dostępu do specjalistycznego sprzętu pomiarowego albo umiejętności wykorzystywania bardzo skomplikowanych wzorów antropometrycznych. Ze wszystkich metod, które zostały stworzone i opracowane, począwszy od pomiarów fałd skórno – mięśniowych aż po metody wykorzystujące impuls bioelektryczny, nieskomplikowaną i skuteczną metodą jest YMCA, która właśnie określa poziom tkanki tłuszczowej w organizmie. Metoda YMCA jest prosta z tego względu, ponieważ wykorzystuję tylko dwie zmienne: obwód pasa (talii) oraz masę ciała. Wiele osób, które nie mają dostępu do specjalistycznego sprzętu badającego zawartość tkanki tłuszczowej w organizmie, jest skazana na niewiedzę. A przecież poziom tkanki tłuszczowej jest wskaźnikiem, który można wykorzystywać w rejestrowaniu zmian w organizmie podczas prowadzenia diety lub dawkowania wzmożonej aktywności ruchowej.");
    }
    else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton2)))
    {
        if(wiek==0)
        {
            blokada=0;
            gtk_entry_set_text(GTK_ENTRY(entry3),"BŁĄD(wprowadź np. 20)");
        }
        if(waga==0)
        {
            blokada=0;
            gtk_entry_set_text(GTK_ENTRY(entry6),"BŁĄD(wprowadź np. 80)");
        }
        if(wiek!=0&&waga!=0) blokada=1;
        text = "Kalkulator tętna maksymalnego"; // https://trenerbiegania.pl/kalkulatory/hrmax metoda Sally Edwards
        if(plec==0)
        {
            lbl1=g_strdup_printf("%s dla: mężczyzny %dkg i %d lat",text,waga,wiek);
            wynik=(210-(0.5*wiek))-(0.022*waga)+4;
        }
        else
        {
            lbl1=g_strdup_printf("%s dla: kobiety %dkg %d lat",text,waga,wiek);
            wynik=(210-(0.5*wiek))-(0.022*waga);
        }
        gtk_label_set_text(GTK_LABEL(label),lbl1);
        lbl2=g_strdup_printf("wynik: %.2f",wynik);
        gtk_label_set_text(GTK_LABEL(label2),lbl2);
        lbl3=g_strdup_printf("Tętno maksymalne to wartość, przy której zawodnik porusza się w absolutnej granicy mocy. Trening przy maksymalnym obciążeniu jest subiektywnie postrzegany jako niezwykle uciążliwy i odpowiedni tylko dla profesjonalnych sportowców.Początkujący powinni zmierzyć swoje maksymalne tętno przed rozpoczęciem treningu i, w razie potrzeby, zlecić lekarzowi sprawdzenie, jaki zakres tętna mogą bezpiecznie trenować. Zapewnia to, że trenują w granicach swoich możliwości i nie zagrażają zdrowiu.");

    }
    gtk_label_set_line_wrap(GTK_LABEL(label3), TRUE);
    markup2 = g_markup_printf_escaped (format2, lbl3);
    gtk_label_set_markup (GTK_LABEL (label3), markup2);
    g_free(markup2);
    markup = g_markup_printf_escaped (format, lbl1);
    gtk_label_set_markup (GTK_LABEL (label), markup);
    g_free(markup);

    /*Create a grid and attach the button and progress bar
    accordingly*/
    gtk_grid_attach (GTK_GRID (grid), label, 1, 1, 1, 1);
    gtk_grid_attach (GTK_GRID (grid), label2, 1, 42, 76, 1);
    if(!gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton6))) gtk_grid_attach (GTK_GRID (grid), label3, 1, 20, 76, 1);
    gtk_grid_attach (GTK_GRID (grid), button, 50, 90, 100, 50);
    gtk_grid_attach_next_to (GTK_GRID (grid),
                             button2,
                             button,
                             GTK_POS_LEFT, 35, 35);



    /*Connecting the clicked signal to the callback function*/
    g_signal_connect (GTK_BUTTON (button), "clicked",
                      G_CALLBACK (SaveFile), label);

    g_signal_connect (G_OBJECT (button2), "clicked",
                      G_CALLBACK(close_window), NULL);



    gtk_container_add (GTK_CONTAINER (window2), GTK_WIDGET (grid));


    if(blokada!=0)
    {
        gtk_widget_show_all(window2);
        g_signal_connect(window2, "destroy", G_CALLBACK(gtk_main_quit), NULL);
        gtk_main();
    }
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
G_MODULE_EXPORT void on_entry1_icon_press()
{
    gtk_entry_set_text(GTK_ENTRY(entry1),"");
    gtk_widget_grab_focus (entry1);
}
G_MODULE_EXPORT void on_entry2_icon_press()
{
    gtk_entry_set_text(GTK_ENTRY(entry2),"");
    gtk_widget_grab_focus (entry2);
}
G_MODULE_EXPORT void on_entry3_icon_press()
{
    gtk_entry_set_text(GTK_ENTRY(entry3),"");
    gtk_widget_grab_focus (entry3);
}
G_MODULE_EXPORT void on_entry4_icon_press()
{
    gtk_entry_set_text(GTK_ENTRY(entry4),"");
    gtk_widget_grab_focus (entry4);
}
G_MODULE_EXPORT void on_entry5_icon_press()
{
    gtk_entry_set_text(GTK_ENTRY(entry5),"");
    gtk_widget_grab_focus (entry5);
}
G_MODULE_EXPORT void on_entry6_icon_press()
{
    gtk_entry_set_text(GTK_ENTRY(entry6),"");
    gtk_widget_grab_focus (entry6);
}
G_MODULE_EXPORT void on_entry7_icon_press()
{
    gtk_entry_set_text(GTK_ENTRY(entry7),"");
    gtk_widget_grab_focus (entry7);
}
G_MODULE_EXPORT void on_entry8_icon_press()
{
    gtk_entry_set_text(GTK_ENTRY(entry8),"");
    gtk_widget_grab_focus (entry8);
}


