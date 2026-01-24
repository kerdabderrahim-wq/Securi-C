#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Encryption & Decryption/enc_dec.h"
#include "Math & Security Tools/math.h"
#include "Security audit and analysis/security_audit.h"
#include "User Management/user.h"
#include "Log Management & Analysis _/log.h"
static struct Log global_logs[100];
static int global_log_count = 0;

static struct User global_users[100];
static int global_user_count = 0;

// a struct to pass multiple ui elements to callbacks
typedef struct {
    GtkWidget *entry_input1;
    GtkWidget *entry_input2;
    GtkWidget *label_output;
} UiPack;

//switcher callback
static void on_row_toggled(GtkToggleButton *btn, GtkRevealer *revealer) {
    gboolean active = gtk_toggle_button_get_active(btn);
    gtk_revealer_set_reveal_child(revealer, active);
}

//intialize predefined users and logs for testing
void init_predefined_data() {

    global_log_count = 0;
    global_user_count = 0;
    strcpy(global_users[0].name, "admin");
    strcpy(global_users[0].password, "admin123");
    global_users[0].role = 1; // Admin
    global_users[0].state = 0; // Active
    global_user_count++;

    strcpy(global_users[1].name, "yasser");
    strcpy(global_users[1].password, "pass123");
    global_users[1].role = 0; // User
    global_users[1].state = 0; // Active
    global_user_count++;

    
    strcpy(global_users[2].name, "hacker");
    strcpy(global_users[2].password, "123456");
    global_users[2].role = 0; 
    global_users[2].state = 1; // Blocked
    global_user_count++;

    
    strcpy(global_logs[0].user, "admin");
    strcpy(global_logs[0].action, "login");
    strcpy(global_logs[0].date, "2026-01-27");
    strcpy(global_logs[0].time, "10:00");
    global_logs[0].code = 0; 
    global_log_count++;

    strcpy(global_logs[1].user, "admin");
    strcpy(global_logs[1].action, "error");
    strcpy(global_logs[1].date, "2026-01-27");
    strcpy(global_logs[1].time, "10:15");
    global_logs[1].code = 1; // Error
    global_log_count++;

   
    strcpy(global_logs[2].user, "hacker");
    strcpy(global_logs[2].action, "Attempted Access");
    strcpy(global_logs[2].date, "2026-01-27");
    strcpy(global_logs[2].time, "12:00");
    global_logs[2].code = 2; // Blocked
    global_log_count++;
}
             

//Encryption & Decryption Callbacks

static void Gui_encrypt_cesar(GtkWidget *btn, gpointer data) {
    //static means this function is only visible within this file
    UiPack *p = (UiPack*)data;
    const char *txt = gtk_entry_get_text(GTK_ENTRY(p->entry_input1));
    const char *k = gtk_entry_get_text(GTK_ENTRY(p->entry_input2));
    struct Message m;
    strncpy(m.text, txt, 511); m.text[511] = 0;
    m.length = strlen(m.text);
    encryptCesar(&m, atoi(k));
    // atoi is to convert string to integer a function from stdlib.h
    gtk_label_set_text(GTK_LABEL(p->label_output), m.text);
    // label_output is the label where we display the result
}

static void Gui_decrypt_cesar(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    const char *txt = gtk_entry_get_text(GTK_ENTRY(p->entry_input1));
    const char *k = gtk_entry_get_text(GTK_ENTRY(p->entry_input2));
    struct Message m;
    strncpy(m.text, txt, 511); m.text[511] = 0;
    m.length = strlen(m.text);
    decryptCesar(&m, atoi(k));
    gtk_label_set_text(GTK_LABEL(p->label_output), m.text);
}

static void Gui_encrypt_xor(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    const char *txt = gtk_entry_get_text(GTK_ENTRY(p->entry_input1));
    const char *k = gtk_entry_get_text(GTK_ENTRY(p->entry_input2));
    struct Message m;
    strncpy(m.text, txt, 511); m.text[511] = 0;
    m.length = strlen(m.text);
    encryptXOR(&m, atoi(k));
    gtk_label_set_text(GTK_LABEL(p->label_output), m.text);
}

static void Gui_decrypt_xor(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    const char *txt = gtk_entry_get_text(GTK_ENTRY(p->entry_input1));
    const char *k = gtk_entry_get_text(GTK_ENTRY(p->entry_input2));
    struct Message m;
    strncpy(m.text, txt, 511); m.text[511] = 0;
    m.length = strlen(m.text);
    decryptXOR(&m, atoi(k));
    gtk_label_set_text(GTK_LABEL(p->label_output), m.text);
}

static void Gui_reverse_message(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    const char *txt = gtk_entry_get_text(GTK_ENTRY(p->entry_input1));
    struct Message m;
    strncpy(m.text, txt, 511); m.text[511] = 0;
    m.length = strlen(m.text);
    reverseMessage(&m);
    gtk_label_set_text(GTK_LABEL(p->label_output), m.text);
}

//Math Callbacks
static void Gui_is_prime(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    int val = atoi(gtk_entry_get_text(GTK_ENTRY(p->entry_input1)));
    int res = isPrime(val);
    gtk_label_set_text(GTK_LABEL(p->label_output), res ? "True (Prime)" : "False (Not Prime)");
    //ternary operator to set text based on result 
    //res ? "True" : "False" means if res is true return "True" else return "False
}

static void Gui_factorial(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    int val = atoi(gtk_entry_get_text(GTK_ENTRY(p->entry_input1)));
    int res = factorial(val);
    char buf[64]; sprintf(buf, "%d", res);
    //this is the inverse of atoi sprintf converts formatted data to string print into a variable
      
    gtk_label_set_text(GTK_LABEL(p->label_output), buf);
}

static void Gui_gcd(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    int a = atoi(gtk_entry_get_text(GTK_ENTRY(p->entry_input1)));
    int b = atoi(gtk_entry_get_text(GTK_ENTRY(p->entry_input2)));
    int res = gcd(a, b);
    char buf[64]; sprintf(buf, "GCD: %d", res);
    gtk_label_set_text(GTK_LABEL(p->label_output), buf);
}

static void Gui_power(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    int b = atoi(gtk_entry_get_text(GTK_ENTRY(p->entry_input1)));
    int e = atoi(gtk_entry_get_text(GTK_ENTRY(p->entry_input2)));
    int res = power(b, e);
    char buf[64]; sprintf(buf, "Result: %d", res);
    gtk_label_set_text(GTK_LABEL(p->label_output), buf);
}

static void Gui_is_palindrome(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    int val = atoi(gtk_entry_get_text(GTK_ENTRY(p->entry_input1)));
    int res = isPalindromeNumber(val);
    gtk_label_set_text(GTK_LABEL(p->label_output), res ? "Yes" : "No");
}

//Security Audit Callbacks
static void Gui_check_email(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    char buf[256];
    strncpy(buf, gtk_entry_get_text(GTK_ENTRY(p->entry_input1)), 255);
    int res = checkEmailFormat(buf);
    gtk_label_set_text(GTK_LABEL(p->label_output), res ? "Valid Email" : "Invalid Email");
}

static void Gui_password_score(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    char buf[256];
    strncpy(buf, gtk_entry_get_text(GTK_ENTRY(p->entry_input1)), 255);
    int score = passwordScore(buf);
    char out[64]; sprintf(out, "Score: %d", score);
    gtk_label_set_text(GTK_LABEL(p->label_output), out);
}

static void Gui_gen_random_pass(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    int len = atoi(gtk_entry_get_text(GTK_ENTRY(p->entry_input1)));
    if(len > 99) len = 99; 
    char pass[100] = {0};
    generateRandomPassword(len, pass);
    gtk_label_set_text(GTK_LABEL(p->label_output), pass);
}

static void Gui_avg_security(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    //     predefined users
    float avg = averageScore(global_users, global_user_count);
    char out[64]; sprintf(out, "Avg Score: %.2f", avg);
    gtk_label_set_text(GTK_LABEL(p->label_output), out);
}

static void Gui_is_hex_key(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    char buf[256];
    strncpy(buf, gtk_entry_get_text(GTK_ENTRY(p->entry_input1)), 255);
    int res = isHexKey(buf);
    gtk_label_set_text(GTK_LABEL(p->label_output), res ? "Yes" : "No");
}

//User Management Callbacks
static void Gui_user_check_login(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    char u[256], pass[256];
    strncpy(u, gtk_entry_get_text(GTK_ENTRY(p->entry_input1)), 255); u[255]=0;
    strncpy(pass, gtk_entry_get_text(GTK_ENTRY(p->entry_input2)), 255); pass[255]=0;
    
    int res = checkLogin(global_users, global_user_count, u, pass);
    if(res == 1) gtk_label_set_text(GTK_LABEL(p->label_output), "Login Success");
    else if(res == 0) gtk_label_set_text(GTK_LABEL(p->label_output), "Login Failed");
    else if(res == -1) gtk_label_set_text(GTK_LABEL(p->label_output), "Blocked");
    else gtk_label_set_text(GTK_LABEL(p->label_output), "Unknown Error");
}

static void Gui_user_search(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    char u[256];
    strncpy(u, gtk_entry_get_text(GTK_ENTRY(p->entry_input1)), 255); u[255]=0;
    
    int idx = searchUser(global_users, global_user_count, u);
    if(idx != -1) {
        char out[100];
        sprintf(out, "Found at index %d", idx);
        gtk_label_set_text(GTK_LABEL(p->label_output), out);
    } else {
        gtk_label_set_text(GTK_LABEL(p->label_output), "User Not Found");
    }
}

static void Gui_user_add(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    char u[256], pass[256];
    strncpy(u, gtk_entry_get_text(GTK_ENTRY(p->entry_input1)), 255); u[255]=0;
    strncpy(pass, gtk_entry_get_text(GTK_ENTRY(p->entry_input2)), 255); pass[255]=0;
    
    if(global_user_count < 100) {
        strcpy(global_users[global_user_count].name, u);
        strcpy(global_users[global_user_count].password, pass);
        global_users[global_user_count].role = 0;
        global_users[global_user_count].state = 0;
        global_user_count++;
        gtk_label_set_text(GTK_LABEL(p->label_output), "User Added");
    } else {
        gtk_label_set_text(GTK_LABEL(p->label_output), "Full");
    }
}

static void Gui_user_strong_pass(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    char buf[256];
    strncpy(buf, gtk_entry_get_text(GTK_ENTRY(p->entry_input1)), 255);
    int res = strongPassword(buf);
    gtk_label_set_text(GTK_LABEL(p->label_output), res ? "Strong" : "Weak");
}

static void Gui_contains_upper(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    char buf[256];
    strncpy(buf, gtk_entry_get_text(GTK_ENTRY(p->entry_input1)), 255);
    int res = containsUppercase(buf);
    gtk_label_set_text(GTK_LABEL(p->label_output), res ? "Yes" : "No");
}

static void Gui_contains_digit(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    char buf[256];
    strncpy(buf, gtk_entry_get_text(GTK_ENTRY(p->entry_input1)), 255);
    int res = containsDigit(buf);
    gtk_label_set_text(GTK_LABEL(p->label_output), res ? "Yes" : "No");
}

static void Gui_string_length(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    char buf[256];
    strncpy(buf, gtk_entry_get_text(GTK_ENTRY(p->entry_input1)), 255);
    int res = stringLength(buf);
    char out[64]; sprintf(out, "Length: %d", res);
    gtk_label_set_text(GTK_LABEL(p->label_output), out);
}

static void Gui_contains_symbol(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    char buf[256];
    strncpy(buf, gtk_entry_get_text(GTK_ENTRY(p->entry_input1)), 255);
    int res = containsSymbol(buf);
    gtk_label_set_text(GTK_LABEL(p->label_output), res ? "Yes" : "No");
}


//log Management & Analysis Callbacks  
static void Gui_add_log(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    char usr[256], act[256];
    strncpy(usr, gtk_entry_get_text(GTK_ENTRY(p->entry_input1)), 255);
    strncpy(act, gtk_entry_get_text(GTK_ENTRY(p->entry_input2)), 255);
    
    if (global_log_count < 100) {
        addLog(global_logs, global_log_count, usr, act, 0); 
        global_log_count++;
        gtk_label_set_text(GTK_LABEL(p->label_output), "Log Added");
    } else {
        gtk_label_set_text(GTK_LABEL(p->label_output), "Storage Full");
    }
}

static void Gui_count_error(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    int c = countErrorLogs(global_logs, global_log_count);
    char buf[64]; sprintf(buf, "Errors: %d", c);
    gtk_label_set_text(GTK_LABEL(p->label_output), buf);
}

static void Gui_count_blocked(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    int c = countBlockedLogs(global_logs, global_log_count);
    char buf[64]; sprintf(buf, "Blocked: %d", c);
    gtk_label_set_text(GTK_LABEL(p->label_output), buf);
}

static void Gui_error_rate(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    float r = errorRate(global_logs, global_log_count);
    char buf[64]; sprintf(buf, "Rate: %.2f", r);
    gtk_label_set_text(GTK_LABEL(p->label_output), buf);
}

static void Gui_clear_logs(GtkWidget *btn, gpointer data) {
    UiPack *p = (UiPack*)data;
    global_log_count = 0; 
    gtk_label_set_text(GTK_LABEL(p->label_output), "Logs Cleared");
}


//building the GUI
void add_test_row(GtkWidget *parent, const char *title, const char *desc, 
                  int inputs, const char *ph1, const char *ph2, 
                  GCallback func) {
    // ph1 and ph2 are placeholder texts for input entries
    GtkWidget *btn = gtk_toggle_button_new_with_label(title);
    //gtkwidget is the base class for all widgets in GTK
    GtkWidget *revealer = gtk_revealer_new();
    gtk_revealer_set_transition_type(GTK_REVEALER(revealer), GTK_REVEALER_TRANSITION_TYPE_SLIDE_DOWN);
    
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_set_border_width(GTK_CONTAINER(box), 10);
    
    GtkWidget *lbl_desc = gtk_label_new(desc);
    gtk_label_set_justify(GTK_LABEL(lbl_desc), GTK_JUSTIFY_LEFT);
    gtk_widget_set_halign(lbl_desc, GTK_ALIGN_START);
    gtk_box_pack_start(GTK_BOX(box), lbl_desc, FALSE, FALSE, 0);
    
    UiPack *pack = g_malloc(sizeof(UiPack));
    pack->entry_input1 = NULL;
    pack->entry_input2 = NULL;
    
    if (inputs >= 1) {
        pack->entry_input1 = gtk_entry_new();
        gtk_entry_set_placeholder_text(GTK_ENTRY(pack->entry_input1), ph1);
        gtk_box_pack_start(GTK_BOX(box), pack->entry_input1, FALSE, FALSE, 0);
    }
    if (inputs >= 2) {
        pack->entry_input2 = gtk_entry_new();
        gtk_entry_set_placeholder_text(GTK_ENTRY(pack->entry_input2), ph2);
        gtk_box_pack_start(GTK_BOX(box), pack->entry_input2, FALSE, FALSE, 0);
    }
    
    GtkWidget *run_btn = gtk_button_new_with_label("Run");
    g_signal_connect(run_btn, "clicked", func, pack);
    gtk_box_pack_start(GTK_BOX(box), run_btn, FALSE, FALSE, 5);
    
    pack->label_output = gtk_label_new("Result: -");
    gtk_box_pack_start(GTK_BOX(box), pack->label_output, FALSE, FALSE, 0);
    
    gtk_container_add(GTK_CONTAINER(revealer), box);
    
    gtk_box_pack_start(GTK_BOX(parent), btn, FALSE, FALSE, 2);
    gtk_box_pack_start(GTK_BOX(parent), revealer, FALSE, FALSE, 2);
    
    g_signal_connect(btn, "toggled", G_CALLBACK(on_row_toggled), revealer);
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *header_bar;
    GtkWidget *stack;
    GtkWidget *stack_switcher;
    
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "B3 Securi-c Tests");
    gtk_window_set_default_size(GTK_WINDOW(window), 900, 700);
    
    header_bar = gtk_header_bar_new();
    // Enable the close button on the header bar
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(header_bar), TRUE);
    // Set the title of the header bar
    gtk_window_set_titlebar(GTK_WINDOW(window), header_bar);
    
    stack = gtk_stack_new();
    // Create a stack switcher to switch between pages
    gtk_stack_set_transition_type(GTK_STACK(stack), GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT_RIGHT);
    
    //encription & decryption page
    GtkWidget *box_enc = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    //horizontal alignment
    gtk_widget_set_halign(box_enc, GTK_ALIGN_FILL);

    gtk_box_pack_start(GTK_BOX(box_enc), gtk_label_new("Encryption Tools"), FALSE, FALSE, 10);
    
    add_test_row(box_enc, "Caesar Encrypt", "Text + Integer Key", 2, "Message", "Key (int)", G_CALLBACK(Gui_encrypt_cesar));
    add_test_row(box_enc, "Caesar Decrypt", "Text + Integer Key", 2, "Message", "Key (int)", G_CALLBACK(Gui_decrypt_cesar));
    add_test_row(box_enc, "XOR Encrypt", "Text + Integer Key", 2, "Message", "Key (int)", G_CALLBACK(Gui_encrypt_xor));
    add_test_row(box_enc, "XOR Decrypt", "Text + Integer Key", 2, "Message", "Key (int)", G_CALLBACK(Gui_decrypt_xor));
    add_test_row(box_enc, "Reverse Message", "Reverses the text", 1, "Message", NULL, G_CALLBACK(Gui_reverse_message));
    
    //math page
    GtkWidget *box_math = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_pack_start(GTK_BOX(box_math), gtk_label_new("Math Tools"), FALSE, FALSE, 10);
    
    add_test_row(box_math, "Is Prime", "Check if number is prime", 1, "Number", NULL, G_CALLBACK(Gui_is_prime));
    add_test_row(box_math, "Factorial", "Calculate Factorial", 1, "Number", NULL, G_CALLBACK(Gui_factorial));
    add_test_row(box_math, "GCD", "Greatest Common Divisor", 2, "Num A", "Num B", G_CALLBACK(Gui_gcd));
    add_test_row(box_math, "Power", "Calculate Base^Exp", 2, "Base", "Exponent", G_CALLBACK(Gui_power));
    add_test_row(box_math, "Palindrome", "Check if number is palindrome", 1, "Number", NULL, G_CALLBACK(Gui_is_palindrome));
    
    //security audit page
    GtkWidget *box_sec = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_pack_start(GTK_BOX(box_sec), gtk_label_new("Security Audit"), FALSE, FALSE, 10);
    
    add_test_row(box_sec, "Check Email", "Validate email format", 1, "Email", NULL, G_CALLBACK(Gui_check_email));
    add_test_row(box_sec, "Password Score", "Get password strength score", 1, "Password", NULL, G_CALLBACK(Gui_password_score));
    add_test_row(box_sec, "Generate Random Pass", "Generate random password of length", 1, "Length", NULL, G_CALLBACK(Gui_gen_random_pass));
    add_test_row(box_sec, "User Security Avg", "Avg Security Score of Predefined Users", 0, NULL, NULL, G_CALLBACK(Gui_avg_security));
    add_test_row(box_sec, "Hex Key Check", "Check if string is hex key", 1, "Key", NULL, G_CALLBACK(Gui_is_hex_key));
    
    //user management page
    GtkWidget *box_user = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_pack_start(GTK_BOX(box_user), gtk_label_new("User Management"), FALSE, FALSE, 10);
    
    add_test_row(box_user, "Add User", "Add a new user to the global list", 2, "Username", "Password", G_CALLBACK(Gui_user_add));
    add_test_row(box_user, "Check Strong Password", "Check password strength", 1, "Password", NULL, G_CALLBACK(Gui_user_strong_pass));
    add_test_row(box_user, "Contains Uppercase", "Check for uppercase chars", 1, "Text", NULL, G_CALLBACK(Gui_contains_upper));
    add_test_row(box_user, "Contains Digit", "Check for digits", 1, "Text", NULL, G_CALLBACK(Gui_contains_digit));
    add_test_row(box_user, "String Length", "Calculate length", 1, "Text", NULL, G_CALLBACK(Gui_string_length));
    add_test_row(box_user, "Contains Symbol", "Check for symbols", 1, "Text", NULL, G_CALLBACK(Gui_contains_symbol));
    add_test_row(box_user, "Check Login", "Verify credentials against predefined users (e.g. admin/admin123)", 2, "Username", "Password", G_CALLBACK(Gui_user_check_login));
    add_test_row(box_user, "Search User", "Find index of user by name (e.g. john)", 1, "Username", NULL, G_CALLBACK(Gui_user_search));
    
    //logs page
    GtkWidget *box_log = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_pack_start(GTK_BOX(box_log), gtk_label_new("Log Management"), FALSE, FALSE, 10);
    
    add_test_row(box_log, "Add Log", "Add a new log entry", 2, "User", "Action", G_CALLBACK(Gui_add_log));
    add_test_row(box_log, "Count Errors", "Count error logs (Code 1)", 0, NULL, NULL, G_CALLBACK(Gui_count_error));
    add_test_row(box_log, "Count Blocked", "Count blocked logs (Code 2)", 0, NULL, NULL, G_CALLBACK(Gui_count_blocked));
    add_test_row(box_log, "Error Rate", "Calculate error rate among all logs", 0, NULL, NULL, G_CALLBACK(Gui_error_rate));
    add_test_row(box_log, "Clear Logs", "Clear all logs", 0, NULL, NULL, G_CALLBACK(Gui_clear_logs));

    // Scrolled Windows
    GtkWidget *scroll_enc = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(scroll_enc), box_enc);
    
    GtkWidget *scroll_math = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(scroll_math), box_math);
    
    GtkWidget *scroll_sec = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(scroll_sec), box_sec);
    
    GtkWidget *scroll_user = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(scroll_user), box_user);
    
    GtkWidget *scroll_log = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(scroll_log), box_log);
    
    gtk_stack_add_titled(GTK_STACK(stack), scroll_enc, "enc", "Encryption");
    gtk_stack_add_titled(GTK_STACK(stack), scroll_math, "math", "Math");
    gtk_stack_add_titled(GTK_STACK(stack), scroll_sec, "sec", "Security");
    gtk_stack_add_titled(GTK_STACK(stack), scroll_user, "user", "User");
    gtk_stack_add_titled(GTK_STACK(stack), scroll_log, "log", "Logs");
    
    stack_switcher = gtk_stack_switcher_new();
    gtk_stack_switcher_set_stack(GTK_STACK_SWITCHER(stack_switcher), GTK_STACK(stack));
    gtk_header_bar_set_custom_title(GTK_HEADER_BAR(header_bar), stack_switcher);
    
    gtk_container_add(GTK_CONTAINER(window), stack);
    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    // Initialize Data
    init_predefined_data();

    GtkApplication *app;
    int status;

    app = gtk_application_new("com.b3.securic", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}